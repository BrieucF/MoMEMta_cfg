function append(t1, t2)
    for i = 1, #t2 do
        t1[#t1 + 1] = t2[i]
    end

    return t1
end

function copy_and_append(t1, t2)
    local t3 = {}

    append(t3, t1)
    append(t3, t2)

    return t3
end

-- Order convention : e+ e- b bbar
-- Reco particles : input::particles/1
-- Gen particles, depends on what you do

-- Available parameters : https://github.com/MoMEMta/MoMEMta/blob/master/core/src/MoMEMta.cc#L141
-- If "relative accuracy" is reached stop launching points unless "min_eval" point have been launched,
-- if after "max_eval" points have been launched stop launching even if we do not have reahced accuracy.
-- "n_start" : Vegas works by iterations will launch n_start point by n_start point and refine the grid at each step
-- n_increase allow to launch more points at each iteration
-- NB : all the point that have been launched are used to compute the intergal
cuba = {
    relative_accuracy = 0.01,
    verbosity = 3,
    max_eval = 500000,
    n_start = 15000,
}

-- NB: to be defined in the .cc is matrix_element_prefix

USE_TF = true
USE_PERM = true -- carefull if you use TF binned in eta and the permutations, jet1 tf is applied to jet2

baseDirME = "/home/fynu/bfrancois/scratch/MoMEMta/plugin_mode/"
baseDirTF = "/home/fynu/bfrancois/scratch/framework/MIS_prod_data/CMSSW_7_6_5/src/cp3_llbb/HHTools/histFactory_hh/"
TFFile = baseDirTF .. "tf_genCut0_noRecoCut_lljjorbb_Oct18/condor/output/allTT_smoothed_notPutToZero.root"
parameters = {
    energy = 13000.,
    top_mass = 173.,
    top_width = 1.491500,
    W_mass = 80.419002,
    W_width = 2.047600,
    Z_mass = 91.1876,
    Z_width = 2.49,
    lep1_me_index = 1,
    lep1TFFile = TFFile,
    lep1TFName = "ERecMinEGenVSEGen_el_matchedToAfterFSR_allEta_Norm_hh_llmetjj_HWWleptons_nobtag_csv",
    lep2_me_index = 2,
    lep2TFFile = TFFile,
    lep2TFName = "ERecMinEGenVSEGen_el_matchedToAfterFSR_allEta_Norm_hh_llmetjj_HWWleptons_nobtag_csv",
    jet1TFFile = TFFile,
    jet1TFName = "ERecMinEGenVSEGen_bjet_matchedToAfterFSR_allEta_Norm_hh_llmetjj_HWWleptons_nobtag_csv",
    jet2TFFile = TFFile,
    jet2TFName = "ERecMinEGenVSEGen_bjet_matchedToAfterFSR_allEta_Norm_hh_llmetjj_HWWleptons_nobtag_csv",
    matrix_element = matrix_element_prefix .. "_sm_P1_Sigma_sm_gg_epembbx", --"pp_to_Z_to_llbb_sm_P1_Sigma_sm_gg_epembbx", 'pp_to_llbb_sm_P1_Sigma_sm_gg_epembbx', 'gg_to_z_to_llbb_sm_P1_Sigma_sm_gg_epembbx', 'gg_to_z_to_llbb_sm_P1_Sigma_sm_gg_mupmumbbx',
    matrix_element_parameters = baseDirME .. "/" .. matrix_element_prefix .. "/Cards/param_card.dat",
}
matrix_element_lib = baseDirME .. "/" .. matrix_element_prefix .. "/build/libme_" .. matrix_element_prefix .. ".so"
load_modules(matrix_element_lib)

if USE_PERM then
    -- Permute b and bbar
    -- ME va etre moyenné sur les permutations --> effectuer les permutations uniquement si il y a une différence (sinon == *2/2) e.g. pas pour H--> bbbar
    Permutator.permutator = {
        ps_point = add_dimension(),
        inputs = {
            'input::particles/3',
            'input::particles/4',
        }
    }
    recoParticles = {
        'input::particles/1',
        'input::particles/2',
        'permutator::output/1',
        'permutator::output/2',
    }
else
    -- No permutation, take particles as they come
    recoParticles = {'input::particles/1', 'input::particles/2', 'input::particles/3', 'input::particles/4'}
end

if USE_TF then
    -- Fix gen energy of the two leptons according to their transfer function
    BinnedTransferFunctionOnEnergy.tf_p2 = {
        ps_point = add_dimension(),
        reco_particle = recoParticles[2],
        file = parameter('lep2TFFile'),
        th2_name = parameter('lep2TFName'),
    }
    BinnedTransferFunctionOnEnergy.tf_p1 = {
        ps_point = add_dimension(),
        reco_particle = recoParticles[1],
        file = parameter('lep1TFFile'),
        th2_name = parameter('lep1TFName'),
    }
    -- Compute the phase space density for observed particles not concerned by the change of variable : here lepton on which we evaluate the TF 
    -- The TF jacobian just account for dp/dE to go from |p| to E, not the phase space volume, the other blocks give the whole product of jacobian and phase space volume to go from one param to another
    StandardPhaseSpace.phaseSpaceOut = {
        particles = {'tf_p1::output', 'tf_p2::output'}
    }
    -- Obtain the energy of the b's from momentum conservation (first two input are RECO b's, other inputs are used to fix PT to be balanced, all at gen level) 
    BlockA.blocka = {
        inputs = {'input::particles/3', 'input::particles/4', 'tf_p1::output', 'tf_p2::output', 'input::particles/5'},
    }
    Looper.looper = {
        solutions = "blocka::solutions",
        path = Path("tfEval_p3", "tfEval_p4", "boost", "dy", "integrand") -- everything that will depend on the different solutions
    }
    genParticles = {
        'tf_p1::output',
        'tf_p2::output',
        'looper::particles/1',
        'looper::particles/2',
        }
    BinnedTransferFunctionOnEnergyEvaluator.tfEval_p3 = {
        reco_particle = recoParticles[3],
        gen_particle = genParticles[3], 
        file = parameter('jet1TFFile'),
        th2_name = parameter('jet1TFName'),
    }
    BinnedTransferFunctionOnEnergyEvaluator.tfEval_p4 = {
        reco_particle = recoParticles[4],
        gen_particle = genParticles[4], 
        file = parameter('jet2TFFile'),
        th2_name = parameter('jet2TFName'),
    }
else 
    genParticles = {
        'input::particles/1',
        'input::particles/2',
        'input::particles/3',
        'input::particles/4',
        }
    -- Compute the phase space density for observed particles not concerned by the change of variable : here lepton on which we evaluate the TF 
    -- The TF jacobian just account for dp/dE to go from |p| to E, not the phase space volume, the other blocks give the whole product of jacobian and phase space volume to go from one param to another
    StandardPhaseSpace.phaseSpaceOut = {
        particles = genParticles
    }
end


BuildInitialState.boost = {
    do_transverse_boost = true,
    particles = genParticles
}
--P4Printer.printparton2 = {
--    input = 'boost::partons/2'
--}

jacobians = {'phaseSpaceOut::phase_space'}

if USE_TF then
    append(jacobians, {'tf_p1::TF_times_jacobian', 'looper::jacobian', 'tf_p2::TF_times_jacobian', 'tfEval_p3::TF', 'tfEval_p4::TF'})
end

MatrixElement.dy = {
  pdf = 'CT10nlo',
  pdf_scale = parameter('Z_mass'),

  matrix_element = parameter('matrix_element'),
  matrix_element_parameters = {
      card = parameter('matrix_element_parameters'),
  },

  override_parameters = {
      mdl_MT = parameter('top_mass'),
  },

  initialState = 'boost::partons',

  particles = {
    inputs = genParticles,
    ids = {
      {
        pdg_id =  -11,
        me_index = parameter("lep1_me_index"),
      },

      {
        pdg_id = 11,
        me_index = parameter("lep2_me_index"),
      },

      {
        pdg_id = 5,
        me_index = 3,
      },

      {
        pdg_id = -5,
        me_index = 4,
      }
    }
  },

  jacobians = jacobians
}

DoubleLooperSummer.integrand = {
    input = "dy::output"
}

integrand("integrand::sum")

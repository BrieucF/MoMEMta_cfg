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

-- Order convention : e- e+ b b
-- Reco particles : input::particles/1
-- Gen particles, depends on what you do

-- Available parameters : https://github.com/MoMEMta/MoMEMta/blob/master/core/src/MoMEMta.cc#L141
-- If "relative accuracy" is reached stop launching points unless "min_eval" point have been launched,
-- if after "max_eval" points have been launched stop launching even if we do not have reahced accuracy.
-- "n_start" : Vegas works by iterations will launch n_start point by n_start point and refine the grid at each step
-- n_increase allow to launch more points at each iteration
-- NB : all the point that have been launched are used to compute the intergal
cuba = {
    algorithm = "vegas",
    relative_accuracy = 0.01,
    verbosity = 3,
    max_eval = 300000,
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
    lep1TFName = "ERecMinEGenVSEGen_el_matchedToAfterFSR_allEta_Norm_hh_llmetjj_HWWleptons_nobtag_csv", -- Lep1, 1 meaning the first one given to computeWeight!
    lep2_me_index = 3,
    lep2TFFile = TFFile,
    lep2TFName = "ERecMinEGenVSEGen_el_matchedToAfterFSR_allEta_Norm_hh_llmetjj_HWWleptons_nobtag_csv",
    jet1TFFile = TFFile,
    jet1TFName = "ERecMinEGenVSEGen_bjet_matchedToAfterFSR_allEta_Norm_hh_llmetjj_HWWleptons_nobtag_csv",
    jet2TFFile = TFFile,
    jet2TFName = "ERecMinEGenVSEGen_bjet_matchedToAfterFSR_allEta_Norm_hh_llmetjj_HWWleptons_nobtag_csv",
    matrix_element = matrix_element_prefix .. "_sm_P1_Sigma_sm_gg_emvexepvebbx", --"pp_to_Z_to_llbb_sm_P1_Sigma_sm_gg_epembbx", 'pp_to_llbb_sm_P1_Sigma_sm_gg_epembbx', 'gg_to_z_to_llbb_sm_P1_Sigma_sm_gg_epembbx', 'gg_to_z_to_llbb_sm_P1_Sigma_sm_gg_mupmumbbx',
    matrix_element_parameters = baseDirME .. "/" .. matrix_element_prefix .. "/Cards/param_card.dat",
}
matrix_element_lib = baseDirME .. "/" .. matrix_element_prefix .. "/build/libme_" .. matrix_element_prefix .. ".so"
load_modules(matrix_element_lib)

-- inputs as will be feed to the blocks and ME
if USE_TF then
    -- With transfer functions
    inputs_before_perm = {
        'tf_p1::output',
        'tf_p2::output',
        'tf_p3::output',
        'tf_p4::output',
    }
else
    -- No transfer functions
    inputs_before_perm = {
        'input::particles/1',
        'input::particles/2',
        'input::particles/3',
        'input::particles/4',
    }
end

if USE_PERM then
  -- Use permutator module to permutate input particles 0 and 2 using the MC
  inputs = {
    inputs_before_perm[1],
    inputs_before_perm[2],
    'permutator::output/1',
    'permutator::output/2',
  }
else
  -- No permutation, take particles as they come
  inputs = inputs_before_perm
end

BreitWignerGenerator.flatter_s13 = {
    -- add_dimension() generates an input tag of type `cuba::ps_points/i`
    -- where `i` is automatically incremented each time the function is called.
    -- This function allows MoMEMta to track how many dimensions are needed for the integration.
    ps_point = add_dimension(),
    mass = parameter('W_mass'),
    width = parameter('W_width')
}

BreitWignerGenerator.flatter_s134 = {
    ps_point = add_dimension(),
    mass = parameter('top_mass'),
    width = parameter('top_width')
}

BreitWignerGenerator.flatter_s25 = {
    ps_point = add_dimension(),
    mass = parameter('W_mass'),
    width = parameter('W_width')
}

BreitWignerGenerator.flatter_s256 = {
    ps_point = add_dimension(),
    mass = parameter('top_mass'),
    width = parameter('top_width')
}

if USE_TF then
    BinnedTransferFunctionOnEnergy.tf_p1 = {
        ps_point = add_dimension(),
        reco_particle = 'input::particles/1',
        file = parameter('lep1TFFile'),
        th2_name = parameter('lep1TFName'),
        --min_E = 5.,
    }
    BinnedTransferFunctionOnEnergy.tf_p2 = {
        ps_point = add_dimension(),
        reco_particle = 'input::particles/2',
        file = parameter('lep2TFFile'),
        th2_name = parameter('lep2TFName'),
        --min_E = 5.,
    }
    BinnedTransferFunctionOnEnergy.tf_p3 = {
        ps_point = add_dimension(),
        reco_particle = 'input::particles/3',
        file = parameter('jet1TFFile'),
        th2_name = parameter('jet1TFName'),
        --min_E = 10.,
    }
    BinnedTransferFunctionOnEnergy.tf_p4 = {
        ps_point = add_dimension(),
        reco_particle = 'input::particles/4',
        file = parameter('jet2TFFile'),
        th2_name = parameter('jet2TFName'),
        --min_E = 10.,
    }
end

StandardPhaseSpace.phaseSpaceOut = {
    particles = inputs -- only on visible particles. BlockD only trade neutrinos degree of freedom d3v1d3v2dx1dx2Delta4(...) [8-4=4dof] --> ds12 ds134 ds25 ds256 [4dof]
}

-- Declare module before the permutator to test read-access in the pool
-- for non-existant values.
BlockD.blockd = {
    inputs = {inputs[1], inputs[3], inputs[2], inputs[4]}, -- Assumes the following order lepton- bbar, lepton+, b  NB: leptons and b being (anti)particle or not is defined by the order given in the matrix element below

    pT_is_met = true,
    met = 'input::met',

    s13 = 'flatter_s13::s',
    s134 = 'flatter_s134::s',
    s25 = 'flatter_s25::s',
    s256 = 'flatter_s256::s',
}

if USE_PERM then
    Permutator.permutator = {
        ps_point = add_dimension(),
        inputs = {
          inputs_before_perm[3],
          inputs_before_perm[4],
        }
    }
end

-- Loop over block solutions

Looper.looper = {
    solutions = "blockd::solutions",
    path = Path("boost", "ttbar", "integrand")
}

    -- Block D produce solutions with two particles
    full_inputs = copy_and_append(inputs, {'looper::particles/1', 'looper::particles/2'})

    BuildInitialState.boost = {
        do_transverse_boost = true,
        particles = full_inputs
    }

    jacobians = {'flatter_s13::jacobian', 'flatter_s134::jacobian', 'flatter_s25::jacobian', 'flatter_s256::jacobian'}

    if USE_TF then
        append(jacobians, {'tf_p1::TF_times_jacobian', 'tf_p2::TF_times_jacobian', 'tf_p3::TF_times_jacobian', 'tf_p4::TF_times_jacobian'})
    end

    append(jacobians, {'phaseSpaceOut::phase_space', 'looper::jacobian'})

    MatrixElement.ttbar = {
      pdf = 'CT10nlo',
      pdf_scale = parameter('top_mass'),

      matrix_element = parameter('matrix_element'),
      matrix_element_parameters = {
          card =  parameter('matrix_element_parameters'),
      },

      override_parameters = {
          mdl_MT = parameter('top_mass'),
      },

      initialState = 'boost::partons',

      particles = { -- NB negatively charged lepton must be the first particle given in the .cc, me_index = 1 --> first output of blockD will be the antineutrino . positively charge --> me_index =  3
        inputs = full_inputs,
        ids = {
          {
            pdg_id = 11,
            me_index = parameter("lep1_me_index"),
          },

          {
            pdg_id = -11,
            me_index = parameter("lep2_me_index"),
          },

          {
            pdg_id = -5,
            me_index = 6,
          },

          {
            pdg_id = 5,
            me_index = 5,
          },

          {
            pdg_id = -12,
            me_index = 2,
          },

          {
            pdg_id = 12,
            me_index = 4,
          }
        }
      },

      jacobians = jacobians
    }

    DoubleLooperSummer.integrand = {
        input = "ttbar::output"
    }

-- End of loop
integrand("integrand::sum")

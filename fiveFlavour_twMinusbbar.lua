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
    max_eval = 2000000,
    n_start = 50000,
}

-- NB: to be defined in the .cc is matrix_element_prefix 

USE_TF = true
NWA = false
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
    lep1TFFile = TFFile,
    lep1TFName = "ERecMinEGenVSEGen_el_matchedToAfterFSR_allEta_Norm_hh_llmetjj_HWWleptons_nobtag_csv", 
    lep2TFFile = TFFile,
    lep2TFName = "ERecMinEGenVSEGen_el_matchedToAfterFSR_allEta_Norm_hh_llmetjj_HWWleptons_nobtag_csv",
    jet1TFFile = TFFile,
    jet1TFName = "ERecMinEGenVSEGen_bjet_matchedToAfterFSR_allEta_Norm_hh_llmetjj_HWWleptons_nobtag_csv",
    jet2TFFile = TFFile,
    jet2TFName = "ERecMinEGenVSEGen_bjet_matchedToAfterFSR_allEta_Norm_hh_llmetjj_HWWleptons_nobtag_csv",
    matrix_element = matrix_element_prefix .. "_sm_no_b_mass_P1_Sigma_sm_no_b_mass_gb_mupvmbemvex",
    matrix_element_parameters = baseDirME .. "/" .. matrix_element_prefix .. "/Cards/param_card.dat",
}
matrix_element_lib = baseDirME .. "/" .. matrix_element_prefix .. "/build/libme_" .. matrix_element_prefix .. ".so"
load_modules(matrix_element_lib)

-- inputs as will be fed to the blocks and ME
local neg_lepton = declare_input("neg_lepton")
local pos_lepton = declare_input("pos_lepton")
local bjet1 = declare_input("bjet1")
local bjet2 = declare_input("bjet2")
--local isr = declare_input("isr")
local dummy_neutrino = declare_input("dummy_neutrino")

if USE_PERM then
  -- Use permutator module to permutate input particles
  add_reco_permutations(bjet1, bjet2) -- Carefull if you use binned eta tf
end

if NWA then
    NarrowWidthApproximation.flatter_s12 = {
        mass = parameter('W_mass'),
        width = parameter('W_width')
    }

    NarrowWidthApproximation.flatter_s123 = {
        mass = parameter('top_mass'),
        width = parameter('top_width')
    }
    NarrowWidthApproximation.flatter_s45 = {
        mass = parameter('W_mass'),
        width = parameter('W_width')
    }
else
    BreitWignerGenerator.flatter_s12 = {
        -- add_dimension() generates an input tag of type `cuba::ps_points/i`
        -- where `i` is automatically incremented each time the function is called.
        -- This function allows MoMEMta to track how many dimensions are needed for the integration.
        ps_point = add_dimension(),
        mass = parameter('W_mass'),
        width = parameter('W_width')
    }

    BreitWignerGenerator.flatter_s123 = {
        ps_point = add_dimension(),
        mass = parameter('top_mass'),
        width = parameter('top_width')
    }
    BreitWignerGenerator.flatter_s45 = {
        ps_point = add_dimension(),
        mass = parameter('W_mass'),
        width = parameter('W_width')
    }
end

if USE_TF then
    BinnedTransferFunctionOnEnergy.tf_neg_lepton = {
        ps_point = add_dimension(),
        reco_particle = neg_lepton.reco_p4,
        file = parameter('lep1TFFile'),
        th2_name = parameter('lep1TFName'),
        --min_E = 5.,
    }
    neg_lepton.set_gen_p4("tf_neg_lepton::output")
    
    BinnedTransferFunctionOnEnergy.tf_pos_lepton = {
        ps_point = add_dimension(),
        reco_particle = pos_lepton.reco_p4,
        file = parameter('lep2TFFile'),
        th2_name = parameter('lep2TFName'),
        --min_E = 5.,
    }
    pos_lepton.set_gen_p4("tf_pos_lepton::output")
    
    BinnedTransferFunctionOnEnergy.tf_bjet1 = {
        ps_point = add_dimension(),
        reco_particle = bjet1.reco_p4,
        file = parameter('jet1TFFile'),
        th2_name = parameter('jet1TFName'),
        --min_E = 10.,
    }
    bjet1.set_gen_p4("tf_bjet1::output")

    --BinnedTransferFunctionOnEnergy.tf_bjet2 = {
    --    ps_point = add_dimension(),
    --    reco_particle = bjet2.reco_p4,
    --    file = parameter('jet2TFFile'),
    --    th2_name = parameter('jet2TFName'),
    --    --min_E = 10.,
    --}
    --bjet2.set_gen_p4("tf_bjet2::output")
end
-- Fix the neutrino phi angle
FlatTransferFunctionOnPhi.neutrino_phi_fixed = {
    ps_point = add_dimension(),
    reco_particle = dummy_neutrino.reco_p4, -- only used to obtain the mass of the particle, here we want it to stay at zero, dummy neutrino is defined in the .cc as such
}
-- Fix the neutrino momemtum using W and top mass as well as the known bjet and positive lepton 
-- NB : the given bjet is now assumed to be the particle b (not anti-particle) since : t > W+ b, W+ > l+ nu)
SecondaryBlockB.sb_b = {
    p1 = 'neutrino_phi_fixed::output',
    p2 = pos_lepton.gen_p4,
    p3 = bjet1.gen_p4,
    s12 = 'flatter_s12::s',
    s123 = 'flatter_s123::s',
}

Looper.looper_sb_b = {
    solutions = "sb_b::solutions",
    path = Path("met_substracted", "blockb", "looper_blockb")
}
VectorLinearCombinator.met_substracted = {
    inputs = {'met::p4', 'looper_sb_b::particles/1'},
    coefficients = {1., -1.}
}
-- Fix the anti-neutrino momentum using W mass as well as all previously obtained particles 
BlockB.blockb = {
    --inputs = {neg_lepton.gen_p4, bjet1.gen_p4, pos_lepton.gen_p4, bjet2.gen_p4, 'looper_sb_b::particles/1'}, -- A priori, no need to pass him the other particles for the pt tot balance since instead we impose PT neutrino == (MET-firstNeutrino) 
    --inputs = {neg_lepton.gen_p4, bjet1.gen_p4, pos_lepton.gen_p4, 'looper_sb_b::particles/1'}, -- A priori, no need to pass him the other particles for the pt tot balance since instead we impose PT neutrino == (MET-firstNeutrino) 
    inputs = {neg_lepton.gen_p4},
                     -- But still we can do it so that the check whether the found solution is physycal or not take the energy of other particles into account
                     -- The first output of BlockB will be the anti-neutrino associated to neg_lepton
                     -- (W- > l- nu~), to be propagated in the ME below
    pT_is_met = true,-- Name is a bit misleading, we should understand neutrinoPt_is_met
    met = 'met_substracted::output',
    s12 = 'flatter_s45::s',
}

Looper.looper_blockb = {
    solutions = "blockb::solutions",
    path = Path("boost", "twMinus", "phaseSpaceOut", "integrand")
}

StandardPhaseSpace.phaseSpaceOut = {
    particles = {neg_lepton.gen_p4, bjet1.gen_p4, pos_lepton.gen_p4} -- only on visible particles. SB_B trade one neutrinos dof, BlockB trades the other neutrino dof
}
--DoublePrinter.printPhaseSpace = {
--    input = 'phaseSpaceOut::phase_space'
--}
-- full inputs order is (l-, b, l+, neutrino, anti-neutrino) as fixed by passing the positive lepton to the SB_B
full_inputs = {neg_lepton.gen_p4, bjet1.gen_p4, pos_lepton.gen_p4, 'looper_sb_b::particles/1', 'looper_blockb::particles/1'}

BuildInitialState.boost = {
    do_transverse_boost = true,
    particles = full_inputs
}

jacobians = {'flatter_s12::jacobian', 'flatter_s123::jacobian', 'flatter_s45::jacobian', 'neutrino_phi_fixed::TF_times_jacobian', 'looper_blockb::jacobian', 'looper_sb_b::jacobian'}

--DoublePrinter.printjacSecondaryBlockB = {
--    input = 'looper_sb_b::jacobian'
--}
--DoublePrinter.printjacSBlockB = {
--    input = 'looper_blockb::jacobian'
--}


if USE_TF then
    --append(jacobians, {'tf_neg_lepton::TF_times_jacobian', 'tf_pos_lepton::TF_times_jacobian', 'tf_bjet1::TF_times_jacobian', 'tf_bjet2::TF_times_jacobian'})
    append(jacobians, {'tf_neg_lepton::TF_times_jacobian', 'tf_pos_lepton::TF_times_jacobian', 'tf_bjet1::TF_times_jacobian'})
end

append(jacobians, {'phaseSpaceOut::phase_space'})

MatrixElement.twMinus = {
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

  particles = { -- full_inputs = {neg_lepton.gen_p4, bjet1.gen_p4, pos_lepton.gen_p4, bjet2.gen_p4, 'looper_sb_b::particles/1', 'looper_blockb::particles/1'}
                -- full inputs order is (l-, b, l+, b~, neutrino, anti-neutrino) as fixed by passing the positive lepton to the SB_B
                --  t > W+ b, W+ > l+ nu (tbarwPlus lua will be  t~ > W- b~, W- > l- nu~)
                --  in MG mapFinalStates[{-13, 14, 5, 13, -14}]
  inputs = full_inputs,
    ids = { 
      {
        pdg_id = 13,
        me_index = 4,
      },

      {
        pdg_id = 5,
        me_index = 3,
      },

      {
        pdg_id = -13,
        me_index = 1,
      },

      {
        pdg_id = 14,
        me_index = 2,
      },

      {
        pdg_id = -14,
        me_index = 5,
      }
    }
  },

  jacobians = jacobians
}

DoubleLooperSummer.integrand = {
    input = "twMinus::output"
}

-- End of loop
integrand("integrand::sum")

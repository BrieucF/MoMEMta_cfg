/*
 *  MoMEMta: a modular implementation of the Matrix Element Method
 *  Copyright (C) 2016  Universite catholique de Louvain (UCL), Belgium
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */


#include <momemta/ConfigurationReader.h>
#include <momemta/Logging.h>
#include <momemta/MoMEMta.h>
#include <momemta/Unused.h>

#include <TH1D.h>

#include <chrono>

using namespace std::chrono;

int main(int argc, char** argv) {

    UNUSED(argc);
    UNUSED(argv);

    logging::set_level(logging::level::debug);

    ParameterSet dy_lua_parameters;
logging::set_level(logging::level::debug);

dy_lua_parameters.set("matrix_element_prefix", "pp_to_Z_to_llbb");
ConfigurationReader pp_Z_llbb_elel_tfAllEta_tradeElep2ForZMass_configuration("/home/fynu/bfrancois/scratch/framework/MIS_prod_data/CMSSW_7_6_5/src/cp3_llbb/MoMEMta_cfg/dy_to_ll_tradeElep2ForZMass.lua", dy_lua_parameters);
pp_Z_llbb_elel_tfAllEta_tradeElep2ForZMass_configuration.getGlobalParameters().set("matrix_element", "pp_to_Z_to_llbb_sm_P1_Sigma_sm_gg_epembbx");
pp_Z_llbb_elel_tfAllEta_tradeElep2ForZMass_configuration.getGlobalParameters().set("matrix_element_prefix", "pp_to_Z_to_llbb");
pp_Z_llbb_elel_tfAllEta_tradeElep2ForZMass_configuration.getGlobalParameters().set("jet1TFFile", "/home/fynu/bfrancois/scratch/framework/MIS_prod_data/CMSSW_7_6_5/src/cp3_llbb/HHTools/histFactory_hh/tf_genCut0_noRecoCut_lljjorbb_Oct18/condor/output/allTT_smoothed_notPutToZero.root");
pp_Z_llbb_elel_tfAllEta_tradeElep2ForZMass_configuration.getGlobalParameters().set("lep1TFFile", "/home/fynu/bfrancois/scratch/framework/MIS_prod_data/CMSSW_7_6_5/src/cp3_llbb/HHTools/histFactory_hh/tf_genCut0_noRecoCut_lljjorbb_Oct18/condor/output/allTT_smoothed_notPutToZero.root");
pp_Z_llbb_elel_tfAllEta_tradeElep2ForZMass_configuration.getGlobalParameters().set("lep2_me_index", 2);
pp_Z_llbb_elel_tfAllEta_tradeElep2ForZMass_configuration.getGlobalParameters().set("lep1_me_index", 1);
pp_Z_llbb_elel_tfAllEta_tradeElep2ForZMass_configuration.getGlobalParameters().set("jet2TFFile", "/home/fynu/bfrancois/scratch/framework/MIS_prod_data/CMSSW_7_6_5/src/cp3_llbb/HHTools/histFactory_hh/tf_genCut0_noRecoCut_lljjorbb_Oct18/condor/output/allTT_smoothed_notPutToZero.root");
pp_Z_llbb_elel_tfAllEta_tradeElep2ForZMass_configuration.getGlobalParameters().set("lep2TFName", "ERecMinEGenVSEGen_el_matchedToAfterFSR_allEta_Norm_hh_llmetjj_HWWleptons_nobtag_csv");
pp_Z_llbb_elel_tfAllEta_tradeElep2ForZMass_configuration.getGlobalParameters().set("lep1TFName", "ERecMinEGenVSEGen_el_matchedToAfterFSR_allEta_Norm_hh_llmetjj_HWWleptons_nobtag_csv");
pp_Z_llbb_elel_tfAllEta_tradeElep2ForZMass_configuration.getGlobalParameters().set("jet1TFName", "ERecMinEGenVSEGen_bjet_matchedToAfterFSR_allEta_Norm_hh_llmetjj_HWWleptons_nobtag_csv");
pp_Z_llbb_elel_tfAllEta_tradeElep2ForZMass_configuration.getGlobalParameters().set("jet2TFName", "ERecMinEGenVSEGen_bjet_matchedToAfterFSR_allEta_Norm_hh_llmetjj_HWWleptons_nobtag_csv");
pp_Z_llbb_elel_tfAllEta_tradeElep2ForZMass_configuration.getGlobalParameters().set("matrix_element_parameters", "/home/fynu/bfrancois/scratch/MoMEMta/plugin_mode//pp_to_Z_to_llbb/Cards/param_card.dat");
pp_Z_llbb_elel_tfAllEta_tradeElep2ForZMass_configuration.getGlobalParameters().set("lep2TFFile", "/home/fynu/bfrancois/scratch/framework/MIS_prod_data/CMSSW_7_6_5/src/cp3_llbb/HHTools/histFactory_hh/tf_genCut0_noRecoCut_lljjorbb_Oct18/condor/output/allTT_smoothed_notPutToZero.root");
MoMEMta pp_Z_llbb_elel_tfAllEta_tradeElep2ForZMass_weightComputer(pp_Z_llbb_elel_tfAllEta_tradeElep2ForZMass_configuration.freeze());
dy_lua_parameters.set("matrix_element_prefix", "pp_to_Z_to_llbb");
ConfigurationReader pp_Z_llbb_elel_tfAllEta_simple_configuration("/home/fynu/bfrancois/scratch/framework/MIS_prod_data/CMSSW_7_6_5/src/cp3_llbb/MoMEMta_cfg/dy_to_ll_simple.lua", dy_lua_parameters);
pp_Z_llbb_elel_tfAllEta_simple_configuration.getGlobalParameters().set("matrix_element", "pp_to_Z_to_llbb_sm_P1_Sigma_sm_gg_epembbx");
pp_Z_llbb_elel_tfAllEta_simple_configuration.getGlobalParameters().set("matrix_element_prefix", "pp_to_Z_to_llbb");
pp_Z_llbb_elel_tfAllEta_simple_configuration.getGlobalParameters().set("jet1TFFile", "/home/fynu/bfrancois/scratch/framework/MIS_prod_data/CMSSW_7_6_5/src/cp3_llbb/HHTools/histFactory_hh/tf_genCut0_noRecoCut_lljjorbb_Oct18/condor/output/allTT_smoothed_notPutToZero.root");
pp_Z_llbb_elel_tfAllEta_simple_configuration.getGlobalParameters().set("lep1TFFile", "/home/fynu/bfrancois/scratch/framework/MIS_prod_data/CMSSW_7_6_5/src/cp3_llbb/HHTools/histFactory_hh/tf_genCut0_noRecoCut_lljjorbb_Oct18/condor/output/allTT_smoothed_notPutToZero.root");
pp_Z_llbb_elel_tfAllEta_simple_configuration.getGlobalParameters().set("lep2_me_index", 2);
pp_Z_llbb_elel_tfAllEta_simple_configuration.getGlobalParameters().set("lep1_me_index", 1);
pp_Z_llbb_elel_tfAllEta_simple_configuration.getGlobalParameters().set("jet2TFFile", "/home/fynu/bfrancois/scratch/framework/MIS_prod_data/CMSSW_7_6_5/src/cp3_llbb/HHTools/histFactory_hh/tf_genCut0_noRecoCut_lljjorbb_Oct18/condor/output/allTT_smoothed_notPutToZero.root");
pp_Z_llbb_elel_tfAllEta_simple_configuration.getGlobalParameters().set("lep2TFName", "ERecMinEGenVSEGen_el_matchedToAfterFSR_allEta_Norm_hh_llmetjj_HWWleptons_nobtag_csv");
pp_Z_llbb_elel_tfAllEta_simple_configuration.getGlobalParameters().set("lep1TFName", "ERecMinEGenVSEGen_el_matchedToAfterFSR_allEta_Norm_hh_llmetjj_HWWleptons_nobtag_csv");
pp_Z_llbb_elel_tfAllEta_simple_configuration.getGlobalParameters().set("jet1TFName", "ERecMinEGenVSEGen_bjet_matchedToAfterFSR_allEta_Norm_hh_llmetjj_HWWleptons_nobtag_csv");
pp_Z_llbb_elel_tfAllEta_simple_configuration.getGlobalParameters().set("jet2TFName", "ERecMinEGenVSEGen_bjet_matchedToAfterFSR_allEta_Norm_hh_llmetjj_HWWleptons_nobtag_csv");
pp_Z_llbb_elel_tfAllEta_simple_configuration.getGlobalParameters().set("matrix_element_parameters", "/home/fynu/bfrancois/scratch/MoMEMta/plugin_mode//pp_to_Z_to_llbb/Cards/param_card.dat");
pp_Z_llbb_elel_tfAllEta_simple_configuration.getGlobalParameters().set("lep2TFFile", "/home/fynu/bfrancois/scratch/framework/MIS_prod_data/CMSSW_7_6_5/src/cp3_llbb/HHTools/histFactory_hh/tf_genCut0_noRecoCut_lljjorbb_Oct18/condor/output/allTT_smoothed_notPutToZero.root");
MoMEMta pp_Z_llbb_elel_tfAllEta_simple_weightComputer(pp_Z_llbb_elel_tfAllEta_simple_configuration.freeze());
dy_lua_parameters.set("matrix_element_prefix", "pp_to_Z_to_llbb");
ConfigurationReader pp_Z_llbb_elel_tfJet_ba_ba_tradeElep2ForZMass_configuration("/home/fynu/bfrancois/scratch/framework/MIS_prod_data/CMSSW_7_6_5/src/cp3_llbb/MoMEMta_cfg/dy_to_ll_tradeElep2ForZMass.lua", dy_lua_parameters);
pp_Z_llbb_elel_tfJet_ba_ba_tradeElep2ForZMass_configuration.getGlobalParameters().set("matrix_element", "pp_to_Z_to_llbb_sm_P1_Sigma_sm_gg_epembbx");
pp_Z_llbb_elel_tfJet_ba_ba_tradeElep2ForZMass_configuration.getGlobalParameters().set("matrix_element_prefix", "pp_to_Z_to_llbb");
pp_Z_llbb_elel_tfJet_ba_ba_tradeElep2ForZMass_configuration.getGlobalParameters().set("jet1TFFile", "/home/fynu/bfrancois/scratch/framework/MIS_prod_data/CMSSW_7_6_5/src/cp3_llbb/HHTools/histFactory_hh/tf_genCut0_noRecoCut_lljjorbb_Oct18/condor/output/allTT_smoothed_notPutToZero.root");
pp_Z_llbb_elel_tfJet_ba_ba_tradeElep2ForZMass_configuration.getGlobalParameters().set("lep1TFFile", "/home/fynu/bfrancois/scratch/framework/MIS_prod_data/CMSSW_7_6_5/src/cp3_llbb/HHTools/histFactory_hh/tf_genCut0_noRecoCut_lljjorbb_Oct18/condor/output/allTT_smoothed_notPutToZero.root");
pp_Z_llbb_elel_tfJet_ba_ba_tradeElep2ForZMass_configuration.getGlobalParameters().set("lep2_me_index", 2);
pp_Z_llbb_elel_tfJet_ba_ba_tradeElep2ForZMass_configuration.getGlobalParameters().set("lep1_me_index", 1);
pp_Z_llbb_elel_tfJet_ba_ba_tradeElep2ForZMass_configuration.getGlobalParameters().set("jet2TFFile", "/home/fynu/bfrancois/scratch/framework/MIS_prod_data/CMSSW_7_6_5/src/cp3_llbb/HHTools/histFactory_hh/tf_genCut0_noRecoCut_lljjorbb_Oct18/condor/output/allTT_smoothed_notPutToZero.root");
pp_Z_llbb_elel_tfJet_ba_ba_tradeElep2ForZMass_configuration.getGlobalParameters().set("lep2TFName", "ERecMinEGenVSEGen_el_matchedToAfterFSR_allEta_Norm_hh_llmetjj_HWWleptons_nobtag_csv");
pp_Z_llbb_elel_tfJet_ba_ba_tradeElep2ForZMass_configuration.getGlobalParameters().set("lep1TFName", "ERecMinEGenVSEGen_el_matchedToAfterFSR_allEta_Norm_hh_llmetjj_HWWleptons_nobtag_csv");
pp_Z_llbb_elel_tfJet_ba_ba_tradeElep2ForZMass_configuration.getGlobalParameters().set("jet1TFName", "ERecMinEGenVSEGen_bjet_matchedToAfterFSR_allEta_Norm_hh_llmetjj_HWWleptons_nobtag_csv");
pp_Z_llbb_elel_tfJet_ba_ba_tradeElep2ForZMass_configuration.getGlobalParameters().set("jet2TFName", "ERecMinEGenVSEGen_bjet_matchedToAfterFSR_allEta_Norm_hh_llmetjj_HWWleptons_nobtag_csv");
pp_Z_llbb_elel_tfJet_ba_ba_tradeElep2ForZMass_configuration.getGlobalParameters().set("matrix_element_parameters", "/home/fynu/bfrancois/scratch/MoMEMta/plugin_mode//pp_to_Z_to_llbb/Cards/param_card.dat");
pp_Z_llbb_elel_tfJet_ba_ba_tradeElep2ForZMass_configuration.getGlobalParameters().set("lep2TFFile", "/home/fynu/bfrancois/scratch/framework/MIS_prod_data/CMSSW_7_6_5/src/cp3_llbb/HHTools/histFactory_hh/tf_genCut0_noRecoCut_lljjorbb_Oct18/condor/output/allTT_smoothed_notPutToZero.root");
MoMEMta pp_Z_llbb_elel_tfJet_ba_ba_tradeElep2ForZMass_weightComputer(pp_Z_llbb_elel_tfJet_ba_ba_tradeElep2ForZMass_configuration.freeze());
dy_lua_parameters.set("matrix_element_prefix", "pp_to_Z_to_llbb");
ConfigurationReader pp_Z_llbb_elel_tfJet_ec_ba_tradeElep2ForZMass_configuration("/home/fynu/bfrancois/scratch/framework/MIS_prod_data/CMSSW_7_6_5/src/cp3_llbb/MoMEMta_cfg/dy_to_ll_tradeElep2ForZMass.lua", dy_lua_parameters);
pp_Z_llbb_elel_tfJet_ec_ba_tradeElep2ForZMass_configuration.getGlobalParameters().set("matrix_element", "pp_to_Z_to_llbb_sm_P1_Sigma_sm_gg_epembbx");
pp_Z_llbb_elel_tfJet_ec_ba_tradeElep2ForZMass_configuration.getGlobalParameters().set("matrix_element_prefix", "pp_to_Z_to_llbb");
pp_Z_llbb_elel_tfJet_ec_ba_tradeElep2ForZMass_configuration.getGlobalParameters().set("jet1TFFile", "/home/fynu/bfrancois/scratch/framework/MIS_prod_data/CMSSW_7_6_5/src/cp3_llbb/HHTools/histFactory_hh/tf_genCut0_noRecoCut_lljjorbb_Oct18/condor/output/allTT_smoothed_notPutToZero.root");
pp_Z_llbb_elel_tfJet_ec_ba_tradeElep2ForZMass_configuration.getGlobalParameters().set("lep1TFFile", "/home/fynu/bfrancois/scratch/framework/MIS_prod_data/CMSSW_7_6_5/src/cp3_llbb/HHTools/histFactory_hh/tf_genCut0_noRecoCut_lljjorbb_Oct18/condor/output/allTT_smoothed_notPutToZero.root");
pp_Z_llbb_elel_tfJet_ec_ba_tradeElep2ForZMass_configuration.getGlobalParameters().set("lep2_me_index", 2);
pp_Z_llbb_elel_tfJet_ec_ba_tradeElep2ForZMass_configuration.getGlobalParameters().set("lep1_me_index", 1);
pp_Z_llbb_elel_tfJet_ec_ba_tradeElep2ForZMass_configuration.getGlobalParameters().set("jet2TFFile", "/home/fynu/bfrancois/scratch/framework/MIS_prod_data/CMSSW_7_6_5/src/cp3_llbb/HHTools/histFactory_hh/tf_genCut0_noRecoCut_lljjorbb_Oct18/condor/output/allTT_smoothed_notPutToZero.root");
pp_Z_llbb_elel_tfJet_ec_ba_tradeElep2ForZMass_configuration.getGlobalParameters().set("lep2TFName", "ERecMinEGenVSEGen_el_matchedToAfterFSR_allEta_Norm_hh_llmetjj_HWWleptons_nobtag_csv");
pp_Z_llbb_elel_tfJet_ec_ba_tradeElep2ForZMass_configuration.getGlobalParameters().set("lep1TFName", "ERecMinEGenVSEGen_el_matchedToAfterFSR_allEta_Norm_hh_llmetjj_HWWleptons_nobtag_csv");
pp_Z_llbb_elel_tfJet_ec_ba_tradeElep2ForZMass_configuration.getGlobalParameters().set("jet1TFName", "ERecMinEGenVSEGen_bjet_matchedToAfterFSR_allEta_Norm_hh_llmetjj_HWWleptons_nobtag_csv");
pp_Z_llbb_elel_tfJet_ec_ba_tradeElep2ForZMass_configuration.getGlobalParameters().set("jet2TFName", "ERecMinEGenVSEGen_bjet_matchedToAfterFSR_allEta_Norm_hh_llmetjj_HWWleptons_nobtag_csv");
pp_Z_llbb_elel_tfJet_ec_ba_tradeElep2ForZMass_configuration.getGlobalParameters().set("matrix_element_parameters", "/home/fynu/bfrancois/scratch/MoMEMta/plugin_mode//pp_to_Z_to_llbb/Cards/param_card.dat");
pp_Z_llbb_elel_tfJet_ec_ba_tradeElep2ForZMass_configuration.getGlobalParameters().set("lep2TFFile", "/home/fynu/bfrancois/scratch/framework/MIS_prod_data/CMSSW_7_6_5/src/cp3_llbb/HHTools/histFactory_hh/tf_genCut0_noRecoCut_lljjorbb_Oct18/condor/output/allTT_smoothed_notPutToZero.root");
MoMEMta pp_Z_llbb_elel_tfJet_ec_ba_tradeElep2ForZMass_weightComputer(pp_Z_llbb_elel_tfJet_ec_ba_tradeElep2ForZMass_configuration.freeze());
dy_lua_parameters.set("matrix_element_prefix", "pp_to_Z_to_llbb");
ConfigurationReader pp_Z_llbb_elel_tfJet_ba_ec_tradeElep2ForZMass_configuration("/home/fynu/bfrancois/scratch/framework/MIS_prod_data/CMSSW_7_6_5/src/cp3_llbb/MoMEMta_cfg/dy_to_ll_tradeElep2ForZMass.lua", dy_lua_parameters);
pp_Z_llbb_elel_tfJet_ba_ec_tradeElep2ForZMass_configuration.getGlobalParameters().set("matrix_element", "pp_to_Z_to_llbb_sm_P1_Sigma_sm_gg_epembbx");
pp_Z_llbb_elel_tfJet_ba_ec_tradeElep2ForZMass_configuration.getGlobalParameters().set("matrix_element_prefix", "pp_to_Z_to_llbb");
pp_Z_llbb_elel_tfJet_ba_ec_tradeElep2ForZMass_configuration.getGlobalParameters().set("jet1TFFile", "/home/fynu/bfrancois/scratch/framework/MIS_prod_data/CMSSW_7_6_5/src/cp3_llbb/HHTools/histFactory_hh/tf_genCut0_noRecoCut_lljjorbb_Oct18/condor/output/allTT_smoothed_notPutToZero.root");
pp_Z_llbb_elel_tfJet_ba_ec_tradeElep2ForZMass_configuration.getGlobalParameters().set("lep1TFFile", "/home/fynu/bfrancois/scratch/framework/MIS_prod_data/CMSSW_7_6_5/src/cp3_llbb/HHTools/histFactory_hh/tf_genCut0_noRecoCut_lljjorbb_Oct18/condor/output/allTT_smoothed_notPutToZero.root");
pp_Z_llbb_elel_tfJet_ba_ec_tradeElep2ForZMass_configuration.getGlobalParameters().set("lep2_me_index", 2);
pp_Z_llbb_elel_tfJet_ba_ec_tradeElep2ForZMass_configuration.getGlobalParameters().set("lep1_me_index", 1);
pp_Z_llbb_elel_tfJet_ba_ec_tradeElep2ForZMass_configuration.getGlobalParameters().set("jet2TFFile", "/home/fynu/bfrancois/scratch/framework/MIS_prod_data/CMSSW_7_6_5/src/cp3_llbb/HHTools/histFactory_hh/tf_genCut0_noRecoCut_lljjorbb_Oct18/condor/output/allTT_smoothed_notPutToZero.root");
pp_Z_llbb_elel_tfJet_ba_ec_tradeElep2ForZMass_configuration.getGlobalParameters().set("lep2TFName", "ERecMinEGenVSEGen_el_matchedToAfterFSR_allEta_Norm_hh_llmetjj_HWWleptons_nobtag_csv");
pp_Z_llbb_elel_tfJet_ba_ec_tradeElep2ForZMass_configuration.getGlobalParameters().set("lep1TFName", "ERecMinEGenVSEGen_el_matchedToAfterFSR_allEta_Norm_hh_llmetjj_HWWleptons_nobtag_csv");
pp_Z_llbb_elel_tfJet_ba_ec_tradeElep2ForZMass_configuration.getGlobalParameters().set("jet1TFName", "ERecMinEGenVSEGen_bjet_matchedToAfterFSR_allEta_Norm_hh_llmetjj_HWWleptons_nobtag_csv");
pp_Z_llbb_elel_tfJet_ba_ec_tradeElep2ForZMass_configuration.getGlobalParameters().set("jet2TFName", "ERecMinEGenVSEGen_bjet_matchedToAfterFSR_allEta_Norm_hh_llmetjj_HWWleptons_nobtag_csv");
pp_Z_llbb_elel_tfJet_ba_ec_tradeElep2ForZMass_configuration.getGlobalParameters().set("matrix_element_parameters", "/home/fynu/bfrancois/scratch/MoMEMta/plugin_mode//pp_to_Z_to_llbb/Cards/param_card.dat");
pp_Z_llbb_elel_tfJet_ba_ec_tradeElep2ForZMass_configuration.getGlobalParameters().set("lep2TFFile", "/home/fynu/bfrancois/scratch/framework/MIS_prod_data/CMSSW_7_6_5/src/cp3_llbb/HHTools/histFactory_hh/tf_genCut0_noRecoCut_lljjorbb_Oct18/condor/output/allTT_smoothed_notPutToZero.root");
MoMEMta pp_Z_llbb_elel_tfJet_ba_ec_tradeElep2ForZMass_weightComputer(pp_Z_llbb_elel_tfJet_ba_ec_tradeElep2ForZMass_configuration.freeze());
dy_lua_parameters.set("matrix_element_prefix", "pp_to_Z_to_llbb");
ConfigurationReader pp_Z_llbb_elel_tfJet_ec_ec_tradeElep2ForZMass_configuration("/home/fynu/bfrancois/scratch/framework/MIS_prod_data/CMSSW_7_6_5/src/cp3_llbb/MoMEMta_cfg/dy_to_ll_tradeElep2ForZMass.lua", dy_lua_parameters);
pp_Z_llbb_elel_tfJet_ec_ec_tradeElep2ForZMass_configuration.getGlobalParameters().set("matrix_element", "pp_to_Z_to_llbb_sm_P1_Sigma_sm_gg_epembbx");
pp_Z_llbb_elel_tfJet_ec_ec_tradeElep2ForZMass_configuration.getGlobalParameters().set("matrix_element_prefix", "pp_to_Z_to_llbb");
pp_Z_llbb_elel_tfJet_ec_ec_tradeElep2ForZMass_configuration.getGlobalParameters().set("jet1TFFile", "/home/fynu/bfrancois/scratch/framework/MIS_prod_data/CMSSW_7_6_5/src/cp3_llbb/HHTools/histFactory_hh/tf_genCut0_noRecoCut_lljjorbb_Oct18/condor/output/allTT_smoothed_notPutToZero.root");
pp_Z_llbb_elel_tfJet_ec_ec_tradeElep2ForZMass_configuration.getGlobalParameters().set("lep1TFFile", "/home/fynu/bfrancois/scratch/framework/MIS_prod_data/CMSSW_7_6_5/src/cp3_llbb/HHTools/histFactory_hh/tf_genCut0_noRecoCut_lljjorbb_Oct18/condor/output/allTT_smoothed_notPutToZero.root");
pp_Z_llbb_elel_tfJet_ec_ec_tradeElep2ForZMass_configuration.getGlobalParameters().set("lep2_me_index", 2);
pp_Z_llbb_elel_tfJet_ec_ec_tradeElep2ForZMass_configuration.getGlobalParameters().set("lep1_me_index", 1);
pp_Z_llbb_elel_tfJet_ec_ec_tradeElep2ForZMass_configuration.getGlobalParameters().set("jet2TFFile", "/home/fynu/bfrancois/scratch/framework/MIS_prod_data/CMSSW_7_6_5/src/cp3_llbb/HHTools/histFactory_hh/tf_genCut0_noRecoCut_lljjorbb_Oct18/condor/output/allTT_smoothed_notPutToZero.root");
pp_Z_llbb_elel_tfJet_ec_ec_tradeElep2ForZMass_configuration.getGlobalParameters().set("lep2TFName", "ERecMinEGenVSEGen_el_matchedToAfterFSR_allEta_Norm_hh_llmetjj_HWWleptons_nobtag_csv");
pp_Z_llbb_elel_tfJet_ec_ec_tradeElep2ForZMass_configuration.getGlobalParameters().set("lep1TFName", "ERecMinEGenVSEGen_el_matchedToAfterFSR_allEta_Norm_hh_llmetjj_HWWleptons_nobtag_csv");
pp_Z_llbb_elel_tfJet_ec_ec_tradeElep2ForZMass_configuration.getGlobalParameters().set("jet1TFName", "ERecMinEGenVSEGen_bjet_matchedToAfterFSR_allEta_Norm_hh_llmetjj_HWWleptons_nobtag_csv");
pp_Z_llbb_elel_tfJet_ec_ec_tradeElep2ForZMass_configuration.getGlobalParameters().set("jet2TFName", "ERecMinEGenVSEGen_bjet_matchedToAfterFSR_allEta_Norm_hh_llmetjj_HWWleptons_nobtag_csv");
pp_Z_llbb_elel_tfJet_ec_ec_tradeElep2ForZMass_configuration.getGlobalParameters().set("matrix_element_parameters", "/home/fynu/bfrancois/scratch/MoMEMta/plugin_mode//pp_to_Z_to_llbb/Cards/param_card.dat");
pp_Z_llbb_elel_tfJet_ec_ec_tradeElep2ForZMass_configuration.getGlobalParameters().set("lep2TFFile", "/home/fynu/bfrancois/scratch/framework/MIS_prod_data/CMSSW_7_6_5/src/cp3_llbb/HHTools/histFactory_hh/tf_genCut0_noRecoCut_lljjorbb_Oct18/condor/output/allTT_smoothed_notPutToZero.root");
MoMEMta pp_Z_llbb_elel_tfJet_ec_ec_tradeElep2ForZMass_weightComputer(pp_Z_llbb_elel_tfJet_ec_ec_tradeElep2ForZMass_configuration.freeze());
dy_lua_parameters.set("matrix_element_prefix", "pp_to_llbb");
ConfigurationReader pp_llbb_elel_tfAllEta_tradeElep2ForZMass_configuration("/home/fynu/bfrancois/scratch/framework/MIS_prod_data/CMSSW_7_6_5/src/cp3_llbb/MoMEMta_cfg/dy_to_ll_tradeElep2ForZMass.lua", dy_lua_parameters);
pp_llbb_elel_tfAllEta_tradeElep2ForZMass_configuration.getGlobalParameters().set("matrix_element", "pp_to_llbb_sm_P1_Sigma_sm_gg_epembbx");
pp_llbb_elel_tfAllEta_tradeElep2ForZMass_configuration.getGlobalParameters().set("matrix_element_prefix", "pp_to_llbb");
pp_llbb_elel_tfAllEta_tradeElep2ForZMass_configuration.getGlobalParameters().set("lep2_me_index", 2);
pp_llbb_elel_tfAllEta_tradeElep2ForZMass_configuration.getGlobalParameters().set("lep1TFFile", "/home/fynu/bfrancois/scratch/framework/MIS_prod_data/CMSSW_7_6_5/src/cp3_llbb/HHTools/histFactory_hh/tf_genCut0_noRecoCut_lljjorbb_Oct18/condor/output/allTT_smoothed_notPutToZero.root");
pp_llbb_elel_tfAllEta_tradeElep2ForZMass_configuration.getGlobalParameters().set("jet1TFFile", "/home/fynu/bfrancois/scratch/framework/MIS_prod_data/CMSSW_7_6_5/src/cp3_llbb/HHTools/histFactory_hh/tf_genCut0_noRecoCut_lljjorbb_Oct18/condor/output/allTT_smoothed_notPutToZero.root");
pp_llbb_elel_tfAllEta_tradeElep2ForZMass_configuration.getGlobalParameters().set("lep2TFFile", "/home/fynu/bfrancois/scratch/framework/MIS_prod_data/CMSSW_7_6_5/src/cp3_llbb/HHTools/histFactory_hh/tf_genCut0_noRecoCut_lljjorbb_Oct18/condor/output/allTT_smoothed_notPutToZero.root");
pp_llbb_elel_tfAllEta_tradeElep2ForZMass_configuration.getGlobalParameters().set("jet2TFName", "ERecMinEGenVSEGen_bjet_matchedToAfterFSR_allEta_Norm_hh_llmetjj_HWWleptons_nobtag_csv");
pp_llbb_elel_tfAllEta_tradeElep2ForZMass_configuration.getGlobalParameters().set("lep1_me_index", 1);
pp_llbb_elel_tfAllEta_tradeElep2ForZMass_configuration.getGlobalParameters().set("jet2TFFile", "/home/fynu/bfrancois/scratch/framework/MIS_prod_data/CMSSW_7_6_5/src/cp3_llbb/HHTools/histFactory_hh/tf_genCut0_noRecoCut_lljjorbb_Oct18/condor/output/allTT_smoothed_notPutToZero.root");
pp_llbb_elel_tfAllEta_tradeElep2ForZMass_configuration.getGlobalParameters().set("matrix_element_parameters", "/home/fynu/bfrancois/scratch/MoMEMta/plugin_mode//pp_to_llbb/Cards/param_card.dat");
pp_llbb_elel_tfAllEta_tradeElep2ForZMass_configuration.getGlobalParameters().set("lep2TFName", "ERecMinEGenVSEGen_el_matchedToAfterFSR_allEta_Norm_hh_llmetjj_HWWleptons_nobtag_csv");
pp_llbb_elel_tfAllEta_tradeElep2ForZMass_configuration.getGlobalParameters().set("lep1TFName", "ERecMinEGenVSEGen_el_matchedToAfterFSR_allEta_Norm_hh_llmetjj_HWWleptons_nobtag_csv");
pp_llbb_elel_tfAllEta_tradeElep2ForZMass_configuration.getGlobalParameters().set("jet1TFName", "ERecMinEGenVSEGen_bjet_matchedToAfterFSR_allEta_Norm_hh_llmetjj_HWWleptons_nobtag_csv");
MoMEMta pp_llbb_elel_tfAllEta_tradeElep2ForZMass_weightComputer(pp_llbb_elel_tfAllEta_tradeElep2ForZMass_configuration.freeze());
dy_lua_parameters.set("matrix_element_prefix", "gg_to_z_to_llbb");
ConfigurationReader gg_Z_llbb_elel_tfAllEta_tradeElep2ForZMass_configuration("/home/fynu/bfrancois/scratch/framework/MIS_prod_data/CMSSW_7_6_5/src/cp3_llbb/MoMEMta_cfg/dy_to_ll_tradeElep2ForZMass.lua", dy_lua_parameters);
gg_Z_llbb_elel_tfAllEta_tradeElep2ForZMass_configuration.getGlobalParameters().set("matrix_element", "gg_to_z_to_llbb_sm_P1_Sigma_sm_gg_epembbx");
gg_Z_llbb_elel_tfAllEta_tradeElep2ForZMass_configuration.getGlobalParameters().set("matrix_element_prefix", "gg_to_z_to_llbb");
gg_Z_llbb_elel_tfAllEta_tradeElep2ForZMass_configuration.getGlobalParameters().set("lep2_me_index", 2);
gg_Z_llbb_elel_tfAllEta_tradeElep2ForZMass_configuration.getGlobalParameters().set("lep1TFFile", "/home/fynu/bfrancois/scratch/framework/MIS_prod_data/CMSSW_7_6_5/src/cp3_llbb/HHTools/histFactory_hh/tf_genCut0_noRecoCut_lljjorbb_Oct18/condor/output/allTT_smoothed_notPutToZero.root");
gg_Z_llbb_elel_tfAllEta_tradeElep2ForZMass_configuration.getGlobalParameters().set("jet1TFFile", "/home/fynu/bfrancois/scratch/framework/MIS_prod_data/CMSSW_7_6_5/src/cp3_llbb/HHTools/histFactory_hh/tf_genCut0_noRecoCut_lljjorbb_Oct18/condor/output/allTT_smoothed_notPutToZero.root");
gg_Z_llbb_elel_tfAllEta_tradeElep2ForZMass_configuration.getGlobalParameters().set("lep2TFFile", "/home/fynu/bfrancois/scratch/framework/MIS_prod_data/CMSSW_7_6_5/src/cp3_llbb/HHTools/histFactory_hh/tf_genCut0_noRecoCut_lljjorbb_Oct18/condor/output/allTT_smoothed_notPutToZero.root");
gg_Z_llbb_elel_tfAllEta_tradeElep2ForZMass_configuration.getGlobalParameters().set("jet2TFName", "ERecMinEGenVSEGen_bjet_matchedToAfterFSR_allEta_Norm_hh_llmetjj_HWWleptons_nobtag_csv");
gg_Z_llbb_elel_tfAllEta_tradeElep2ForZMass_configuration.getGlobalParameters().set("lep1_me_index", 1);
gg_Z_llbb_elel_tfAllEta_tradeElep2ForZMass_configuration.getGlobalParameters().set("jet2TFFile", "/home/fynu/bfrancois/scratch/framework/MIS_prod_data/CMSSW_7_6_5/src/cp3_llbb/HHTools/histFactory_hh/tf_genCut0_noRecoCut_lljjorbb_Oct18/condor/output/allTT_smoothed_notPutToZero.root");
gg_Z_llbb_elel_tfAllEta_tradeElep2ForZMass_configuration.getGlobalParameters().set("matrix_element_parameters", "/home/fynu/bfrancois/scratch/MoMEMta/plugin_mode//gg_to_z_to_llbb/Cards/param_card.dat");
gg_Z_llbb_elel_tfAllEta_tradeElep2ForZMass_configuration.getGlobalParameters().set("lep2TFName", "ERecMinEGenVSEGen_el_matchedToAfterFSR_allEta_Norm_hh_llmetjj_HWWleptons_nobtag_csv");
gg_Z_llbb_elel_tfAllEta_tradeElep2ForZMass_configuration.getGlobalParameters().set("lep1TFName", "ERecMinEGenVSEGen_el_matchedToAfterFSR_allEta_Norm_hh_llmetjj_HWWleptons_nobtag_csv");
gg_Z_llbb_elel_tfAllEta_tradeElep2ForZMass_configuration.getGlobalParameters().set("jet1TFName", "ERecMinEGenVSEGen_bjet_matchedToAfterFSR_allEta_Norm_hh_llmetjj_HWWleptons_nobtag_csv");
MoMEMta gg_Z_llbb_elel_tfAllEta_tradeElep2ForZMass_weightComputer(gg_Z_llbb_elel_tfAllEta_tradeElep2ForZMass_configuration.freeze());
dy_lua_parameters.set("matrix_element_prefix", "pp_to_Z_to_llbb");
ConfigurationReader pp_llbb_mumu_tfAllEta_tradeElep2ForZMass_configuration("/home/fynu/bfrancois/scratch/framework/MIS_prod_data/CMSSW_7_6_5/src/cp3_llbb/MoMEMta_cfg/dy_to_ll_simple.lua", dy_lua_parameters);
pp_llbb_mumu_tfAllEta_tradeElep2ForZMass_configuration.getGlobalParameters().set("matrix_element", "pp_to_Z_to_llbb_sm_P1_Sigma_sm_gg_epembbx");
pp_llbb_mumu_tfAllEta_tradeElep2ForZMass_configuration.getGlobalParameters().set("matrix_element_prefix", "pp_to_Z_to_llbb");
pp_llbb_mumu_tfAllEta_tradeElep2ForZMass_configuration.getGlobalParameters().set("jet1TFFile", "/home/fynu/bfrancois/scratch/framework/MIS_prod_data/CMSSW_7_6_5/src/cp3_llbb/HHTools/histFactory_hh/tf_genCut0_noRecoCut_lljjorbb_Oct18/condor/output/allTT_smoothed_notPutToZero.root");
pp_llbb_mumu_tfAllEta_tradeElep2ForZMass_configuration.getGlobalParameters().set("lep1TFFile", "/home/fynu/bfrancois/scratch/framework/MIS_prod_data/CMSSW_7_6_5/src/cp3_llbb/HHTools/histFactory_hh/tf_genCut0_noRecoCut_lljjorbb_Oct18/condor/output/allTT_smoothed_notPutToZero.root");
pp_llbb_mumu_tfAllEta_tradeElep2ForZMass_configuration.getGlobalParameters().set("lep2_me_index", 2);
pp_llbb_mumu_tfAllEta_tradeElep2ForZMass_configuration.getGlobalParameters().set("lep1_me_index", 1);
pp_llbb_mumu_tfAllEta_tradeElep2ForZMass_configuration.getGlobalParameters().set("jet2TFFile", "/home/fynu/bfrancois/scratch/framework/MIS_prod_data/CMSSW_7_6_5/src/cp3_llbb/HHTools/histFactory_hh/tf_genCut0_noRecoCut_lljjorbb_Oct18/condor/output/allTT_smoothed_notPutToZero.root");
pp_llbb_mumu_tfAllEta_tradeElep2ForZMass_configuration.getGlobalParameters().set("lep2TFName", "ERecMinEGenVSEGen_el_matchedToAfterFSR_allEta_Norm_hh_llmetjj_HWWleptons_nobtag_csv");
pp_llbb_mumu_tfAllEta_tradeElep2ForZMass_configuration.getGlobalParameters().set("lep1TFName", "ERecMinEGenVSEGen_el_matchedToAfterFSR_allEta_Norm_hh_llmetjj_HWWleptons_nobtag_csv");
pp_llbb_mumu_tfAllEta_tradeElep2ForZMass_configuration.getGlobalParameters().set("jet1TFName", "ERecMinEGenVSEGen_bjet_matchedToAfterFSR_allEta_Norm_hh_llmetjj_HWWleptons_nobtag_csv");
pp_llbb_mumu_tfAllEta_tradeElep2ForZMass_configuration.getGlobalParameters().set("jet2TFName", "ERecMinEGenVSEGen_bjet_matchedToAfterFSR_allEta_Norm_hh_llmetjj_HWWleptons_nobtag_csv");
pp_llbb_mumu_tfAllEta_tradeElep2ForZMass_configuration.getGlobalParameters().set("matrix_element_parameters", "/home/fynu/bfrancois/scratch/MoMEMta/plugin_mode//pp_to_Z_to_llbb/Cards/param_card.dat");
pp_llbb_mumu_tfAllEta_tradeElep2ForZMass_configuration.getGlobalParameters().set("lep2TFFile", "/home/fynu/bfrancois/scratch/framework/MIS_prod_data/CMSSW_7_6_5/src/cp3_llbb/HHTools/histFactory_hh/tf_genCut0_noRecoCut_lljjorbb_Oct18/condor/output/allTT_smoothed_notPutToZero.root");
MoMEMta pp_llbb_mumu_tfAllEta_tradeElep2ForZMass_weightComputer(pp_llbb_mumu_tfAllEta_tradeElep2ForZMass_configuration.freeze());



    LorentzVector p3(-16.1563,-44.4986,34.4327,58.5386);
    LorentzVector p5(4.14736,27.3872,-27.2313,38.8434);
    LorentzVector p4(-66.7698,5.92761,-28.8242,73.3709);
    LorentzVector p6(-41.3411,-41.6881,36.3177,69.3681);

    //// Electron
    //LorentzVector p3(16.171895980835, -13.7919054031372, -3.42997527122497, 21.5293197631836);
    //// b-quark
    //LorentzVector p4(-55.7908325195313, -111.59294128418, -122.144721984863, 174.66259765625);
    //// Muon
    //LorentzVector p5(-18.9018573760986, 10.0896110534668, -0.602926552295686, 21.4346446990967);
    //// Anti b-quark
    //LorentzVector p6(71.3899612426758, 96.0094833374023, -77.2513122558594, 142.492813110352);

    auto start_time = system_clock::now();
    //std::vector<std::pair<double, double>> weights = weight.computeWeights({p3, p4, p5, p6, -(p3+p4+p5+p6)});
    // Particles, fifth being the pt to balance
    std::vector<std::pair<double, double>> weights = pp_Z_llbb_elel_tfAllEta_simple_weightComputer.computeWeights({p3, p5, p4, p6, -(p3+p4+p5+p6)});
    auto end_time = system_clock::now();

    LOG(debug) << "Result:";
    for (const auto& r: weights) {
        LOG(debug) << r.first << " +- " << r.second;
    }

    std::cout << weights.at(0).first << " +- " << weights.at(0).second << std::endl;
    //LOG(debug) << "Integration status: " << (int) weight.getIntegrationStatus();

    LOG(info) << "Weight computed in " << std::chrono::duration_cast<milliseconds>(end_time - start_time).count() << "ms";


    return 0;
}

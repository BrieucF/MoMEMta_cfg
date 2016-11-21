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

    ParameterSet lua_parameters;
    lua_parameters.set("matrix_element_prefix", "pp_twMinusbbar_tAndWOnshell");

    ConfigurationReader configuration("twMinusbbar.lua", lua_parameters);

    // Change top mass
    configuration.getGlobalParameters().set("top_mass", 173.);

    MoMEMta weight(configuration.freeze());
    // Electron
    Particle electron { "neg_lepton", LorentzVector(16.171895980835, -13.7919054031372, -3.42997527122497, 21.5293197631836), -11 };
    // b-quark
    Particle b1 { "bjet1", LorentzVector(-55.7908325195313, -111.59294128418, -122.144721984863, 174.66259765625), 5 };
    // Muon
    Particle muon { "pos_lepton", LorentzVector(-18.9018573760986, 10.0896110534668, -0.602926552295686, 21.4346446990967), +13 };
    // Anti b-quark
    Particle b2 { "bjet2", LorentzVector(71.3899612426758, 96.0094833374023, -77.2513122558594, 142.492813110352), -5 };
    Particle met { "met", LorentzVector(71.3899612426758-18.9018573760986-55.7908325195313+16.171895980835, 96.0094833374023+10.0896110534668-111.59294128418 -13.7919054031372, -77.2513122558594-0.602926552295686-122.144721984863-3.42997527122497, 142.492813110352+21.4346446990967+174.66259765625+21.5293197631836), 0 };
    Particle dummy_neutrino { "dummy_neutrino", LorentzVector(1,0,0,1), 0 };

    auto start_time = system_clock::now();
    std::vector<std::pair<double, double>> weights = weight.computeWeights({muon, electron, b1, b2, dummy_neutrino}, LorentzVector(71.3899612426758-18.9018573760986-55.7908325195313+16.171895980835, 96.0094833374023+10.0896110534668-111.59294128418 -13.7919054031372, -77.2513122558594-0.602926552295686-122.144721984863-3.42997527122497, 142.492813110352+21.4346446990967+174.66259765625+21.5293197631836));//, -(p3 + p5 + p4 + p6));
    auto end_time = system_clock::now();

    LOG(debug) << "Result:";
    for (const auto& r: weights) {
        LOG(debug) << r.first << " +- " << r.second;
    }

    LOG(debug) << "Integration status: " << (int) weight.getIntegrationStatus();

    InputTag dmemInputTag {"dmem", "hist"};
    bool exists = weight.getPool().exists(dmemInputTag);

    LOG(debug) << "Hist in pool: " << exists;

    if (exists) {
        Value<TH1D> dmem = weight.getPool().get<TH1D>(dmemInputTag);
        LOG(debug) << "DMEM integral: " << dmem->Integral();
    }

    LOG(info) << "Weight computed in " << std::chrono::duration_cast<milliseconds>(end_time - start_time).count() << "ms";


    return 0;
}

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
using namespace momemta;

int main(int argc, char** argv) {

    UNUSED(argc);
    UNUSED(argv);

    logging::set_level(logging::level::debug);

    ParameterSet dy_lua_parameters;

    dy_lua_parameters.set("matrix_element_prefix", "pp_to_Z_to_llbb");
    ConfigurationReader configuration("dy_to_ll_simple.lua", dy_lua_parameters);
    MoMEMta weight(configuration.freeze());
    // Electron
    LorentzVector p3(16.171895980835, -13.7919054031372, -3.42997527122497, 21.5293197631836);
    // b-quark
    LorentzVector p4(-55.7908325195313, -111.59294128418, -122.144721984863, 174.66259765625);
    // Muon
    LorentzVector p5(-18.9018573760986, 10.0896110534668, -0.602926552295686, 21.4346446990967);
    // Anti b-quark
    LorentzVector p6(71.3899612426758, 96.0094833374023, -77.2513122558594, 142.492813110352);

    //LorentzVector p3(-16.1563,-44.4986,34.4327,58.5386);
    //LorentzVector p5(4.14736,27.3872,-27.2313,38.8434);
    //LorentzVector p4(-66.7698,5.92761,-28.8242,73.3709);
    //LorentzVector p6(-41.3411,-41.6881,36.3177,69.3681);
    Particle electron { "pos_lepton", LorentzVector(16.171895980835, -13.7919054031372, -3.42997527122497, 21.5293197631836), -11 };
    // b-quark
    Particle b1 { "bjet1", LorentzVector(-55.7908325195313, -111.59294128418, -122.144721984863, 174.66259765625), 5 };
    // Muon
    Particle muon { "neg_lepton", LorentzVector(-18.9018573760986, 10.0896110534668, -0.602926552295686, 21.4346446990967), +13 };
    // Anti b-quark
    Particle b2 { "bjet2", LorentzVector(71.3899612426758, 96.0094833374023, -77.2513122558594, 142.492813110352), -5 };
    Particle met { "met", LorentzVector(71.3899612426758-18.9018573760986-55.7908325195313+16.171895980835, 96.0094833374023+10.0896110534668-111.59294128418 -13.7919054031372, -77.2513122558594-0.602926552295686-122.144721984863-3.42997527122497, 142.492813110352+21.4346446990967+174.66259765625+21.5293197631836), 0 };
    LorentzVector isr_p4;
    isr_p4 = -(p3+p4+p5+p6);
    isr_p4.SetE(std::abs(isr_p4.E()));
    Particle isr {"isr", isr_p4, 0};

    auto start_time = system_clock::now();
    //std::vector<std::pair<double, double>> weights = weight.computeWeights({p3, p4, p5, p6, -(p3+p4+p5+p6)});
    // Particles, fifth being the pt to balance
    std::vector<std::pair<double, double>> weights = weight.computeWeights({muon, electron, b1, b2, isr});
    auto end_time = system_clock::now();

    //////// Electron
    //////LorentzVector p3(16.171895980835, -13.7919054031372, -3.42997527122497, 21.5293197631836);
    //////// b-quark
    //////LorentzVector p4(-55.7908325195313, -111.59294128418, -122.144721984863, 174.66259765625);
    //////// Muon
    //////LorentzVector p5(-18.9018573760986, 10.0896110534668, -0.602926552295686, 21.4346446990967);
    //////// Anti b-quark
    //////LorentzVector p6(71.3899612426758, 96.0094833374023, -77.2513122558594, 142.492813110352);

    LOG(debug) << "Result:";
    for (const auto& r: weights) {
        LOG(debug) << r.first << " +- " << r.second;
    }

    std::cout << weights.at(0).first << " +- " << weights.at(0).second << std::endl;
    LOG(debug) << "Integration status: " << (int) weight.getIntegrationStatus();

    LOG(info) << "Weight computed in " << std::chrono::duration_cast<milliseconds>(end_time - start_time).count() << "ms";


    return 0;
}

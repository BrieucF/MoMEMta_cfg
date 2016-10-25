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
    //lua_parameters.set("USE_TF", true);
    //lua_parameters.set("USE_PERM", false);
    //lua_parameters.set("NWA", false);
    lua_parameters.set("matrix_element_prefix", "pp_to_Z_to_llbb"); //  pp_to_llbb, gg_to_z_to_llbb, pp_to_Z_to_llbb

    ConfigurationReader configuration("dy_to_ll_tradeElep2ForZMass.lua", lua_parameters);

    configuration.getGlobalParameters().set("top_mass", 173.);

    MoMEMta weight(configuration.freeze());

    // Electron
    LorentzVector p3(16.171895980835, -13.7919054031372, -3.42997527122497, 21.5293197631836);
    // b-quark
    LorentzVector p4(-55.7908325195313, -111.59294128418, -122.144721984863, 174.66259765625);
    // Muon
    LorentzVector p5(-18.9018573760986, 10.0896110534668, -0.602926552295686, 21.4346446990967);
    // Anti b-quark
    LorentzVector p6(71.3899612426758, 96.0094833374023, -77.2513122558594, 142.492813110352);
//    LorentzVector p3(28.1583,-32.8119,-13.4703,44.6727);
//    LorentzVector p4(-23.2368,21.8771,54.2188,63.2692);
//    std::cout  << "Masssssssssssssssssss" << std::endl;
//    std::cout  << p4.M() << std::endl;
//    LorentzVector p5(-76.9412,-138.709,8.87853,170.862);
//    LorentzVector p6(-51.2887,-14.691,13.9445,54.9725);

    auto start_time = system_clock::now();
    //std::vector<std::pair<double, double>> weights = weight.computeWeights({p3, p4, p5, p6, -(p3+p4+p5+p6)});
    std::vector<std::pair<double, double>> weights = weight.computeWeights({p3, p5, p4, p6, -(p3+p4+p5+p6)});
    auto end_time = system_clock::now();

    LOG(debug) << "Result:";
    for (const auto& r: weights) {
        LOG(debug) << r.first << " +- " << r.second;
    }

    std::cout << weights.at(0).first << " +- " << weights.at(0).second << std::endl;
    LOG(debug) << "Integration status: " << (int) weight.getIntegrationStatus();

    LOG(info) << "Weight computed in " << std::chrono::duration_cast<milliseconds>(end_time - start_time).count() << "ms";


    return 0;
}

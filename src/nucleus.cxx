// LANGEVIN: 
// Copyright@2018 Yao, Li CCNU

#include <memory>
#include <cstring>
#include <iostream>
#include "gsl/gsl_integration.h"
#include "../include/nucleus.h"

namespace langevin {

Nucleus::Nucleus(const std::string& species, int protonZ, int atomA) :
    _species(species),
    _protonZ(protonZ),
    _atomA(atomA) {}

Nucleus* Nucleus::create(const std::string& species) {
    if (species == "Pb") {
        return (Nucleus*)new WoodsSaxonNucleus{species, 82, 208, 0.169347, 6.62, 0.546};
    }

    std::cout << "Not supported nuclues" << std::endl;

    exit(1);
}

WoodsSaxonNucleus::WoodsSaxonNucleus(const std::string& species, int protonZ, int atomA, double rho0, double radiusA, double a) :
    Nucleus(species, protonZ, atomA),
    _rho0(rho0),
    _radiusA(radiusA),
    _a(a) {}

namespace {

constexpr double GSL_INTEGRATION_RELATIVE_PRECISION = 0.000001;
constexpr double GSL_INTEGRATION_WORKSPACE_SIZE = 1000;

// all parameters' units are fm
constexpr double RADIUS_CUTOFF = 50;
constexpr double XT_MAX = 15;
constexpr double XT_MIN = 0;
constexpr double Z_MAX = 15;
constexpr double Z_MIN = 0;


struct WoodsSaxonParams {
    double xt;
    double rho0;
    double radiusA;
    double a;
};

double rho(double z, void * p) {
    WoodsSaxonParams params = *(WoodsSaxonParams *)p;
    // x transver
    double xt = params.xt;

    return params.rho0 / (std::exp((std::sqrt(xt * xt + z * z) - params.radiusA) / params.a) + 1);
}

}

double WoodsSaxonNucleus::thick(double z0, double xt) {

    double result, error;
    double min = z0;
    double max = RADIUS_CUTOFF;

    gsl_integration_workspace * w = gsl_integration_workspace_alloc(GSL_INTEGRATION_WORKSPACE_SIZE);

    WoodsSaxonParams params = {xt, rho0(), radiusA(), a()};

    gsl_function F;
    F.function = &rho;
    F.params   = &params;
 
    gsl_integration_qags(&F, min, max, 0, GSL_INTEGRATION_RELATIVE_PRECISION, GSL_INTEGRATION_WORKSPACE_SIZE, w, &result, &error);
    gsl_integration_workspace_free(w);

    // if (xt - 0.0 < GSL_INTEGRATION_RELATIVE_PRECISION)
    //     std::cout << "xt=" << xt << ", rho0=" << rho0() << ", radiusA=" << radiusA() << ", a=" << a() << " " << result << std::endl;

    return result;
}

void WoodsSaxonNucleus::computeNuclearThickness(Grid& thickGrid) {

    double xtstep = (XT_MAX - XT_MIN) / (XT_NUM - 1);
    double zstep = (Z_MAX - Z_MIN) / (Z_NUM - 1);

    int i, j;
    double xt, z, result;
//    double sum = 0.0;
    for(i = 0; i < XT_NUM; i++) {
        xt = XT_MIN + i * xtstep;
        for(j = 0; j < Z_NUM; j++) {
            z = Z_MIN + j * zstep;
            result = thick(z, xt);

            thickGrid[i][j][0] = z;
            thickGrid[i][j][1] = xt;
            thickGrid[i][j][2] = result;

//            if (j == 0) sum = sum + result;
        }
    }
//    std::cout << "sum = " << sum << std::endl;
}



}
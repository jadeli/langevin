// LANGEVIN: 
// Copyright@2018 Yao, Li CCNU

#include <memory>
#include <cstring>
#include <iostream>
#include "../include/nucleus.h"

namespace langevin {

Nucleus::Nucleus(const std::string& species, int protonZ, int atomA) :
    _species(species),
    _protonZ(protonZ),
    _atomA(atomA) {}

NucleusPtr Nucleus::create(const std::string& species) {
    if (species == "Pb") {
        return NucleusPtr{new WoodsSaxonNucleus{species, 82, 208, 0.169347, 6.62, 0.546}};
    }

    std::cout << "Not supported nuclues" << std::endl;

    exit(1);
}

std::string Nucleus::species() {
    return _species;
}

int Nucleus::protonZ() const {
    return _protonZ;
}

int Nucleus::atomA() const {
    return _atomA;
}

WoodsSaxonNucleus::WoodsSaxonNucleus(const std::string& species, int protonZ, int atomA, double radiusA, double rho0, double a) :
    Nucleus(species, protonZ, atomA),
    _radiusA(radiusA),
    _rho0(rho0),
    _a(a) {}

double WoodsSaxonNucleus::radiusA() const {
    return _radiusA;
}

double WoodsSaxonNucleus::rho0() const {
    return _rho0;
}

double WoodsSaxonNucleus::a() const {
    return _a;
}


}
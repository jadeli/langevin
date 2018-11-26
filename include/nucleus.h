// LANGEVIN: 
// Copyright@2018 Yao, Li CCNU

#include <memory>
#include <cstring>
#include <boost/multi_array.hpp>
#include "../include/util.h"

namespace langevin {

class Nucleus;

// Alias for a smart pointer to a Nucleus.
using NucleusPtr = std::unique_ptr<Nucleus>;

constexpr int XT_NUM = 1501;
constexpr int Z_NUM = 101;
constexpr int THICK_MARGIN = 2;

class Nucleus {
public:
    Nucleus(const std::string& species, int protonZ, int atomA);

    static Nucleus* create(const std::string& species);

    /// Default virtual destructor for abstract base class.
    virtual ~Nucleus() = default;

    std::string species() const;
    int protonZ() const;
    int atomA() const;

    virtual void computeNuclearThickness(Grid& thickGrid) = 0;
    
protected:
    const std::string _species;
    const int _protonZ;
    const int _atomA;
};

class WoodsSaxonNucleus : public Nucleus {
public:
    WoodsSaxonNucleus(const std::string& species, int protonZ, int atomA, double rho0, double radiusA, double a);

    ~WoodsSaxonNucleus() = default;

    virtual void computeNuclearThickness(Grid& thickGrid) override;

    double rho0() const;

    /// The radius of nucleus
    double radiusA() const;

    double a() const;

private:
    double thick(double z0, double xt);

    const double _radiusA;
    const double _rho0;
    const double _a;
};


inline std::string Nucleus::species() const {
    return _species;
}

inline int Nucleus::protonZ() const {
    return _protonZ;
}

inline int Nucleus::atomA() const {
    return _atomA;
}


inline double WoodsSaxonNucleus::rho0() const {
    return _rho0;
}

inline double WoodsSaxonNucleus::radiusA() const {
    return _radiusA;
}

inline double WoodsSaxonNucleus::a() const {
    return _a;
}


}
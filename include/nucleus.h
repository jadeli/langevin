// LANGEVIN: 
// Copyright@2018 Yao, Li CCNU

#include <memory>
#include <cstring>

namespace langevin {
    
class Nucleus;

// Alias for a smart pointer to a Nucleus.
using NucleusPtr = std::unique_ptr<Nucleus>;

class Nucleus {
public:
    Nucleus(const std::string& species, int protonZ, int atomA);
    
    static NucleusPtr create(const std::string& species);

    /// Default virtual destructor for abstract base class.
    virtual ~Nucleus() = default;

    std::string species();
    int protonZ() const;
    int atomA() const;
    
protected:
    const std::string _species;
    const int _protonZ;
    const int _atomA;
};

class WoodsSaxonNucleus : public Nucleus {
public:
    WoodsSaxonNucleus(const std::string& species, int protonZ, int atomA, double radiusA, double rho0, double a);

    /// The radius of nucleus
    double radiusA() const;

    double rho0() const;

    double a() const;

private:
    const double _radiusA;
    const double _rho0;
    const double _a;
};

}
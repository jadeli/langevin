// LANGEVIN: 
// Copyright@2018 Yao, Li CCNU

#include <memory>
#include "../include/particle.h"

namespace langevin {

class Sample {
public:
    Sample() = default;

    std::unique_ptr<Particle>* getParticles();
};

}
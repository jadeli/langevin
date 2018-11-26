// LANGEVIN: 
// Copyright@2018 Yao, Li CCNU

#include <memory>
#include "../include/random.h"
#include "../include/particle.h"

namespace langevin {
    
// Alias for a smart pointer to a Particle.
using ParticlePtr = std::unique_ptr<Particle>;

template<class T>
struct array_deleter
{
    void operator()(T* &x) const { delete[] x; }
};

using ParticleArrayPtr = std::unique_ptr<ParticlePtr, array_deleter<ParticlePtr>>;

class Sample {
public:
    explicit Sample(const enum RandomType type);

    ~Sample();

    ParticleArrayPtr getParticles(size_t size);

private:
    Random rand;
    double getMomentumTransverse();
};

}
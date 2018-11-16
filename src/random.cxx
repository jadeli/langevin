// LANGEVIN: 
// Copyright@2018 Yao, Li CCNU

#include <iostream>
#include <gsl/gsl_rng.h>
#include "../include/random.h"
#include <ctime>

namespace langevin {
    
Random::Random(const enum RandomType type) {

    switch(type) {
        case RandomType::Default:
            // old process, just for testing
            // read the value of GSL_RNG_TYPE and GSL_RNG_SEED, 
            // then set them to gsl_rng_default and gsl_rng_default_seed respectively.
            gsl_rng_env_setup();

            // create random number generator with gsl_rng_default
            rng = gsl_rng_alloc(gsl_rng_default);

            std::cout << "-----DON'T USE THIS METHOD-----" << std::endl;
            break;
            
        case RandomType::RANLXS0:
            // set random number generator seed
            gsl_rng_default_seed  = ((unsigned long)(time(NULL)));

            // create random number generator with gsl_rng_ranlxs0
            rng = gsl_rng_alloc(gsl_rng_ranlxs0);
            break;

        default:
            std::cout << "Random type = " << (int)type << " is not supported!" << std::endl;
            exit(1);
            break;
    }
    
    // print rng infos
    std::cout << "Generator type: " << gsl_rng_name(rng) << ", seed = " << gsl_rng_default_seed << std::endl;
}

double Random::next() {
    return gsl_rng_uniform(rng);
}

double Random::next_pos() {
    return gsl_rng_uniform_pos(rng);
}

void Random::destroy() {
    gsl_rng_free(rng);
}

}
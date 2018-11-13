// LANGEVIN: 
// Copyright@2018 Yao, Li
// CCNU License

#include <gsl/gsl_rng.h>

namespace langevin {

class Random {
public:
    explicit Random(bool isNew = false);

    // get a random number between [0, 1)
    double next();

    // get a random number between (0, 1)
    double next_pos();

    void destroy();

private:
    gsl_rng *rng;
};

}
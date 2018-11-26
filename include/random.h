// LANGEVIN: 
// Copyright@2018 Yao, Li CCNU

#include <gsl/gsl_rng.h>

namespace langevin {

enum class RandomType {
    Default,
    RANLXS0,
};

class Random {
public:
    explicit Random(const enum RandomType type);

    /// get a random number between [0, 1)
    double next();

    /// get a random number between (0, 1)
    double nextPos();

    /// you should call destroy() to free memory
    void destroy();

private:
    gsl_rng *rng;
};

}
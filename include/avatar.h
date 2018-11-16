// LANGEVIN: 
// Copyright@2018 Yao, Li CCNU

#include "../include/random.h"

namespace langevin {

class Avatar {
public:
    explicit Avatar();

    ~Avatar();

    void run();

private:
    Random rand;
};

}
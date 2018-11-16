// LANGEVIN: 
// Copyright@2018 Yao, Li CCNU

#include <iostream>
#include <cstring>

#include "../include/avatar.h"

#ifndef LANGEVIN_VERSION
#define LANGEVIN_VERSION "dev"
#endif

namespace langevin {

namespace {
    void print_version() {
        std::cout << "CCNU Langevin " << LANGEVIN_VERSION << std::endl;
    }
}
}


int main(int argc, char* argv[]) {
    using namespace langevin;

    print_version();

    Avatar avatar;
    avatar.run();

    return 0;
}
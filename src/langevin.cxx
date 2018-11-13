#include <iostream>
#include <cstring>

#include "../include/random.h"

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

    Random rand{};
    std::cout << rand.next() << std::endl;
    rand.destroy();

    Random rand2{true};
    std::cout << rand2.next() << std::endl;
    rand2.destroy();

    return 0;
}
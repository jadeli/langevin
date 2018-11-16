// LANGEVIN: 
// Copyright@2018 Yao, Li CCNU

#include <iostream>
#include "../include/avatar.h"

namespace langevin {
namespace {

}

Avatar::Avatar()
    :rand(RandomType::RANLXS0) {
}

Avatar::~Avatar() = default;

void Avatar::run() {
    std::cout << "----Avatar Begin----" << std::endl;


    std::cout << "----Avatar Done!----" << std::endl;
    rand.destroy();
}

}
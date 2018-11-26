// LANGEVIN: 
// Copyright@2018 Yao, Li CCNU

#include <iostream>
#include "../include/avatar.h"
#include "../include/util.h"
#include "../include/input.h"

namespace langevin {

namespace {

constexpr int PARTICLES_NUM = 42399;

}

Avatar::Avatar() {
}                                                                                                                                                                                  

Avatar::~Avatar() = default;

void Avatar::run() {
    std::cout << "----Avatar Begin----" << std::endl;

    Sample sample(RandomType::RANLXS0);
    ParticleArrayPtr particles(sample.getParticles(PARTICLES_NUM));

    Grid probGrid(boost::extents[GSM][GSE][GSJ]);
    Input::getProb(probGrid);

    Table qhatTable(boost::extents[QHAT_ROW][QHAT_COL]);
    Input::getQhat(qhatTable);

    double px, py;
    auto p = particles.get();
    for (int i = 0; i < PARTICLES_NUM; i++) {
        auto particle = *(p[i]);

        px = particle.px();
        py = particle.py();
    }


    std::cout << "----Avatar Done!----" << std::endl;
}

}
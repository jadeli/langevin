#include <gtest/gtest.h>
#include <cstring>
#include <fstream>
#include <iostream>
#include <memory>
#include "../include/nucleus.h"

using namespace langevin;

TEST(WoodsSaxonNucleus, thick) {

    const std::string species = "Pb";
    Grid grid(boost::extents[XT_NUM][Z_NUM][3]);
    char data[100];

    auto nucleus = (WoodsSaxonNucleus *) Nucleus::create(species);
    nucleus->computeNuclearThickness(grid);

    std::ofstream of;
    of.open("thickPb.dat", std::ios::out | std::ios::trunc);

//    EXPECT_NE(nullptr, of);

    for (int i = 0; i < XT_NUM; i++) {
        for (int j = 0; j < Z_NUM; j++) {
            sprintf(data, "%6.4lf\t%6.4lf\t%13.10lf\n", grid[i][j][0], grid[i][j][1], grid[i][j][2]);
            of << data;
        }
    }
    of.close();

    //auto nucleus = dynamic_cast<WoodsSaxonNucleus*>(n.release());
    //std::unique_ptr<WoodsSaxonNucleus> nucleusPtr(nucleus);
}
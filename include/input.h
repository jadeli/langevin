// LANGEVIN: 
// Copyright@2018 Yao, Li CCNU

#ifndef INPUT_H
#define INPUT_H

#include <cstring>
#include <fstream>
#include <iostream>
#include "util.h"

namespace langevin {

///hydro target for LHC
constexpr int GSX = 140;
constexpr int GSY = 140;
constexpr int GST = 172;
constexpr int GSJ = 800;
constexpr int GSE = 100;
constexpr int GSM = 100;

constexpr int QHAT_ROW = 110;
constexpr int QHAT_COL = 150;

class Input {
public:
    Input() = default;

    static void getProb(Grid& grid);
    static void getQhat(Table& table);
};

}

#endif
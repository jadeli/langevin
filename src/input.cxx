// LANGEVIN: 
// Copyright@2018 Yao, Li CCNU

#include "../include/input.h"

namespace langevin {

namespace {

}

void Input::getProb(Grid& grid) {

    char fileName[255];
    double sj, tmr, ien, prob;

    std::cout << "Loading the data of prob..." << std::endl;
    
    std::fstream input;
    for(int i = 0; i < GSJ; i++) {
        sprintf(fileName, "data/input/pro_LHC/pro0%ds", i);
        input.open(fileName, std::ios::in);
        
        if(!input) std::cout << "Can not open file: " << fileName << std::endl;
        
        for(int j = 0; j < GSM; j++) {
            for(int k = 0; k < GSE; k++) {
                input >> sj >> tmr >> ien >> prob;
                grid[j][k][i] = prob;
            }
        }
        input.close();
    }

    std::cout << "Load prob sampling done!" << std::endl;
}

void Input::getQhat(Table& table) {
    
    const std::string fileName = "data/input/qhat/qhat.dat";
    double qhie, qhtmr, qhat;

    std::cout << "Loading the data of qhat..." << std::endl;
        
    std::fstream input(fileName, std::ios::in);
    if(!input) std::cout << "Can not open file: " << fileName << std::endl;
        
    for(int i = 0; i < QHAT_COL; i++) {
        for(int j = 0; j < QHAT_ROW; j++) {
            input >> qhie >> qhtmr >> qhat;
            table[j][i] = qhat;
        }
    }
    input.close();
    
    std::cout << "Load qhat sampling done!" << std::endl;
}

}
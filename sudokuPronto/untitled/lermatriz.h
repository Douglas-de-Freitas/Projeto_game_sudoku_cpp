#ifndef LERMATRIZ_H
#define LERMATRIZ_H

#include <fstream>
#include <iostream>
#include <cctype>
#include <sstream>
#include <QString>
#include <exception>

const std::string cyan("\033[0;36m");
const std::string magenta("\033[0;35m");
const std::string green("\033[1;32m");
const std::string red("\033[0;31m");
const std::string reset("\033[0m");

#define tMat 81 //int tMat = 81;// tamanho da matriz
#define tpMat 9 //int tpMat = 9; // tipo de matriz 9x9

using namespace std;

class lerMatriz{
private:
    int **matriz;
public:
    lerMatriz();
    bool setMatriz();
    bool setMatrizCarregandoJogo();
    int getMatriz(int i, int j);
    void liberarMatriz();
    int **getMatrizCompleta();
    void colocaNaMatriz(int lin, int col, int num);
    ~lerMatriz();
};

#endif // LERMATRIZ_H

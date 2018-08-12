#ifndef TRATACOLUNA_H
#define TRATACOLUNA_H

#include "tratamatriz.h"
#include "lermatriz.h"

class trataColuna : public trataMatriz{ // <----------------------------- HERDANDO LINHA E COLUNA DA CLASSE TRATAMATRIZ -------------------------------
private:
    int numero;
    int **copia; // matriz que não pode ser mechida
    int **matrizEdita; // essa matriz é a inicial lida do arquivo e que vai ser futuramente editada
public:
    void setDados(int lin, int col, int num, int **copy, int **matrizInicial);
    bool verificaSePode();
};

#endif // TRATACOLUNA_H

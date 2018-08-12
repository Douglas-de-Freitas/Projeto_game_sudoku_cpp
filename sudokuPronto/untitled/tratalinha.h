 #ifndef TRATALINHA_H
#define TRATALINHA_H

#include "tratamatriz.h"
#include "lermatriz.h"

class trataLinha : public trataMatriz{ // <----------------------------- HERDANDO LINHA E COLUNA DA CLASSE TRATAMATRIZ -------------------------------
private:
    int numero;
    int **copia; // matriz que não pode ser mechida
    int **matrizEdita; // essa matriz é a inicial lida do arquivo e que vai ser futuramente editada
public:
    void setDados(int lin, int col, int num, int **copy, int **matrizInicial);
    bool verificaSePode();
};

#endif // TRATALINHA_H

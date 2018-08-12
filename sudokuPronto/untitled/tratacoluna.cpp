#include "tratacoluna.h"

void trataColuna::setDados(int lin, int col, int num, int **copy, int **matrizInicial){
    linha = lin;
    coluna = col;
    numero = num;
    copia = copy;
    matrizEdita = matrizInicial;
}

bool trataColuna::verificaSePode(){


    if(matrizEdita[linha][coluna] == 0){ // organiza.getMatriz(linha, coluna)
        for(int i = 0; i < 9; i++){
            if(matrizEdita[i][coluna] == numero) return false; // organiza.getMatriz(i, coluna)
        }

        return true;

    }else{

        if(copia[linha][coluna] == 0){
            for(int i = 0; i < 9; i++){
                if(matrizEdita[i][coluna] == numero) return false; // organiza.getMatriz(i, coluna)
            }

            return true;

        }else{
            return false;
        }

    }

}

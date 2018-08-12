#include "tratalinha.h"

void trataLinha::setDados(int lin, int col, int num, int **copy, int **matrizInicial){
    linha = lin;
    coluna = col;
    numero = num;
    copia = copy;
    matrizEdita = matrizInicial;
}

bool trataLinha::verificaSePode(){

    if(matrizEdita[linha][coluna] == 0){ // organiza.getMatriz(linha, i)
        for(int i = 0; i < 9; i++){
            if(matrizEdita[linha][i] == numero) return false; // organiza.getMatriz(linha, i)
        }

        return true;

    }else{

        if(copia[linha][coluna] == 0){
            for(int i = 0; i < 9; i++){
                if(matrizEdita[linha][i] == numero) return false; // organiza.getMatriz(linha, i)
            }

            return true;

        }else{
            return false;
        }

    }
}

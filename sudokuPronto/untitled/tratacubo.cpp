#include "tratacubo.h"

void trataCubo::setDados(int lin, int col, int num, int **copy, int **matrizInicial){
    linha = lin;
    coluna = col;
    numero = num;
    copia = copy;
    matrizEdita = matrizInicial;
}

bool trataCubo::verificaQuadrado(){

    if((linha >= 0 and linha <= 2) and (coluna >= 0 and coluna <= 2)){

        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                if(matrizEdita[i][j] == numero) return false;
            }
        }

        //cout << "\n entrou no 1 \n";
        return true; // ok 3


    }else if((linha >= 0 and linha <= 2) and (coluna >= 3 and coluna <= 5)){

        for(int i = 0; i < 3; i++){
            for(int j = 3; j < 6; j++){
                if(matrizEdita[i][j] == numero) return false;
            }
        }

        //cout << "\n entrou no 2 \n";
        return true; // ok 3


    }else if((linha >= 0 and linha <= 2) and (coluna >= 6 and coluna <= 8)){

        for(int i = 0; i < 3; i++){
            for(int j = 6; j < 9; j++){
                if(matrizEdita[i][j] == numero) return false;
            }
        }

        //cout << "\n entrou no 3 \n";
        return true; // ok 3


    }else if((linha >= 3 and linha <= 5) and (coluna >= 0 and coluna <= 2)){

        for(int i = 3; i < 6; i++){
            for(int j = 0; j < 3; j++){
                if(matrizEdita[i][j] == numero) return false;
            }
        }

        //cout << "\n entrou no 4 \n";
        return true; // ok 3


    }else if((linha >= 3 and linha <= 5) and (coluna >= 3 and coluna <= 5)){

        for(int i = 3; i < 6; i++){
            for(int j = 3; j < 6; j++){
                if(matrizEdita[i][j] == numero) return false;
            }
        }

        //cout << "\n entrou no 5 \n";
        return true; // ok 3


    }else if((linha >= 3 and linha <= 5) and (coluna >= 6 and coluna <= 8)){

        for(int i = 3; i < 6; i++){
            for(int j = 6; j < 9; j++){
                if(matrizEdita[i][j] == numero) return false;
            }
        }

        //cout << "\n entrou no 6 \n";
        return true; // ok 3


    }else if((linha >= 6 and linha <= 8) and (coluna >= 0 and coluna <= 2)){

        for(int i = 6; i < 9; i++){
            for(int j = 0; j < 3; j++){
                if(matrizEdita[i][j] == numero) return false;
            }
        }

        //cout << "\n entrou no 7 \n";
        return true; // ok 3


    }else if((linha >= 6 and linha <= 8) and (coluna >= 3 and coluna <= 5)){

        for(int i = 6; i < 9; i++){
            for(int j = 3; j < 6; j++){
                if(matrizEdita[i][j] == numero) return false;
            }
        }

        //cout << "\n entrou no 8 \n";
        return true; // ok 3


    }else if((linha >= 6 and linha <= 8) and (coluna >= 6 and coluna <= 8)){

        for(int i = 6; i < 9; i++){
            for(int j = 6; j < 9; j++){
                if(matrizEdita[i][j] == numero) return false;
            }
        }

        //cout << "\n entrou no 9 \n";
        return true; // ok 3


    }else{
        //cout << "\n entrou no final \n";
        return false;
    }

}

bool trataCubo::verificaSePode(){

    if(matrizEdita[linha][coluna] == 0){
        return verificaQuadrado();
    }else{
        if(copia[linha][coluna] == 0){
            return verificaQuadrado();
        }else{
            return false;
        }
    }
}

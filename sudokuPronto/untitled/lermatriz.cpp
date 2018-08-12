#include "lermatriz.h"

lerMatriz::lerMatriz(){

}

bool lerMatriz::setMatriz(){ // <----------------------------- LEITURA DE ARQUIVO -------------------------------

    string data;

    ifstream infile;
    infile.open("game.txt");

    if (infile.is_open() && infile.good()){

        // *********************** LER MATRIZ *********************** //
     int contagem = 0;

     try{ // <----------------------------- TRATAMENTO DE EXCEÇÃO E ALOCAÇÃO DINAMICA -------------------------------

             matriz = (int**) malloc(tMat * sizeof(int*));
             if(matriz == NULL) throw string("\nNão existe memória suficiente para que o programa possa continuar\nPor este motivo o programa vai ser interrompido.\n");

        }catch(string msg){
             cout << msg;
             exit(EXIT_SUCCESS);
        }

     try{ // <----------------------------- TRATAMENTO DE EXCEÇÃO E ALOCAÇÃO DINAMICA -------------------------------

             for(int i = 0; i < tMat; i++){
                 matriz[i] = (int*) malloc(tMat * sizeof(int));
                 if(matriz==NULL) throw string("\nNão existe memória suficiente para que o programa possa continuar\nPor este motivo o programa vai ser interrompido.\n");
                 else contagem+=1;
             }

        }catch(string msg){

            cout << msg;
            for(int i = 0; i < contagem; i++){
                free(matriz[i]);
            }
            free(matriz);
            exit(EXIT_SUCCESS);
        }

     contagem = 0;
     int qtdElementos = 0;
     int lin = 0;
     int col = 0;

     getline(infile,data);

     QString downToMat;

     while(!infile.eof() and qtdElementos < tMat){

         for(int i = 0; i < int(data.size()); i++){

             if(qtdElementos == tMat)break;

             if(!isspace(data[i])){
                if(isdigit(data[i])){
                    downToMat = data[i];
                    if(col >= tpMat){
                        col = 0;
                        lin+=1;
                    }
                    matriz[lin][col] = downToMat.toInt();//stoi(downToMat.str());
                    qtdElementos+=1;
                    col+=1;
             }else{
                    cout << "\nExiste caracteres não númericos no ARQUIVO favor reve-lo.\n" << "Por conter caracteres esquisitos o programa vai ser fechado!!!\n" << endl;
                    liberarMatriz(); // ----------------------------------- liberando matriz
                    return false;
             }
        }
    }

         getline(infile,data);
    }

     if(qtdElementos < tMat){
         cout << "\no arquivo está incompleto\n\n";
         liberarMatriz(); // ----------------------------------- liberando matriz
         return false;
     }

    infile.close();

    return true;

    }else{
        //liberarMatriz(); // ----------------------------------- liberando matriz
        return false;
    }



}

bool lerMatriz::setMatrizCarregandoJogo(){ // <----------------------------- LEITURA DE ARQUIVO -------------------------------

    string data;

    ifstream infile;
    infile.open("save.txt");

    if (infile.is_open() && infile.good()){

     //int matriz[tpMat][tpMat];
     int qtdElementos = 0;
     int lin = 0;
     int col = 0;

     getline(infile,data);

     QString downToMat;

     while(!infile.eof() and qtdElementos < tMat){

         for(int i = 0; i < int(data.size()); i++){

             if(qtdElementos == tMat)break;

             if(!isspace(data[i])){
                if(isdigit(data[i])){
                    downToMat = data[i];
                    if(col >= tpMat){
                        col = 0;
                        lin+=1;
                    }
                    matriz[lin][col] = downToMat.toInt();//stoi(downToMat.str());
                    qtdElementos+=1;
                    col+=1;
             }else{
                    cout << "\nExiste caracteres não númericos no ARQUIVO favor reve-lo.\n" << "Por conter caracteres esquisitos o programa vai ser fechado!!!\n" << endl;
                    //liberarMatriz(); // ----------------------------------- liberando matriz
                    return false;
             }
        }
    }

         getline(infile,data);
    }

     if(qtdElementos < tMat){
         cout << "\no arquivo está incompleto\n\n";
         //liberarMatriz(); // aqui não vai liberar a matriz pois foi criada pelo jogo e não tem como estar errada
         return false;
     }

    infile.close();

    return true;

    }else{

        return false; // retorna que não deu certo ler o arquivo ou encontra-lo
    }
}

int lerMatriz::getMatriz(int i, int j){
    return matriz[i][j];
}

void lerMatriz::liberarMatriz(){
    for(int i = 0; i < tpMat; i++){
        free(matriz[i]);
    }
    free(matriz);
}

int **lerMatriz::getMatrizCompleta(){
    return matriz;
}

void lerMatriz::colocaNaMatriz(int lin, int col, int num){
    matriz[lin][col] = num;
}

lerMatriz::~lerMatriz(){
    ifstream verificaSeFoiCriadoMatriz;
    verificaSeFoiCriadoMatriz.open("game.txt");
    if(verificaSeFoiCriadoMatriz.is_open() && verificaSeFoiCriadoMatriz.good()){
        liberarMatriz();
    }
}






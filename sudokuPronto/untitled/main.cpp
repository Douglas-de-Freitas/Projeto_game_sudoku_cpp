#include <iostream>
#include <cstdlib>
#include "lermatriz.h"
#include "tratamatriz.h"
#include "tratalinha.h"
#include "tratacoluna.h"
#include "tratacubo.h"
#include <QString>

using namespace std;

void salvarJogo(int **matriz){ // <----------------------------- GRAVAÇÃO NO ARQUIVO -------------------------------

    ofstream salvar;
    salvar.open("save.txt");

    if(salvar.is_open() && salvar.good()){
        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                if(j == 8) salvar << matriz[i][j];
                else salvar << matriz[i][j] << " ";
            }
            salvar << endl;
        }

        cout << green << "\nO jogo foi salvo com sucesso!!!\n" << reset;
    }else{
        cout << red << "\nNão foi possível salvar o jogo!!!\n" << reset;
    }

}

int main (){

     lerMatriz game;
     if(game.setMatriz()){

         trataMatriz *verifica[3];

         trataLinha tratLinha;
         trataColuna tratColuna;
         trataCubo tratCubo;

         // <----------------------------- POLIMORFISMO -------------------------------

         verifica[0] = &tratLinha;
         verifica[1] = &tratColuna;
         verifica[2] = &tratCubo;

         // <----------------------------- POLIMORFISMO -------------------------------

         int num, lin, col;
         string converte;
         bool ok, okLinha, okColuna;

         //#####################################################################################################################

         //Cria um novo tabuleiro copia
         int **matrizCopia;
         int contagem = 0;

         try{ // <----------------------------- TRATAMENTO DE EXCEÇÃO E ALOCAÇÃO DINAMICA -------------------------------

             matrizCopia = (int **) malloc(9 * sizeof(int*));
             if(matrizCopia==NULL)throw string("\nNão existe memória suficiente para que o programa possa continuar\nPor este motivo o programa vai ser interrompido.\n");

         }catch(string msg){

             cout << msg;
             exit(EXIT_SUCCESS);

         }

         try{ // <----------------------------- TRATAMENTO DE EXCEÇÃO E ALOCAÇÃO DINAMICA -------------------------------

             for(int i = 0; i < 9; i++){

                 matrizCopia[i] = (int*) malloc(9 * sizeof(int));
                 if(matrizCopia==NULL)throw string("\nNão existe memória suficiente para que o programa possa continuar\nPor este motivo o programa vai ser interrompido.\n");
                 else contagem+=1;

             }

         }catch(string msg){

             cout << msg;
             for(int i = 0; i < contagem; i++){
                 free(matrizCopia[i]);
             }
             free(matrizCopia);
             exit(EXIT_SUCCESS);

         }

         contagem = 0;

         // Copia as informações do tabuleiro existente para o que foi criado para que as informaões não sejam alteradas
         for(int i = 0; i < 9; i++){
             for(int j = 0; j < 9; j++){
                 matrizCopia[i][j] = game.getMatriz(i,j);
             }
         }
         //#####################################################################################################################

         for(int i = 0; i < 9; i++){
             if(i==0)cout << "  -----------------------------------" << endl;
             if(i==3 or i == 6)cout << green << "  ----------- ----------- -----------" << reset << endl;
             for(int j = 0; j < 9; j++){
                 if(j==0)cout << " | ";
                 if(game.getMatriz(i,j) == 0) cout << " ";
                 else cout << game.getMatriz(i,j);
                 if(j==2 or j == 5)cout << green << " | " << reset;
                 else cout << " | ";
             }
             cout << endl;
             if(i != 2 and i != 5)cout << "  -----------------------------------";
             cout << endl;
         }

         while(true){

             do{

             cout << magenta;
             cout << "-Digite um número de 1 a 9 para inserir no jogo\n";
             cout << "-Digite 0 para apagar uma linha/coluna\n";
             cout << "-Digite qualquer coisa na inserção do número para sair\n" << reset;

             cout << "\nS salvar, C carregar jogo salvo ou Digite um número para colocar no jogo: ";
             cin >> converte;

             while(converte == "s" or converte == "S" or converte == "c" or converte == "C"){

                 if(converte == "s" or converte == "S"){ // <-------------- Aqui salva o jogo
                     salvarJogo(game.getMatrizCompleta());
                     cout << "\nS salvar, C carregar jogo salvo ou Digite um número para colocar no jogo: ";
                     cin >> converte;
                 }

                 if(converte == "c" or converte == "C"){ // <----------------------------- LEITURA DE ARQUIVO -------------------------------
                     if(game.setMatrizCarregandoJogo()){
                         cout << green << "\nJogo carregado com sucesso!!!\n" << reset;
                         for(int i = 0; i < 9; i++){
                             if(i==0)cout << "  -----------------------------------" << endl;
                             if(i==3 or i == 6)cout << green << "  ----------- ----------- -----------" << reset << endl;
                             for(int j = 0; j < 9; j++){
                                 if(j==0)cout << " | ";
                                 if(game.getMatriz(i,j) == 0) cout << " ";
                                 else cout << game.getMatriz(i,j);
                                 if(j==2 or j == 5)cout << green << " | " << reset;
                                 else cout << " | ";
                             }
                             cout << endl;
                             if(i != 2 and i != 5)cout << "  -----------------------------------";
                             cout << endl;
                         }

                         cout << "\nS salvar, C carregar jogo salvo ou Digite um número para colocar no jogo: ";
                         cin >> converte;

                     }else{
                         cout << red << "\nNão foi possivel carregar o seu jogo, verifique se existe jogo salvo.\n" << reset;
                         cout << "\nS salvar, C carregar jogo salvo ou Digite um número para colocar no jogo: ";
                         cin >> converte;
                     }
                 }
             }

             num = QString::fromStdString(converte).toInt(&ok);
             if(!ok) exit(EXIT_SUCCESS);

             if(num < 0 or num > 9) exit(EXIT_SUCCESS);

             cout << "\nDigite a linha que deseja colocar este número: ";
             cin >> converte;

             lin = QString::fromStdString(converte).toInt(&ok);
             if(!ok) okLinha = false;
             else okLinha = true;

             cout << "\nDigite a coluna que deseja  colocar este número: ";
             cin >> converte;

             col = QString::fromStdString(converte).toInt(&ok);
             if(!ok) okColuna = false;
             else okColuna = true;

             if(num == 0){
                 if((lin >= 0 and lin <= 8) and (col >= 0 and col <= 8)){

                     if(matrizCopia[lin][col] == 0){

                        game.colocaNaMatriz(lin, col, num);

                     }else{
                         cout << red << "\n\nVocê não pode apagar o elemento escolhido.\n\n" << reset;
                     }

                     for(int i = 0; i < 9; i++){
                         if(i==0)cout << "  -----------------------------------" << endl;
                         if(i==3 or i == 6)cout << green << "  ----------- ----------- -----------" << reset << endl;
                         for(int j = 0; j < 9; j++){
                             if(j==0)cout << " | ";
                             if(game.getMatriz(i,j) == 0) cout << " ";
                             else cout << game.getMatriz(i,j);
                             if(j==2 or j == 5)cout << green << " | " << reset;
                             else cout << " | ";
                         }
                         cout << endl;
                         if(i != 2 and i != 5)cout << "  -----------------------------------";
                         cout << endl;
                     }

                 }
             }

             if(((lin < 0 or lin > 8) or (col < 0 or col > 8)) or (okLinha == false or okColuna == false)){
                 cout << red << "\nPossiveis erros:\n"
                                "Coluna maior do que 8 ou menor do que 0.\n"
                                "Linha maior do que 8 ou menor do que 0.\n"
                                "Número maior do que 9 ou menor do que 1.\n\n" << reset;
             }


             }while((num < 1 or num > 9) or ((lin < 0 or lin > 8) or (col < 0 or col > 8)) or (okLinha == false or okColuna == false)); // <-- aqui foi modificado para teste


             tratLinha.setDados(lin, col, num, matrizCopia, game.getMatrizCompleta());
             tratColuna.setDados(lin, col, num, matrizCopia, game.getMatrizCompleta());
             tratCubo.setDados(lin, col, num, matrizCopia, game.getMatrizCompleta());

             //verifica[0] = &tratLinha;
             //verifica[1] = &tratColuna;
             //verifica[2] = &tratCubo;

    /* -- este comentario esta ocuto
             if(verifica[0]->verificaSePode()) cout << "\nOK!! Você pode inserir nesta linha\n";
             else cout << "\nErro! Você não pode inserir nesta linha\n";

             if(verifica[1]->verificaSePode()) cout << "\nOK!! Você pode inserir nesta coluna\n";
             else cout << "\nErro! Você não pode inserir nesta coluna\n";

             if(verifica[2]->verificaSePode()) cout << "\nOK!! Você pode inserir no cubo\n";
             else cout << "\nErro! Você não pode inserir no cubo\n";*/


             // ########################################### POLIMORFISMO ###########################################

             if(verifica[0]->verificaSePode() && verifica[1]->verificaSePode() && verifica[2]->verificaSePode()){
                 game.colocaNaMatriz(lin, col, num);

             }else{
                 cout << red << "\n\nErro! Você não pode inserir este número neste local\n\n" << reset;
             }

             // ########################################### POLIMORFISMO ###########################################

             cout << endl;

             for(int i = 0; i < 9; i++){
                 if(i==0)cout << "  -----------------------------------" << endl;
                 if(i==3 or i == 6)cout << green << "  ----------- ----------- -----------" << reset << endl;
                 for(int j = 0; j < 9; j++){
                     if(j==0)cout << " | ";
                     if(game.getMatriz(i,j) == 0) cout << " ";
                     else cout << game.getMatriz(i,j);
                     if(j==2 or j == 5)cout << green << " | " << reset;
                     else cout << " | ";
                 }
                 cout << endl;
                 if(i != 2 and i != 5)cout << "  -----------------------------------";
                 cout << endl;
             }

             bool fim = true;


             for(int i = 0; i < 9; i++){
                 for(int j = 0; j < 9; j++){
                     if(game.getMatriz(i,j) == 0){

                         fim = false;
                         break;
                     }
                 }
             }

             if(fim){
                 break;
             }



         }

         cout << green << "\nO jogo terminou\n" << reset;

         for(int i = 0; i < 9; i++){
             free(matrizCopia[i]);
         }
         free(matrizCopia);


     }else{
         cout << red << "Verifique, pois o arquivo não abriu, possíveis problemas:\n"
                        "1- Pode haver caracteres não numericos no arquivo\n"
                        "2- Pode não haver a quantidade de numeros suficientes para completar a matriz.\n"
                        "3- O arquivo game.txt pode não existir\n\n" << reset;
     }

    return 0;
}

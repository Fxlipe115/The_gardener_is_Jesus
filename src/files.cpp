#include "./../lib/bst.h"
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

template <class Tree>
int readFile(string FILE_PATH, Tree *arv){
    /*
     Lê o arquivo e já insere no tipo de árvore desejado.
     
    In:
        FILE_PATH:string = caminho para o arquivo;
        *arv:Tree = ponteiro para o tipo de árvore a ser inserida;
    Out:
        int = 0 - Sucesso;
              1 - Erro ao abrir arquivo;
     */
    ifstream arq(FILE_PATH);
    if(arq.is_open()){
        string file_content;

        //Itera por todas as linhas
        while(getline(arq, file_content)) 
            // Insere o valor na árvore
            arv->insert(stoi(file_content, nullptr, 10));
        arq.close();
        return 0;
    }
    else
        return 1;
}

int main(void){
    /*
     Testing purposes.
     */
    string FILE_PATH = "./../files/sorted/n100sorted.txt";
    graeff_zachow::Bst abp;

    if(int erro = readFile<graeff_zachow::Bst>(FILE_PATH, &abp))
        return 1;
    else
        return 0;
}

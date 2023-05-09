#include<stdio.h>
#include<stdlib.h>

typedef struct celula {
    int dado;
    struct celula *prox;
} celula;

celula *busca (celula *le, int x){
    /* Uma função que procura pela primeira ocorrência do elemento x na
    lista encadeada e devolve um ponteiro para a célula que o contém. */ 
    if(le->prox == NULL){
        return NULL;
    } 

    celula *pAux = (celula*)malloc(sizeof(celula));
    pAux = le->prox;

    while (pAux != NULL){
        if(pAux->dado == x){
            return pAux;
        }
        pAux = pAux->prox;
    }
    
};

celula *busca_rec (celula *le, int x){
    if(le == NULL){
        return NULL;
    }
    if(le->dado == x){
        return le;
    }

    le = le->prox;
    busca_rec(le,x);
};

// int main (){
//     celula *le = (celula*)malloc(sizeof(celula));
//     le->prox = NULL;

//     celula *nova = (celula*)malloc(sizeof(celula));
//     nova->dado = 5;
//     nova->prox = NULL;
//     le->prox = nova;

//     celula *pos = (celula*)malloc(sizeof(celula));
//     pos->dado = 6;
//     pos->prox = NULL;
//     nova->prox = pos;

//     celula *num = (celula*)malloc(sizeof(celula));
//     num = busca(le, 0);

//     return 0;
// }
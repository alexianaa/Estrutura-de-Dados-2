#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
    int dado;
    struct celula *prox;
} celula;

void imprime (celula *le) {
    for(;le->prox != NULL; le = le->prox){
        printf("%d -> ", le->prox->dado);
    }
    printf("NULL\n");
};

void insere_inicio (celula *le, int x){
    // cria novo no
    celula *nova;
    nova = (celula*)malloc(sizeof(celula));

    // aloca numero em dado e prox da nova aponta para prox de le
    nova->dado = x;
    nova->prox = le->prox;

    // le agora aponta para nova
    le->prox = nova;
};

void insere_antes (celula *le, int x, int y){
    // cria novo no e no auxiliar
    celula *nova, *pAux;
    nova = (celula *)malloc(sizeof(celula));

    // aloca dado e inicia no auxiliar em le->prox
    nova->dado = x;
    pAux = le->prox;

    if(pAux == NULL){ // se o no for vazio
        nova->prox = NULL;
        le->prox = nova;
        return;
    }

    while (pAux->prox != NULL){ // enquanto nao encontra o numero vai andando pela lista
        if(pAux->prox->dado == y){ // se encontrar adiciona antes do y e sai da funcao
            nova->prox = pAux->prox; 
            pAux->prox = nova;
            return;
        }
        pAux = pAux->prox; // caso nao, continua pela lista
    } 

    // caso chegue ao final da lista sem encontrar o numero adicona no final
    pAux->prox = nova;
    nova->prox = NULL;
    
};

// int main () {
//     celula *le = (celula*)malloc(sizeof(celula));
//     le->prox = NULL;

//     insere_inicio(le, 3);
//     insere_inicio(le, 7);
//     // insere_inicio(le, 8);
//     insere_antes(le,5,3);

//     imprime(le);

//     return 0;
// }

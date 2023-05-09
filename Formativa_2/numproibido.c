#include <stdio.h>
#include <stdlib.h>

#define M 13 

typedef struct celula{
    int chave, numProibido;
    struct celula *prox;
} celula;
celula th[M];

int hash (int chave) {
    return chave % M;
}

void inicializa_hash(celula *th){
    for(int i = 0; i < M; i++) th[i].prox = NULL;
}

void insere_hash(celula *th, int chave, int numProibido){
    int pos = hash(chave);
    celula *elem;
    for(elem = th[pos].prox; elem != NULL && elem->chave != chave; elem = elem->prox); 
    if(elem == NULL){
        celula *nova = malloc(sizeof(celula));
        nova->chave = chave;
        nova->numProibido = numProibido;
        nova->prox = th[pos].prox;
        th[pos].prox = nova;
    }
    
}

void confere(celula *th, long int numProibido){
    // ver se tem o numero na tabela hash
    // passar por cada posicao
    // ir ate o null de cada lista
    int pos = hash(numProibido);
    celula *nova = malloc(sizeof(celula));
    nova = th;

    while(th[pos].prox != NULL){
        if(nova[pos].prox->numProibido == numProibido){
            printf("sim\n");
            free(nova);
            return;
        }
        nova[pos].prox = nova[pos].prox->prox;
    }

    free(nova);
    printf("nao\n");
    return;
}

int main() {
    int num;
    long int numProibido;
    inicializa_hash(th);

    scanf("%d",&num);

    for(int i = 0; i < num; i++){
        scanf("%ld",&numProibido);
        insere_hash(th, numProibido, numProibido);
    }

    while(numProibido != EOF){
        scanf("%ld",&numProibido);
        //printf("%ld",numProibido);
        confere(th,numProibido);
    }

    return 0;
}
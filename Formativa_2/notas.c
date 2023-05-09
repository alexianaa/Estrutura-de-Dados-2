#include <stdio.h>
#include <stdlib.h>

#define M 13 // 1001

typedef struct celula{
    int chave, nota, ocorr;
    struct celula *prox;
} celula;
celula th[M];

int hash (int chave) {
    return chave % M;
}

void inicializa_hash(celula *th){
    for(int i = 0; i < M; i++) th[i].prox = NULL;
}

void insere_hash(celula *th, int chave, int nota){
    int pos = hash(chave);
    celula *elem;
    for(elem = th[pos].prox; elem != NULL && elem->chave != chave; elem = elem->prox); 
    if(elem != NULL){
        elem->ocorr++; 
    } 
    else {
        celula *nova = malloc(sizeof(celula));
        nova->chave = chave;
        nova->nota = nota;
        nova->ocorr = 1;
        nova->prox = th[pos].prox;
        th[pos].prox = nova;
    }
    
}

int busca_maiorOcorr (celula *th){
    // comparar as ocorrencias 
    celula *maior;
    int chave;
    // aloca um numero como o maior da lista
    for(int i = 0; i < M;i++){
        if(th[i].prox != NULL){
            maior = th[i].prox; 
            break;
        }
    }

    // anda pela tabela hash vendo se tem um numero maior
    for(int i = 0; i<M;i++){
        while(th[i].prox != NULL){
            if(th[i].prox->ocorr > maior->ocorr) {
                maior = th[i].prox;
                chave = i;
            } else if (th[i].prox->ocorr == maior->ocorr){ // se a ocorrencia for igual guarda a maior nota
                if(th[i].prox->nota > maior->nota){
                    maior = th[i].prox;
                }
            }
            th[i].prox = th[i].prox->prox;
        }
    }

    return maior->nota;
}

int main() {
    int entrada;
    inicializa_hash(th);

    int num;
    scanf("%d",&num);

    for(int i = 0; i < num; i++){
        scanf("%d",&entrada);
        insere_hash(th,entrada,entrada);
    } 

    printf("%d",busca_maiorOcorr(th));
    return 0;
}
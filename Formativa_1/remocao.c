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

int remove_depois (celula *p){
    if(p->prox != NULL){
        celula *nova = (celula*)malloc(sizeof(celula));
        nova = p->prox;
        p->prox = nova->prox;
        free(nova);
    }

    return 1;
};

void remove_elemento (celula *le, int x){
    celula *pAux = (celula*)malloc(sizeof(celula));
    pAux = le->prox;

    if(pAux->dado == x){ // caso seja o apos a cabeca
        remove_depois(le);
        return;
    }

    while (pAux != NULL){
        if(pAux->prox->dado == x){
            celula *lixo = (celula*)malloc(sizeof(celula));
            lixo = pAux->prox;
            pAux->prox = lixo->prox;
            free(lixo);
            return;
        }else{
            pAux = pAux->prox;
        };
    };
    

};

void remove_todos_elementos (celula *le, int x){
    celula *pAux = (celula*)malloc(sizeof(celula));
    celula *lixo = (celula*)malloc(sizeof(celula));
    pAux = le->prox;

    // caso esteja no comeco
    while(pAux->dado == x){
        lixo = le->prox;
        le->prox = lixo->prox;
        pAux = le->prox;
        free(lixo);
        if(pAux == NULL){
            return;
        }
    }

    // caso esteja no meio ou final
    while(pAux != NULL){
        
        if(pAux->prox == NULL){
            return;
        };

        if(pAux->prox->dado == x){
            lixo = pAux->prox;
            pAux->prox = lixo->prox;
            free(lixo);
        }
        
        pAux = pAux->prox;
    }
    
};

// int main () {
//     celula *le = (celula*)malloc(sizeof(celula));
//     le->prox = NULL;

//     celula *nova, *pos, *ter;
//     nova = (celula*)malloc(sizeof(celula));
//     nova->dado = 2;
//     nova->prox = le->prox;
//     le->prox = nova;

//     pos = (celula*)malloc(sizeof(celula));
//     pos->dado = 0;
//     pos->prox = nova->prox;
//     nova->prox = pos;

//     ter = (celula*)malloc(sizeof(celula));
//     ter->dado = 0;
//     ter->prox = pos->prox;
//     pos->prox = ter;

//     remove_todos_elementos(le,2);

//     imprime(le);

//     return 0;
// }

#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
    int dado;
    struct celula *prox;
} celula;

void mescla_listas (celula *l1, celula *l2, celula *l3){
    // andar pelas listas 1 e 2 
    l1 = l1->prox;
    l2 = l2->prox;
    
    // compara os valores de cada o menor valor vai para l3
    while(l1 != NULL && l2 != NULL){

        if(l1->dado < l2->dado){
            l3->prox = l1;
            l1 = l1->prox; // anda a lista no qual o valor foi selecionado
        }else{
            l3->prox = l2;
            l2 = l2->prox;
        }

        l3 = l3->prox; // anda l3

    }

    // caso l1 tenha acabado l3 e o resto de l2
    while (l1 != NULL) {
        l3->prox = l1;
        l1 = l1->prox;
        l3 = l3->prox;
    }
    
    // caso l2 tenha acabado l3 e o resto de l1
    while (l2 != NULL) {
        l3->prox = l2;
        l2 = l2->prox;
        l3 = l3->prox;
    }

};

// void insere_inicio (celula *le, int x){
//     // cria novo no
//     celula *nova;
//     nova = (celula*)malloc(sizeof(celula));

//     // aloca numero em dado e prox da nova aponta para prox de le
//     nova->dado = x;
//     nova->prox = le->prox;

//     // le agora aponta para nova
//     le->prox = nova;
// };

// void imprime (celula *le) {
//     for(;le->prox != NULL; le = le->prox){
//         printf("%d -> ", le->prox->dado);
//     }
//     printf("NULL\n");
// };

// int main (){
//     celula *l1 = (celula*)malloc(sizeof(celula));
//     l1->prox = NULL;

//     celula *l2 = (celula*)malloc(sizeof(celula));
//     l2->prox = NULL;
//     insere_inicio(l2,8);
//     insere_inicio(l2,3);
//     insere_inicio(l2,2);

//     celula *l3 = (celula*)malloc(sizeof(celula));
//     l3->prox = NULL;

//     imprime(l1);
//     imprime(l2);
//     mescla_listas(l1,l2,l3);
//     imprime(l3);

//     return 0;
// }
#include <stdlib.h>
#include <stdio.h>
#include "decimalBinario.h"

//TAD Cell

struct celula{
    int item;
    Cell *next;
};

Cell* criar_nova_celula(int num){
    Cell *a;

    a = (Cell*) malloc(sizeof(Cell));

    a->item = num;
    a->next = NULL;

    return a;
}

int acessar_valor(Cell *a){
   return a->item;
}

void liberar_cell(Cell *a){
    if(a!=NULL){
        free(a);
    }
}

//TAD pilha

struct pilha{
    Cell *topo;
};

PilhaEncadeada* criar_nova_pilha_encadeada(){
    PilhaEncadeada *a;

    a = (PilhaEncadeada*) malloc(sizeof(PilhaEncadeada));

    a->topo = NULL;

    return a;
}

int verifica_se_pilha_vazia(PilhaEncadeada *a){
    if(a==NULL){
        return -1;
    }
    else if(a->topo == NULL){
        return 1;
    }
    else{
        return 0;
    }
}

int empilhar_item(PilhaEncadeada *a, int num){
    Cell *novo;

    if(a!=NULL){
        novo = criar_nova_celula(num);

        novo->next = a->topo;
        a->topo = novo;

        return 1;
    }
    return 0;
}

int desenpilhar_item(PilhaEncadeada *a){
    Cell *retirado;
    int item;

    if(verifica_se_pilha_vazia(a)!=1&&verifica_se_pilha_vazia(a)!=-1){
        retirado = a->topo;
        a->topo = retirado->next;

        item = retirado->item;

        free(retirado);
    }
    return item;
}

Cell* teste_desenpilhar_cell_pilha(PilhaEncadeada *a){
    Cell *retirado;

    if(verifica_se_pilha_vazia(a)!=1&&verifica_se_pilha_vazia(a)!=-1){
        retirado = a->topo;

        a->topo = retirado->next;

        retirado->next = NULL;
    }
    return retirado;
}

void imprimir_conteudo_pilha(PilhaEncadeada *a){
    Cell *aux;

    if(verifica_se_pilha_vazia(a)!=1 && verifica_se_pilha_vazia(a)!=-1){
        aux = a->topo;

        while(aux!=NULL){
            printf("%d\n", aux->item);

            aux = aux->next;
        }
    }
}

void teste_imprimir_conteudo_pilha(PilhaEncadeada *a){
    Cell *aux;
    int cont = 0;

    if(verifica_se_pilha_vazia(a)!=-1 && verifica_se_pilha_vazia(a)!=1){
        aux = a->topo;

        while(aux!=NULL){
            printf("Elemento[%d] -> endereco: %d / valor: %d\n", cont, aux, aux->item);
            cont += 1;
            aux = aux->next;
        }
    }
}

int liberar_pilha(PilhaEncadeada *a){
    Cell *aux;

    if(a!=NULL){
        if(verifica_se_pilha_vazia(a)==1){
            free(a);
            return 1;
        }
        else{
            aux = a->topo;
            while(aux!=NULL){
                a->topo = aux->next;

                free(aux);

                aux = a->topo;
            }
            free(a);
            return 1;
        }
    }
    return 0;
}

int cont_elementos_pilha(PilhaEncadeada *a){
    Cell *aux;
    int cont = 0;

    if(verifica_se_pilha_vazia(a)!=1 && verifica_se_pilha_vazia(a)!=-1){
        aux = a->topo;
        while(aux!=NULL){
            cont += 1;
            aux = aux->next;
        }
        return cont;
    }
    return -1;
}

int teste_empilhar_cell(PilhaEncadeada *a, Cell *b){
    if(a!=NULL && b!=NULL){
        b->next = a->topo;
        a->topo = b;

        return 1;
    }
    return 0;
}

char* converter_int_para_binario(int inteiro){
    PilhaEncadeada *conversor;
    char *stringSaida;
    int i = 0;

    conversor = criar_nova_pilha_encadeada();

    while(inteiro!=0){
        empilhar_item(conversor, inteiro%2);
        inteiro /= 2;
    }

    stringSaida = (char*)malloc((cont_elementos_pilha(conversor) + 1) * sizeof(char));

    while(verifica_se_pilha_vazia(conversor)!=1){
        stringSaida[i] = '0' + desenpilhar_item(conversor);
        i += 1;
    }

    stringSaida[i] = '\0';

    liberar_pilha(conversor);

    return stringSaida;
}


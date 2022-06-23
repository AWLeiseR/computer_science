#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
    void *item;
    struct Node *prox;
} Node_t;

typedef struct Fila
{
    struct Node *ini;
    struct Node *fim;
}Fila_t;

Fila_t *fila_create()
{
    Fila_t *fila = (Fila_t*) calloc(1, sizeof(Fila_t));
    return fila;
}
void fila_insert(Fila_t *fila, void *item)
{
    Node_t *node = (Node_t*) calloc(1, sizeof(Node_t));
    node->item = item;
    if(fila->fim == NULL)
    {
        fila->ini = node;
        fila->fim = node;
        return;
    }
    fila->fim->prox = node;
    fila->fim = node;
    return;
}
void *fila_delete(Fila_t *fila)
{
    if(fila->ini == NULL)
        return NULL;
    if(fila->ini == fila->fim)
    {
        void *tmp = fila->ini->item;
        free(fila->ini);
        fila->ini = NULL;
        fila->fim = NULL;
        return tmp;
    }
    Node_t *aux = fila->ini;
    fila->ini = fila->ini->prox;
    void *tmp = aux->item;
    free(aux);
    return tmp;
}

int lista_empty(Fila_t *fila)
{
    return (fila->ini == NULL)?1:0;
}

int main()
{
    Fila_t *fila = fila_create();
    if(lista_empty(fila))
        printf("\nA fila eh vazia");
    else
        printf("\nA fila nao eh vazia");
    int x = 10;
    fila_insert(fila, &x);
    if(lista_empty(fila))
        printf("\nA fila eh vazia");
    else
        printf("\nA fila nao eh vazia");
    int y = 20;
    fila_insert(fila, &y);
    int *p;
    p = fila_delete(fila);
    printf("\n%d", *p);
    p = fila_delete(fila);
    printf("\n%d", *p);
    if(lista_empty(fila))
        printf("\nA fila eh vazia");
    else
        printf("\nA fila nao eh vazia");
    return 0;
}
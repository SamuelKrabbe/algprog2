#include <stdio.h>
#include <stdlib.h>
 
typedef struct cel {
    int chave;
    struct cel *prox;
} celula;

// void enfileiraS(celula *i, celula *f, int x) 
// {
//     celula *nova;
//     nova = (celula *)malloc(sizeof(celula));

//     nova->chave = x;
//     nova->prox = NULL;

//     i = nova;
//     f = nova;
// }

void enfileira_enc_C(celula *i, celula *f, int x)
{
    celula *nova;
    nova = (celula *) malloc(sizeof (celula));
    nova->chave = x;
    nova->prox = NULL;
    f->prox = nova;
    f = nova;
}


int main(){
    celula *i, *f;
    int x = 2;

    i = (celula *) malloc(sizeof (celula));
    f = i;
    
    enfileira_enc_C(i ,f , x);
    printf("%d\n", f->chave);

    free(f);

}

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#define dormir Sleep(1000);

typedef struct no{
    struct no *esq;
    struct no *dir;
    int valor;
}no;

void criaArvVaz(no **raiz){
    *raiz= (no*)malloc(sizeof(no));
    if(*raiz!=NULL){
        *raiz=NULL;
    printf("Arvore criada com sucesso!\n");
    }
}

void inserirNo(no **raiz,int elemento){
    if(*raiz == NULL){
        no *aux= (no *)malloc(sizeof(no));
        aux->valor= elemento;
        aux->dir = aux->esq = NULL;
        *raiz = aux;
        printf("Elemento %d foi inserido na arvore.\n",elemento);
        dormir;
        return;
    }

    if (elemento < (*raiz)->valor){
        inserirNo(&(*raiz)->esq,elemento);
        return;
    }

    if (elemento > (*raiz)->valor){
        inserirNo(&(*raiz)->dir,elemento);
        return;
    }
    printf("Elemento %d ja existe na arvore.\n",elemento);
    dormir;
}

no *DoisFilhos(no *root){
    if(root==NULL)
        return NULL;
    else if(root->esq == NULL)
        return root;
    else
        return DoisFilhos(root->esq);
}

void removerNo(no **raiz,int elemento){

    if(elemento < (*raiz)->valor){
        removerNo(&(*raiz)->esq,elemento);
    }
    else if(elemento > (*raiz)->valor){
        removerNo(&(*raiz)->dir,elemento);
    }
    else if((*raiz)->esq!=NULL && (*raiz)->dir!=NULL){
        no *aux= NULL;
        aux= DoisFilhos((*raiz)->dir);
        (*raiz)->valor = aux->valor;
        removerNo(&(*raiz)->dir,(*raiz)->valor);
    }
    else{
        no *aux = (*raiz);
        if((*raiz)->esq==NULL){
            (*raiz) = (*raiz)->dir;
        }
        else{
            *raiz = (*raiz)->esq;
        }
        free(aux);
    printf("Item removido com sucesso.\n");
    }
}

void excluiArvore(no **raiz){
    if(*raiz==NULL){
        return;
    }
    else{
        excluiArvore (&(*raiz)->esq);
        excluiArvore (&(*raiz)->dir);
        free(*raiz);
        *raiz=NULL;
    }
}

void checaArvore(no *raiz){
    if((raiz)==NULL){
        printf("A arvore esta vazia!");
    }
    else{
        printf("A arvore esta cheia!");
    }
}

int checaElemento(no **raiz,int elemento){
    if (*raiz == NULL){
        return 0;
    }
    struct no *aux = *raiz;
    while(aux!=NULL){
        if(elemento == aux->valor){
            printf("Valor encontrado na arvore.\n");
            return 0;
        }
        if(elemento > aux->valor){
            aux= aux->dir;
        }
        else{
            aux= aux->esq;
        }
    }
printf("Valor nao encontrado na arvore.");
}

void pesquisaOrdem(no *raiz){
    if(raiz == NULL)
        return;
    pesquisaOrdem(raiz->esq);
    printf("%d ",raiz->valor);
    pesquisaOrdem(raiz->dir);
}

void pesquisaPosOrdem(no *raiz){
    if(raiz == NULL)
        return;
    pesquisaPosOrdem(raiz->esq);
    pesquisaPosOrdem(raiz->dir);
    printf("%d ",raiz->valor);
}

void pesquisaPreOrdem(no *raiz){
    if(raiz == NULL)
        return;
    printf("%d ",raiz->valor);
    pesquisaPreOrdem(raiz->esq);
    pesquisaPreOrdem(raiz->dir);
}

void inserir(no **raiz){
int valor;
while (1){
    system("cls");
    printf("Digite um valor a ser inserido, -1 pra encerrar\n");
    printf("Valor: ");
    scanf("%d", &valor);
    if (valor == -1){
        break;
    }
    inserirNo(&(*raiz), valor);
    }
}

int main(){
    no *arvore;
    int escolha, valor;
    while(1){
        printf("\nMenu principal - Arvore Binaria de busca\n");
        printf("\n1)Criar uma arvore vazia\n");
        printf("\n2)Verificar se a arvore esta vazia\n");
        printf("\n3)Inserir um item\n");
        printf("\n4)Consultar um item na arvore\n");
        printf("\n5)Remover um item da arvore\n");
        printf("\n6)Esvaziar arvore\n");
        printf("\n7)Pesquisa Pre-ordem\n");
        printf("\n8)Pesquisa Em ordem\n");
        printf("\n9)Pesquisa Pos-ordem\n");
        printf("\n-1)Sair do programa\n");
        scanf("%d", &escolha);
        switch(escolha){
        case 1:
            system("cls");
            criaArvVaz(&arvore);
            break;
        case 2:
            system("cls");
            checaArvore(arvore);
            break;
        case 3:
            inserir(&(arvore));
            break;
        case 4:
            system("cls");
            printf("Digite o valor a ser consultado: ");
            scanf("%d",&valor);
            checaElemento(&arvore,valor);
            break;
        case 5:
            system("cls");
            printf("Digite o valor a ser removido: ");
            scanf("%d", &valor);
            removerNo(&arvore, valor);
            break;
        case 6:
            system("cls");
            excluiArvore(&arvore);
            printf("Arvore esvaziada com sucesso!!\n");
            break;
        case 7:
            system("cls");
            printf("Em Pre Ordem: ");
            pesquisaPreOrdem(arvore);
            getchar();
            getchar();
            break;
        case 8:
            system("cls");
            printf("Em ordem: ");
            pesquisaOrdem(arvore);
            getchar();
            getchar();
            break;
        case 9:
            system("cls");
            printf("Em Pos Ordem: ");
            pesquisaPosOrdem(arvore);
            getchar();
            getchar();
            break;
        case -1:
            return;
        default:
            printf("Digite uma opcao valida");
            break;
    }
}

    /*criaArvVaz(&arvore);
    inserirNo(&arvore,5);
    inserirNo(&arvore,7);
    inserirNo(&arvore,6);
    inserirNo(&arvore,4);
    inserirNo(&arvore,8);
    inserirNo(&arvore,3);
    printf("\n");

    checaElemento(&arvore,6);
    printf("\n");

    checaElemento(&arvore,10);
    printf("\n\n");

    printf("PreOrdem: ");
    pesquisaPreOrdem(arvore);
    printf("\n");

    printf("PosOrdem: ");
    pesquisaPosOrdem(arvore);
    printf("\n");

    printf("Ordem: ");
    pesquisaOrdem(arvore);
    printf("\n\n");

    removerNo(&arvore,7);
    printf("\n\n");

    pesquisaOrdem(arvore);
    printf("\n\n");

    excluiArvore(&arvore);
    printf("Arvore excluida!\n");
    printf("\n\n");

    checaArvore(arvore);
    printf("\n\n");*/


}

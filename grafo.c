#include <stdio.h>
#include <stdlib.h>
#include "grafo.h"

struct grafo{
    int ponderado;
    int vertices;
    int grau_max;
    int** arestas;
    float** pesos;
    int* grau;
};

/*Criando um grafo*/
Grafo* criaGrafo(int vertices,int grau_max,int ponderado){
    Grafo *gr= (Grafo*) malloc(sizeof(struct grafo));
    //Verifica se o gr é vazio, se não atribui a suas variáveis os valores que há dentro dos parâmetros
    if(gr != NULL){
        int i, j;
        gr->vertices = vertices;
        gr->grau_max = grau_max;
        gr->ponderado = (ponderado != 0)?1:0;
        gr->grau = (int*)calloc(vertices,sizeof(int));
        //Cria o vetor de arestas e um vetor com o grau máximo de cada vertice
        gr->arestas = (int**)malloc(vertices*sizeof(int*));
        for(i=0; i<vertices; i++)
            gr->arestas[i] = (int*)malloc(grau_max*sizeof(int));
        //Se o grafo é ponderado, ele faz o mesmo procedimento das arestas
        if(gr->ponderado){
            gr->pesos = (float**)malloc(vertices*sizeof(float*));
            for(j=0; j<vertices; j++)
                gr->pesos[j] = (float*)malloc(grau_max*sizeof(float));
        }
    }
    return gr;
}

/*Função para inserir uma aresta no grafo*/
int insereAresta(Grafo* gr,int orig,int dest,int digrafo,float peso){
    //Verifica que o grafo é vazio, e se a origem e o destino são válidos
    if(gr == NULL)
        return 0;
    if(orig<0 || orig >= gr->vertices)
        return 0;
    if(dest<0 || dest >= gr->vertices)
        return 0;
    //Ele atribui ao campo de grau da origem o destino, se ele for ponderado, ele faz a mesma coisa com o peso
    gr->arestas[orig][gr->grau[orig]] = dest;
    if(gr->ponderado)
        gr->pesos[orig][gr->grau[orig]] = peso;
    gr->grau[orig]++;
    //Se ele não for dígrafo, ele faz o procedimento, só que voltando, com o parametro digrafo trocado para 1, pra não repetir o processo
    if(digrafo == 0)
        insereAresta(gr,dest,orig,1,peso);
    return 1;

}

/*Função auxiliar para buscar menor caminho no grafo*/
int procuraMenorDist(float *dist,int *visitado,int NV){
    int i, menor= -1, primeiro =1;
    //Percorre todo o vetor e veritica se distância é menor ou igual a 0 e se ele ainda não foi visitado
    for(i=0; i < NV; i++){
        if(dist[i] >= 0 && visitado[i] == 0){
            //Se for o primeiro, menor recebe i e o primeiro recebe zero, se não ele compara dentro do else
            if(primeiro){
                menor = i;
                primeiro = 0;
            }else{
                if(dist[menor] > dist[i])
                    menor = i;
            }
        }
    }
    return menor;
}

/*Função para encontrar menor caminho no grafo*/
void menorCaminho(Grafo *gr,int ini,int *ant,float *dist){
    int i, cont, NV, ind, *visitado, u;
    cont = NV = gr->vertices;
    //Inicializa vetor auxiliar e seta a distancia do vetor de inicio para 0
    visitado = (int*)malloc(NV * sizeof(int));
    for(i=0; i < NV; i++){
        ant[i] = -1;
        dist[i] = -1;
        visitado[i] = 0;
    }
    dist[ini] = 0;
    //Procura menor distancia com a função auxiliar
    while(cont > 0){
        u = procuraMenorDist(dist,visitado,NV);
        if(u == -1)
            break;

        visitado[u] = 1;
        cont--;
        //para cada vertice vizinho, ind recebe essa distância, se ela for menor que zero, ele passa a ser a distância de u mais o peso
        for(i=0; i < gr->grau[u]; i++){
            ind = gr->arestas[u][i];
            if(dist[ind] < 0){
                dist[ind] = dist[u] + gr->pesos[u][i];
                printf("%d a %d\n", ini,ind);
                printf("%f\n", (dist[u] + gr->pesos[u][i]));
                ant[ind] = u;
            }else{
                //Se já existe uma distância válida, ele compara se não existe uma distância menor
                if(dist[ind] > dist[u] + gr->pesos[u][i]){
                    dist[ind] = dist[u] + gr->pesos[u][i];
                    printf(" %d a %d\n", ini,ind);
                    printf("%f\n", (dist[u] + gr->pesos[u][i]));
                    ant[ind] = u;
                }
            }
        }
    }
    free(visitado);
}






int main(){
    Grafo *gr;
    gr= criaGrafo(7,6,1);

    insereAresta(gr,1,2,0,10);
    insereAresta(gr,1,3,0,20);
    insereAresta(gr,1,4,0,11);
    insereAresta(gr,2,5,0,2);
    insereAresta(gr,3,4,0,4);
    insereAresta(gr,3,5,0,16);
    insereAresta(gr,3,6,0,6);
    insereAresta(gr,4,6,0,30);
    insereAresta(gr,5,6,0,10);

    int ant[6];
    float dist[6];
    menorCaminho(gr,1,ant,dist);

}

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//função auxiliar para preencher nosso array de inteiros.
//arry_int sera preenchido com os valores inseridos
//max_elementos quantidade maxima de elementos que o array_int pode receber
//retorna a quantidade de elementos inteiros maiores que zero foram inseridos
int criar_array(int *array_int, int max_elementos){
    int idx = 0;
    char array_str[128];
    memset(array_str, '\0', sizeof(array_str));
    char valor[16];
    char *posicao_inicio = NULL;
    char *posicao_fim = NULL;
    printf ("Informe os valores do tipo inteiros, separados por virgula\n");
    scanf ("%s", array_str);
    if (strlen (array_str) > 0){
        //posica_inicio = inicio do espaço de memória do primeiro algarismo
        posicao_inicio = array_str;
        do {
            //posicao_fim == inicio do espaço de memória da vírgula
            posicao_fim = strchr (posicao_inicio, ',');
            memset(valor,0, sizeof(valor));
            if(posicao_fim != NULL) {
                memcpy(valor, posicao_inicio,(int) (posicao_fim - posicao_inicio) );
                posicao_inicio = (posicao_fim + 1 );
            }
            else if(posicao_inicio != NULL){
                memcpy(valor, posicao_inicio,(int) strlen(posicao_inicio) );
            }
            if(strlen(valor)) {
                array_int[idx++] = atoi(valor);
            }
        } while (posicao_fim != NULL && idx < max_elementos);
    }
    printf ("ARRAY -> [" );
    for(int i=0; i<idx; ++i){
        printf ("%d", array_int[i]);
        if(i+1 < idx){
            printf(",");
        }
    }
    printf ("] \n");
    return idx;
}

//Implementação auxiliar de algoritmo de ordenação Quick Sort
void quick_sort(int* array, int inicio, int fim){
    int pivo, aux;
    int i = inicio;
    int j = fim-1;
    pivo = array[(fim - inicio)/2];
    while(i <= j){
        while(array[i] < pivo && i < fim){
            i++;
        }
        while(array[j] > pivo && j > inicio){
            j--;
        }
        if(i <= j){
            aux = array[i];
            array[i] = array[j];
            array[j] = aux;
            i++;
            j--;
        }
    }
    if(j > inicio){
        quick_sort(array, inicio, j+1);
    }
    if(i < fim){
        quick_sort(array, i, fim);
    }
    return;
}

int maximo_elementos(int valor_ref, int* array, int tamanho_array) {
    int * aux_array = malloc(tamanho_array * sizeof(int));
    int soma = 0;
    int numero_agrupamentos = 0;
    
    //Copiando os valores para um array auxiliar que será ordenado. Isso é feito para garantir a imutabilidade do array original
    for(int i = 0; i < tamanho_array; i++){
        aux_array[i] = array[i];
    }

    //ordenando array auxiliar
    quick_sort(aux_array, 0, tamanho_array);

    //com o array ordenado, é fácil encontrar o agrupamento
    for(int i = 0; i < tamanho_array; i++){
        if(soma + aux_array[i] <= valor_ref){
            soma += aux_array[i];
            numero_agrupamentos++;
        }else{
            break;
        }
    }
    return numero_agrupamentos;
}

int main () {
    const int max_elementos = 128;
    int array_int[max_elementos] ;
    int qtd_elementos = 0;
    int tamanho_array = 0;
    int valor_ref = 0;
    tamanho_array = criar_array(array_int, max_elementos);
    printf("Informe o valor para agrupamento.\n");
    scanf ("%d", &valor_ref);
    qtd_elementos = maximo_elementos(valor_ref, array_int, tamanho_array);
    printf("O numero maximo de agrupamento e [%d].\n", qtd_elementos);
    return 0;
}
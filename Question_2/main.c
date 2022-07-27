#include <stdio.h>

void calc_fatorial(int *valor_ft, int valor_n){

    //Verificação de overflow. Inteiros com sinal só aceitam valores até 2147483647.
    if(valor_n > 16){
        printf("Valor causará overflow na variável de tipo inteiro, fatorial não será calculado!\n");
        *valor_ft = -1;
        return;
    }

    int iterador_fatorial = valor_n;
    //como a ordem dos fatores não altera o produto, começo multiplicando por 1
    int valor_fatorial = 1;
    //fat(x) = x*x-1*x-2*...*1
    while(iterador_fatorial > 1){
        //O iterador começa em X e vai diminuindo até chegar em 2.
        // se o valor_n for igual à 1, não entrará na verificação, pois fat(1) = 1. O mesmo ocorre com 0;
        valor_fatorial = valor_fatorial*(iterador_fatorial);
        iterador_fatorial--;
    }
    
    *valor_ft = valor_fatorial;
    return;
}

int main() {
    int v, vf = 0;
    int *pv = &v;
    scanf("%d", &v);
    //Código não compilaria com a linha abaixo:
    //  calc_fatorial(vf, pv);
    calc_fatorial(&vf, *pv);
    if(vf != -1 ) printf("Valor fatorial de: [%d] é [%d]", v, vf);
    return 0;
}
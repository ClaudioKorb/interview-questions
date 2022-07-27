#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

/*
    Pra ser sincero, não entendi exatamente o que foi solicitado pelo enunciado.
    Fiquei em dúvida entre 2 interpretações:
     1) Se estava pedindo para realizar as operações de bitwise e encontrar qual delas retorna o maior valor;
     2) Se estava pedindo uma implementação da função MAX utilizando operações de bitwise;
    Por via das dúvidas, implementei as duas.
*/

//Faz as operações e retorna o valor da maior
int calcular_maximum_bitwise(int v1, int v2) {

    //OR
    int bit_or = v1 & v2;
    int max = bit_or;

    //AND
    int bit_and = v1 | v2;
    max = bit_and > max ? bit_and : max;

    //XOR
    int bit_xor = v1 ^ v2;
    max = bit_xor > max ? bit_xor : max;


    //Left
    int bit_left = v1 << v2;
    max = bit_left > max ? bit_left : max;

    //Right
    int bit_right = v1 >> v2;
    max = bit_right > max ? bit_right : max;

    //BitWise NOT não faria sentido entre 2 valores.
    return max;

}

//Maior entre 2 numeros usando operações de bit
int max_bitwise(int v1, int v2){
    return v1 ^((v1 ^ v2) & -(v1 < v2));
    //Se v1 < v2, -(v1 < v2) será um inteiro cheio de 1s (11111...)
    //  portanto avaliamos v1 ^ v1 ^ v2
    //  v1 ^ v1 será sempre 00000...
    //  00000... ^ v2 = v2
    //Se v1 > v2, -(v1 < v2) será um inteiro cheio de 0s (00000...)
    //  portanto, avaliamos v1 ^ (0000...) = v1
}


int main() {
    int valor_1, valor_2, maior_valor, max;
    printf("Informe os valores.\n");
    scanf("%d %d", &valor_1, &valor_2);
    //Linha abaixo causaria erro
    //  maior_valor = calculate_the_maximum(valor_1, valor_2);
    maior_valor = calcular_maximum_bitwise(valor_1, valor_2);
    max = max_bitwise(valor_1, valor_2);
    printf("O maior valor e: %d .\n", maior_valor);
    printf("O maior entre os 2 valores e: %d .\n" , max);
    return 0;
}
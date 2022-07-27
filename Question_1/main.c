#include <stdio.h>

int maior_valor(int v1, int v2, int v3, int v4){
    int max = v1;

    //v2 é maior que v1?
    max = v2 > max ? v2 : max;
    
    //v3 é maior? Se v3 for maior que o maior entre v1 e v2, será maior que v1 e v2.
    max = v3 > max ? v3 : max;

    //v4 é maior? Se v4 for maior que o maior entre v1, v2 e v3, será maior que v1, v2 e v3.
    max = v4 > max ? v4 : max;

    //Se v2, v3 e v3 não forem maiores que v1, v1 é o maior.
    return max;
}


int main() {
    int a, b, c, d;

    //Usuário poderia inserir valores inválidos com as linhas abaixo. 
    // scanf("%d %d %d %d", &a, &b, &c, &d);
    // int valor = maior_valor(a, b, c, d);
    // printf("%d", valor);

    //Melhor realizar alguma validação.
    if( scanf("%d %d %d %d", &a, &b, &c, &d) != 4){ //scanf retorna a quantidade de instancias válidas lidas.
        printf("Por favor, insira 4 digitos inteiros!");
    }else{
        int valor = maior_valor(a, b, c, d);
        printf("%d", valor);
    }

    return 0;
}
#include <stdio.h>
#include <stdlib.h>

int main(){
    int num, *vetor, num2;

    printf("digite quantas posições você deseja no vetor");
    scanf("%d", &num);

    vetor = (int *) malloc(num*sizeof(int));

    printf("digite %d números", num);
    for(int i = 0; i < num; i++){
        scanf("%d", &vetor[i]);
    }

    printf("digite um número para acher seus múltiplos digitados");
    scanf("%d", &num2);

    for(int i = 0; i < num; i++){
        if(vetor[i] % num2 == 0){
            printf("%d", vetor[i]);
        }
    }
}
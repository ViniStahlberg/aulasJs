#include <stdio.h>
#include <stdlib.h>

int main(){
    int *nums;
    nums = (int *) malloc(5*sizeof(int));

    printf("digite os 5 números:");
    for(int i = 0; i < 5; i ++){
        scanf("%d", &nums[i]);
    }

    printf("\n\n\n");

    for(int i = 0; i < 5; i ++){
        printf("%d", nums[i]);
    }

    free(nums);
}
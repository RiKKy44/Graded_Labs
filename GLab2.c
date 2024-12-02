#include <stdio.h>
#include <stdlib.h>
void print_array(int A[],int size){
    printf("[ ");
    for (int i=0;i<size-1;i++){
        printf("%d, ",A[i]);
    }
    printf("%d ",A[size-1]);
    printf("]");
}

void find_biggest_2_sum_index(int A[],int size){
    int max = A[0] + A[1];
    int sum = 0;
    int index = 0;
    if (size>=2){
        for (int i=1;i<size;i++){
        sum = A[i] + A[i-1];
        if (sum>max){
            max = sum;
            index = i-1;
        }
    }
    printf("Index: %d",index);

    }
    else{
        printf("Array is too short");
    }
}
int find_biggest_k_sum_index(int A[],int size,int k){
    int max=0;
    int sum_max = 0;
    int index = 0;
    for (int i=0;i<k;i++){
        sum_max+=A[i];
    }
    max = sum_max;
    for (int i=k;i<size;i++){
        int sum_k = 0;
        for (int j=0;j<i;j++){
            sum_k+=A[j];
        }
        if(sum_k>max){
            max = sum_k;
            index = i-k;
        }
    }
    return index;
}
void print_biggest_k_sum(int A[],int size,int k){
    int index = find_biggest_k_sum_index(A,size,k);
    int sum = 0;
    printf("[ ");
    for (int i = index;i<index + k-1;i++){
        printf("%d, ",A[i]);
    }
    printf("%d ]",A[index+k-1]);

}
void count_non_negative(int A[],int size,int Counts[]){
    for(int i=0;i<size;i++){
        Counts[A[i]]++;
    }
    printf("[");
    for(int i=0;i<14;i++){
        printf("%d ",Counts[i]);
    }
    printf("%d ]",Counts[14]);
}
int main(void){
    int A[12] = {0, 2, -3, -4, -2, 7, 6, 0, 0, 0, 12, -4};
    int Counts[15] ={0};
    count_non_negative(A,12,Counts);
}
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int len, rotations, i, j;
    scanf("%d %d", &len, &rotations);
    int *arr;
    arr = (int*)malloc(sizeof(int)*len);
    for(i=0;i<len;i++){
        scanf("%d", &arr[i]);
    }
    int temp;
    if((len/2)>=rotations){
        for(i=0;i<rotations;i++){
            temp = arr[0];
            for(j=1;j<len;j++){
                arr[j-1] = arr[j];
            }
            arr[len-1] = temp;
        }
    }
    else
    {
        for(i=0;i<len-rotations;i++){
            temp = arr[len-1];
            for(j=len-1;j>0;j--){
                arr[j] = arr[j-1];
            }
            arr[0] = temp;
        }
    }
    for(i=0;i<len;i++){
        printf("%d ", arr[i]);
    }
}

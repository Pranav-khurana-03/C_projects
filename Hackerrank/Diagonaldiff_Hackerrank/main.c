#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
   int size;
   scanf("%d", &size);
   int**arr;
   arr = (int**)malloc(sizeof(int*)*size);
   int i, j;
   for(i=0; i<size;i++)
   {
       arr[i] = (int*)malloc(sizeof(int)*size);
       for (j=0;j<size;j++)
       {
           scanf("%d", &arr[i][j]);
       }
   }
   int diagonal_sum1 = 0, diagonal_sum2 = 0, last_index = size-1;
   for(i=0; i<size;i++)
   {
       diagonal_sum1 += arr[i][i];
       diagonal_sum2 += arr[i][last_index];
       last_index -= 1;
   }
   int ans = abs(diagonal_sum1 - diagonal_sum2);
   printf("%d", ans);
}

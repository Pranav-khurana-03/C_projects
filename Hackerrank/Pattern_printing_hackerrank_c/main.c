#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int n,i,j,u_limit,l_limit,to_print, loop;
    scanf("%d", &n);
    loop= (n*2)-1;
    to_print = n;
  	for(i=0;i<loop;i++){
          to_print = n;
          if(i<(loop/2))
          {
              l_limit =i;
              u_limit =loop-i;
          }
          else
          {
              l_limit = loop-i;
              u_limit = i;
          }
          for(j=0;j<loop;j++)
          {
              printf("%d", to_print);
              if(j<l_limit)
              {
                  to_print--;
              }
              else if(j>u_limit)
              {
                  to_print++;
              }
          }
          printf("\n");
      }
}

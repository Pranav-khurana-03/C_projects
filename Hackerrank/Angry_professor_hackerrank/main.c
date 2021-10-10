#include <stdio.h>
#include <stdlib.h>

int main()
{
    int tests, strength, minimum, i, *times, present=0, j;
    scanf("%d", &tests);
    for(i=0;i<tests;i++){
        present = 0;
        scanf("%d %d", &strength, &minimum);
        times = (int*)malloc(sizeof(int)*strength);
        for(j=0;j<strength;j++){
            scanf("%d", &times[i]);
            if (times[i]<=0){
                present++;
            }
        }
        if (present<minimum){
            printf("YES\n");
        }
        else{
            printf("NO\n");
        }
    }
}

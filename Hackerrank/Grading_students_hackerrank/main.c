#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int num, i;
    scanf("%d", &num);
    int *students;
    students = (int*)malloc(sizeof(int)*num);
    for (i=0;i<num;i++){
        scanf("%d", &students[i]);
    }
    for(i=0;i<num;i++){
        if (((students[i]%5)>=3)&&(students[i]>=38)){
            students[i] = 5-(students[i]%5)+students[i];
        }
    }
    for (i=0;i<num;i++){
        printf("%d\n", students[i]);
    }
}

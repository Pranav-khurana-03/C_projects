#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int tests, i, len, j, modified=0, index_to_start, index_to_end, f;
    char temp, str[100];
    scanf("%d", &tests);
    for(i=0;i<tests;i++)
    {
        modified = 0;
        memset(str, 0, 100);
        scanf("%s", str);
        len = strlen(str);
        index_to_start = 0;
        index_to_end = len-1;

        for(j=len-2;j>=0;j--)
        {
            if (str[j]<str[index_to_end]){
                //printf("reached label 1\n");
                modified = 1;
                index_to_start = j;
                break;
            }
        }
        //printf("%d %d\n", index_to_start, index_to_end);
        for(j=index_to_end-1;j>index_to_start;j--)
        {
            for(f=j-1;f>=index_to_start;f--)
            {
                if (str[f]<str[j])
                {
                    if (modified==0){
                        if(f>=index_to_start)
                        {
                            modified= 1;
                            index_to_start = f;
                            index_to_end = j;
                            //printf("%d %d\n%c %c\n",f,j, str[f], str[j]);
                        }
                    }
                    else
                    {
                        if(f>index_to_start)
                        {
                            modified= 1;
                            index_to_start = f;
                            index_to_end = j;
                            //printf("%d %d\n%c %c\n",f,j, str[f], str[j]);
                        }
                    }
                }
            }
        }
        if (modified)
        {
            temp = str[index_to_start];
            str[index_to_start] = str[index_to_end];
            str[index_to_end] = temp;
            for(j=len-1;j>index_to_start;j--)
            {
                for(f=j-1;f>index_to_start;f--)
                {
                    if(str[f]>str[j])//how to break out of a nested for loop?
                    {
                        temp = str[f];
                        str[f] = str[j];
                        str[j] = temp;
                    }
                }
            }
            printf("%s\n", str);
        }
        else{
            printf("no answer\n");
        }
    }
}

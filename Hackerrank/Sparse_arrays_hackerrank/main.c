#include <stdio.h>
#include <stdlib.h>
#include<string.h>

int main()
{
    int string_count, query_count, *result_count, i,j;
    char **strings, **queries;
    scanf("%d %d", &string_count, &query_count);
    strings = (char**)malloc(sizeof(char*)*string_count);
    queries = (char**)malloc(sizeof(char*)*query_count);
    result_count = (int*)malloc(sizeof(int)*query_count);
    memset(result_count, 0, query_count);
    for(i=0;i<string_count;i++){
        strings[i] = (char*)malloc(sizeof(char)*20);
        scanf("%s", &strings[i][0]);
    }
    for(i=0;i<query_count;i++){
        queries[i] = (char*)malloc(sizeof(char)*20);
        scanf("%s", &queries[i][0]);
    }
    for(i=0;i<query_count;i++){
        result_count[i] = 0;
        for(j=0;j<string_count;j++){
            if (!strcmp(strings[j], queries[i])){
                    result_count[i]++;
            }
        }
        printf("%d\n", result_count[i]);
    }
}

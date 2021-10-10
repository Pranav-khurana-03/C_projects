#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main()
{
    char str[81];
    int i, len=0, row, col, x,y, char_count;
    memset(str, 0, 81);
    gets(str);
    int length = strlen(str);
    //printf("%s", str);
    for(i=0;i<length;i++){
        if (str[i]!=' '){
            //printf("%c\n", str[i]);
            len++;
        }
    }
    row = floor(sqrt(len));
    col = ceil(sqrt(len));
    //printf("%d %d", row, col);
    if ((row*col)<len){
        row++;
        //printf("%d %d", row, col);
    }
    char**arr;
    arr = (char**)malloc(sizeof(char*)*row);
    for(i=0;i<row;i++)
    {
        arr[i] = (char*)malloc(sizeof(char)*col);
        memset(arr[i], 0, col);
    }
    char_count=0;
    for(i=0;i<length;)
    {
        if (str[i]!=' ')
        {
            y= char_count/col;
            if(char_count<col)
            {
                x=char_count;
            }
            else
            {
                x = (char_count-col)%col;
            }
            arr[y][x] = str[i];
            char_count++;
        }
        i++;
    }
   for(x=0;x<col;x++)
   {
       for(y=0;y<row;y++)
       {
           if (arr[y][x])
           {
                printf("%c", arr[y][x]);
           }
       }
       printf(" ");
   }
}

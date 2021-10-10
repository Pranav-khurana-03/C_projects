#include<stdbool.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define SIZE 60

int arr[SIZE][2];

int hash(char a, bool* status)
{
    int index =  a % SIZE;
    if(arr[index][0]=='\0')
        *status = true;
    else
        *status = false;
    return index;
}

int lengthOfLongestSubstring(char * s){
    int count = 0;
    int max = 0;
    int i = 0;
    memset(arr, '\0', sizeof(char)*SIZE);
    while(s[i])
    {
        bool status;
        int index = hash(s[i], &status);
        if(!status)
        {
            count--;
            i = arr[index][1]+1;
            arr[index][0] = '\0';
            arr[index][1] = 0;
            continue;
        }
        else
        {
            arr[index][0] = s[i];
            arr[index][1] = i;
            count++;
            if(count>max)
                max = count;
        }
        i++;
    }
    return max;
}

int main()
{
    char str[] = "abcdefgjhiewiuhwedqhzbghvfgc  ghqshvwegvdyehwuh4378yrh83ehchbruiejrui4rhyf89rc__4urehf89u4r9ejcine";
    printf("%d", lengthOfLongestSubstring(str));
    char str1[] = "bbbbbb";
    printf("\n%d", lengthOfLongestSubstring(str1));
}
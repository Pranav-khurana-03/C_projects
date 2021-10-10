#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int top_right_func(int row, int col, int len){
        int top_right = 0;
        if(len-row>=len-col)
        {
            top_right = len-col;
        }
        else if(len-row<len-col)
        {
            top_right = len-row;
        }
        return row+top_right;
    }
int top_left_func(int row, int col, int len)
    {
        int top_left = 0;
        if((row==len)||(col==1))
        {
            return row;
        }
        else
        {
            if(len-row<col-0)
            {
                top_left = len-row;
                return row+top_left;
            }
            else
            {
                top_left = col-0;
                return row+top_left-1;
            }

        }
    }
int bottom_left_func(int row, int col, int len)
    {
        int bottom_left= 0;
        if(row-0>=col-0)
        {
            bottom_left = col-0;
        }
        else if(row-0<col-0)
        {
            bottom_left = row-0;
        }
        return row-bottom_left+1;
    }
int bottom_right_func(int row, int col, int len)
    {
        int bottom_right=0;
        if ((row==1)||(col==len))
        {
            return row;
        }
        else
        {
            if(row-0>len-col)
            {
                bottom_right = len-col;
                return row-bottom_right;
            }
            else
            {
                bottom_right = row-0;
                return row-bottom_right+1;
            }

        }
    }
int main()
{
    int n, obstacles, top, bottom, left, right, top_left, top_right, bottom_right, bottom_left, queen[2];
    int **obstacles_pos,i,j, mov,top_left_bool =0, top_right_bool=0, bottom_right_bool=0, bottom_left_bool=0;
    scanf("%d %d", &n, &obstacles);
    scanf("%d %d", &queen[0], &queen[1]);
    obstacles_pos = (int**)malloc(sizeof(int*)*obstacles);
    for(i=0;i<obstacles;i++)
    {
        obstacles_pos[i]=(int*)malloc(sizeof(int)*2);
        for(j=0;j<2;j++)
        {
            scanf("%d", &obstacles_pos[i][j]);
        }
    }
    top = n+1;
    bottom = 0;
    left = 0;
    right = n+1;
    top_right = top_right_func(queen[0], queen[1], n);
    top_left = top_left_func(queen[0], queen[1], n);
    bottom_left = bottom_left_func(queen[0], queen[1], n);
    bottom_right = bottom_right_func(queen[0], queen[1], n);
    if (obstacles){
        for(i=0;i<obstacles;i++)
        {
            if((obstacles_pos[i][1]==queen[1])&&(obstacles_pos[i][0]>queen[0]))//top move
            {
                if(obstacles_pos[i][0]<top){//is it closer?
                    top = obstacles_pos[i][0];
                }
            }
            else if((obstacles_pos[i][1]==queen[1])&&(obstacles_pos[i][0]<queen[0]))//bottom move
            {
                if(obstacles_pos[i][0]>bottom){//is it closer?
                    bottom = obstacles_pos[i][0];
                }
            }
            else if((obstacles_pos[i][0]==queen[0])&&(obstacles_pos[i][1]<queen[1]))//left move
            {
                if (obstacles_pos[i][1]>left)//is it closer?
                {
                    left = obstacles_pos[i][1];
                }
            }
            else if((obstacles_pos[i][0]==queen[0])&&(obstacles_pos[i][1]>queen[1]))//right move
            {
                if (obstacles_pos[i][1]<right)//is it closer?
                {
                    right = obstacles_pos[i][1];
                }
            }
            else if((abs(queen[0]-obstacles_pos[i][0]))==(abs(queen[1]-obstacles_pos[i][1])))//check for diagonal
            {
                if((obstacles_pos[i][0]>queen[0])&&(obstacles_pos[i][1]<queen[1]))//top left
                {
                    top_left_bool = 1;
                    if(obstacles_pos[i][0]<top_left)
                    {
                        top_left = obstacles_pos[i][0];
                    }
                }
                else if((obstacles_pos[i][0]>queen[0])&&(obstacles_pos[i][1]>queen[1]))//top right
                {
                    top_right_bool = 1;
                    if(obstacles_pos[i][0]<top_right)
                    {
                        //printf("top right is: %d\n\n", top_right);
                        top_right = obstacles_pos[i][0];
                    }
                }
                else if((obstacles_pos[i][0]<queen[0])&&(obstacles_pos[i][1]<queen[1]))//bottom left
                {
                    bottom_left_bool = 1;
                    if(obstacles_pos[i][0]>bottom_left)
                    {
                        bottom_left = obstacles_pos[i][0];
                    }
                }
                else if ((obstacles_pos[i][0]<queen[0])&&(obstacles_pos[i][1]>queen[1]))//bottom right
                {
                    bottom_right_bool = 1;
                    if(obstacles_pos[i][0]>bottom_right)
                    {
                        bottom_right = obstacles_pos[i][0];
                    }
                }
            }
        }
    }
    top = top-queen[0]-1;
    bottom = queen[0]-bottom-1;
    left = queen[1] - left -1;
    right = right - queen[1] -1;
    //printf("%d", top_right);
    if (top_left_bool){
        top_left = top_left-queen[0]-1;
    }
    else
    {
        top_left = top_left-queen[0];
    }
    if (top_right_bool)
    {
        top_right = top_right-queen[0]-1;
    }
    else
    {
        top_right = top_right-queen[0];
    }
    if (bottom_left_bool)
    {
        bottom_left = queen[0]-bottom_left-1;
    }
    else
    {
        bottom_left = queen[0]-bottom_left;
    }
    if (bottom_right_bool)
    {
        bottom_right = queen[0]-bottom_right-1;
    }
    else
    {
        bottom_right = queen[0]-bottom_right;
    }
    mov = top+bottom+left+right+bottom_left+bottom_right+top_left+top_right;
    printf("top: %d\nbottom: %d\nleft %d\nright: %d\ntop left: %d\ntop right: %d\nbottom left: %d\nbottom right: %d\n   ", top, bottom, left, right, top_left, top_right, bottom_left, bottom_right);
    if(n==1)
    {
        mov = 0;
    }

    printf("%d", mov);
}

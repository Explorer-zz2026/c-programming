/*先有一盘已经填满的井字棋，写一个程序判断是执O还是执X的玩家获胜*/
#include <stdio.h>
#define ROW 3
#define COLUMN 3

int main(void)
{
    int board[ROW][COLUMN];//棋盘
    int i,j;//行与列
    int X = 0, O = 0;
    int result = -1;//预设一个平局结果

    /*设置一个3*3且游戏已经结束的棋盘*/
    printf("请从按照左到右，从上到下的顺序，依次输入棋盘中每一格情况，0代表圈，1代表叉。\n");
    for(i = 0; i < ROW; i++)//依次选行（这是按照我们对二维数组先行后列的理解来的）
    {
        for(j = 0; j < COLUMN; j++)//填满这一行
        {
            scanf("%d",&board[i][j]);//把相应的情况输入到对应的位置
        }
    }

    /*检查每一行*/
    for(i = 0; i < ROW && result == -1; i++)//依次选行
    {
        X = 0, O = 0;
        for(j = 0; j < ROW; j++)//检查这一行并进行计数
        {
            if(board[i][j] == 0)
            {
                O++;
            }
            else if(board[i][j] == 1)
            {
                X++;
            }
        }

        /*某一行被X或O填满了，就对赢家进行标记*/
        if(O == ROW)
        {
            result = 0;//执O玩家获胜
        }
        else if(X == COLUMN)
        {
            result = 1;//执X玩家获胜
        }
    }

    /*检查每一列*/
    for(j = 0; j < COLUMN && result == -1; j++)//依次选列
    {
        X = 0, O = 0;
        for(i = 0; i < COLUMN; i++)//检查这一列并进行计数
        {
            if(board[i][j] == 0)
            {
                O++;
            }
            else if(board[i][j] == 1)
            {
                X++;
            }
        }

        /*某一列被X或O填满了，就对获胜玩家进行标记*/
        if(O == ROW)
        {
            result = 0;//执O玩家获胜
        }
        else if(X == COLUMN)
        {
            result = 1;//执X玩家获胜
        }
    }

    /*检查正对角线*/
    for(i = 0; i < ROW; i++)
    {
        X = 0, O = 0;
        if(board[i][i] == 0)//检查这一对角线并进行计数
        {
            O++;
        }
        else if(board[i][i] == 1)
        {
            X++;
        }

        /*正对角线被X或O填满了，就对获胜玩家进行标记*/
        if(O == ROW)
        {
            result = 0;//执O玩家获胜
        }
        else if(X == COLUMN)
        {
            result = 1;//执X玩家获胜
        }
    }

    /*检查反对角线*/
    for(i = 0; i < ROW; i++)
    {
        X = 0, O = 0;
        if(board[i][COLUMN - 1 -i] == 0)//检查这一对角线并进行计数
        {
            O++;
        }
        else if(board[i][COLUMN - 1 -i] == 1)
        {
            X++;
        }

        /*反对角线被X或O填满了，就对获胜玩家进行标记*/
        if(O == ROW)
        {
            result = 0;//执O玩家获胜
        }
        else if(X == COLUMN)
        {
            result = 1;//执X玩家获胜
        }
    }

    if(result == 0)
    {
        printf("选O的玩家赢了！\n");
    }
    else if(result == 1)
    {
        printf("选X的玩家赢了！\n");
    }
    else if(result == -1)
    {
        printf("平局。\n");
    }

    return 0;
}
// ConsoleSnake.cpp : �������̨Ӧ�ó������ڵ㡣
//

// #include "stdafx.h"
#include <iostream>
#include <windows.h>
#include <conio.h>
using namespace std;


int main()
{
    int boardLen = 15;
    int snakex[255] = { 5, 5 };
    int snakey[255] = { 6, 7 };
    int len = 2;
    int dir = 0;

    int foodx = 10;
    int foody = 10;

    int gameState = 0;  // 0 ��Ϸ���У�1 ��Ϸ����

    char board[] = "\
+------------------------------+\n\
|                              |\n\
|                              |\n\
|                              |\n\
|                              |\n\
|                              |\n\
|                              |\n\
|                              |\n\
|                              |\n\
|                              |\n\
|                              |\n\
|                              |\n\
|                              |\n\
|                              |\n\
|                              |\n\
|                              |\n\
+------------------------------+\n\
             asdw����           \
";
    cout << board;
    while (true)
    {
        if (gameState == 0)
        {
            char ch = ' ';
            if (_kbhit())
            {
                ch = _getch();
            }

            if (ch == 'w' && dir != 2)
            {
                dir = 0;
            }

            if (ch == 'd' && dir != 3)
            {
                dir = 1;
            }

            if (ch == 's' && dir != 0)
            {
                dir = 2;
            }

            if (ch == 'a' && dir != 1)
            {
                dir = 3;
            }

            int lastx = snakex[len - 1];
            int lasty = snakey[len - 1];

            // ���ƶ�
            for (int i = len - 1; i >= 1; --i)
            {
                snakex[i] = snakex[i - 1];
                snakey[i] = snakey[i - 1];
            }

            if (dir == 0)
            {
                snakey[0]--;
            }

            if (dir == 1)
            {
                snakex[0]++;
            }

            if (dir == 2)
            {
                snakey[0]++;
            }
            if (dir == 3)
            {
                snakex[0]--;
            }

            // �Ե�ʳ��
            int nextLen = len;
            if (snakex[0] == foodx && snakey[0] == foody)
            {
                // �����ߵĳ���
                nextLen++;

                // ��������ʳ��
                while (true)
                {
                    foodx = rand() % 10;
                    foody = rand() % 10;

                    bool isCoincided = false;
                    for (int i = 0; i < len; ++i)
                    {
                        if (snakex[i] == foodx && snakey[i] == foody)
                        {
                            isCoincided = true;
                        }
                    }

                    if (!isCoincided)
                    {
                        break;
                    }
                }
            }

            // �Ե��Լ�
            for (int i = 1; i < len; ++i)
            {
                if (snakex[i] == snakex[0] && snakey[i] == snakey[0])
                {
                    gameState = 1;
                    break;
                }
            }

            // ��������
            if (snakex[0] < 0 || snakex[0] >= boardLen || snakey[0] < 0 || snakey[0] >= boardLen)
            {
                gameState = 1;
            }


            // �����ߵ����һ���ڵ�
            COORD co;
            co.X = lastx * 2 + 1;
            co.Y = lasty + 1;

            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), co);


            cout << "  ";

            // ��ʳ��
            COORD foodCo;
            foodCo.X = foodx * 2 + 1;
            foodCo.Y = foody + 1;

            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), foodCo);


            cout << "��";

            // ����
            for (int i = 0; i < len; ++i)
            {
                COORD co;
                co.X = snakex[i] * 2 + 1;
                co.Y = snakey[i] + 1;

                SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), co);

                if (i == 0)
                {
                    cout << "��";
                }
                else
                {
                    cout << "��";
                }
                
            }

            len = nextLen;



            Sleep(500);
        }

        if (gameState == 1)
        {
            // ��ʾ��Ϸ����
            COORD co;
            co.X = boardLen - 4;
            co.Y = boardLen / 2;

            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), co);

            cout << "Game Over";
            break;
        }
    }
    
    
    
   
    getchar();

    return 0;
}

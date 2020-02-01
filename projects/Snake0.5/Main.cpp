// Main.cpp
//
#include <graphics.h>
#include <Windows.h>
#include "Class.h"
#include "Main.h"

enum GameState
{
	Running,
	GameOver,
};

// ȫ�ַ�Χbegin--------------------------------------
bool isGameRunning = true;

Snake snake;        // �߶���
Wall wall;                // ǽ����
Apple apple;         // ƻ������
UI ui;                    // UI����

int state = Running;		// ��Ϸ����״̬

// ȫ�ַ�Χend--------------------------------------

// �жϼ����Ƿ���
bool IsKeyDown(int key)
{
	return (GetAsyncKeyState(key) & 0x8000 ? 1 : 0);
}

void Draw()
{
	BeginBatchDraw();	// ��ʼ������ͼ����ֹ��˸
	cleardevice();		// �ñ���ɫ�����Ļ
	
	snake.Draw();
	wall.Draw();
	apple.Draw();
	ui.Draw();
	EndBatchDraw();
}
void KeyboardControl()
{
	if (IsKeyDown(VK_ESCAPE)) // esc���������˳�ѭ��������Ϸ
	{
		isGameRunning = false;
		return;
	}

	if (IsKeyDown(VK_LEFT))
	{
		snake.ChangeDirection(Direction::Left);
	}

	if (IsKeyDown(VK_RIGHT))
	{
		snake.ChangeDirection(Direction::Right);
	}

	if (IsKeyDown(VK_UP))
	{
		snake.ChangeDirection(Direction::Up);
	}

	if (IsKeyDown(VK_DOWN))
	{
		snake.ChangeDirection(Direction::Down);
	}

	if (IsKeyDown(VK_RETURN) && state == GameState::GameOver)
	{
		state = GameState::Running;
		snake.Reset();
	}
}

void HandleLogic()
{
	if (state == GameState::Running)
	{
		if (snake.Move())
		{
			if (snake.IsDie())
			{
				state = GameState::GameOver;
			}
			
			snake.TryEat(apple);
		}
	}
	
}

int main()
{
	initgraph(640, 480); // ��ʼ��EasyX����
						 
	setbkcolor(WHITE);	// ���ñ���ɫΪ��ɫ
	setlinecolor(BLACK);
	settextcolor(BLACK);

	cleardevice();		// �ñ���ɫ�����Ļ

	while (isGameRunning)
	{
		KeyboardControl(); // ������̲���
		HandleLogic();        // ������Ϸ�߼�
		Draw();                    // �������л���
		Sleep(10);			// �ȴ�30���룬����֡��
	}

	closegraph(); // ����EasyX����
	return 0;
}
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

// 全局范围begin--------------------------------------
bool isGameRunning = true;

Snake snake;        // 蛇对象
Wall wall;                // 墙对象
Apple apple;         // 苹果对象
UI ui;                    // UI对象

int state = Running;		// 游戏运行状态

// 全局范围end--------------------------------------

// 判断键盘是否按下
bool IsKeyDown(int key)
{
	return (GetAsyncKeyState(key) & 0x8000 ? 1 : 0);
}

void Draw()
{
	BeginBatchDraw();	// 开始批量绘图，防止闪烁
	cleardevice();		// 用背景色清空屏幕
	
	snake.Draw();
	wall.Draw();
	apple.Draw();
	ui.Draw();
	EndBatchDraw();
}
void KeyboardControl()
{
	if (IsKeyDown(VK_ESCAPE)) // esc键按下则退出循环结束游戏
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
	initgraph(640, 480); // 初始化EasyX环境
						 
	setbkcolor(WHITE);	// 设置背景色为白色
	setlinecolor(BLACK);
	settextcolor(BLACK);

	cleardevice();		// 用背景色清空屏幕

	while (isGameRunning)
	{
		KeyboardControl(); // 处理键盘操作
		HandleLogic();        // 处理游戏逻辑
		Draw();                    // 处理所有绘制
		Sleep(10);			// 等待30毫秒，控制帧率
	}

	closegraph(); // 清理EasyX环境
	return 0;
}
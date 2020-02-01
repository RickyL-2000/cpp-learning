// 因为项目非常简单，所以类都放一个文件里
#include <graphics.h>
#include <list>
using namespace std;
class Wall
{
public:
	void Draw() 
	{
		line(160, 0, 160, 480);
	}
};

class Apple
{
public:
	Apple()
	{
		NewApple();
	}

	void Draw() 
	{
		circle(_x * 48 + 160 + 24, _y * 48 + 24, 15);
	}

	void NewApple()
	{
		_x = rand() % 10;
		_y = rand() % 10;
	}

	int GetX() { return _x; }
	int GetY() { return _y; }
	
private:
	int _x;
	int _y;
};

enum Direction
{
	Up,
	Down,
	Left,
	Right,
};

class Snake
{
public:
	Snake()
	{
		Reset();
	}
	void Draw() 
	{
		int n = 1;
		for (list<POINT>::iterator it = _bodyList.begin(); it != _bodyList.end(); ++it)
		{
			POINT pos = *it;

			// 蛇的每个节点都画一个正方形，长和宽都是48
			rectangle(pos.x * 48 + 160, pos.y * 48, (pos.x + 1) * 48 + 160, (pos.y + 1) * 48);

			if (n == 1)
			{
				circle(pos.x * 48 + 160 + 24, pos.y * 48 + 24, 10);
			}

			n++;
		}
	}

	void ChangeDirection(Direction dir)
	{
		if (_dir == Direction::Up && dir == Direction::Down
			|| _dir == Direction::Down && dir == Direction::Up
			|| _dir == Direction::Right && dir == Direction::Left
			|| _dir == Direction::Left && dir == Direction::Right)
		{
			return;
		}
		_dir = dir;
	}

	void TryEat(Apple &apple)
	{
		POINT headPos = *_bodyList.begin();

		if (headPos.x != apple.GetX() || headPos.y != apple.GetY())
		{
			return;	// 没吃到苹果，返回
		}

		apple.NewApple();	// 创建新苹果

		POINT end = _bodyList.back();
		_bodyList.push_back(end);		//把尾巴的位置复制一次放入身体末尾

	
	}

	bool CheckEatSelf(int x, int y)
	{
		list<POINT>::iterator it = _bodyList.begin();
		POINT headPos = *it;
		++it;

		for (; it != _bodyList.end(); ++it)
		{
			// 检查所有节点是否与头节点重合
			if (it->x == x && it->y == y)
			{
				return true;
			}
		}

		return false;
	}

	bool CheckHitWall(int x, int y)
	{
		if (x < 0 || x >= 10 || y < 0 || y >= 10)
		{
			return true;
		}

		return false;
	}

	void Reset()
	{
		_bodyList.clear();
		POINT head = { 5, 5 };
		_bodyList.push_back(head);

		_dir = Direction::Right;

		_isDie = false;
	}

	bool Move()
	{
		int xOffset[4] = { 0, 0, -1, 1 };
		int yOffset[4] = { -1, 1, 0, 0 };

		static int lastMoveTick = 0;	// 使用静态变量，记录每次蛇移动的时间

		DWORD curTick = GetTickCount();	// 当前时间

		if (curTick - lastMoveTick < 500)	// 如果当前时间距离上次移动时间小于500ms则不移动
		{
			return false;
		}

		lastMoveTick = curTick;

		list<POINT>::iterator it = _bodyList.begin();

		int prevX = it->x;			// 记录头部坐标
		int prevY = it->y;

		if (CheckEatSelf(it->x + xOffset[_dir], it->y + yOffset[_dir]) || CheckHitWall(it->x + xOffset[_dir], it->y + yOffset[_dir]))
		{
			_isDie = true;
			return true;
		}


		it->x += xOffset[_dir];		// 修改头部坐标
		it->y += yOffset[_dir];

		it++;

		for (; it != _bodyList.end(); ++it)
		{
			// 后续节点全部移动到前面节点的位置
			int curX = it->x;
			int curY = it->y;

			if (curX == prevX && curY == prevY)
			{
				break;
			}

			it->x = prevX;
			it->y = prevY;

			prevX = curX;
			prevY = curY;


		}

		return true;
	}

	bool IsDie()
	{
		return _isDie;
	}
	

	
private:
	list<POINT>	_bodyList;
	Direction _dir;
	bool _isDie;
};

class UI
{
public:
	void Draw() 
	{
		RECT scoreRect = { 10, 10, 140, 50 };
		drawtext("分数", &scoreRect, DT_CENTER);

		RECT levelRect = { 10, 240, 140, 290 };
		drawtext("难度", &levelRect, DT_CENTER);
	}
};
// ��Ϊ��Ŀ�ǳ��򵥣������඼��һ���ļ���
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

			// �ߵ�ÿ���ڵ㶼��һ�������Σ����Ϳ���48
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
			return;	// û�Ե�ƻ��������
		}

		apple.NewApple();	// ������ƻ��

		POINT end = _bodyList.back();
		_bodyList.push_back(end);		//��β�͵�λ�ø���һ�η�������ĩβ

	
	}

	bool CheckEatSelf(int x, int y)
	{
		list<POINT>::iterator it = _bodyList.begin();
		POINT headPos = *it;
		++it;

		for (; it != _bodyList.end(); ++it)
		{
			// ������нڵ��Ƿ���ͷ�ڵ��غ�
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

		static int lastMoveTick = 0;	// ʹ�þ�̬��������¼ÿ�����ƶ���ʱ��

		DWORD curTick = GetTickCount();	// ��ǰʱ��

		if (curTick - lastMoveTick < 500)	// �����ǰʱ������ϴ��ƶ�ʱ��С��500ms���ƶ�
		{
			return false;
		}

		lastMoveTick = curTick;

		list<POINT>::iterator it = _bodyList.begin();

		int prevX = it->x;			// ��¼ͷ������
		int prevY = it->y;

		if (CheckEatSelf(it->x + xOffset[_dir], it->y + yOffset[_dir]) || CheckHitWall(it->x + xOffset[_dir], it->y + yOffset[_dir]))
		{
			_isDie = true;
			return true;
		}


		it->x += xOffset[_dir];		// �޸�ͷ������
		it->y += yOffset[_dir];

		it++;

		for (; it != _bodyList.end(); ++it)
		{
			// �����ڵ�ȫ���ƶ���ǰ��ڵ��λ��
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
		drawtext("����", &scoreRect, DT_CENTER);

		RECT levelRect = { 10, 240, 140, 290 };
		drawtext("�Ѷ�", &levelRect, DT_CENTER);
	}
};
#include "pch.h"
#include "Player.h"
#include "Board.h"

void Player::Init(Board* board)
{
	_pos = board->GetEnterPos();
	_board = board;

	Pos pos = _pos;

	_path.clear();
	_path.push_back(pos);

	// ������ �����ϱ� ������ ��� ����
	Pos dest = board->GetExitPos();

	/*
	DIR_UP = 0,		// ������ 3(x+1), ���� 1(x-1), ��(y-1)
	DIR_LEFT = 1,	// ������ 0(y-1), ���� 2(y+1), ��(x-1)
	DIR_DOWN = 2,	// ������ 1(x-1), ���� 3(x+1), ��(y+1)
	DIR_RIGHT = 3,	// ������ 2(y+1), ���� 0(y-1), ��(x+1)
	*/
	Pos front[4] =
	{
		Pos { -1, 0 },	// UP
		Pos { 0, -1 },	// LEFT
		Pos { 1, 0 },	// DOWN
		Pos { 0, 1 },	// RIGHT
	};

	while (pos != dest)
	{
		int32 newDir = (_dir - 1 + DIR_COUNT) % DIR_COUNT;

		// 1. ���� �ٶ󺸴� ������ �������� ���������� �� �� �ִ��� Ȯ��.
		if (CanGo(pos + front[newDir]))
		{
			// ������ �������� 90�� ȸ��.
			_dir = newDir;
			// ������ �� �� ����.
			pos += front[_dir];

			_path.push_back(pos);
		}
		// 2. ���� �ٶ󺸴� ������ �������� ������ �� �ִ��� Ȯ��.
		else if (CanGo(pos + front[_dir]))
		{
			// ������ �� �� ����.
			pos += front[_dir];

			_path.push_back(pos);
		}
		else
		{
			// ���� �������� 90�� ȸ��.
			_dir = (_dir + 1) % DIR_COUNT;
		}
	}


}

void Player::Update(uint64 deltaTick)
{
	if (_pathIndex >= _path.size())
		return;

	_sumTick += deltaTick;
	if (_sumTick >= MOVE_TICK)
	{
		_sumTick = 0;

		_pos = _path[_pathIndex];
		_pathIndex++;
	}
}

bool Player::CanGo(Pos pos)
{
	TileType tileType = _board->GetTileType(pos);
	return tileType == TileType::EMPTY;
}

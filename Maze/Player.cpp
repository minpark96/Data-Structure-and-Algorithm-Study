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

	// 목적지 도착하기 전에는 계속 실행
	Pos dest = board->GetExitPos();

	/*
	DIR_UP = 0,		// 오른쪽 3(x+1), 왼쪽 1(x-1), 앞(y-1)
	DIR_LEFT = 1,	// 오른쪽 0(y-1), 왼쪽 2(y+1), 앞(x-1)
	DIR_DOWN = 2,	// 오른쪽 1(x-1), 왼쪽 3(x+1), 앞(y+1)
	DIR_RIGHT = 3,	// 오른쪽 2(y+1), 왼쪽 0(y-1), 앞(x+1)
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

		// 1. 현재 바라보는 방향을 기준으로 오른쪽으로 갈 수 있는지 확인.
		if (CanGo(pos + front[newDir]))
		{
			// 오른쪽 방향으로 90도 회전.
			_dir = newDir;
			// 앞으로 한 보 전진.
			pos += front[_dir];

			_path.push_back(pos);
		}
		// 2. 현재 바라보는 방향을 기준으로 전진할 수 있는지 확인.
		else if (CanGo(pos + front[_dir]))
		{
			// 앞으로 한 보 전진.
			pos += front[_dir];

			_path.push_back(pos);
		}
		else
		{
			// 왼쪽 방향으로 90도 회전.
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

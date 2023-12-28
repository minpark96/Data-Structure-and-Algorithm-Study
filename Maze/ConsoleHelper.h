#pragma once

#include <windows.h>
#include "Types.h"

enum class ConsoleColor
{
	BLACK = 0,
	RED = FOREGROUND_RED,
	GREEN = FOREGROUND_GREEN,
	BLUE = FOREGROUND_BLUE,
	YELLOW = RED | GREEN,
	WHITE = RED | GREEN | BLUE,
};

class ConsoleHelper
{
public:
	// static �Լ�, ��ü �������ص� ��밡��
	static void SetCursorPosition(int32 x, int32 y); // ���ڰŸ��� Ŀ�� ����
	static void SetCursorColor(ConsoleColor color);
	static void ShowConsoleCursor(bool flag);
};


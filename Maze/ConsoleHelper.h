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
	// static 함수, 객체 생성안해도 사용가능
	static void SetCursorPosition(int32 x, int32 y); // 깜박거리는 커서 설정
	static void SetCursorColor(ConsoleColor color);
	static void ShowConsoleCursor(bool flag);
};


#include "pch.h"
#include "ConsoleHelper.h"

void ConsoleHelper::SetCursorPosition(int32 x, int32 y)
{
	// :: -> 범위 지정 연산자
	// 함수 앞에 붙어 있는 경우, 전역 함수를 호출하고 있다는 것을 나타냄
	// 같은 이름을 가진 다른 함수가 있을 경우, 원하는 함수를 정확하게 호출하게 하기 위함
	HANDLE output = ::GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos = { static_cast<SHORT>(x), static_cast<SHORT>(y) };
	// static_cast 형변환 - 오류를 코드상에서 체크
	// dynamic_cast 형변환 - RTTI 사용, 런타임 시에 체크, 상속관계에서 다운캐스팅
	// const_cast 형변환 - 상수성을 제거
	// reinterpret_cast 형변환 - C 스타일과 가장 유사, 관계가 없어도 캐스팅 가능 (상수성 제거는 불가능)
	::SetConsoleCursorPosition(output, pos);
}

void ConsoleHelper::SetCursorColor(ConsoleColor color)
{
	HANDLE output = ::GetStdHandle(STD_OUTPUT_HANDLE);
	::SetConsoleTextAttribute(output, static_cast<int16>(color));
}

void ConsoleHelper::ShowConsoleCursor(bool flag)
{
	HANDLE output = ::GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursorInfo;
	::GetConsoleCursorInfo(output, &cursorInfo);
	cursorInfo.bVisible = flag;
	::SetConsoleCursorInfo(output, &cursorInfo);
}

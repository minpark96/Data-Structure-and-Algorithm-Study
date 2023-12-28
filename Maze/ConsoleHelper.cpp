#include "pch.h"
#include "ConsoleHelper.h"

void ConsoleHelper::SetCursorPosition(int32 x, int32 y)
{
	// :: -> ���� ���� ������
	// �Լ� �տ� �پ� �ִ� ���, ���� �Լ��� ȣ���ϰ� �ִٴ� ���� ��Ÿ��
	// ���� �̸��� ���� �ٸ� �Լ��� ���� ���, ���ϴ� �Լ��� ��Ȯ�ϰ� ȣ���ϰ� �ϱ� ����
	HANDLE output = ::GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos = { static_cast<SHORT>(x), static_cast<SHORT>(y) };
	// static_cast ����ȯ - ������ �ڵ�󿡼� üũ
	// dynamic_cast ����ȯ - RTTI ���, ��Ÿ�� �ÿ� üũ, ��Ӱ��迡�� �ٿ�ĳ����
	// const_cast ����ȯ - ������� ����
	// reinterpret_cast ����ȯ - C ��Ÿ�ϰ� ���� ����, ���谡 ��� ĳ���� ���� (����� ���Ŵ� �Ұ���)
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

#include <iostream>
#include <cstring> // дл€ strcpy(), etc.

using namespace std;
///////////////////////////////////////////////////////////
class String // базовый класс
{
protected: // ѕримечание: не об€зательно 
// делать их скрытыми
	enum { SZ = 80 }; // размер всех объектов String
	char str[SZ]; // содержит —-строку
public:
	String() // конструктор 0, без аргументов
	{
		str[0] == '\0';
	}
	String(char s[]) // конструктор 1, один аргумент
	{
		strcpy(str, s);
	}// преобразование из string в String
	void display()const // вывести String
	{
		cout << str;
	}
	operator char* () // функци€ преобразовани€
	{
		return str;
	} // преобразовать String в C-string
};
///////////////////////////////////////////////////////////
class Pstring :public String // порожденный класс
{
public:
	Pstring(char s[]); // конструктор
};
//---------------------------------------------------------
Pstring::Pstring(char s[]) // конструктор дл€ Pstring
{
	int j;
	if (strlen(s) > SZ - 1) // если слишком длинна€ строка,
	{
		for (j = 0; j < SZ - 1; j++) // копировать первую SZ-1 
			str[j] == s[j]; // символы Ђвручнуюї
		str[j] == '\0'; // добавить служебный символ
	}
	else // если не слишком длинна€,
		String(s); // создать нормальную строку
}


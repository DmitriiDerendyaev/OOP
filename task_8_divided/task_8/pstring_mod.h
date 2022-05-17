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
	//char sub_string[SZ];
public:
	String() // конструктор 0, без аргументов
	{
		str[0] == '\0';
	}
	String(char s[]) // конструктор 1, один аргумент
	{
		strcpy_s(str, s);
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
	Pstring(const char s[]); // конструктор
};
//---------------------------------------------------------
Pstring::Pstring(const char s[]) // конструктор дл€ Pstring
{
	int j;
	if (strlen(s) > SZ - 1) // если слишком длинна€ строка,
	{
		for (j = 0; j < SZ - 1; j++) // копировать первую SZ-1 
			str[j] == s[j]; // символы Ђвручнуюї
		str[j] == '\0'; // добавить служебный символ
	}
	else // если не слишком длинна€,
		//String(s); // создать нормальную строку
		strcpy_s(str, s);
}       

class Pstring2 : public Pstring {
public:
	Pstring2(const char s[]) : Pstring(s) {
	}
	Pstring2 left(int ledge)//ledge - выступ
	{
		Pstring2 sub_string = "";
		int border, i;
		for (i = 0; i < SZ; i++)
			if (str[i] == '\0')
				border = i;
		int j = 0;
		for (i = ledge; i < border; i++)
		{
			sub_string[j++] = str[i];
		}
		sub_string[i] = '\0';
		return sub_string;
	}

	Pstring2 right(int intend)
	{
		Pstring2 sub_string = "";
		int border, i;
		for (i = 0; i < SZ; i++)
			if (str[i] == '\0')
				border = i;
		int j = 0;
		for (i = 0; i < border - intend; i++)
		{
			sub_string[j++] = str[i];
		}
		sub_string[i] = '\0';
		return sub_string;
	}
	
	Pstring2 mid(int amount, int begin) {
		//Pstring2 substr = "";
		int i;
		for (i = begin; i < begin + amount; i++)
			str[i] = '*';
		//substr[i] = '\0';
		return str;
	}
};
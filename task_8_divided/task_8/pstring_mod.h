#include <iostream>
#include <cstring> // ��� strcpy(), etc.

using namespace std;
///////////////////////////////////////////////////////////
class String // ������� �����
{
protected: // ����������: �� ����������� 
// ������ �� ��������
	enum { SZ = 80 }; // ������ ���� �������� String
	char str[SZ]; // �������� �-������
	//char sub_string[SZ];
public:
	String() // ����������� 0, ��� ����������
	{
		str[0] == '\0';
	}
	String(char s[]) // ����������� 1, ���� ��������
	{
		strcpy_s(str, s);
	}// �������������� �� string � String
	void display()const // ������� String
	{
		cout << str;
	}
	operator char* () // ������� ��������������
	{
		return str;
	} // ������������� String � C-string
};
///////////////////////////////////////////////////////////
class Pstring :public String // ����������� �����
{
public:
	Pstring(const char s[]); // �����������
};
//---------------------------------------------------------
Pstring::Pstring(const char s[]) // ����������� ��� Pstring
{
	int j;
	if (strlen(s) > SZ - 1) // ���� ������� ������� ������,
	{
		for (j = 0; j < SZ - 1; j++) // ���������� ������ SZ-1 
			str[j] == s[j]; // ������� ���������
		str[j] == '\0'; // �������� ��������� ������
	}
	else // ���� �� ������� �������,
		//String(s); // ������� ���������� ������
		strcpy_s(str, s);
}       

class Pstring2 : public Pstring {
public:
	Pstring2(const char s[]) : Pstring(s) {
	}
	Pstring2 left(int ledge)//ledge - ������
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
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
public:
	String() // ����������� 0, ��� ����������
	{
		str[0] == '\0';
	}
	String(char s[]) // ����������� 1, ���� ��������
	{
		strcpy(str, s);
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
	Pstring(char s[]); // �����������
};
//---------------------------------------------------------
Pstring::Pstring(char s[]) // ����������� ��� Pstring
{
	int j;
	if (strlen(s) > SZ - 1) // ���� ������� ������� ������,
	{
		for (j = 0; j < SZ - 1; j++) // ���������� ������ SZ-1 
			str[j] == s[j]; // ������� ���������
		str[j] == '\0'; // �������� ��������� ������
	}
	else // ���� �� ������� �������,
		String(s); // ������� ���������� ������
}


#include <iostream>
#include <Windows.h>
#include <string>
using namespace std;
/*
�����2�·���29��
��ͨ���꣺�ܱ�4���������ܱ�100���������Ϊ
�������꣺�ܱ�400����
*/

int main(void) {

	int year;//��
	int month;//��
	int days;//��
	bool flag;//�ж��Ƿ�����

	cout << "��������ݣ�" << endl;
	cin >> year;

	cout << "�������·ݣ�" << endl;
	cin >> month;

	if (year % 4 == 0 && year % 100 != 0) {
		flag= true;
	} else if (year % 400 == 0) {
		flag= true;
	} else {
		flag = false;
	}

	switch (month) {
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:
		days=31;
		break;
	case 4:
	case 6:
	case 9:
	case 11:
		days=30;
		break;
	case 2:
		days = flag ? 29 : 28;
		break;
	default:
		cout << "�Ƿ��·�" << endl;
	}
	cout << year << "��" << month << "��" << days << "��" << endl;
	system("pause");

	return 0;

}
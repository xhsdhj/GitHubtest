#include <iostream>
#include <Windows.h>
#include <string>
using namespace std;
/*
闰年的2月份有29天
普通闰年：能被4整除但不能被100整除的年份为
世纪闰年：能被400整除
*/

int main(void) {

	int year;//年
	int month;//月
	int days;//日
	bool flag;//判断是否闰年

	cout << "请输入年份：" << endl;
	cin >> year;

	cout << "请输入月份：" << endl;
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
		cout << "非法月份" << endl;
	}
	cout << year << "年" << month << "月" << days << "天" << endl;
	system("pause");

	return 0;

}
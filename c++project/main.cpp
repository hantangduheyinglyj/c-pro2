#include <iostream>
#include<stdlib.h>
#include "calculator.h"
using namespace std;
int main()
{
	Calculator cal;
	cout << "支持运算符：+, - , *, /。优先级符号：()。负数请加（）。" << endl;
	while (1) {
		getline(cin, cal.infix);
		//防止内存条溢出
		if (cal.infix.length() > 1000) {
			cout << "超出最大长度！" << endl;
			system("pause");
		}
		else {
			cal.getFormat();
			cal.getSuffix();
			cal.calSuffix();
			cout << cal.getResult() << endl;
		}
	}
	return 0;
}
//测试样例：9+(3-1)*3+10/2
#include <iostream>
#include<stdlib.h>
#include "calculator.h"
using namespace std;
int main()
{
	Calculator cal;
	cout << "֧���������+, - , *, /�����ȼ����ţ�()��������ӣ�����" << endl;
	while (1) {
		getline(cin, cal.infix);
		//��ֹ�ڴ������
		if (cal.infix.length() > 1000) {
			cout << "������󳤶ȣ�" << endl;
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
//����������9+(3-1)*3+10/2
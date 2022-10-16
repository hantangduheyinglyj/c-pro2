#include "calculator.h"
//算术符号优先权等级
void Calculator::getFormat() {
	stdInfix = infix;
	for (size_t i = 0; i < stdInfix.size(); i++) {
		if (stdInfix[i] == '-' || stdInfix[i] == '+') {
			if (i == 0) {
				stdInfix.insert(0, 1, '0');
			}
			else if (stdInfix[i - 1] == '(') {
				stdInfix.insert(i, 1, '0');
			}
		}
	}
}
//获取算术符号优先级
int Calculator::getPrior(char c) 
{
	int priority = 100;
	if (c == '+' || c == '-') 
	{
		priority = 1;
	}
	else if (c == '*' || c == '/') 
	{
		priority = 0;
	}
	else if (c == '(') 
	{
		priority = 2;
	}
	return priority;
}
//后缀表达式转换
void Calculator::getSuffix()
{
	for (size_t i = 0; i < infix.size(); i++)
	{
		//是数字的情况下直接输出
		if (infix[i] >= '0' && infix[i] <= '9')
		{
			suffix += infix[i];
		}
		else //不是数字的情况分类讨论进行判断
		{
			if (!ope.empty())
			{
				switch (infix[i])
				{
				case '(':
					ope.push('(');
					break;
				case ')':
					while (ope.top() != '(')
					{
						suffix += ope.top();
						ope.pop();
					}
					ope.pop();
					break;
				default:
					while (getPrior(infix[i]) >= getPrior(ope.top()))
					{
						suffix += ope.top();
						ope.pop();
						if (ope.empty())
						{
							break;
						}
					}
					ope.push(infix[i]);
					break;
				}
			}
			ope.push(infix[i]);
		}
	}
	while (!ope.empty())
	{
		suffix += ope.top();
		ope.pop();
	}
}
//计算后缀表达式
void Calculator::calSuffix() 
{
	double num1 = 0;
	double num2 = 0;
	for (int i = 0; i < suffix.size(); i++)
	{
		if (suffix[i] >= '0' && suffix[i] <= '9')
		{
			figure.push(suffix[i]);
		}
		else {
			switch (suffix[i])
			{
			case '+':
				if (!figure.empty()) {
					num2 = figure.top();
					figure.pop();
				}
				if (!figure.empty()) {
					num1 = figure.top();
					figure.pop();
				}
				figure.push(num1 + num2);
				break;
			case '-':
				if (!figure.empty()) {
					num2 = figure.top();
					figure.pop();
				}
				if (!figure.empty()) {
					num1 = figure.top();
					figure.pop();
				}
				figure.push(num1 - num2);
				break;
			case '*':
				if (!figure.empty()) {
					num2 = figure.top();
					figure.pop();
				}
				if (!figure.empty()) {
					num1 = figure.top();
					figure.pop();
				}
				figure.push(num1 * num2);
				break;
			case '/':
				if (!figure.empty()) {
					num2 = figure.top();
					figure.pop();
				}
				if (!figure.empty()) {
					num1 = figure.top();
					figure.pop();
				}
				if (num2 != 0) {
					figure.push(num1 / num2);
				}
				break;
			default:
				break;
			}
		}
	}
	if (!figure.empty()) {
		result = figure.top();
	}
}
double Calculator::getResult() 
{
	return result;
}



#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <vector>
using namespace std;
class Calculator
{
public:
	void getFormat();				
	int getPrior(char c);				
	void getSuffix();					
	void calSuffix();				
	double getResult();		
	string infix;					
private:
	string suffix;
	string stdInfix;
	stack<char> ope;				   
	stack<double> figure;				
	double result;					
};
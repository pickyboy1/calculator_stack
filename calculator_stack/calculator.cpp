#include "calculator.h"
#include"Stack.h"
#include <iostream>
calculator::calculator()
{
}

double calculator::exce(char end)
{
	char c;
	while ((c = get_num()) != end) {
		if (c == ' ') {
			continue;
		}
		if (c == '(') {
			calculator temp;
			opr_Stack.push(temp.exce(')'));
			continue;
		}
		if (opt_Stack.size()) {
			if (is_pre(c, opt_Stack.top())) {
				opt_Stack.push(c);
			}
			else {
				double temp = product(opr_Stack.pop(), opr_Stack.pop(), opt_Stack.pop());
				opr_Stack.push(temp);
				opt_Stack.push(c);
			}
		}
		else opt_Stack.push(c);
	}
	while (opr_Stack.size() > 1) {
		double temp = product(opr_Stack.pop(), opr_Stack.pop(), opt_Stack.pop());
		opr_Stack.push(temp);
	}
	return opr_Stack.pop();
}

double calculator::product(double Lopr, double Ropr, char opt)
{
	switch (opt) {
	case '+':
		return Lopr + Ropr;
	case '-':
		return Lopr - Ropr;
	case '*':
		return Lopr * Ropr;
	case '/':
		if (Ropr == 0) {
			std::cout << "除数不能为0,请重新输入:";
			std::cin >> Ropr;
			return Lopr / Ropr;
		}
		else return Lopr / Ropr;
	}
}

bool calculator::is_pre(char opt1, char opt2)
{
	switch (opt1) {
	case '(':
		return true;
	case '+':
	case '-':
		return false;
	case '*':
	case '/':
		if (opt2 == '+' || opt2 == '-') {
			return true;
		}
		else return false;
	}
	return false;
}

char calculator::get_num()
{
	char ch;
	int Icount = 0;
	int Dcount = 0;
	bool is_decimal = 0;
	Stack<char> tem_S;
	bool is_numgot = false;
	while ((ch = getchar())<='9'&&ch>='0'||ch=='.')
	{
		if (ch == '.') {
			is_decimal = 1;
			continue;
		}
		else {
			is_numgot = true;
			tem_S.push(ch);
			if (is_decimal) {
				Dcount++;
			}
			else Icount++;
		}
	}
	double decimal = 0;
	while (Dcount--)
	{
		decimal += (static_cast<double>(tem_S.top() - '0') / pow(10, Dcount+1));
		tem_S.pop();
	}
	double int_part = 0;
	for (int i = 0; i < Icount; i++) {
		int_part += (static_cast<double>(tem_S.top() - '0') * pow(10, i));
		tem_S.pop();
	}
	if (is_numgot) {
		opr_Stack.push(decimal + int_part);
	}
	return ch;
}

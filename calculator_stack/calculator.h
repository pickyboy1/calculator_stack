#pragma once
#include"Stack.h"
#include<math.h>
#include<iostream>
class calculator
{
public:
	calculator();
	double exce(char end);
	double product(double Lopr, double Ropr, char opt);
	bool is_pre(char opt1, char opt2);
	char get_num();
private:
	Stack<char> opt_Stack;
	Stack<double> opr_Stack;
};


// ArgsDemo.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

bool IsValidOperator(char curOperator);
bool IsNumber(char str[]);

int main(int argc, char* argv[])
{
	if (argc != 4)
	{
		std::cout << "Wrong amount of arguments." << "\n";
		std::cout << "Usage: ArgsDemo.exe <operator> <argument> <argument>" << "\n";
		std::cout << "or: ArgsDemo.exe <argument> <operator> <argument>" << "\n";
		return 0;
	}

	char curOperator{ argv[1][0] };
	int parameter1{ };
	int parameter2{ };

	if (!IsValidOperator(curOperator))
	{
		curOperator = argv[2][0];
		if (!IsValidOperator(curOperator))
		{
			std::cout << "You probably need some help:" << "\n";
			std::cout << "Possible operators: + - * / p" << "\n";
			return 0;
		}
		else
		{
			if (!IsNumber(argv[1]) || !IsNumber(argv[3]))
			{
				return 0;
			}
			parameter1 = std::stoi(argv[1]);
			parameter2 = std::stoi(argv[3]);
		}
	}
	else
	{
		if (!IsNumber(argv[2]) || !IsNumber(argv[3]))
		{
			return 0;
		}
		parameter1 = std::stoi(argv[2]);
		parameter2 = std::stoi(argv[3]);
	}

	switch (curOperator)
	{
	case '+':
		std::cout << "Result is " << parameter1 + parameter2 << "\n";
		break;
	case '-':
		std::cout << "Result is " << parameter1 - parameter2 << "\n";
		break;
	case '/':
		if (parameter2 == 0)
		{
			std::cout << "You can't divide by 0!" << "\n";
		}
		else
		{
			const int quotient{ parameter1 / parameter2 };
			std::cout << "Result is " << quotient << " with rest " << parameter1 - quotient * parameter2 << "\n";
		}
		break;
	case '*':
		std::cout << "Result is " << parameter1 * parameter2 << "\n";
		break;
	case 'p':
		std::cout << "Result is " << pow(parameter1, parameter2) << "\n";
		break;
	}
}

bool IsValidOperator(char curOperator)
{
	switch (curOperator)
	{
	case '+':
	case '-':
	case '/':
	case '*':
	case 'p':
		return true;
	}
	return false;
}

bool IsNumber(char str[])
{
	int idx{};
	while (true)
	{
		if (str[idx] == 0)
		{
			return true;
		}
		if (str[idx] < '0' || str[idx] > '9')
		{
			std::cout << "One or more argument(s) is not an integer value!" << "\n";
			return false;
		}
		++idx;
	}
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

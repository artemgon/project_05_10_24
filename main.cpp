#include "classes.h"

bool pairFunc(char open, char close);

void checkFunc(const std::string& str);

int main()
{
	std::string str;
	std::cout << "Enter a string: ";
	std::getline(std::cin, str);
	checkFunc(str);
	return 0;
}

bool pairFunc(char open, char close)
{
	if (open == '(' && close == ')')
	{
		return true;
	}
	else if (open == '{' && close == '}')
	{
		return true;
	}
	else if (open == '[' && close == ']')
	{
		return true;
	}
	else
	{
		return false;
	}
}

void checkFunc(const std::string& str)
{
	std::stack<char> stack;
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] == '(' || str[i] == '{' || str[i] == '[')
		{
			stack.push(str[i]);
		}
		else if (str[i] == ')' || str[i] == '}' || str[i] == ']')
		{
			if (stack.empty() || !pairFunc(stack.top(), str[i]))
			{
				std::cout << "Unbalanced" << std::endl;
				return;
			}
			else
			{
				stack.pop();
			}
		}
	}
	if (stack.empty())
	{
		std::cout << "Balanced" << std::endl;
	}
	else
	{
		std::cout << "Unbalanced" << std::endl;
	}
}

#include "includes/RPN.hpp"

RPN::RPN(char *input)
{
	std::string inputString = input;

	for (size_t i = 0; i < inputString.size(); i++) {
		if (!_isCharValid(input[i])) {
			throw BadCharacter();
		}
	}
}

RPN::~RPN()
{
}

int RPN::evaluate(char *input)
{
	for (size_t i = 0; input[i] != '\0'; i++) {
		if (isdigit(input[i])) {
			_stack.push(input[i] - '0');
		} else if (_isOperator(input[i])) {
			if (_stack.size() < 2)
				throw StackToSmall();
			int result;
			int second_operand = _stack.top();
			_stack.pop();

			int first_operand = _stack.top();
			_stack.pop();

			switch (input[i]) {
				case '+':
					result = _add(first_operand, second_operand); break;
				case '-':
					result = _substract(first_operand, second_operand); break;
				case '/':
					if ( second_operand == 0 )
						throw DivisionByZero();
					result = _divide(first_operand, second_operand); break;
				case '*':
					result = _multiple(first_operand, second_operand); break;
			}
			_stack.push(result);
		}
	}
	return _stack.top();
}

int RPN::_add(int first_operand, int second_operand)
{
	return (first_operand + second_operand);
}

int RPN::_substract(int first_operand, int second_operand)
{
	return (first_operand - second_operand);
}

int RPN::_multiple(int first_operand, int second_operand)
{
	return (first_operand * second_operand);
}

int RPN::_divide(int first_operand, int second_operand)
{
	return (first_operand * second_operand);
}

bool RPN::_isOperator(char c) const
{
	if(c == '+'
	|| c == '-'
	|| c == '/'
	|| c == '*')
	{
		return true;
	}
	return false;
}

bool RPN::_isCharValid(char c) const
{
	if (isdigit(c) || _isOperator(c) || c == ' ')
	{
		return true;
	}
	return false;
}

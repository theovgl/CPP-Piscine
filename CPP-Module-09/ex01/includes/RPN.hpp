#ifndef RPN_HPP
# define RPN_HPP

# include <cstdlib>
# include <stack>
# include <string>
# include <exception>
# include <iostream>

class RPN
{

 public:
	RPN(char*);
	RPN(RPN const&);
	RPN operator=(RPN const&);
	~RPN();

	int evaluate(char*);

	class BadCharacter : public std::exception {
		public:
			virtual const char* what() const throw() {
				return "Error: bad character";
			}
	};

	class DivisionByZero : public std::exception {
		public:
			virtual const char* what() const throw() {
				return "Error: division by zero";
			}
	};

	class StackToSmall : public std::exception {
		public:
			virtual const char* what() const throw() {
				return "Error: not enough number to perfom operation";
			}
	};

 private:
	std::stack<int> _stack;

	bool _isCharValid(char) const;
	bool _isOperator(char c) const;

	int _add(int firstNumber,int secondNumber);
	int _substract(int firstNumber,int secondNumber);
	int _divide(int firstNumber,int secondNumber);
	int _multiple(int firstNumber, int secondNumber);
};

#endif

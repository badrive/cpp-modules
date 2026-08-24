#ifndef RPN_HPP
# define RPN_HPP

# include <string>
# include <stack>
# include <exception>

class RPN
{
	private:
		std::stack<int>	_stack;

	public:
		RPN();
		RPN(RPN const &src);
		RPN	&operator=(RPN const &rhs);
		~RPN();

		int		evaluate(std::string const &expression);

		class BadExpressionException : public std::exception
		{
			public:
				virtual char const	*what() const throw();
		};
};

#endif

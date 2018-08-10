#ifndef EXCEPTION_MAP
# define EXCEPTION_MAP

# include <exception>
# include <string>

class Exception_Map : public std::exception
{
	public:
							Exception_Map(std::string const &str);
		virtual const char*	what(void) const throw();
		virtual				~Exception_Map() throw();
	private:
		std::string const	m_str;
};

#endif

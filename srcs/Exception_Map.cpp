#include "Exception_Map.hpp"

							Exception_Map::Exception_Map(std::string const &str) : m_str(str)
{

}

const char *				Exception_Map::what(void) const throw()
{
	return (m_str.c_str());
}


							Exception_Map::~Exception_Map()
{

}

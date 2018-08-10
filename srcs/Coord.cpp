#include "../incs/Coord.hpp"

							Coord::Coord(unsigned int const y, unsigned int const x) :
		m_y(y),
		m_x(x)
{
}

void						Coord::set_y(unsigned int const y)
{
	m_y = y;
}

void						Coord::set_x(unsigned int const x)
{
	m_x = x;
}

unsigned int				Coord::get_y(void) const
{
	return (m_y);
}

unsigned int				Coord::get_x(void) const
{
	return (m_x);
}

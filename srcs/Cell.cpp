#include "Cell.hpp"

unsigned int const		Cell::NB_VAL_CHAR = 3;
Cell::t_val_char const	Cell::VAL_CHAR[NB_VAL_CHAR] = {
	{EMPTY, '0'},
	{WALL, '1'},
	{POSITION, '*'},
};

						Cell::Cell(unsigned int const y, unsigned int const x) :
	Coord(y, x)
{
	this->set_val('1');
}

bool					Cell::set_val(char const c)
{
	unsigned int		i;

	for (i = 0; i < this->NB_VAL_CHAR; i++)
		if (this->VAL_CHAR[i].c == c)
		{
			this->m_val = VAL_CHAR[i].val;
			this->m_c = this->VAL_CHAR[i].c;
			return (true);
		}
	return (false);
}

char					Cell::get_val(void) const
{
	return (this->m_c);
}

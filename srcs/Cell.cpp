#include "Cell.hpp"

std::vector<Cell::t_val_char> const
						Cell::VAL_CHAR = {
	{EMPTY, '0'},
	{WALL, '1'},
	{POSITION, '*'},
};
int const				Cell::DISTANCE_SCREEN = 40;
int const				Cell::HEIGHT_WALL = 200;
int const				Cell::WIDTH_PIX_CELL = 64;
int const				Cell::DEPTH_PIX_CELL = 64;

						Cell::Cell(unsigned int const y, unsigned int const x) :
	Coord(y, x)
{
	this->set_val('1');
}

bool					Cell::set_val(char const c)
{
	unsigned int		i;

	for (i = 0; i < this->VAL_CHAR.size(); i++)
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

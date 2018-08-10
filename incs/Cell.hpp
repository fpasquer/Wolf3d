#ifndef CELL_HPP
# define CELL_HPP

# include <iostream>
# include <vector>
# include "Coord.hpp"

class Cell : public Coord
{
	public:
		enum Val {
			EMPTY,
			WALL,
			POSITION
		};
		typedef struct		s_val_char
		{
			Cell::Val		val;
			char			c;
		}					t_val_char;
		static std::vector<t_val_char> const
							VAL_CHAR;
							Cell(unsigned int const y, unsigned int const x);
		static int const	DISTANCE_SCREEN;
		static int const	HEIGHT_WALL;
		static int const	WIDTH_PIX_CELL;
		static int const	DEPTH_PIX_CELL;
		bool				set_val(char const val);
		char				get_val(void) const;
	private:
		Cell::Val			m_val;
		char				m_c;
};

#endif

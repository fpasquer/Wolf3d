#ifndef CELL_HPP
# define CELL_HPP

# include <iostream>
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
		static t_val_char const
							VAL_CHAR[];
							Cell(unsigned int const y, unsigned int const x);
		bool				set_val(char const val);
		char				get_val(void) const;
	private:
		static unsigned int const
							NB_VAL_CHAR;
		Cell::Val			m_val;
		char				m_c;
};

#endif

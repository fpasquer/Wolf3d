#ifndef COORD_HPP
# define COORD_HPP

class Coord
{
	public:
							Coord(unsigned int const y, unsigned int const x);
		void				set_y(unsigned int const y);
		void				set_x(unsigned int const x);
		unsigned int		get_y(void) const;
		unsigned int		get_x(void) const;
	protected:
		unsigned int		m_y;
		unsigned int		m_x;
};

#endif

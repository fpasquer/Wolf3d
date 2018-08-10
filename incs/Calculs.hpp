#ifndef CALCUL_HPP
# define CALCUL_HPP

# include <math.h>
# include "Coord.hpp"

class Calculs
{
	public:
		static int			get_perceive_height(int const distance_screen,
				int const height_wall, int const distance_wall);
		static int			get_bottom_wall(int const perceive_height,
				int const height_eyes);
		static int			get_top_wall(int const perceive_height,
				int const height_eyes);
		static int			get_distance_wall(Coord const &player,
				Coord const &wall);
};

#endif

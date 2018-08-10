#include "../incs/Calculs.hpp"

int							Calculs::get_perceive_height(
		int const distance_screen, int const height_wall,
		int const distance_wall)
{
	return (distance_screen * height_wall / distance_wall);
}


int							Calculs::get_bottom_wall(
		int const perceive_height, int const height_eyes)
{
	return (height_eyes - perceive_height / 2);
}

int							Calculs::get_top_wall(
		int const perceive_height, int const height_eyes)
{
	return (height_eyes + perceive_height / 2);
}

int							Calculs::get_distance_wall(Coord const &player,
				Coord const &wall)
{
	double					distance_wall_p2;

	distance_wall_p2 =  pow((double)(player.get_x() - wall.get_x()), 2.0) +
			pow((double)(player.get_y() - wall.get_y()), 2.0);
	return ((int)sqrt(distance_wall_p2));
}

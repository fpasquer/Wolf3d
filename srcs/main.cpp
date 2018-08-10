#include <iostream>
#include "../incs/Map.hpp"

void						need_map(char const *name_bin)
{
	std::cerr << name_bin << " need a map" << std::endl;
	exit(EXIT_FAILURE);
}


int							main(int argc, char **argv)
{
	if (argc != 2)
		need_map(argv[0]);
	Map						map(argv[1]);

	map.print_map();
	return (0);
}

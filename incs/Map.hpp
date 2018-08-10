#ifndef MAP_HPP
# define MAP_HPP

# include <fstream>
# include <iostream>
# include <string>
# include <vector>
# include <boost/algorithm/string.hpp>
# include "Exception_Map.hpp"
# include "Cell.hpp"
# include "Coord.hpp"


class Map
{
	public:
							Map(char const *map_path);
							~Map(void);
		void				print_map(void) const;
	private:
		Cell				***m_grid;
		unsigned int		m_height;
		unsigned int		m_width;
		Coord				m_position;
		void				parse_save_map(std::string const &map_str);
		void				save_map(std::vector<std::string> const &list_lines);
		void				init_position(unsigned int const y, unsigned int const x);
		void				set_position(unsigned int const y, unsigned int const x);
};

#endif

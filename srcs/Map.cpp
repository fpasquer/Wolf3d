#include "../incs/Map.hpp"

							Map::Map(char const *map_path) :
		m_grid(nullptr),
		m_height(0),
		m_width(0),
		m_position(UINT_MAX, UINT_MAX)
{
	std::ifstream			map_file;
	std::string				map_str("");
	char					tmp;

	map_file.open(map_path);
	try
	{
		if (map_file.is_open() == false)
			throw Exception_Map("Not possible to open the file map");
	}
	catch (Exception_Map const &e)
	{
		std::cerr << e.what() << std::endl;
		exit(EXIT_FAILURE);
	}
	while (!map_file.eof())
		if ((tmp = map_file.get()) != EOF)
			map_str += tmp;
	map_file.close();
	this->parse_save_map(map_str);
}

							Map::~Map(void)
{
	unsigned int			y, x;

	if (this->m_grid == nullptr)
		return ;
	for (y = 0; y < this->m_height; y++)
		for (x = 0; x < this->m_width; x++)
			delete this->m_grid[y][x];
	for (y = 0; y < this->m_height; y++)
		delete[] this->m_grid[y];
	delete[] this->m_grid;
}

void						Map::print_map(void) const
{
	std::string				map_str = "";
	unsigned int			y, x;

	for (y = 0; y < this->m_height; y++)
	{
		for (x = 0; x < this->m_width; x++)
			map_str += this->m_grid[y][x]->get_val();
		map_str += '\n';
	}
	std::cout << map_str;
	std::cout << "POSITION y = " << std::to_string(this->m_position.get_y()) << " POSITION x = " << std::to_string(this->m_position.get_x()) << std::endl;
}

void						Map::parse_save_map(std::string const &map_str)
{
	unsigned int			y;
	std::vector<std::string>
							list_lines;

	boost::split(list_lines, map_str, [](char c){return (c == '\n');});
	for (y = 0; y < list_lines.size(); y++)
		this->m_width = list_lines[y].length() > this->m_width ?
				list_lines[y].length() : this->m_width;
	this->m_height = y + 2;
	this->m_width += 2;
	try
	{
		this->save_map(list_lines);
		if (this->m_position.get_y() == UINT_MAX ||
				this->m_position.get_x() == UINT_MAX)
			throw Exception_Map("Start position not set");
	}
	catch (Exception_Map const &e)
	{
		std::cerr << e.what() << std::endl;
		exit(EXIT_FAILURE);
	}
}

void						Map::save_map(
		std::vector<std::string> const &list_lines)
{
	unsigned int			y, x;

	if (this->m_height <= 2 || this->m_width <= 2)
		throw Exception_Map("Empty map");
	if ((this->m_grid = new Cell**[this->m_height]) == nullptr)
		throw Exception_Map("Not possible to allocate grid");
	for (y = 0; y < this->m_height; y++)
	{
		if ((this->m_grid[y] = new Cell*[this->m_width]) == nullptr)
			throw Exception_Map("Not possible to allocate grid*");
		for (x = 0; x < this->m_width; x++)
		{
			if ((this->m_grid[y][x] = new Cell(y, x)) == nullptr)
				throw Exception_Map("Not possible to allocate grid**");
			if (y == 0 || y == this->m_height - 1 || x == 0 ||
					x == this->m_width - 1 ||
					x - 1 >= list_lines[y - 1].length())
				continue ;
			if (this->m_grid[y][x]->set_val(list_lines[y - 1][x - 1])
					== false)
				throw Exception_Map("value not avalable");
			if (list_lines[y - 1][x - 1] == Cell::VAL_CHAR[Cell::POSITION].c)
				this->init_position(y, x);
		}
	}
}

void						Map::init_position(unsigned int const y,
		unsigned int const x)
{
	if (this->m_position.get_y() != UINT_MAX ||
			this->m_position.get_x() != UINT_MAX)
		throw Exception_Map("Position start already set");
	else
		this->set_position(y, x);
}

void						Map::set_position(unsigned int const y,
		unsigned int const x)
{
	this->m_position.set_y(y);
	this->m_position.set_x(x);
}

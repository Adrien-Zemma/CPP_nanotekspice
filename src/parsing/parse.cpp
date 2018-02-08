/*
** EPITECH PROJECT, 2018
** cpp_nanotekspice
** File description:
** 
*/
#include "parse.hpp"

Parse::Parse()
	: _file("")
{
	_links = new std::map<std::pair<std::string, size_t>, std::pair<std::string, size_t>>;
	_chipsets = new std::map<std::string, std::string>;
}

Parse::Parse(const std::string &file)
	: _file(file)
{
	_links = new std::map<std::pair<std::string, size_t>, std::pair<std::string, size_t>>;
	_chipsets = new std::map<std::string, std::string>;
}

Parse::~Parse()
{
	delete _links;
	delete _chipsets;
}

void Parse::read()
{
	if (_file.empty()) {
		std::cerr << "No files loaded" << std::endl;
		return;
	}
	this->read(_file);
}

void Parse::read(std::string file)
{
	std::ifstream in(file);

	if (!in) {
		std::cerr << "Can't open file" << std::endl;
		return ;
	}
	std::string line;
	while (getline(in, line)) {
		if (line.rfind(".chipsets:", 0) == 0)
			_title = CHIPSETS;
		else if (line.rfind(".links:", 0) == 0)
			_title = LINKS;
		append_line(line);
	}
	dumpChipsets();
}

void Parse::append_line(std::string line)
{
	auto elems = split_line(line);
	int args = count_args(line);

	switch(_title) {
		case CHIPSETS:
		if (elems.size() == 2)
			_chipsets->insert(std::pair<std::string,std::string>(elems[0], elems[1]));
		case LINKS:
		break;
	}
}

int Parse::count_args(const std::string line) const
{
	size_t	nb = 0;

	for (auto &ch : line) {
		if (ch == ' ' || ch == '\t')
			nb++;
		else if (ch == '#')
			return -1;
	}
	return (nb == 0 ? 1 : nb);
}

std::vector<std::string> Parse::split_line(const std::string &line) const
{
	std::vector<std::string> elems;
	std::string el;

	for (size_t i = 0; i < line.length(); i++) {
		if (line[i] == '#') {
			if (!el.empty())
				elems.push_back(el);
			return elems;
		}
		else if (line[i] == ' ' || line[i] == '\t') {
			if (!el.empty())
				elems.push_back(el);
			el.clear();
		}
		else
			el += line[i];
	}
	if (!el.empty())
		elems.push_back(el);
	return elems;
}

void Parse::dumpChipsets() const
{
	for (const auto &it : _chipsets) {
		std::cout << it.first << " => " << it.second << std::endl;
	}
}
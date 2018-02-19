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
	_links = new std::vector<std::pair<std::pair<std::string, size_t>, std::pair<std::string, size_t>>>;
	_chipsets = new std::vector<std::pair<std::string, std::string>>;
	_title = UNKONW;
}

Parse::Parse(const std::string &file)
	: _file(file)
{
	_links = new std::vector<std::pair<std::pair<std::string, size_t>, std::pair<std::string, size_t>>>;
	_chipsets = new std::vector<std::pair<std::string, std::string>>;
	_title = UNKONW;
}

Parse::~Parse()
{
	delete _links;
	delete _chipsets;
}

int Parse::read()
{
	if (_file.empty()) {
		std::cerr << "No files loaded" << std::endl;
		return (84);
	}
	return (this->read(_file));
}

int Parse::read(std::string file)
{
	std::ifstream in(file);

	if (!in) {
		std::cerr << "Can't open file" << std::endl;
		return (84);
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
	dumpLinks();
	return (manage_error());
}

void Parse::append_line(std::string line)
{
	auto elems = split_line(line);

	switch(_title) {
		case CHIPSETS:
		if (elems.size() == 2)
			_chipsets->push_back(std::pair<std::string,std::string>(elems[0], elems[1]));
		break;
		case LINKS:
		if (elems.size() == 2) {
			std::pair<std::string, size_t> first;
			std::pair<std::string, size_t> second;
			auto sub_elems = split_args(elems[0]);
			if (sub_elems.size() == 2)
				first = std::make_pair(sub_elems[0], std::stoi(sub_elems[1]));
			sub_elems = split_args(elems[1]);			
			if (sub_elems.size() == 2)
				second = std::make_pair(sub_elems[0], std::stoi(sub_elems[1]));
			_links->push_back(std::pair<std::pair<std::string, size_t>, std::pair<std::string, size_t>>(first, second));
		}
		break;
		default:
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

std::vector<std::string> Parse::split_args(const std::string &line) const
{
	std::vector<std::string> elems;
	std::string el;

	for (size_t i = 0; i < line.length(); i++) {
		if (line[i] == '#') {
			if (!el.empty())
				elems.push_back(el);
			return elems;
		}
		else if (line[i] == ':') {
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

bool Parse::find_elem(const std::string value) const
{
	for (const auto &el : *_chipsets) {
		if (el.first == value)
			return true;
	}
	return false;
}

int Parse::manage_error() const
{
	for (const auto &it : *_links) {
		if (!find_elem(it.first.first)) {
			std::cerr << "Chipset " << it.first.first << " not declared" << std::endl;
			return (84);
		}
	}
	return (0);
}

void Parse::dumpChipsets() const
{
	std::cout << "Dump Chipsets" << std::endl;
	for (const auto &it : *_chipsets) {
        	std::cout << it.first << " => " << it.second << std::endl;
	}
}

void Parse::dumpLinks() const
{
	std::cout << "Dump Links" << std::endl;
	for (const auto &it : *_links) {
		std::cout << "[" <<it.first.first << " => " << it.first.second << "] => ";
		std::cout << "[" <<it.second.first << " => " << it.second.second << "]" << std::endl;
	}
}
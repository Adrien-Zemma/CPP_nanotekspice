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
	_data = new std::map<std::string, std::string>;
}

Parse::Parse(const std::string &file)
	: _file(file)
{
	_data = new std::map<std::string, std::string>;
}

Parse::~Parse()
{
	delete _data;
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
	while (getline(in, line))
	{
		std::vector<std::string> elems = split_line(line);
		if (elems.size() == 2)
			_data->insert(std::pair<std::string, std::string>(elems[0], elems[1]));
		else if (elems.size() == 1)
		_data->insert(std::pair<std::string, std::string>(elems[0], ""));
	}
	std::cout << "Dump _data\n";
	for (auto &it : *_data)
    		std::cout << it.first << " => " << it.second << '\n';
	
}

std::vector<std::string> Parse::split_line(const std::string &line) const
{
	std::vector<std::string> elems;
	std::string el;

	for (unsigned int i = 0; i < line.length(); i++) {
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

std::map<std::string, std::string> *Parse::getData() const
{
	return _data;
}
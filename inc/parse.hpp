/*
** EPITECH PROJECT, 2017
** NanotekSpice
** File description:
** 
*/

#ifndef PARSE_HPP_
	#define PARSE_HPP_

#include <string>
#include <iostream>
#include <map>
#include <fstream>
#include <iterator>
#include <sstream>
#include <vector>

class Parse
{
public:
	Parse();
	Parse(const std::string &file);
	~Parse();
	
	void read();
	void read(std::string file);
	std::vector<std::string> split_line(const std::string &line) const;

	enum ParseTitle {
		CHIPSETS,
		LINKS
	};

private:
	int count_args(const std::string line) const;
	void append_line(std::string line);
	void dumpChipsets() const;

	std::map<std::string, std::string>		*_chipsets;
	std::map<std::pair<std::string, size_t>, std::pair<std::string, size_t>>	*_links;
	std::string				_file;
	Parse::ParseTitle			_title;
};

#endif /* !PARSE_HPP_ */

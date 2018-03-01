/*
** EPITECH PROJECT, 2017
** NanotekSpice
** File description:
** 
*/

#ifndef PARSE_HPP_
	#define PARSE_HPP_

#include <algorithm>
#include <string>
#include <iostream>
#include <map>
#include <fstream>
#include <iterator>
#include <sstream>
#include <vector>
#include <iterator>

class Parse
{
public:
	Parse();
	Parse(const std::string &file);
	~Parse();
	
	int read();
	int read(std::string file);
	std::vector<std::string> split_line(const std::string &line) const;
	std::vector<std::string> split_args(const std::string &line) const;
	std::vector<std::pair<std::pair
		<std::string, size_t>, 
		std::pair<std::string, size_t>>>	*getLink();
	std::vector<std::pair<std::string, std::string>>	*getChipset();
	void	dumpLinks() const;
	void	dumpChipsets() const;
	enum ParseTitle {
		UNKONW,
		CHIPSETS,
		LINKS
	};
	static std::vector<std::string> split(const std::string &line, char c);
	static void removeSpaces(std::string &input);

private:
	int count_args(const std::string line) const;
	void append_line(std::string line);
	int manage_error() const;
	bool find_elem(const std::string value) const;
	void append_chipsets(auto elems);
	void append_links(auto elems);

	std::vector<std::pair<std::string, std::string>>		*_chipsets;
	std::vector<std::pair<std::pair
		<std::string, size_t>, std::pair<std::string, size_t>>>	*_links;
	std::string				_file;
	Parse::ParseTitle			_title;
};

#endif /* !PARSE_HPP_ */

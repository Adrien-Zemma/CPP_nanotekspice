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
#include <vector>
#include <sstream>

class Parse
{
public:
	Parse();
	Parse(const std::string &file);
	~Parse();
	
	void read();
	void read(std::string file);
	std::map<std::string, std::string> *getData() const;
	std::vector<std::string> split_line(const std::string &line) const;

private:
	std::map<std::string, std::string>	*_data;
	std::string				_file;
};

#endif /* !PARSE_HPP_ */

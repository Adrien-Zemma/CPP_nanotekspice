/*
** EPITECH PROJECT, 2018
** cpp_nanotekspice
** File description:
** 
*/

#include "Driver.hpp"

Driver::Driver()
{
	this->_tab_function["loop"] = &Driver::loop;
	this->_tab_function["exit"] = &Driver::_exit;
	this->_tab_function["display"] = &Driver::display;
	this->_tab_function["simulate"] = &Driver::simulate;
	this->_tab_function["dump"] = &Driver::dump;
	this->_available_chipset["4001"] = new C_nor();
	this->_available_chipset["4008"] = new C_four_added();
	this->_available_chipset["4011"] = new C_nand();
	this->_available_chipset["4013"] = new C_flip_flop();
	this->_available_chipset["4017"] = new C_johnson();
	this->_available_chipset["4030"] = new C_xor();
	this->_available_chipset["4040"] = new C_conter();
	this->_available_chipset["4069"] = new C_invert();
	this->_available_chipset["4071"] = new C_or();
	this->_available_chipset["4081"] = new C_and();
	this->_available_chipset["4094"] = new C_register();
	this->_available_chipset["4514"] = new C_ram();
	this->_available_chipset["2716"] = new C_rom();
}

Driver::~Driver(){}

void file_chipsettab(std::vector <std::map<std::string, std::string>> data)
{
	for (auto el : data)
	{

	}
}

void Driver::shell()
{
	this->new_line();
	for (auto el = _tab_function.begin(); el != _tab_function.end(); ++el)
		if (el->first == _command)
			(this->*el->second)();
}

void Driver::new_line()
{
	std::cout << "> ";	
	std::cin >> this->_command;
}

void Driver::loop()
{
	std::cout << "loop" << std::endl;
}

void Driver::_exit()
{
	std::cout << "exit" << std::endl;
}

void Driver::display()
{
	std::cout << "display" << std::endl;	
}

void Driver::simulate()
{
	std::cout << "simulate" << std::endl;
}

void Driver::dump()
{
	std::cout << "dump" << std::endl;
}
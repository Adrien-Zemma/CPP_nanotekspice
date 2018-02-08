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
	fil_available_chipsettab();
	
}

Driver::~Driver(){}

void Driver::fil_available_chipsettab()
{
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

void Driver::file_chipsettab(std::vector <std::map<std::string, std::string>> *data)
{
	std::vector<std::map<std::string, std::string>>::iterator it;
	it = data->begin();
	for(; it != data->end(); it++){
		for(auto it1=it->begin();it1!=it->end();++it1) {
			create_component_shell(it1->first, it1->second);
			//std::cout << it1->first << " " << it1->second << std::endl; 
		}
	}
}

void Driver::create_component_shell(std::string component, std::string name)
{
	for (auto el : this->_available_chipset)
	{
		if (el.first == component)
		{
			_tab_chipset.push_back(el.second);
			std::cout << name << " create" << std::endl;
		}
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
	while(1)
		this->simulate();
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
	for(auto const& el: this->_tab_chipset)
		el.get()->dump;
}

void Driver::prepar_pin()
{
	//TODO fill le tableau 
	for (auto el : this->parse._data)
	{}
}
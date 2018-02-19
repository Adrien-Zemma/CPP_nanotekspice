/*
** EPITECH PROJECT, 2018
** cpp_nanotekspice
** File description:
** 
*/

#include "Pin.hpp"

Pin::Pin(std::string name)
{
	this->_name = name;
	this->_type = PIN;
	_pin_status.push_back(std::make_shared<nts::Tristate> (nts::Tristate(nts::UNDEFINED)));
	_pin_status.push_back(std::make_shared<nts::Tristate> (nts::Tristate(nts::UNDEFINED)));
}

nts::Tristate	Pin::calculate(size_t pin)
{
	return *this->_pin_status[pin].get();
}

/*void	Pin::dump() const
{
	std::cout << "Composent :\t" << this->_name << std::endl;
	std::cout << "pin " << 1 << " value = \t";
	std::cout <<  *this->_pin_status[1].get() << std::endl;
	std::cout << std::endl;
}*/
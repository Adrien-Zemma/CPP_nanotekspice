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
	this->_type = nts::PIN;
	_pin_status.push_back(std::make_shared<nts::Tristate>
		(nts::Tristate(nts::UNDEFINED)));
	_pin_status.push_back(std::make_shared<nts::Tristate>
		(nts::Tristate(nts::UNDEFINED)));
}

nts::Tristate	Pin::calculate(size_t pin)
{
	return *this->_pin_status[pin].get();
}
/*
** EPITECH PROJECT, 2018
** cpp_nanotekspice
** File description:
** 
*/

#include "Pin.hpp"

Pin::Pin(std::string name){
	this->_name = name;
	std::shared_ptr<nts::Tristate> tmp (new nts::Tristate(nts::UNDEFINED));
	_pin_status.push_back(tmp);
	_pin_status.push_back(tmp);

}

nts::Tristate	Pin::calculate(size_t pin)
{
	return *this->_pin_status[pin].get();
}

std::shared_ptr<nts::Tristate> Pin::getPinPtr(size_t pin)
{
	return this->_pin_status[pin];
}

void	Pin::dump() const
{
	std::cout << "Composent :\t" << this->_name << std::endl;
	std::cout << "pin " << 1 << " value = \t";
	std::cout <<  *this->_pin_status[0] << std::endl;
	std::cout << std::endl;
}
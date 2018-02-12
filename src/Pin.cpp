/*
** EPITECH PROJECT, 2018
** cpp_nanotekspice
** File description:
** 
*/

#include "Pin.hpp"

Pin::Pin(std::string name){
	this->_name = name;
}
// Pin::~Pin(){}

nts::Tristate	Pin::calculate(size_t pin)
{
	return *this->_pin_status[pin].get();
}

std::shared_ptr<nts::Tristate> Pin::getPinPtr(size_t pin)
{
	return this->_pin_status[pin];
}
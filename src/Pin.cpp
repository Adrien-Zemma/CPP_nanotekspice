/*
** EPITECH PROJECT, 2018
** cpp_nanotekspice
** File description:
** 
*/

#include "Pin.hpp"
#include "Driver.hpp"

Pin::Pin(const std::string &name) noexcept
{
	this->_name = name;
	this->_type = nts::PIN;
	_pin_status.push_back(std::make_shared<nts::Tristate>
		(nts::Tristate(nts::UNDEFINED)));
	_pin_status.push_back(std::make_shared<nts::Tristate>
		(nts::Tristate(nts::UNDEFINED)));
}

Pin::Pin(const std::string &value, const std::string &name) noexcept
{
	this->_name = name;
	this->_type = nts::PIN;
	this->_value = Driver::stringToTristate(value);
	_pin_status.push_back(std::make_shared<nts::Tristate>
		(nts::Tristate(nts::UNDEFINED)));
	_pin_status.push_back(std::make_shared<nts::Tristate>
		(nts::Tristate(nts::UNDEFINED)));
}

nts::Tristate	Pin::calculate(const size_t &pin) noexcept
{
	return *this->_pin_status[pin].get();
}
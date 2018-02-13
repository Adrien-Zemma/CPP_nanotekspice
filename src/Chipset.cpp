/*
** EPITECH PROJECT, 2018
** cpp_nanotekspice
** File description:
** 
*/

#include "Chipset.hpp"

Chipset::Chipset()
{
	for(int i = 0; i <= 20 ; i++)
		_pin_status.push_back(std::shared_ptr<nts::Tristate>(new nts::Tristate(nts::UNDEFINED)));
}

nts::Tristate	Chipset::compute(std::size_t pin)
{
	return this->calculate(pin);
}

void Chipset::setName(std::string name)
{
	this->_name = name;
}

std::shared_ptr<nts::Tristate> Chipset::getPinPtr(int index)
{
	return _pin_status[index];
}

void	Chipset::setPinPtr(int index, std::shared_ptr<nts::Tristate> status)
{
	this->_pin_status[index] = status;
}

nts::Tristate	Chipset::getPinValue(int index)
{
	return *_pin_status[index].get();
}

void	Chipset::setPinValue(int index, nts::Tristate value)
{
	*_pin_status[index] = value;
}

void	Chipset::dump() const
{
	int i = -1;
	std::cout << "Composent :\t" << this->_name << std::endl;
	for (auto el : this->_pin_status)
		std::cout << "pin " << ++i << " value = \t" << *el.get() << std::endl;
	std::cout << std::endl;
}

void	Chipset::setLink (std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
	this->_pin_status[pin] = other.getPinPtr(otherPin);
}

std::string 	Chipset::getName()
{
	return this->_name;
}

std::ostream &operator<<(std::ostream &s, const nts::Tristate &o)
{
	if (o == nts::UNDEFINED)
		return  s << "UNDEFINED";
	else if (o == nts::TRUE)
		return s << "TRUE";
	else if (o == nts::FALSE)
		return s << "FASLE";
}
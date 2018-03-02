/*
** EPITECH PROJECT, 2018
** cpp_nanotekspice
** File description:
**
*/

#include "Chipset.hpp"

Chipset::Chipset()
{
	_pinMax = 25;
	for (size_t i = 0; i <= this->_pinMax ; i++)
		this->_pin_status.push_back(std::make_shared<nts::Tristate>
			(nts::Tristate(nts::UNDEFINED)));
}

Chipset::~Chipset()
{
}

nts::Type	Chipset::getType()
{
	return this->_type;
}

nts::Tristate	Chipset::compute(std::size_t pin)
{
	return this->calculate(pin);
}

void	Chipset::setName(std::string name)
{
	this->_name = name;
}

std::shared_ptr<nts::Tristate> Chipset::getPinPtr(int index)
{
	std::cout << _name <<"\t"<<index << std::endl;
	std::cout << (_pin_status[index] == nullptr ? "C'est null" : "Wala je sais pas ce qui se passe") << std::endl;
	return _pin_status[index];
}

void	Chipset::setPinPtr(int index, std::shared_ptr<nts::Tristate> status)
{
	this->_pin_status[index] = status;
}

nts::Tristate	Chipset::getPinValue(int index)
{
	return *this->_pin_status[index].get();
}

void	Chipset::setPinValue(int index, nts::Tristate value)
{
	*this->_pin_status[index].get() = value;
}

void	Chipset::setPinValue(int index, std::string value)
{
	if (value == "1")
		*this->_pin_status[index].get() = nts::TRUE;
	else if (value == "0")
		*this->_pin_status[index].get() = nts::FALSE;
	else
		*this->_pin_status[index].get() = nts::UNDEFINED;
}

size_t	Chipset::getPinMax()
{
	return this->_pinMax;
}

void	Chipset::dumpPin() const
{
	std::cout << this->_name << "=" << *this->_pin_status[1].get();
	std::cout << std::endl;
}

void	Chipset::dump() const
{
	if (_type == nts::PIN) {
		this->dumpPin();
		return ;
	}
	else {
		for (size_t i = 1; i <= this->_pinMax; i++){
			std::cout << _name << " : " << i << "\t= ";
			std::cout << *this->_pin_status[i].get() << std::endl;
		}
	}
}

void	Chipset::setLink (std::size_t pin, nts::IComponent &other,
	std::size_t otherPin)
{
	this->setPinPtr(pin, other.getPinPtr(otherPin));
}

std::string 	Chipset::getName()
{
	return this->_name;
}

nts::Tristate	Chipset::getValue()
{
	return this->_value;
}

std::ostream &operator<<(std::ostream &s, const nts::Tristate &o)
{
	if (o == nts::UNDEFINED)
		return  s << 'U';
	else if (o == nts::TRUE)
		return s << 1;
	else if (o == nts::FALSE)
		return s << 0;
}

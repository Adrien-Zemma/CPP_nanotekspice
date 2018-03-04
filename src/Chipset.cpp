/*
** EPITECH PROJECT, 2018
** cpp_nanotekspice
** File description:
**
*/

#include "Chipset.hpp"

Chipset::Chipset() noexcept
{
	_pinMax = 25;
	for (size_t i = 0; i <= this->_pinMax ; i++)
		this->_pin_status.push_back(std::make_shared<nts::Tristate>
			(nts::Tristate(nts::UNDEFINED)));
}

Chipset::~Chipset()
{
}

nts::Type	Chipset::getType() const noexcept
{
	return this->_type;
}

nts::Tristate	Chipset::compute(const std::size_t &pin) noexcept
{
	return this->calculate(pin);
}

void	Chipset::setName(const std::string &name) noexcept
{
	this->_name = name;
}

std::shared_ptr<nts::Tristate> Chipset::getPinPtr(const int &index) const noexcept
{	
	return _pin_status[index];
}

void	Chipset::setPinPtr(const int &index, std::shared_ptr<nts::Tristate> status) noexcept
{
	this->_pin_status[index] = status;
}

nts::Tristate	Chipset::getPinValue(const int &index) const noexcept
{
	return *this->_pin_status[index].get();
}

void	Chipset::setPinValue(const int &index, const nts::Tristate &value) noexcept
{
	*this->_pin_status[index].get() = value;
}

void	Chipset::setPinValue(const int &index, const std::string &value) noexcept
{
	if (value == "1")
		*this->_pin_status[index].get() = nts::TRUE;
	else if (value == "0")
		*this->_pin_status[index].get() = nts::FALSE;
	else
		*this->_pin_status[index].get() = nts::UNDEFINED;
}

size_t	Chipset::getPinMax() const noexcept
{
	return this->_pinMax;
}

void	Chipset::dumpPin() const noexcept
{
	std::cout << this->_name << "=" << *this->_pin_status[1].get();
	std::cout << std::endl;
}

void	Chipset::dump() const noexcept
{
	if (_type == nts::PIN) {
		this->dumpPin();
		return ;
	}
	else {
		std::cout << "-----" << _name << "-----" << std::endl;
		for (size_t i = 1; i <= this->_pinMax; i++){
			std::cout << _name << " : " << i << "\t= ";
			std::cout << *this->_pin_status[i].get() << std::endl;
		}
	}
}

void	Chipset::setLink (const std::size_t &pin, nts::IComponent &other,
	const std::size_t &otherPin) noexcept
{
	this->setPinPtr(pin, other.getPinPtr(otherPin));
}

std::string 	Chipset::getName() const noexcept
{
	return this->_name;
}

nts::Tristate	Chipset::getValue() const noexcept
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

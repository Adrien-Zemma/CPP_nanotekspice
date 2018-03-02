/*
** EPITECH PROJECT, 2018
** cpp_nanotekspice
** File description:
** 
*/

#ifndef PIN_HPP_
	#define PIN_HPP_

#include "Chipset.hpp"

class Pin : public Chipset
{
public:
	Pin(const std::string &name) noexcept;
	Pin(const std::string &value, const std::string &name) noexcept;
	std::shared_ptr<nts::Tristate> getPinPtr(const size_t &pin) const noexcept;
	nts::Tristate	calculate(const size_t &pin) noexcept;
	
private:
	std::vector<std::shared_ptr<nts::Tristate>>	_pin_status;
};

#endif /* !PIN_HPP_ */

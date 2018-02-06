/*
** EPITECH PROJECT, 2018
** cpp_nanotekspice
** File description:
** 
*/

#ifndef CHIPSET_HPP_
	#define CHIPSET_HPP_

#include "IComponent.hpp"

class Chipset :public nts::IComponent
{
public:
	nts::Tristate			compute(std::size_t pin);
	std::shared_ptr<nts::Tristate>	getPin_ptr(int index);
	void 				setPin_ptr(int, std::shared_ptr<nts::Tristate>);
	nts::Tristate 			getPin_value(int index);
	void				setPin_value(int index, nts::Tristate);
	void				setLink (std::size_t pin, nts::IComponent &other, std::size_t otherPin);
	void				dump() const;
	nts::Tristate			calculate();

protected:
	std::vector <std::shared_ptr<nts::Tristate>>	_pin_status;
	std::vector<std::shared_ptr<nts::Tristate>>	_output;
	nts::Tristate					clock;
	std::string					_name;
};

#endif /* !CHIPSET_HPP_ */

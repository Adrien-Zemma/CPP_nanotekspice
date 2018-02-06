/*
** EPITECH PROJECT, 2018
** cpp_nanotekspice
** File description:
** 
*/

#ifndef C_OR_HPP_
	#define C_OR_HPP_

#include "IComponent.hpp"

class C_or: public nts::IComponent
{
public:
	C_or();
	void				calculate();
	nts::Tristate			compute(std::size_t pin);
	void				setLink (std::size_t pin, nts::IComponent &other, std::size_t otherPin);
	void				dump() const;
	void				_or(int index1, int index2, int output);
private:
	std::vector <nts::Tristate>	_pin_status;
	std::string			_name;
	nts::Tristate 			_clock;
};


#endif /* !C_OR_HPP_ */

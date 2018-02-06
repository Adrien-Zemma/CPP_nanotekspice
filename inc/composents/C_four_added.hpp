/*
** EPITECH PROJECT, 2018
** cpp_nanotekspice
** File description:
** 
*/

#ifndef C_FOUR_ADDED_HPP_
	#define C_FOUR_ADDED_HPP_

#include "IComponent.hpp"

#define CARRY_OUT 14

class C_four_added: public nts::IComponent
{
public:
	C_four_added();
	void calculate();
	nts::Tristate compute(std::size_t pin);
	void setLink (std::size_t pin, nts::IComponent &other, std::size_t otherPin);
	void dump() const;
private:
	void _added(int index1, int index2, int carry_in, int output);
	std::vector <nts::Tristate> _pin_status;
	std::string _name;
	nts::Tristate clock;
};

#endif /* !C_FOUR_ADDED_HPP_ */

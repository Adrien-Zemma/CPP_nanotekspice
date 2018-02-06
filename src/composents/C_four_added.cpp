/*
** EPITECH PROJECT, 2018
** cpp_nanotekspice
** File description:
** 
*/

#include "C_four_added.hpp"

C_four_added::C_four_added(){}

nts::Tristate C_four_added::compute(std::size_t pin)
{
	return nts::UNDEFINED;
}

void C_four_added::setLink (std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
}

void C_four_added::dump() const 
{
	std::cout << "dump" << std::endl;
}

void C_four_added::_added(int index1, int index2, int carry_in ,int output)
{
	std::vector <nts::Tristate> tab_a {nts::FALSE, nts::TRUE, nts::FALSE, nts::TRUE, nts::FALSE, nts::TRUE, nts::FALSE, nts::TRUE};
	std::vector <nts::Tristate> tab_b {nts::FALSE, nts::FALSE, nts::TRUE, nts::TRUE, nts::FALSE, nts::FALSE, nts::TRUE, nts::TRUE};
	std::vector <nts::Tristate> tab_c {nts::FALSE, nts::FALSE, nts::FALSE, nts::FALSE, nts::TRUE, nts::TRUE, nts::TRUE, nts::TRUE};
	std::vector <nts::Tristate> tab_p {nts::FALSE, nts::FALSE, nts::FALSE, nts::TRUE, nts::FALSE, nts::TRUE, nts::TRUE, nts::TRUE};
	std::vector <nts::Tristate> tab_o {nts::FALSE, nts::TRUE, nts::TRUE, nts::FALSE, nts::TRUE, nts::FALSE, nts::FALSE, nts::TRUE};

	for (int el = 0; el <= tab_a.size() + 1; el++)
	{
		if (this->_pin_status[index1] == tab_a[el] && 
			this->_pin_status[index2] == tab_b[el] &&
			this->_pin_status[carry_in] == tab_c[el])
		{
			this->_pin_status[CARRY_OUT] = tab_c[el];
			this->_pin_status[output] = tab_o[el];
			return ;
		}
	}
	this->_pin_status[CARRY_OUT] = nts::UNDEFINED;
	this->_pin_status[output] = nts::UNDEFINED;
}

void C_four_added::calculate()
{
	_added(7, 6, 9, 10);
	_added(5, 4, 10, 11);
	_added(3, 2, 11, 12);
	_added(1, 15, 12, 13);
}
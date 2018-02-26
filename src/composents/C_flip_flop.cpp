/*
** EPITECH PROJECT, 2018
** cpp_nanotekspice
** File description:
** 
*/

#include "C_flip_flop.hpp"

C_flip_flop::C_flip_flop(nts::Tristate cloc)
{
	this->_type = nts::CHIPSETS;
	this->_clock = cloc;
}

void	C_flip_flop::_flip_flop(std::vector<int> set)
{
	std::vector<nts::Tristate> table1 = {nts::TRUE, nts::FALSE, nts::FALSE, nts::FALSE, nts::FALSE, nts::TRUE};
	std::vector<nts::Tristate> table2 = {nts::TRUE, nts::FALSE, nts::FALSE, nts::TRUE, nts::TRUE, nts::FALSE};
	std::vector<nts::Tristate> table3 = {nts::FALSE, nts::FALSE, nts::TRUE, nts::FALSE, nts::FALSE, nts::TRUE};
	std::vector<nts::Tristate> table4 = {nts::FALSE, nts::TRUE, nts::FALSE, nts::FALSE, nts::TRUE, nts::FALSE};
	std::vector<nts::Tristate> table5 = {nts::FALSE, nts::TRUE, nts::TRUE, nts::FALSE, nts::TRUE, nts::TRUE};
}

nts::Tristate C_flip_flop::calculate(size_t index)
{
	std::vector<int> set1 = {1, 2, 4, 3, 5, 6};
	std::vector<int> set2 = {13, 12, 10, 11, 9, 8};
	if (index == 1 || index == 2)
		_flip_flop(set1);
	else if (index == 12 || index == 13)
		_flip_flop(set2);
	return *this->_pin_status[index].get();
}
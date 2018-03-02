/*
** EPITECH PROJECT, 2018
** cpp_nanotekspice
** File description:
** 
*/

#ifndef C_FOUR_ADDED_HPP_
	#define C_FOUR_ADDED_HPP_

#define CARRY_OUT 14

#include "Chipset.hpp"


class C_four_added: public Chipset
{
public:
	C_four_added();
	nts::Tristate calculate(const size_t &index) noexcept;
private:
	void _added(int index1, int index2, int carry_in ,int output);
};

#endif /* !C_FOUR_ADDED_HPP_ */

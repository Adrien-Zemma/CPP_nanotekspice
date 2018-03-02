/*
** EPITECH PROJECT, 2018
** cpp_nanotekspice
** File description:
** 
*/

#ifndef C_JOHNSON_HPP_
	#define C_JOHNSON_HPP_

#include "Chipset.hpp"

class C_johnson: public Chipset
{
public:
	C_johnson();
private:
	size_t _nb_clock = 0;
	std::vector<std::vector<nts::Tristate>> table;
	nts::Tristate calculate(const size_t &index) noexcept;
};

#endif /* !C_JOHNSON_HPP_ */

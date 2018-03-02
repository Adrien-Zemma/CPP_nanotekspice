/*
** EPITECH PROJECT, 2018
** cpp_nanotekspice
** File description:
** 
*/

#ifndef C_AND_HPP_
	#define C_AND_HPP_

#include "Chipset.hpp"

class C_and: public Chipset
{
public:
	C_and();
	nts::Tristate calculate(const size_t &index) noexcept;
private:
	void _and(size_t index, size_t index2, size_t out);
};

#endif /* !C_AND_HPP_ */

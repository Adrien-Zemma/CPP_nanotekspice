/*
** EPITECH PROJECT, 2018
** cpp_nanotekspice
** File description:
** 
*/

#ifndef C_CONTER_HPP_
	#define C_CONTER_HPP_

#include "Chipset.hpp"

class C_conter: public Chipset
{
public:
	C_conter();
private:
	nts::Tristate calculate(const size_t &index) noexcept;
};

#endif /* !C_CONTER_HPP_ */

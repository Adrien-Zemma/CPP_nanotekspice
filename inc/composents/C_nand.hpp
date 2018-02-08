/*
** EPITECH PROJECT, 2018
** cpp_nanotekspice
** File description:
** 
*/

#ifndef C_NAND_HPP_
	#define C_NAND_HPP_

#include "Chipset.hpp"

class C_nand: public Chipset
{
public:
	C_nand();
private:
	nts::Tristate calculate(int index);
};

#endif /* !C_NAND_HPP_ */

/*
** EPITECH PROJECT, 2018
** cpp_nanotekspice
** File description:
** 
*/

#include "IComponent.hpp"

#ifndef C_NOR_HPP_
	#define C_NOR_HPP_

#include "Chipset.hpp"

class C_nor: public Chipset
{
public:
	C_nor();
private:
	nts::Tristate calculate(int index);
};

#endif /* !C_NOR_HPP_ */

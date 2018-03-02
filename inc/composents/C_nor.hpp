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
	nts::Tristate calculate(const size_t &index) noexcept;
private:
	void _nor(size_t index, size_t index2, size_t out);
};

#endif /* !C_NOR_HPP_ */

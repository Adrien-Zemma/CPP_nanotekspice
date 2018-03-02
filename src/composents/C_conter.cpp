/*
** EPITECH PROJECT, 2018
** cpp_nanotekspice
** File description:
** 
*/

#include "C_conter.hpp"

C_conter::C_conter()
{
	this->_type = nts::CHIPSETS;
	this->_pinMax = 16;
}

nts::Tristate C_conter::calculate(const size_t &index) noexcept
{
	/*
	faire un tableau de pointer sur fonction pour choisire quelle fonctin en fonction de quelle output
	*/
	(void) index;
	return nts::UNDEFINED;
}
/*
** EPITECH PROJECT, 2018
** cpp_nanotekspice
** File description:
** 
*/

#include "C_johnson.hpp"

C_johnson::C_johnson()
{
	this->_type = nts::CHIPSETS;
}


nts::Tristate C_johnson::calculate(const size_t &index) noexcept
{
	/*
	faire un tableau de pointer sur fonction pour choisire quelle fonctin en fonction de quelle output
	*/
	(void) index;
	return nts::UNDEFINED;
}
/*
** EPITECH PROJECT, 2018
** cpp_nanotekspice
** File description:
** 
*/

#include "C_ram.hpp"

C_ram::C_ram()
{
	this->_type = nts::CHIPSETS;
}


nts::Tristate C_ram::calculate(const size_t &index) noexcept
{
	/*
	faire un tableau de pointer sur fonction pour choisire quelle fonctin en fonction de quelle output
	*/
	(void) index;
	return nts::UNDEFINED;
}
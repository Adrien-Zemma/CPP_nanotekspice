/*
** EPITECH PROJECT, 2018
** cpp_nanotekspice
** File description:
** 
*/

#include "C_four_added.hpp"

C_four_added::C_four_added()
{
	this->_type = nts::CHIPSETS;
}

nts::Tristate C_four_added::calculate(size_t index)
{
	switch (index) {
		case 13:
			_added(1, 15, 12, 13);
		break;
		case 12:
			_added(2, 3, 11, 12);
		break;
		case 11:
			_added(4, 5, 10, 11);
		break;
		case 10:
			_added(6, 7, 9, 10);
		break;
	}
	return *this->_pin_status[index];
}

void C_four_added::_added(int index1, int index2, int carry_in ,int output)
{
	std::vector <nts::Tristate> tab_a {nts::FALSE, nts::TRUE, nts::FALSE,
		nts::TRUE, nts::FALSE, nts::TRUE, nts::FALSE, nts::TRUE};
	std::vector <nts::Tristate> tab_b {nts::FALSE, nts::FALSE, nts::TRUE,
		nts::TRUE, nts::FALSE, nts::FALSE, nts::TRUE, nts::TRUE};
	std::vector <nts::Tristate> tab_c {nts::FALSE, nts::FALSE, nts::FALSE,
		nts::FALSE, nts::TRUE, nts::TRUE, nts::TRUE, nts::TRUE};
	std::vector <nts::Tristate> tab_p {nts::FALSE, nts::FALSE, nts::FALSE,
		 nts::TRUE, nts::FALSE, nts::TRUE, nts::TRUE, nts::TRUE};
	std::vector <nts::Tristate> tab_o {nts::FALSE, nts::TRUE, nts::TRUE,
		 nts::FALSE, nts::TRUE, nts::FALSE, nts::FALSE, nts::TRUE};

	for (size_t el = 0; el <= tab_a.size() + 1; el++)
	{
		if (*this->_pin_status[index1].get() == tab_a[el] && 
			*this->_pin_status[index2].get() == tab_b[el] &&
			*this->_pin_status[carry_in].get() == tab_c[el])
		{
			*this->_pin_status[CARRY_OUT] = tab_c[el];
			*this->_pin_status[output] = tab_o[el];
			return ;
		}
	}
	*this->_pin_status[CARRY_OUT] = nts::UNDEFINED;
	*this->_pin_status[output] = nts::UNDEFINED;
}


/*
	5 point noter de 0 a 4
	- qualiter presa
	(comment on a fait le projet repartition des tache)
	- maintenabiliter (l'architecture / norme)
	- organisation et methodologie (les commits repartition des taches / versionnigue)
	- bonus
	- test unitaire (pertinace)
*/
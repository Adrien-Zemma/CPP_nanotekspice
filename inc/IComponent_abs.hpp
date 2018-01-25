/*
** EPITECH PROJECT, 2018
** cpp_nanotekspice
** File description:
** 
*/

#ifndef ICOMPONENT_ABS_HPP_
	#define ICOMPONENT_ABS_HPP_

#include "IComponent.hpp"

class IComponent_abs : public nts::IComponent
{
public:
	void calculation();
	nts::Tristate getOutput();
	void setLink(std::map <std::string std::string> link);
protected:
	int 					_nb_pin;
	std::string 				_name;
	//std::map <std::string std::string>	_chipsets;
	std::map <std::string nts::Tristate>	_input_status;
	std::map <std::string std::string>	_link;
	vector <nts::Tristate> 				_status_pin(20, UNDEFINED);
};

#endif /* !ICOMPONENT_ABS_HPP_ */

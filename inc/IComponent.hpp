/*
** EPITECH PROJECT, 2018
** cpp_nanotekspice
** File description:
** 
*/

#ifndef ICOMPONENT_HPP_
	#define ICOMPONENT_HPP_

#include <iostream>
#include <vector>
#include <memory>


namespace	nts
{
	enum	Tristate {
		UNDEFINED = (-true),
		TRUE = true,
		FALSE = false
	};
	class	IComponent
	{
	public:
		virtual 		~IComponent() = default;
		virtual nts::Tristate	compute(std::size_t pin = 1) = 0;
		virtual void		setLink (std::size_t pin, nts::IComponent &other,
					std::size_t otherPin) = 0;
		virtual void		dump() const = 0;
		virtual std::shared_ptr<nts::Tristate>	getPin_ptr(int index) = 0;
	};
}

#endif /* !ICOMPONENT_HPP_ */

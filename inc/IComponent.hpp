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
	enum Type
	{
		PIN,
		CHIPSETS
	};
	class	IComponent
	{
	public:
		virtual 		~IComponent() = default;
		virtual nts::Tristate	compute(std::size_t pin = 1) = 0;
		virtual void		setLink (std::size_t pin, nts::IComponent &other,
					std::size_t otherPin) = 0;
		virtual void		dump() const = 0;
		virtual std::string	getName() = 0;
		virtual std::shared_ptr<nts::Tristate>	getPinPtr(int index) = 0;
		virtual void				setName(std::string name) = 0;
		virtual void	setPinValue(int index, nts::Tristate) = 0;
		virtual void	setPinValue(int index, std::string value) = 0;
		virtual	size_t	getPinMax() = 0;
		virtual	nts::Tristate	getPinValue(int index) = 0;
		virtual void	setPinPtr(int index, std::shared_ptr<nts::Tristate> status) = 0;
		virtual	nts::Type	getType() = 0;
	};
}
std::ostream &operator<<(std::ostream &s, const nts::Tristate &o);

#endif /* !ICOMPONENT_HPP_ */

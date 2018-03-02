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
#include <csignal>


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
		virtual nts::Tristate	compute(const std::size_t &pin = 1) noexcept = 0;
		virtual void		setLink (const std::size_t &pin, nts::IComponent &other,
					const std::size_t &otherPin) = 0;
		virtual void		dump() const noexcept = 0;
		virtual std::string	getName() const noexcept = 0;
		virtual std::shared_ptr<nts::Tristate>	getPinPtr(const int &index) const noexcept = 0;
		virtual void				setName(const std::string &name) noexcept = 0;
		virtual void	setPinValue(const int &index, const nts::Tristate &) noexcept = 0;
		virtual void	setPinValue(const int &index, const std::string &value) noexcept = 0;
		virtual	size_t	getPinMax() const noexcept= 0;
		virtual	nts::Tristate	getPinValue(const int &index) const noexcept = 0;
		virtual void	setPinPtr(const int &index, std::shared_ptr<nts::Tristate> status) noexcept = 0;
		virtual	nts::Type	getType() const noexcept = 0;
		virtual nts::Tristate	getValue() const noexcept = 0;
	};
}
std::ostream &operator<<(std::ostream &s, const nts::Tristate &o);

#endif /* !ICOMPONENT_HPP_ */

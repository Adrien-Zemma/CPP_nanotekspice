/*
** EPITECH PROJECT, 2018
** cpp_nanotekspice
** File description:
** 
*/

#ifndef DRIVER_HPP_
	#define DRIVER_HPP_

#include <iostream>
#include <map>
#include <vector>
#include <memory>
#include <csignal>
#include "IComponent.hpp"
#include "Chipset.hpp"
#include "Pin.hpp"
#include "Parse.hpp"
#include "C_and.hpp"
#include "C_conter.hpp"
#include "C_flip_flop.hpp"
#include "C_four_added.hpp"
#include "C_invert.hpp"
#include "C_johnson.hpp"
#include "C_nand.hpp"
#include "C_nor.hpp"
#include "C_or.hpp"
#include "C_ram.hpp"
#include "C_register.hpp"
#include "C_rom.hpp"
#include "C_xor.hpp"

class Driver
{
public:
	Driver(char **arg);
	~Driver();
	void	shell();
	void	_init(char *file, char **av);
	Parse	parse;
	static nts::Tristate	stringToTristate(const std::string &value);
private:
	std::unique_ptr<nts::IComponent>	creat4001(const std::string
		&value) const noexcept;
	std::unique_ptr<nts::IComponent>	creat4008(const std::string
		 &value) const noexcept;
	std::unique_ptr<nts::IComponent>	creat4011(const std::string
		 &value) const noexcept;
	std::unique_ptr<nts::IComponent>	creat4013(const std::string
		 &value) const noexcept;
	std::unique_ptr<nts::IComponent>	creat4017(const std::string
		 &value) const noexcept;
	std::unique_ptr<nts::IComponent>	creat4030(const std::string
		 &value) const noexcept;
	std::unique_ptr<nts::IComponent>	creat4040(const std::string
		 &value) const noexcept;
	std::unique_ptr<nts::IComponent>	creat4069(const std::string
		 &value) const noexcept;
	std::unique_ptr<nts::IComponent>	creat4071(const std::string
		 &value) const noexcept;
	std::unique_ptr<nts::IComponent>	creat4081(const std::string
		 &value) const noexcept;
	std::unique_ptr<nts::IComponent>	creat4094(const std::string
		 &value) const noexcept;
	std::unique_ptr<nts::IComponent>	creat4514(const std::string
		 &value) const noexcept;
	std::unique_ptr<nts::IComponent>	creat2716(const std::string
		 &value) const noexcept;
	void 	loop();
	void 	dump();
	void	_exit();
	void	display();
	void	setclock();
	void 	simulate();
	void	dumpAll();
	void	filTabFactory();
	void 	filAvailableChipsetTab();
	bool	isAChipset(std::string);
	void	makeLink();
	void	setValue();
	void	reverseClock();
	void	readAv(char **av);
	void	makeLink2(std::pair <std::pair<std::string, size_t>, 
	std::pair<std::string, size_t>> link, 
	std::unique_ptr<nts::IComponent> &chipset);
	nts::IComponent	&getComponentFromName(std::string name);
	bool	getComponentFromNameBool(std::string name);
	void	checkUndefined(std::unique_ptr<nts::IComponent> &el);
	void	checkLinks();
	std::unique_ptr<nts::IComponent>	chipsetFactory(std::string type,
		std::string name);
	std::string	_commande;
	nts::Tristate	_clock;
	std::string	_file;
	std::map <std::string, void (Driver::*)()>	_tab_function;
	std::map <std::string, std::unique_ptr<nts::IComponent> (Driver::*)(const std::string &value) const noexcept>	_tab_factory;
	std::map <std::string, nts::IComponent *>	_available_chipset;
	std::vector <std::unique_ptr<nts::IComponent>>	_tab_chipset;
	std::vector <std::unique_ptr<nts::IComponent>>	_tab_input;
	std::vector <std::unique_ptr<nts::IComponent>>	_tab_output;
	bool	_exit_status;	
};

#endif /* !SHELL_HPP_ */

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
#include "IComponent.hpp"
#include "C_and.hpp"
#include "C_conter.hpp"
#include "C_flip_flop.hpp"
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
	Driver();
	~Driver();
	void shell();
	void file_chipsettab(std::vector <std::map<std::string, std::string>> *data);

	std::unique_ptr < nts::IComponent> creat4001 (const std::string &value) const noexcept;
	std::unique_ptr < nts::IComponent> creat4008 (const std::string &value) const noexcept;
	std::unique_ptr < nts::IComponent> creat4011 (const std::string &value) const noexcept;
	std::unique_ptr < nts::IComponent> creat4013 (const std::string &value) const noexcept;
	std::unique_ptr < nts::IComponent> creat4017 (const std::string &value) const noexcept;
	std::unique_ptr < nts::IComponent> creat4030 (const std::string &value) const noexcept;
	std::unique_ptr < nts::IComponent> creat4040 (const std::string &value) const noexcept;
	std::unique_ptr < nts::IComponent> creat4069 (const std::string &value) const noexcept;
	std::unique_ptr < nts::IComponent> creat4071 (const std::string &value) const noexcept;
	std::unique_ptr < nts::IComponent> creat4081 (const std::string &value) const noexcept;
	std::unique_ptr < nts::IComponent> creat4094 (const std::string &value) const noexcept;
	std::unique_ptr < nts::IComponent> creat4514 (const std::string &value) const noexcept;
	std::unique_ptr < nts::IComponent> creat2716 (const std::string &value) const noexcept;

private:
	void setclock();
	void new_line();
	void _exit();
	void display();
	void simulate();
	void loop();
	void dump();
	void fil_available_chipsettab();
	void create_component_shell(std::string component, std::string name);
	std::string _command;
	nts::Tristate _clock;
	std::string _file;
	std::map <std::string, void (Driver::*)()> _tab_function;
	std::map <std::string, nts::IComponent *> _tab_chipset;
	std::map <std::string, nts::IComponent *> _available_chipset;
};

#endif /* !SHELL_HPP_ */

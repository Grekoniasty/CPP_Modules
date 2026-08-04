#include "PhoneBook.class.hpp"
#include "Contact.class.hpp"
#include <iostream>

int	main(void)
{
	PhoneBook	phonebook;
	std::string	cmd;

	while (std::getline(std::cin, cmd))
	{
		if (cmd == "ADD")
			phonebook.add();
		else if (cmd == "SEARCH")
			phonebook.search();
		else if (cmd == "EXIT")
			break ;
	}
	return (0);
}

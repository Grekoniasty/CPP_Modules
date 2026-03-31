#include "PhoneBook.class.hpp"
#include <iomanip>
#include <cstdlib>
PhoneBook::PhoneBook()
{
	_contactCount = 0;
}

PhoneBook::~PhoneBook()
{
}
std::string truncate(std::string str)
{
	if (str.length() > 10)
		return (str.substr(0, 9) + ".");
	return (str);
}

void PhoneBook::add()
{
	std::string input;
	std::cout << "Input the First Name: ";
	std::getline(std::cin, input);
	_contacts[_contactCount % 8].SetFirstName(input);
	std::cout << "Input the Last Name: ";
	std::getline(std::cin, input);
	_contacts[_contactCount % 8].SetLastName(input);
	std::cout << "Input the Nickname: ";
	std::getline(std::cin, input);
	_contacts[_contactCount % 8].SetNickname(input);
	std::cout << "Set phone Number: ";
	std::getline(std::cin, input);
	_contacts[_contactCount % 8].SetPhoneNumber(input);
	std::cout << "Set Darkest Secret: ";
	std::getline(std::cin, input);
	_contacts[_contactCount % 8].SetDarkestSecret(input);
	_contactCount++;
}

void	PhoneBook::search()
{
	std::string	input;
	int		index;

	std::cout << std::setw(10) << "index" << "|"
		<< std::setw(10) << "first name" << "|"
		<< std::setw(10) << "last name" << "|"
		<< std::setw(10) << "nickname" << std::endl;
	for (int i = 0; i < _contactCount && i < 8; i++)
	{
		std::cout << std::setw(10) << i << "|"
			<< std::setw(10) << truncate(_contacts[i].getFirstName()) << "|"
			<< std::setw(10) << truncate(_contacts[i].getLastName()) << "|"
			<< std::setw(10) << truncate(_contacts[i].getNickname()) << std::endl;
	}
	std::cout << "Enter index: ";
	std::getline(std::cin, input);
	index = atoi(input.c_str());

	if (index < 0 || index >= _contactCount || index >= 8)
	{
		std::cout << "Invalid index." << std::endl;
		return ;
	}
	std::cout << _contacts[index].getFirstName() << std::endl;
	std::cout << _contacts[index].getLastName() << std::endl;
	std::cout << _contacts[index].getNickname() << std::endl;
	std::cout << _contacts[index].getPhoneNumber() << std::endl;

}

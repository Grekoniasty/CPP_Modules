#include "Contact.class.hpp"

Contact::Contact()
{
}

Contact::~Contact()
{
}

void Contact::SetFirstName(std::string input)
{
	_firstName = input;
}

void Contact::SetLastName(std::string input)
{
	_lastName = input;
}

void Contact::SetNickname(std::string input)
{
	_nickname = input;
}

void Contact::SetPhoneNumber(std::string input)
{
	_phoneNumber = input;
}

void Contact::SetDarkestSecret(std::string input)
{
	_darkestSecret = input;
}

std::string	Contact::getFirstName()
{
	return (_firstName);
}

std::string	Contact::getLastName()
{
	return (_lastName);
}

std::string	Contact::getNickname()
{
	return (_nickname);
}

std::string	Contact::getPhoneNumber()
{
	return (_phoneNumber);
}

std::string	Contact::getDarkestSecret()
{
	return (_darkestSecret);
}

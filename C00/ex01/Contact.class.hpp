#ifndef CONTACT_HPP
#define CONTACT_HPP

# include <string>
# include <iostream>
# include <iomanip>
class Contact
{
	private:
		std::string _firstName;
		std::string _lastName;
		std::string _nickname;
		std::string _phoneNumber;
		std::string _darkestSecret;
	public:
		Contact();
		~Contact();
		void SetFirstName(std::string input);
		void SetLastName(std::string input);
		void SetNickname(std::string input);
		void SetPhoneNumber(std::string input);
		void SetDarkestSecret(std::string input);
		std::string getFirstName();
		std::string getLastName();
		std::string getNickname();
		std::string getPhoneNumber();
		std::string getDarkestSecret();
};

#endif

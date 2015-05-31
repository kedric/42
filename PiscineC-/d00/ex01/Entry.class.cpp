// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Entry.class.cpp                                    :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: jmancero <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/05 15:08:39 by jmancero          #+#    #+#             //
//   Updated: 2015/01/05 15:08:43 by jmancero         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Entry.class.hpp"

Entry::Entry (void){
	this->_used = false;
	return;
};

Entry::~Entry (void){

	return;
};

bool Entry::getUsed(void){
	return (this->_used);
};

void Entry::toggleUsed(void){
	this->_used = !this->_used;
	return;
}

void Entry::setId(int id){
	this->_id = id;
};
int Entry::getId(){
	return (this->_id);
};

std::string	Entry::get_first_name(){
	return (this->_first_name);
}

void		Entry::set_first_name(std::string value){
	this->_first_name = value;
	return;
}

std::string	Entry::get_last_name(){
	return (this->_last_name);
}

void		Entry::set_last_name(std::string value){
	this->_last_name = value;
	return;
}

std::string	Entry::get_nickname(){
	return (this->_nickname);
}

void		Entry::set_nickname(std::string value){
	this->_nickname = value;
	return;
}

std::string	Entry::get_login(){
	return (this->_login);
}

void		Entry::set_login(std::string value){
	this->_login = value;
	return;
}

std::string	Entry::get_postal_address(){
	return (this->_postal_address);
}

void		Entry::set_postal_address(std::string value){
	this->_postal_address = value;
	return;
}

std::string	Entry::get_email_address(){
	return (this->_email_address);
}

void		Entry::set_email_address(std::string value){
	this->_email_address = value;
	return;
}

std::string	Entry::get_phone_number(){
	return (this->_phone_number);
}

void		Entry::set_phone_number(std::string value){
	this->_phone_number = value;
	return;
}

std::string	Entry::get_birthday_date(){
	return (this->_birthday_date);
}

void		Entry::set_birthday_date(std::string value){
	this->_birthday_date = value;
	return;
}

std::string	Entry::get_favorite_meal(){
	return (this->_favorite_meal);
}

void		Entry::set_favorite_meal(std::string value){
	this->_favorite_meal = value;
	return;
}
std::string	Entry::get_underwear_color(){
	return (this->_underwear_color);
}

void		Entry::set_underwear_color(std::string value){
	this->_underwear_color = value;
	return;
}

std::string	Entry::get_darkest_secret(){
	return (this->_darkest_secret);
}

void		Entry::set_darkest_secret(std::string value){
	this->_darkest_secret = value;
	return;
}

std::string Entry::AskField(const char *screenName){
	std::string buff;
	std::cout << "Enter " << screenName << " :";
	std::cin >> buff;
	return buff;
}

void	Entry::printField(const std::string value){
	if (value.length() > 10)
		std::cout << value.substr(0,9) << '.';
	else{
		int nbSpace = 10 - value.length();
		for(int i = 0 ; i != nbSpace ;i++)
			std::cout << ' ';
		std::cout << value;
	}
}
void	Entry::printField(const std::string value, const std::string screenName){
	std::cout << screenName << " : " << value << std::endl;
}
void	Entry::printAllField(){
	std::cout << "id : " << this->_id << std::endl;
	this->printField(this->get_first_name(), "first name");
	this->printField(this->get_last_name(), "last name");
	this->printField(this->get_nickname(), "nickname");
	this->printField(this->get_login(), "login");
	this->printField(this->get_postal_address(), "postal address");
	this->printField(this->get_email_address(), "email address");
	this->printField(this->get_phone_number(), "phone number");
	this->printField(this->get_birthday_date(), "birthday date");
	this->printField(this->get_favorite_meal(), "favorite meal");
	this->printField(this->get_underwear_color(), "underwear color");
	this->printField(this->get_darkest_secret(), "darkest secret");
}

void Entry::print(void){
	std::cout << "         " << this->_id << '|';
	this->printField(this->get_first_name());
	std::cout << '|';
	this->printField(this->get_last_name());
	std::cout << '|';
	this->printField(this->get_nickname());
	std::cout << std::endl;
}

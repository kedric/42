// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: jmancero <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/05 15:08:39 by jmancero          #+#    #+#             //
//   Updated: 2015/01/05 15:08:43 by jmancero         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Entry.class.hpp"

void printId(int id,Entry (*phoneBook)[8]){
	for(int i = 0; i < 8; i++){
		if ((*phoneBook)[i].getUsed() && id == (*phoneBook)[i].getId()){
			(*phoneBook)[i].printAllField();
			return;
		}
	}
	std::cerr << "no Entry found" << std::endl;
}

bool addEntry(Entry (*phoneBook)[8],int *last_id_entry){
	int i = 0;
	std::string ret;
	while ((*phoneBook)[i].getUsed() == true){
		i++;
		if (i == 8){
			std::cout << "you have max contact" << std::endl;
			return false;
		}
	}
	Entry work = (*phoneBook)[i];
	work.setId(*last_id_entry);
	work.toggleUsed();
	*last_id_entry = *last_id_entry + 1;
	work.set_first_name(work.AskField("first name"));
	work.set_last_name(work.AskField("last name"));
	work.set_nickname(work.AskField("nickname"));
	work.set_login(work.AskField("login"));
	work.set_postal_address(work.AskField("postal address"));
	work.set_email_address(work.AskField("email address"));
	work.set_phone_number(work.AskField("phone number"));
	work.set_birthday_date(work.AskField("birthday date"));
	work.set_favorite_meal(work.AskField("favorite meal"));
	work.set_underwear_color(work.AskField("underwear color"));
	work.set_darkest_secret(work.AskField("darkest secret"));
	(*phoneBook)[i] = work;
	return true;
}

void searchEntry(Entry (*phoneBook)[8]){
	int i = 0;
	std::string buff;
	int id;

	std::cout << "        ID|first name| last name|  nickname" << std::endl;
	while (i < 8){
		if ((*phoneBook)[i].getUsed() == true)
			(*phoneBook)[i].print();
		i++;
	}
	std::cout << "index : ";
	std::cin >> buff;
	id = std::stoi(buff);
	printId(id, phoneBook);
}

int main(){
	int				last_id_entry;
	Entry			phoneBook[8];
	std::string		buff;

	last_id_entry = 0;
	while (1){
		buff = "";
		std::cin >> buff;
		if (buff == "EXIT"){
			return (0);
		} else if (buff == "ADD") {
			addEntry(&phoneBook, &last_id_entry);
		} else if (buff == "SEARCH") {
			searchEntry(&phoneBook);
		}
	}
	return (0);
}

// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   ZombieHorde.cpp                                     :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: jmancero <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/05 15:08:39 by jmancero          #+#    #+#             //
//   Updated: 2015/01/05 15:08:43 by jmancero         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "ZombieHorde.hpp"
#include <ctime>
#include <cstdlib>

ZombieHorde::ZombieHorde(int nb) : _nb(nb) {
	this->_horde = new Zombie[nb];
	srand(time(NULL));
	for(int i=0; i < nb; i++){
		this->_horde[i].init(this->randomName(), this->randomType());
	}
	return;
}

std::string ZombieHorde::randomName() {
	std::string Name[10] = {"Taonga","Tafadzwa", "Quy", "Maria", "Kondwani", "Derya", "Dana", "Akachi", "Idowu", "Mphatso"};
	return (Name[rand() % 10 ]);
};

std::string ZombieHorde::randomType() {
	std::string Name[6] = {"Walker","Runners", "Crawlers", "Halfers", "Chopped", "Ankle biters"};

	return (Name[rand() % 6 ]);
}

ZombieHorde::~ZombieHorde() {
	delete [] this->_horde;
	return;
}

void	ZombieHorde::announce(void) {
	for(int i=0; i < this->_nb; i++){
		this->_horde[i].announce();
	}
	return;
}

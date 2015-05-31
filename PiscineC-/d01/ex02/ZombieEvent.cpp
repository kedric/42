// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   ZombieEvent.class.cpp                              :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: jmancero <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/05 15:08:39 by jmancero          #+#    #+#             //
//   Updated: 2015/01/05 15:08:43 by jmancero         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "ZombieEvent.hpp"
#include <ctime>
#include <cstdlib>

ZombieEvent::ZombieEvent() {

	return;
}

ZombieEvent::~ZombieEvent() {

	return;
}

std::string	ZombieEvent::getZombieType(void) { return (this->_ZombieType); };
void	ZombieEvent::setZombieType(std::string in) { this->_ZombieType = in; };

Zombie*	ZombieEvent::newZombie(std::string name) {

	Zombie *p = new Zombie(name, this->getZombieType());
	return (p);
}

std::string ZombieEvent::randomName() {
	srand(time(NULL));
	std::string Name[10] = {"Taonga","Tafadzwa", "Quy", "Maria", "Kondwani", "Derya", "Dana", "Akachi", "Idowu", "Mphatso"};
	return (Name[rand() % 10 ]);
}

std::string ZombieEvent::randomType() {
	std::string Name[6] = {"Walker","Runners", "Crawlers", "Halfers", "Chopped", "Ankle biters"};
	srand(time(NULL));
	return (Name[rand() % 6 ]);
}

Zombie*	ZombieEvent::randomChump(void) {
	Zombie *p = new Zombie(this->randomName(), this->randomType());
	return (p);
}

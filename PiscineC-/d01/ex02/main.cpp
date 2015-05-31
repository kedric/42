/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmancero <jmancero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/06 14:23:01 by jmancero          #+#    #+#             */
/*   Updated: 2015/01/06 15:40:21 by jmancero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include "ZombieEvent.hpp"

int main (){
	ZombieEvent event;
	Zombie* ptr;

	event.setZombieType("walker");
	ptr = event.newZombie("haha");
	ptr->announce();
	delete ptr;
	ptr = event.randomChump();
	ptr->announce();
	delete ptr;
	return (0);
}

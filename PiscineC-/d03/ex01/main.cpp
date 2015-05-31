/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmancero <jmancero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/08 16:41:26 by jmancero          #+#    #+#             */
/*   Updated: 2015/01/08 21:21:00 by jmancero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main(){
	FragTrap player1("the virgine");
	FragTrap player2("player2");
	ScavTrap player3("orge");
	ScavTrap player4("player5");
	ScavTrap player5(player4);

	player2 = player1;
	player4 = player5;

	player3.takeDamage(6);
	player5.takeDamage(30) ;

	player1.vaulthunter_dot_exe("mouton");
	player2.vaulthunter_dot_exe("chat");

	player4.challengeNewcomer("mouton");
	player5.challengeNewcomer("chat");

	return 0;
};

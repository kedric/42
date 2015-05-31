// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   ZombieEvent.class.hpp                              :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: jmancero <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/05 15:08:39 by jmancero          #+#    #+#             //
//   Updated: 2015/01/05 15:08:43 by jmancero         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef ZOMBIEEVENT_HPP
# define ZOMBIEEVENT_HPP
# include <string>
# include "Zombie.hpp"
class ZombieEvent{

	public:
			ZombieEvent(void);
			~ZombieEvent(void);
void		setZombieType(std::string in);
std::string	getZombieType(void);
Zombie*		newZombie(std::string name);
Zombie*		randomChump(void);
std::string randomName();
std::string randomType();

	private:
std::string		_ZombieType;

};

#endif

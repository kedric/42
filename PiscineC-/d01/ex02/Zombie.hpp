// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//    Zombie.class.hpp                                  :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: jmancero <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/05 15:08:39 by jmancero          #+#    #+#             //
//   Updated: 2015/01/05 15:08:43 by jmancero         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef  ZOMBIE_HPP
# define ZOMBIE_HPP
# include <string>
class Zombie{

	public:
				Zombie(void);
				~Zombie(void);
				Zombie(std::string name, std::string type);
void			announce(void);
std::string		get_type(void);
void			set_type(std::string in);
std::string		get_name(void);
void			set_name(std::string in);

	private:
std::string		_type;
std::string		_name;

};

#endif

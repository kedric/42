// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Pony.hpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: jmancero <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/05 15:08:39 by jmancero          #+#    #+#             //
//   Updated: 2015/01/05 15:08:43 by jmancero         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef PONY_CLASS_HPP
# define PONY_CLASS_HPP
# include <string>
class Pony {

	public:
		Pony(std::string name, std::string color);
		~Pony(void);
bool		eat(void);
bool		get_have_eat(void);
void		set_have_eat(bool);
std::string get_name(void);
std::string get_color(void);

	private:
bool		_have_eat;
std::string	_name;
std::string	_color;

};

#endif

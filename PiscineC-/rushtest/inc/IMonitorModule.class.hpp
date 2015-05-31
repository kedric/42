/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMonitorModule.class.hpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmancero <jmancero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/17 15:05:41 by akazian           #+#    #+#             */
/*   Updated: 2015/01/18 19:09:13 by jmancero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMONITOR_MODULE_CLASS_HPP
# define IMONITOR_MODULE_CLASS_HPP

class	IMonitorModule {

	public :
		virtual ~IMonitorModule(){}
		virtual	std::string		getName() =0;
};

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMonitorDisplay.class.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akazian <akazian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/17 15:01:05 by akazian           #+#    #+#             */
/*   Updated: 2015/01/18 17:48:22 by akazian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMONITOR_DISPLAY_CLASS_HPP
# define IMONITOR_DISPLAY_CLASS_HPP

#include "../inc/IMonitorModule.class.hpp"

class	IMonitorDisplay {

	public :
		virtual ~IMonitorDisplay(){}
		virtual int	run()=0;
};

#endif

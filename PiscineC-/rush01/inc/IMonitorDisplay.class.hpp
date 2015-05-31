/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMonitorDisplay.class.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmancero <jmancero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/17 07:10:21 by jmancero          #+#    #+#             */
/*   Updated: 2015/01/17 09:16:37 by jmancero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef IMONITORDISPLAY_CLASS_HPP
# define IMONITORDISPLAY_CLASS_HPP

# include <string>
# include <iostream>


class IMonitorDisplay {
    private:
    public:
                        ~IMonitorDisplay( void  );
                        IMonitorDisplay( void  );
                        IMonitorDisplay(IMonitorDisplay const & in);
IMonitorDisplay&         operator=(IMonitorDisplay const & in);
};

std::ostream & operator<<(std::ostream& o, IMonitorDisplay const & p);



#endif

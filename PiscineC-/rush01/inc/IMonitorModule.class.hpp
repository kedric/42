/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMonitorModule.class.hpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmancero <jmancero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/17 07:07:57 by jmancero          #+#    #+#             */
/*   Updated: 2015/01/17 07:40:44 by jmancero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMONITORMODULE_CLASS_HPP
# define IMONITORMODULE_CLASS_HPP

# include <string>
# include <iostream>


class IMonitorModule {
    private:

    public:


                        ~IMonitorModule( void  );
                        IMonitorModule( void  );
                        IMonitorModule(IMonitorModule const & in);
IMonitorModule&         operator=(IMonitorModule const & in);
};

std::ostream & operator<<(std::ostream& o, IMonitorModule const & p);


#endif

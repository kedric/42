/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GetInfo.class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmancero <jmancero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/18 14:34:15 by jmancero          #+#    #+#             */
/*   Updated: 2015/01/18 17:55:22 by jmancero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef GETINFO_CLASS_HPP
# define GETINFO_CLASS_HPP

# include <cstring>
# include <iostream>
# include <cstdlib>
# include <map>



class GetInfo {
    private:

    public:
                                  ~GetInfo( void  );
                                  GetInfo( void  );
                                  GetInfo(GetInfo const & in);
std::string                       getHostName();
std::string                       getLoadavg();
std::string                       getUserName();
std::string                       getTime();
std::map<std::string,std::string> getOs();
std::map<std::string,float>       getCpuUsage();
std::string                       getCmd(std::string cmd);
GetInfo&                          operator=(GetInfo const & in);
};



#endif

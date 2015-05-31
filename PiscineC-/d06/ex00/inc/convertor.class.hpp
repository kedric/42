/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convertor.class.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmancero <jmancero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/13 14:40:53 by jmancero          #+#    #+#             */
/*   Updated: 2015/01/13 15:16:09 by jmancero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef CONVERTOR_CLASS_HPP
# define CONVERTOR_CLASS_HPP

# include <string>
# include <iostream>


class convertor {
    private:
                std::string _type;
    static      std::string _charValue;

    public:
                        ~convertor( void  );
                        convertor( void  );
                        convertor(convertor& in) { *this = in; return; }
convertor&              operator=(convertor const & in);
};
#endif

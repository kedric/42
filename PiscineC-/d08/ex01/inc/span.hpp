/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmancero <jmancero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/15 16:18:09 by jmancero          #+#    #+#             */
/*   Updated: 2015/01/15 18:53:02 by jmancero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef SPAN_HPP
# define SPAN_HPP

# include <string>
# include <iostream>
# include <vector>


class Span {

    private:
        int _max_len;
        std::vector<int>* _tab_int;

    public:
                        ~Span( void  );
                        Span(unsigned int nb);
                        Span(Span const & in);
Span&                   operator=(Span const & in);

void                    addNumber(int add);
int                     shortestSpan(void);
int                     longestSpan(void);
unsigned int            getMaxLength(void) const;
std::vector<int> *      getTabInt(void) const;

};


#endif

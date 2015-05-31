/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmancero <jmancero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/15 16:17:45 by jmancero          #+#    #+#             */
/*   Updated: 2015/01/15 17:54:45 by jmancero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/span.hpp"

Span::~Span(void){

};
Span::Span(unsigned int nb) {
    this->_max_len = nb;
    this->_tab_int = new std::vector<int>() ;
};
Span::Span(Span const & in) : _max_len(in.getMaxLength()), _tab_int(in.getTabInt()){
};

Span& Span::operator=(Span const & in){
    return(*this);
};

int Span::shortestSpan(void){
    std::vector<int>::iterator it;
    std::vector<int>::iterator ite = this->_tab_int->end();
    int last_nb = 0;
    int ret = 1454646466;
    for(it = this->_tab_int->begin(); it != ite ; it++){
        if (abs(*it - last_nb) <= ret)
            ret = abs(*it - last_nb);
        last_nb = *it;
    }
    return ret;
};
int Span::longestSpan(void){
    int min = *std::min_element(this->_tab_int->begin(), this->_tab_int->end());
    int max = *std::max_element(this->_tab_int->begin(), this->_tab_int->end());
    return max - min;
};

unsigned int Span::getMaxLength(void) const {
    return this->_max_len;
}

std::vector<int> *      Span::getTabInt(void) const{
    return this->_tab_int;
};

void Span::addNumber(int add){
    if (this->_tab_int->size() < this->_max_len)
        this->_tab_int->push_back(add);
    else
        throw std::exception();
};

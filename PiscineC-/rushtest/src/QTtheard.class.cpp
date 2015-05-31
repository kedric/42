/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   QTtheard.class.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmancero <jmancero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/18 21:47:04 by jmancero          #+#    #+#             */
/*   Updated: 2015/01/18 22:04:07 by akazian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/QTtheard.class.hpp"
QTthread::~QTthread( void  ){

};
QTthread::QTthread(void){

};
void                    QTthread::setGi(GetInfo * gi ){
    this->_gi = gi;
};
                        QTthread::QTthread(QTthread const & in){
                            (void)in;
                        };
QTthread&         QTthread::operator=(QTthread const & in){
    (void)in;
	return *this;
}
void QTthread::run(){
        while(1){
        emit resultReady(this->_gi->getTime().c_str());
        sleep(1);
    }
}

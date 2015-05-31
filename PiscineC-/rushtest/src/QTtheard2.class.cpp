/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   QTtheard2.class.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmancero <jmancero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/18 21:47:04 by jmancero          #+#    #+#             */
/*   Updated: 2015/01/18 22:01:56 by jmancero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/QTtheard2.class.hpp"
QTthread2::~QTthread2( void  ){

};
QTthread2::QTthread2(void){

};
void                    QTthread2::setGi(GetInfo * gi ){
    this->_gi = gi;
};
                        QTthread2::QTthread2(QTthread2 const & in){
                            (void)in;
                        };
QTthread2&       QTthread2::operator=(QTthread2 const & in){
    (void)in;
    return *this ;
}
void QTthread2::run(){
    while(1){
      std::map<std::string,float> ret = this->_gi->getCpuUsage();
    emit resultUser((int)ret["cpu_user"]);
    emit resultSys((int)ret["cpu_sys"]);
    emit resultIdle((int)ret["cpu_idle"]);
    sleep(1);
    }
}

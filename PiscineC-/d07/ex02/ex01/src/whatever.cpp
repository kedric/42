/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmancero <jmancero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/14 17:00:42 by jmancero          #+#    #+#             */
/*   Updated: 2015/01/14 17:40:50 by jmancero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <ctime>
#include <iostream>
template< typename T, typename C>
void iter(T * obj, unsigned int len, C callback){
    for(unsigned int i=0; i < len; i++){
        callback(obj[i]);
    }
};

void callback(std::string &args){
    char str[36] = "abcdefhijklmnopqrstuvwxyz1234567890";
    std::cout << "hello"<< std::endl;
    args += str[rand() % 36];
};

void callback2(std::string args){

    std::cout << args<< std::endl;
};

int main(){
    std::string str[50];
    iter(str, 50, callback);
    iter(str, 50, callback2);

}

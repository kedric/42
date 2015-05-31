/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmancero <jmancero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/13 19:05:48 by jmancero          #+#    #+#             */
/*   Updated: 2015/01/13 19:53:52 by jmancero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <ctime>
#include <cstdlib>
#include <iostream>

struct Data {
    std::string s1;
    int n;
    std::string s2;
};

void * serialize( void ){
    char * ptr = new char[20];
    int i = 0;
    while (i < 8){
        ptr[i] = rand() % 127;
        i++;
    }
    void * ptrVoid = static_cast<void *>(ptr+ i);
    int *prtInt = static_cast<int *>(ptrVoid);
    *prtInt = rand();
    i = i + sizeof(int);
    while (i < 20){
        ptr[i] = rand() % 127;
        i++;
    }
    return (static_cast<void *>(ptr));
};

Data * deserialize( void * raw ){
    char * ptr = static_cast<char*>(raw);
    Data *data = new Data;
    data->s1 = ptr;
    void *ptrVoid = static_cast<void *>(ptr + 8);
    data->n = *(static_cast<int *>( ptrVoid));
    data->s2 = ptr + 8 + sizeof(int) ;
    return data;
};


int main(){
    void *ptr;
    Data *ptrData;
    srand(time(NULL));
    ptr = serialize();
    ptrData = deserialize(ptr);
    std::cout <<"data->s1 '" <<ptrData->s1 << "'"<< std::endl;
    std::cout <<"data->n " <<ptrData->n << std::endl;
    std::cout <<"data->s2 '" << ptrData->s2 << "'"<< std::endl;
}

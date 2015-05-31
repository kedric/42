/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmancero <jmancero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/13 14:18:14 by jmancero          #+#    #+#             */
/*   Updated: 2015/01/13 18:56:25 by jmancero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <climits>
#include <string>

#define CHAR    0
#define INT     1
#define FLOAT   2
#define DOUBLE  3
#define NONE    -1

#define DELIMITER "f."
#define DOUBLE_KEY {"-inf", "+inf", "nan"}
#define FLOAT_KEY {"-inff", "+inff", "nanf"}
#define NONE_PRINTALBE {"\\0", "soh","stx","etx","eot","enq","ack","bel","bs","ht","nl","vt","np","cr","so","si","dle","dc1 ","dc2","dc3","dc4","nak","syn","etb","can","em","sub","esc","fs","gs","rs","us","sp" }
int check_keyword(std::string nb){
    int i = 0;
    std::string double_Search[3] = DOUBLE_KEY;
    std::string float_Search[3] = FLOAT_KEY;
    while (i < 3){
        if (double_Search[i] == nb)
            return DOUBLE;
        else if (float_Search[i] == nb)
            return FLOAT;
        i++;
    }
    return NONE;
}

int get_type(char* nb) {
    int i = 0;
    if (strlen(nb) == 1){
        if (nb[0] >= 48 && nb[0] <= 57){
            return INT;
        } else {
           return CHAR;
        }
    }
    int type =  INT ;
    while (nb[i]){
        if (nb[i] < 48 || nb[i] > 57)
            return NONE;
        if(nb[i] == DELIMITER[0]){
            if (type == DOUBLE)
                type = FLOAT;
            else
                type = NONE;
        }
        else if(nb[i] == DELIMITER[1]){
            if(type == INT || type == CHAR)
                type = DOUBLE;
            else
                type = NONE;
        }
        i++;
    }
    return (type);
};

void printChar(char c,  bool possible) {
    std::cout << "char: " ;
    if (possible == false){
        std::cout << "impossible" << std::endl;
        return;
    }
    if(c >= 0 && c <= 32 ){
        std::string nprint[33] = NONE_PRINTALBE;
        std::cout << '\''<< nprint[static_cast<int>(c)]<< '\'' << std::endl;
    }else{

    std::cout << c << std::endl;
}
};

void printInt(int nb, bool possible) {
    std::cout << "int: " ;
    if (possible == false){
        std::cout << "impossible" << std::endl;
        return;
    }
    if (possible == false)
        std::cout << "impossible" << std::endl;
    std::cout << nb << std::endl;

};

void printFloat(float nb, bool up) {
    std::cout << "float: " ;
    std::cout << nb;
    if (up || nb == 0)
        std::cout << ".0";
    std::cout << 'f' << std::endl;

};

void printDouble(double n, bool up) {
    std::cout << "double: " ;
    std::cout << n;
    if (up || n == 0)
        std::cout << ".0";
    std::cout << std::endl;

};

int main(int ac, char** av){
    int type = -1;
    int keyworld = 0;
    if (ac != 2){
        std::cout << "usage: " << av[0];
        std::cout << " <to convert>" << std::endl;
        exit(-1);
    }
    type = check_keyword(av[1]);
    if (type == -1){
        type = get_type(av[1]);
        if (type == -1){
            std::cout << "Type not found!! "<< std::endl;
            exit(-1);
        }
    }
    else
        keyworld = 1;
    int nb = 0;
    float f = 0.0f;
    switch (type){
        case CHAR :
            printChar(av[1][0], true);
            printInt(static_cast<int>(av[1][0]), true);
            printFloat(static_cast<float>(av[1][0]), true);
            printDouble(static_cast<double>(av[1][0]), true);
            break;
        case INT :
            nb = std::stoi(av[1]);
            if (nb < CHAR_MAX && nb > CHAR_MIN)
                printChar(static_cast<int>(nb), true);
            else
                printChar(static_cast<char>(nb), false);
            printInt(nb, true);
            printFloat(static_cast<float>(nb), true);
            printDouble(static_cast<double>(nb), true);
            break;
        case FLOAT :
            f = std::stof(av[1]);
            if (keyworld == 0 && f < CHAR_MAX && f > CHAR_MIN)
                printChar(static_cast<char>(f), true);
            else
                printChar(static_cast<char>(f), false);
            if (keyworld == 0)
                printInt(static_cast<int>(f), true);
            else
                printInt(static_cast<int>(f), false);
            printFloat(f, false);
            printDouble(static_cast<double>(f), false);
            break;
        case DOUBLE :
            double d = std::stod(av[1]);
            if (keyworld == 0 && d < CHAR_MAX && d > CHAR_MIN)
                printChar(static_cast<int>(d), true);
            else
                printChar(d, false);
            if (keyworld == 0 )
                printInt(static_cast<int>(d), true);
            else
                printInt(static_cast<int>(d), false);
            printFloat(static_cast<float>(d), false);
            printDouble(d, false);
            break;
    }
};

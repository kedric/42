/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmancero <jmancero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/06 19:08:52 by jmancero          #+#    #+#             */
/*   Updated: 2015/01/06 20:32:03 by jmancero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <fstream>
#include <iostream>

std::string ReadFile(std::string filename){
	std::fstream fs;
	int length = 0;
	std::string buff;

	fs.open(filename);
	if (!fs.is_open()){
		std::cerr << "Erreur on open" << std::endl;
		exit(1);
	}
	fs.seekg (0, fs.end);
	length = fs.tellg();
	fs.seekg (0, fs.beg);
	char *buffer = new char[length + 1];
	fs.read(buffer,length);
	buffer[length] = 0;
	buff += buffer;
	delete buffer;
	fs.close();
	return (buff);
}

int main(int argc, char** argv){
	if (argc < 4){
		std::cerr << "Usage " << argv[0] << " s1 s2"<< std::endl;
		return (1);
	}
	std::string filename;
	filename = argv[1];

	std::string buff;
	buff = ReadFile(filename);

	int posStart = buff.find(argv[2]);
	while (posStart != -1){
		buff.replace(posStart, 3 , argv[3]);
		posStart = buff.find(argv[2]);
	}
	std::fstream fsout;
	fsout.open(filename + ".replace", std::ios::out);
	fsout << buff;
	fsout.close();
}

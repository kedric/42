#include <QWidget>

#include <QPushButton>
#include <QThread>
#include <QPushButton>
#include <QLCDNumber>
#include <iostream>
#include <QApplication>
#include <QDebug>
#include <QGridLayout>
#include <ctime>


#include "../inc/window.class.hpp"
#include "../inc/GetInfo.class.hpp"
#include "../inc/CursesEngine.class.hpp"

bool argparser(char **av,std::list<std::string> *in){
    std::string tmp;
    bool win = true;
	for(int i = 1; av[i]; i++){
        tmp = av[i];
        if(tmp == "hostname")
			in->push_back("HostName");
        if (tmp == "cpu")
			in->push_back("CPU");
        if (tmp == "time")
    		in->push_back("Time");
		if (tmp == "-nw")
			win = false;
    }
	return win;
};

int main(int argc, char **argv)
{
  GetInfo GI;
  if (argc == 1){
    std::cout << "Usage time, hostname, cpu" << std::endl;
    return 0;
  }
	std::list<std::string> in;
	bool win = argparser(argv, &in);
   if (!win) {
		CursesEngine ui = CursesEngine(in);
	   while(ui.run())
		  sleep(1) ;
   }
   else {
	WinQT *qtwin = new WinQT(argc, argv, &GI);

   	qtwin->run();
   }

   return  0;
}


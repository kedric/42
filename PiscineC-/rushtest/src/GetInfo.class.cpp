/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GetInfo.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmancero <jmancero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/18 14:32:56 by jmancero          #+#    #+#             */
/*   Updated: 2015/01/18 19:39:07 by jmancero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/GetInfo.class.hpp"



std::string             GetInfo::getCmd(std::string cmd) {
    char                buffer[1024];
    std::string         result = "";
    FILE*               pipe = popen(cmd.c_str(), "r");

    if(!pipe)
        return "";
    while (!feof(pipe)) {
        if (fgets(buffer, 1024, pipe) != NULL) {
            result += buffer;
        }
    }
    pclose(pipe);
    result = result.substr(0, result.size() - 1);
    return result;
};
GetInfo::~GetInfo(void){

};
GetInfo::GetInfo(void){

};
GetInfo::GetInfo(GetInfo const & in){
  (void)in;
};

std::string             GetInfo::getHostName(){
    return this->getCmd("hostname");
};
std::string             GetInfo::getUserName(){
    return this->getCmd("echo $USER");
};
std::string             GetInfo::getTime(){
    time_t rawtime;
    struct tm * timeinfo;
    time ( &rawtime );
    timeinfo = localtime ( &rawtime );
    std::string tmp = asctime (timeinfo);
    return tmp.substr(0, tmp.size() - 1);
};


std::map<std::string,float>             GetInfo::getCpuUsage(){
    std::map<std::string,float> ret;
    ret["cpu_user"] = atof(this->getCmd("top -l 1 | head -n 10 | grep \"CPU usage\" | cut -d ' ' -f3 | cut -d% -f1").c_str());
    ret["cpu_sys"] = atof(this->getCmd("top -l 1 | head -n 10 | grep \"CPU usage\" | cut -d ' ' -f5 | cut -d% -f1").c_str());
    ret["cpu_idle"] = atof(this->getCmd("top -l 1 | head -n 10 | grep \"CPU usage\" | cut -d ' ' -f7 | cut -d% -f1").c_str());
    return ret;
};

std::map<std::string,std::string>            GetInfo::getOs(){
   std::map<std::string,std::string> ret;
   ret["os_type"] = this->getCmd("sysctl kern.ostype");
   ret["machine"] = this->getCmd("sysctl hw.machine");
   ret["model"] = this->getCmd("sysctl hw.model");
   ret["ncpu"] = this->getCmd("sysctl hw.ncpu");
   ret["version"] = this->getCmd("sysctl kern.version");
   ret["clockrate"] = this->getCmd("sysctl kern.clockrate");
   ret["memsize"] = this->getCmd("sysctl hw.memsize");
   return ret;
};
std::string             GetInfo::getLoadavg(){
    std::string a(this->getCmd("sysctl vm.loadavg"));
    std::cout << a << std::endl;
    return a;
};
GetInfo& GetInfo::operator=(GetInfo const & in){
    (void)in;
    return(*this);
};


// int main(){
//     GetInfo a;
//     std::cout << a.getHostName() << std::endl;
// };

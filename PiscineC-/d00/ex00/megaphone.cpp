#include <iostream>
#include <string>

void parse_option(std::string *buff, char **opt, int len){
	for(int i = 1; i < len; i++)
	{
		*buff += opt[i];
	}

}

std::string toUpper(std::string in){
	std::string out;

	for(int i = 0; in[i];i++){
		if (in[i] <= 122 && in[i] >= 97)
		{
			out += in[i] - 32;
		}
		else
		{
			out += in[i];
		}
	}
	return out;
}

int main(int argc, char** argv){
	std::string buff;

	if (argc > 1){
		parse_option(&buff, argv, argc);
	}
	else{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}
	std::cout << toUpper(buff) << std::endl;
	return (0);
}
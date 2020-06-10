#include <string>
#include <iostream>
using namespace std;
int main(int argc,char **argv){
	if (1==argc){
		std::cout<<"usage: BingAutoIndex <base url for your website for exapmle https://exapmple.com>"<<std::endl;
		return 1;
	}
	std::string arg;
	arg  = argv[1];
	std::cout<<arg<<std::endl;
}

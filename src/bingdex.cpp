#include "bing_auto_index.cpp"
//
//
int main(int argc,char **argv){
	if (1==argc){
		std::cout<<"usage: BingAutoIndex <base url for your website for exapmle https://exapmple.com>"<<std::endl;
		return 1;
	}
	std::string arg,item,msg;
	std::vector<string> html_list = get_dir_html();
	arg  = argv[1];
	for(int i=html_list.size()-1;i>-1;--i){
		item = html_list[i];
		html_list.pop_back();
		html_list.insert(html_list.begin(),arg+item);
	}
	for(int i=0;i<html_list.size();i++){
		std::cout<<html_list[i]<<std::endl;
	}
}

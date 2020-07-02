#include "bing_auto_index.cpp"
//
//
int main(int argc,char **argv){
	if (1==argc){
		std::cout<<"usage: BingAutoIndex <base url for your website for exapmle https://exapmple.com>"<<std::endl;
		return 1;
	}
	std::string arg,item,msg;
	std::vector<string> file_list = get_dir_html();
	std::vector<string> html_list;
	arg  = argv[1];
	for(int i=0;i<file_list.size();++i){
		item = file_list[i];
		html_list.push_back(arg+item);
	}
	file_list.erase(file_list.begin());
	std::string index_data = get_json_from_vector("urlList",html_list);
	index_data = "\"siteUrl\":\""+arg+"\","+index_data;
	send_bing_json(index_data);
}

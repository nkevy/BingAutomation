#include "bing_auto_index.h"
// get all .html files in a dir
std::vector<string> get_dir_html(){
	std::vector<string> html_list;
	std::string item;
	for(auto& p: std::filesystem::directory_iterator(".")){
		item = p.path().string().substr(1,std::string::npos);
		if(std::string::npos!=item.find(".html")){
			html_list.push_back(item);
		}
	}
	return html_list;
}

// send a json packet to Bing Webmaster (need key)
int send_bing_json(std::vector<string> html_list){
	return 0;
}
//EOF

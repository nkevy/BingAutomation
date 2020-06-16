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
//
std::string get_json_from_vector(std::string label, std::vector<string> html_list){
	std::string json;
	std::string list_data = "[";
	for(auto const &item : html_list){
		list_data = list_data+item+",";
	}
	list_data = list_data+"]";
	return label+":"+list_data;
}
//write response to string
int write_response(void *data,std::size_t size,std::size_t nmemb, void *stream){
	((std::string*)stream)->append((char*)data, size * nmemb);
	return size * nmemb;
}
//parse response json
int json_handle(std::string res_str){
	std::map<std::string,std::string> res_map;
	std::string temp;
	std::size_t found = res_str.find_first_of(":,");
	std::size_t found_last = 0; 
	std::cout<<found<<std::endl;
	while(std::string::npos!=found){
		if(':'==res_str[found]){
			temp = res_str.substr(found_last,found);
			res_map.emplace(temp,"");
		}
		if(','==res_str[found]){
			res_map[temp] = res_str.substr(found_last,found);
		}
		found_last = found;
		temp = "";
		found=res_str.find_first_of(":",found+1);
	}
	for(auto const &pair : res_map){
		std::cout<<pair.first<<" "<<pair.second<<std::endl;
	}
	return 0;
}
// send a json packet to Bing Webmaster (need key)
int send_bing_json(std::string data){
	CURL *curl;
	CURLcode res;
	const std::string url = "https://postman-echo.com/get?json="+data;
	//const std::string url = "https://www.google.com?q="+data;
	std::string result;
	//setup curl
	curl_global_init(CURL_GLOBAL_ALL);
	curl = curl_easy_init();
	if(curl){
		//URL
		curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
		//DATA should be json
		curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_response);
		curl_easy_setopt(curl, CURLOPT_WRITEDATA, &result);
		res = curl_easy_perform(curl);
		//ERROR handle
		if(res!=CURLE_OK){
			std::cout<<"[error] Curl returned the error: "<<curl_easy_strerror(res)<<std::endl;
		}
		std::cout<<std::endl<<"[curl] Success. Curl found the response: "<<result<<std::endl;
		curl_easy_cleanup(curl);
	}
	curl_global_cleanup();
	return 0;
}
//EOF
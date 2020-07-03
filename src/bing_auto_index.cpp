#include "bing_auto_index.h"
//get key and url and create conf
int set_bing_conf(std::ofstream &conf){
	while(bingdata.url.empty()){
		std::cout<<"Enter Website Url: ";
		std::getline(std::cin, bingdata.url);
	}
	while(bingdata.apikey.empty()){
		std::cout<<"Enter Bing Apikey: ";
		std::getline(std::cin,bingdata.apikey);
	}
	conf<<bingdata.url<<"\n"<<bingdata.apikey;
	return 0;
}	
//set key and url from conf
int get_bing_conf(std::ifstream &conf){
	conf.seekg(0,conf.end);
	if(conf.tellg()<1){
		return 1;
	}
	conf.seekg(0,conf.beg);
	std::getline(conf,bingdata.url);
	std::getline(conf,bingdata.apikey);
	if (bingdata.url.empty()||bingdata.apikey.empty()){
		return 1;
	}
	return 0;
}
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
	std::string list_data;
	for(auto const &item : html_list){
		list_data = list_data+"\""+item+"\",";
	}
	list_data = "["+list_data+"]";
	return "\""+label+"\":"+list_data;
}
//write response to string
int write_response(void *data,std::size_t size,std::size_t nmemb, void *stream){
	((std::string*)stream)->append((char*)data, size * nmemb);
	return size * nmemb;
}
//send curl post with data as header and return response
std::string curl_post_json(const std::string url,const std::string json){
	CURL *curl;
	CURLcode res;
	std::string ret;
	struct curl_slist *header = NULL;
	std::string content_len = "Content-Length: "+std::to_string(json.size());
	curl_global_init(CURL_GLOBAL_ALL);
	curl=curl_easy_init();
	if(curl){
		header = curl_slist_append(header,"Content-Type: application/json; charset=utf-8");
		header = curl_slist_append(header,content_len.c_str());
		curl_easy_setopt(curl,CURLOPT_URL,url.c_str());
		curl_easy_setopt(curl,CURLOPT_HTTPHEADER,header);
		curl_easy_setopt(curl,CURLOPT_POSTFIELDS,json.c_str());
		curl_easy_setopt(curl,CURLOPT_WRITEFUNCTION,write_response);
		curl_easy_setopt(curl,CURLOPT_WRITEDATA,&ret);
		res = curl_easy_perform(curl);
		if(res!=CURLE_OK){
			ret=curl_easy_strerror(res);
		}
		curl_easy_cleanup(curl);
	}
	curl_global_cleanup();
	return ret;
}
//parse response json
std::map<std::string,std::string> json_handle(std::string res_str){
	std::map<std::string,std::string> res_map;
	char s1;
	std::string kv,key;
	for(int i=0;i<res_str.size();i++){
		s1=res_str.at(i);
		if('{'==s1||'}'==s1||'\n'==s1||' '==s1){
			continue;
		}else if(':'==s1){
			key=kv;
			kv="";
		}else if(','==s1){
			res_map[key]=kv;
			kv="";
		}else{
			kv=kv+s1;
		}
	}
	res_map[key]=kv;
	for(auto const &pair : res_map){
		std::cout<<pair.first<<"="<<pair.second<<std::endl;
	}
	return res_map;
}
//EOF

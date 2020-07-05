#include "bing_auto_index.cpp"
//
//
int main(int argc,char* args[]){
	if(std::filesystem::exists("./.bingdex.conf")&&!(argc-1)){
		std::ifstream conf ("./.bingdex.conf",std::ifstream::in);
		while(get_bing_conf(conf)){
			std::filesystem::remove("./.bingdex.conf");
			std::cout<<"[ERROR] .bingdex.conf was corrupted and has been deleted. Run again to send index request."<<std::endl;
			return 1;
		}
		conf.close();
	}else{
		std::ofstream conf ("./.bingdex.conf",std::ofstream::out);
		while(set_bing_conf(conf));
		conf.close();
	}
	std::string arg,item,content,msg;
	std::vector<string> file_list = get_dir_html();
	std::vector<string> html_list;
	for(int i=0;i<file_list.size();++i){
		item = file_list[i];
		html_list.push_back(bingdata.url+item);
	}
	content = "{\"siteUrl\":\""+bingdata.url+"\","+get_json_from_vector("urlList",html_list)+"}";
	msg = curl_post_json("www.bing.com/webmaster/api.svc/json/SubmitUrlbatch?apikey="+bingdata.apikey,content);
	std::map<string,string> result = json_handle(msg);
	std::cout<<result.size()<<std::endl;
	//clean
	file_list.erase(file_list.begin());
	html_list.erase(html_list.begin());
	return 0;
}

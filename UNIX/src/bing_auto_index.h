#ifndef BING_AUTO_INDEX
#define BING_AUTO_INDEX
#define CURL_STATICLIB
//
//include necessary methods, libraries, and fields bellow
#include <stdio.h>
#include <stdlib.h>
#include <curl/curl.h>
#include <filesystem>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
//
//
using namespace std;
//
//
struct bingdex_data{
	std::string url;
	std::string apikey;
};
// global data
//
std::vector<string> get_dir_html();
std::string get_json_from_vector(std::vector<string> html_list);
std::string curl_post_json(const std::string url,const std::string json);
std::map<std::string,std::string> json_handle(std::string res_str);
int get_bing_conf(std::ifstream &conf, bingdex *bingdata);
int set_bing_conf(std::ofstream &conf, bingdex *bingdata);
int write_response(void *data,std::size_t size,std::size_t nmemb, void *stream);
#endif 

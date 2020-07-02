#ifndef BING_AUTO_INDEX
#define BING_AUTO_INDEX
//include necessary methods, libraries, and fields bellow
#include <stdio.h>
#include <stdlib.h>
#include <curl/curl.h>
#include <fstream>
#include <filesystem>
#include <iostream>
#include <string>
#include <vector>
#include <map>
//
//
using namespace std;
std::vector<string> get_dir_html();
std::string get_json_from_vector(std::vector<string> html_list);
std::string curl_func(const std::string url,const std::string json);
int write_response(void *data,std::size_t size,std::size_t nmemb, void *stream);
int json_handle(std::string res_str);
int send_bing_json(std::vector<string> html_list);
#endif 

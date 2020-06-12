#ifndef BING_AUTO_INDEX
#define BING_AUTO_INDEX
//include necessary methods, libraries, and fields bellow
#include <filesystem>
#include <iostream>
#include <string>
#include <vector>
//
//
using namespace std;
std::vector<string> get_dir_html();
int send_bing_json(std::vector<string> html_list);
#endif 

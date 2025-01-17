#include "my_file_to_str.h"
#include <fstream>
#include <sstream>


vector<string> read_file(const string& filename)
{
	ifstream ifs(filename);
	ostringstream oss;
	oss << ifs.rdbuf();
	string cur_word;
	vector<string>res;
	stringstream ss(oss.str());
	while (getline(ss, cur_word,' '))
	{
		res.push_back(cur_word);
	} 
	return res;
}
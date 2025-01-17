#include "my_file_to_str.h"
#include <fstream>
#include <sstream>


vector<string> read_file(const string& filename)
{
	ifstream ifs(filename);
	ostringstream oss;
	oss << ifs.rdbuf();
	string cur_word;
	string cur_string;
	vector<string>words;
	stringstream ss(oss.str());
	while (getline(ss, cur_string))
	{
		stringstream s(cur_string);
		while(getline(s,cur_word,' '))
			words.push_back(cur_word);
	} 
	return words;
}
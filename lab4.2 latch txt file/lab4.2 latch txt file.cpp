/*
Сформируйте/позаимствуйте текстовый файл. Запустите столько потоков, сколько букв в алфавите. 
Каждый поток должен сформировать множество слов из файла, начинающихся с заданной буквы. 
Сравните сформированные множества и распечатайте слова, начинающиеся с наименее используемой буквы.
*/
#include <iostream>
#include <thread>
#include <latch>
#include "my_file_to_str.h"
#include <vector>

//vector<vector<string>> words_by_char(const string& source, const char c)
//{
//
//}


int main()
{
	vector<string> words_from_file = read_file(".\\Oxford English Dictionary.txt");

	return 0;
}


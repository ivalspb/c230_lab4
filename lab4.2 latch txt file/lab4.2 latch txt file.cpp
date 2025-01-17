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
#include <set>

void words_by_char(const vector<string>& source, set<string>& res, const char c, latch& l)
{
	for (auto& word : source)
	{
		if (tolower(word[0]) == c)
			res.insert(word);
	}
	l.arrive_and_wait();
}


int main()
{
	vector<string> words_from_file = read_file(".\\Oxford English Dictionary.txt");
	size_t chars = 'z' - 'a'+1;
	latch ltch(chars);
	vector<set<string>>v_words(chars);
	for (char i = 'a'; i <= 'z'; i++)
	{
		thread t(&words_by_char, ref(words_from_file), ref(v_words[i-'a']), i, ref(ltch));
		t.detach();
	}
	ltch.wait();
	auto it = min_element(v_words.begin(), v_words.end(), [](const auto& x, const auto& y) {return x.size() < y.size(); });
	for (auto& i : *it)
		cout << i<<endl;
	return 0;
}


// Chapter 11.4.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <string>
#include <iostream>
#include <map>
#include <set>
#include <ctime>
#include <iterator>
#include <cctype>
#include <algorithm>
#include <fstream>
using namespace std;

int main()
{
	map<string, size_t> word_count;
	fstream in("1.txt");
	string word;
	while (in >> word)
	{
		string::iterator it1;
		for (it1 = word.begin(); it1 != word.end(); ++it1)   //消灭大小写
		{
			*it1 = tolower(*it1);
		}    
		remove_if(word.begin(), word.end(), ispunct);         //消灭标点符号
		++word_count[word];                                   //提取word计数器并将其加1
		/*
		auto ret = word_count.insert({word, 1});
		if (!ret.second) 
		++ret.first->second;
		*/
	}
	for (auto &i:word_count)
	{
		cout << i.first << " ";
		cout << i.second<< " " << endl;
	}


	int secs = 120;                                  //延时120s的程序
	clock_t delay = secs * CLOCKS_PER_SEC;           //总延时
	clock_t start = clock();                         //开始时间
	while (clock() - start < delay);                 //时间差大于总延时 跳出循环

    return 0;
}


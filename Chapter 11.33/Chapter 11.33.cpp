// Chapter 11.33.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <ctime>
#include <string>
#include <map>
#include <iterator>
#include <algorithm>
#include <fstream>
#include <sstream>

using namespace std;

map<string, string>build_Map(ifstream &map_file);                           //建立转换映射
const string &transform(const string &s, const map <string, string>&m);     //生成转换文本
void word_transform(ifstream &map_file, ifstream &input);                   //单词转换程序

int main()
{
	ifstream s1("1.txt"), s2("2.txt");
	word_transform(s1, s2);

	int secs = 120;                                  //延时120s的程序
	clock_t delay = secs * CLOCKS_PER_SEC;           //总延时
	clock_t start = clock();                         //开始时间
	while (clock() - start < delay);                 //时间差大于总延时 跳出循环

	return 0;
}

/*单词转换程序*/
void word_transform(ifstream &map_file, ifstream &input)
{
	auto trans_map = build_Map(map_file);                         //保存转换规则
	string text;                                                  //保存输入中的每一行
	while (getline(input, text))                                  //读取一行输入
	{
		istringstream stream(text);                               //读取每个单词
		string word;
		bool firstwrod = true;
		while (stream >> word)                                    //控制是否打印空格
		{
			if (firstwrod)
				firstwrod = false;
			else
				cout << " ";                                      //在单词间打印一个空格
			cout << transform(word, trans_map);                   //打印输出
		}
		cout << endl;                                             //完成一行输出
	}

}

/*建立转换映射*/
map<string, string>build_Map(ifstream &map_file)
{
	map<string, string>trans_map;
	string key;
	string value;
	while (map_file >> key && getline(map_file, value))      //读取第一个单词存入key，行中剩余内容存入value
	{
		if (value.size() > 1)
			trans_map[key] = value.substr(1);                //跳过前导格复制字符串
            /*trans_map.insert({ key,value.substr(1) });*/
		else
			throw runtime_error("no rule for" + key);
	}
	return trans_map;
}

/*生成转换文本*/
const string &transform(const string &s, const map <string, string>&m)
{
	auto map_it = m.find(s);
	if (map_it != m.cend())
		return map_it->second;
	else
		return s;
}
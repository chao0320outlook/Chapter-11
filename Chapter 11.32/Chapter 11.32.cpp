// Chapter 11.32.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>  
#include <ctime>
#include <string>  
#include <list>
#include <vector> 
#include <map>  
#include <set>
#include <algorithm>
#include <utility>                   //保存pair的头文件
using namespace std;

int main(int argc, char**argv)
{
	string author = "机械先驱";
	string author1 = "卡牌大师";
	multimap<string, string> Library;
	Library.insert(make_pair(author1, "灭世者的帽子"));
	Library.insert(make_pair(author, "法穿杖"));
	Library.insert(make_pair(author1, "法穿鞋"));
	Library.insert(make_pair(author, "冰杖"));
	Library.insert(make_pair(author, "巫妖之祸"));
	Library.insert(make_pair(author, "海克斯科技核心"));

	auto it1 = Library.find(author);                     //返回第一个关键字为author的迭代器
	auto it2 = Library.count(author);                    //返回关键词为author的元素数量

	while (it2)
	{
		if (it1->second == "海克斯科技核心")
		{
			Library.erase(it1);                 //直接删除此关键字值对，传入参数为指向它的迭代器
			break;                              //需要,不然下面调用到已经删除的迭代器，会出粗
		}
		++it1;
		--it2;
	}
	map<string, set<string>> Library2;          //排序所用map,set可自动排序
	set<string> Library2_books;
	auto it3 = Library.begin();
	for (auto & i:Library)
	{
		Library2_books.insert(i.second);
		Library2.insert(pair<string, set<string>>(i.first,Library2_books));
		/*Library2[i.first].insert(i.second);*/
		cout << i.first << "的宝贝儿：" << i.second << endl;
	}

	for (auto &i:Library2)
	{
		cout << i.first << "的宝贝儿：";
		for (auto &j:i.second)
		{
			cout << j << ",";
		}
	}

	int secs = 120;                                  //延时120s的程序
	clock_t delay = secs * CLOCKS_PER_SEC;           //总延时
	clock_t start = clock();                         //开始时间
	while (clock() - start < delay);                 //时间差大于总延时 跳出循环

	return 0;
}



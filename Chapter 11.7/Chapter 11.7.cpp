// Chapter 11.7.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iterator>
#include <iostream>
#include <ctime>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

int main()
{
	map <string, vector<string>> family;
	vector <pair<string, string>> child;
	string first_name, child_name,_birthday;
	multiset<string> c;
	vector <string> vce;

	map <string, vector<string>>::iterator itr;

	copy(vce.begin(), vce.end(), inserter(c, c.end()));
	//copy(vce.begin(), vce.end(), back_inserter(c));
	copy(c.begin(), c.end(), inserter(vce, vce.end()));
	copy(c.begin(), c.end(), back_inserter(vce));

	while ([&]()->bool {cout << "请输入家庭的姓:"; return cin >> first_name && (first_name != "end"); }())
	{
		while ([&]()->bool { cout << "请输入孩子的名字：";return cin >> child_name && (child_name != "end"); } ())
		{
			family[first_name].push_back(child_name);
			cout << "请输入孩子的生日:";
			cin >> child_name;
			child.push_back(make_pair(child_name, _birthday));
		}
	}
	for ( const auto &s : family)
	{
		cout << s.first << " :";
		for (const auto &d : s.second)
		{
			cout << d << " ";
		}
		cout << endl;
	}


	int secs = 120;                                  //延时120s的程序
	clock_t delay = secs * CLOCKS_PER_SEC;           //总延时
	clock_t start = clock();                         //开始时间
	while (clock() - start < delay);                 //时间差大于总延时 跳出循环

    return 0;
}


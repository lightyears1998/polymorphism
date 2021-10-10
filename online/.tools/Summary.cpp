/**
 * 用于读取当前路径下的所有.cpp文件中的注释并保存到文件中的工具
 */

#include <bits/stdc++.h>
#include <dirent.h>
using namespace std;

// 获取当前目录
string trim(string raw)
{
	reverse(raw.begin(), raw.end());

	string res; bool flag = false;
	for (unsigned i=0; i<raw.size(); ++i)
	{
		if (flag) {
			res += raw[i]; continue;
		}
		if ((raw[i]=='\\' || raw[i]=='/') && i) flag = true;
	}
	reverse(res.begin(), res.end());
	return res;
}

// 读取注释并输出
string summary(const string &path, const string &file)
{
	string res;
	if (~file.find(".cpp")) {
		ifstream in(path + "\\" + file);

		for (string line; getline(in, line); )
		{
			unsigned pos = line.find("//");
			if (~pos) {
				while (pos<line.size() && (line[pos] == ' ' || line[pos] == '/'))
					++pos;
				res += line.substr(pos);
				res += "\n";
			}
		}
	}

	if (res.size()) res = string(file) +"\n" + res + "\n";
	return res;
}

int main(int argc, char *argv[])
{
	ofstream out(".Summary.txt");
	string path = trim(string(argv[0]));

	// 列出当前目录下的文件
	DIR * dir = opendir(path.c_str());
	struct dirent *ent;
	while ((ent = readdir(dir))) {
		string file = string(ent->d_name);
		out << summary(path, file);
	}
	closedir(dir);

	out.close();
}

#include<iostream>
#include<vector>
#include<list>

using namespace std;

int main(){
	freopen("03.in","r",stdin);
	string a;
	list<char> lst;
	getline(cin,a);
	for (auto &i: a){
		if (i == '<' && lst.empty())
			continue;
		else if (i == '<' && !lst.empty())
			lst.pop_back();
		else
			lst.push_back(i);
	}
	for (char &b: lst)
		cout<<b;

}
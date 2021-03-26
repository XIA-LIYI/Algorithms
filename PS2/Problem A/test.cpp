#include<iostream>
#include<list>
#include<deque>
#include<vector>
#include<string>
#include <iterator>
using namespace std;

int main(){

	freopen("2.in","r",stdin);

	int N;cin>>N;

	for (int i = 0; i < N; ++i){
		list<char> lst;
		auto itr=lst.begin();
		if (i == 0) getchar();
		string line;
		getline(cin,line);
		long pos=0;

		for (long j = 0; j < line.length(); ++j){
			char temp=line[j];
			//cout<<temp<<" ";
			if (temp == '<'){
			    if (pos == 0) continue; 
				itr--;
				lst.erase(itr);
				itr=lst.begin();
				pos--;
				advance(itr,pos);
			}
			else if (temp == '['){
				itr=lst.begin();
				pos=0;
			}
			else if (temp == ']'){
				itr=lst.end();
				pos=lst.size();
			}
			else{
				lst.insert(itr, temp);
				itr=lst.begin();
				pos++;
				advance(itr, pos);
				
			}
				
		}
		for (auto a: lst){cout<<a;}
		cout<<endl;
	}
}


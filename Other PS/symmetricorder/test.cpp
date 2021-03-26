#include<iostream>
#include<list>
#include<deque>
#include<vector>
#include<string>
#include <iterator>
using namespace std;

int main(){

	freopen("sample.in","r",stdin);

	int N;cin>>N;
	int k=0;

	while (N != 0){
		list<string> a;
		list<string> b;
		for (int i = 0; i < N; ++i){
			string intput;
			cin>>intput;
			if (i % 2 == 0)
				a.push_back(intput);
			else
				b.push_front(intput);
		}
		k++;
		a.splice(a.end(),b);
		cout<<"SET "<<k<<endl;
		for (auto x: a)
			cout<<x<<endl;



		cin>>N;
	}

	
}


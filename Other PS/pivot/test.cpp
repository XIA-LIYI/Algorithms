#include<iostream>
#include<vector>
#include<list>

using namespace std;

int main(){
	freopen("2.in","r",stdin);
	list<pair<int, int> > lst;
	long N; cin>>N;
	long max;cin>>max;lst.push_back(make_pair(max,1));
	long min;

	for (long i = 0; i < N-1; ++i){
		long a; cin>>a;
		if (a < max)
			lst.push_back(make_pair(a,0));
		else{
			lst.push_back(make_pair(a,1));
			max=a;
		}
		
	}
	min=lst.end()->first;


	auto a=lst.end();
	for (int i = 0; i < N+1; ++i){
		if (a->first <= min){
			min=a->first;
			a->second+=1;
		}
		a--;
	}


	long num=0;
	for (auto &a: lst){
		if (a.second == 2)
			num+=1;
	}
	cout<<num;
}
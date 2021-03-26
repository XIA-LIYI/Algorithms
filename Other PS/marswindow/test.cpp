#include<iostream>
#include<list>
#include<deque>
#include<vector>
#include<string>
#include <iterator>
using namespace std;

int main(){

	freopen("2.in","r",stdin);

	pair<int,int> window;

	window.first=2018;
	window.second=4;

	int N; cin>>N;

	while (window.first < N){
		if (window.second <= 10){
			window.second+=2;
			window.first+=2;
		}
		else if (window.second == 11){
			window.second=1;
			window.first+=3;
		}
		else if (window.second == 12){
			window.second=2;
			window.first+=3;
		}
	}

	if (window.first == N)
		cout<<"Yes";
	else
		cout<<"No";

	
}


#include<iostream>
#include<list>
#include<deque>
#include<vector>
#include<string>
#include <iterator>
using namespace std;

int main(){

	freopen("2.in","r",stdin);

	int n; cin >> n;
	int i=1;
	int day=0;
	while (i < n){
		i*=2;
		day++;
	}
	cout<<day+1;
}


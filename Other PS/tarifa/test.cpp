#include<iostream>
#include<list>
#include<deque>
#include<vector>
#include<string>
#include <iterator>
using namespace std;

int main(){

	freopen("tarifa.3.in","r",stdin);

	int X,N;
	cin>>X>>N;
	long total=0;
	for (int i = 0; i < N; ++i){
		int A;cin>>A;
		total+=A;
	}
	if (X*N-total+X < 0)
		cout<<0;
	else
		cout<<X*N-total+X;
}


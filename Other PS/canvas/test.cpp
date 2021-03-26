#include<iostream>
#include<queue>
using namespace std;



int main(){
	freopen("sample.in","r",stdin);
	int N;
	cin>>N;
	for (int i = 0; i < N; ++i){
		long num; cin >> num;
		long long cost=0;
		priority_queue<long long, vector<long long>, greater<long long> > X;
		for (long j = 0; j < num; ++j){
			long unit;cin>>unit;//cout<<unit<<" ";
			X.push(unit);
		}

		while (X.size() > 1){
			long a,b;
			a=X.top(); X.pop();
			b=X.top(); X.pop();
			X.push(a+b);
			cost+=(a+b);
		}
		cout<<cost<<endl;
	}
}
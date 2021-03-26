#include<iostream>
#include<string>
#include<vector>
#include<list>
#include<queue>
#include<algorithm>
#include<stack>
#include<deque>

using namespace std;

int main(){
	freopen("1.in", "r", stdin);

	int N; cin>>N;
	vector<list<string> > unit(N);

	for (int i = 0; i < N; ++i){
		string A;
		cin>>A;
		unit[i].push_back(A);
	}

	int left=0,right=0;
	for (int i = 0; i < N-1; ++i){
		cin>>left;cin>>right;
		left--;right--;
		unit[left].splice(unit[left].end(),unit[right]);
	}

	for (auto x: unit[left])
		cout<<x;
	
	
}
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
	freopen("1_sample.in","r",stdin);

	int TC;cin>>TC;

	for (int i = 0; i < TC; ++i){
		long N;cin>>N;
		long A,B,C,X,Y;
		cin>>A>>B>>C>>X>>Y;

		long S[C];
		for (long i = 0; i < C; ++i){
			S[i]=0;
		}
		if (A < C)
			S[A]=1;
		else if (A == C)
			S[0]=1;
		long first=A;
		long second;
		for (long i = 0; i < N-1; ++i){
			second=(first*B+A)%C;
			S[second]+=1;
			first=second;
		}

		// for (long i = 0; i < C; ++i)
		// 	cout<<S[i]<<" ";
		// cout<<endl;
		long V=0;
		for (long i = 0; i < C; ++i){
			for (long j = 0; j < S[i]; ++j){
				V=(V*X+i)%Y;
			}
		}
		if (A > C)
			V=(V*X+A)%Y;
		cout<<V<<endl;
	}


	
}

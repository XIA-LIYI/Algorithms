#include<iostream>

using namespace std;

void swap(long &x, long &y){

	long temp=x;
	y=x;
	x=temp;

}

int main(){

	freopen("E.0.in","r",stdin);

	long N;cin>>N;
	long A[N];

	for (long i = 0; i < N; ++i){
		cin>>A[i];
	}

	long num=0;

	for (long i = 0; i < N; ++i){
		for (long j = 0; j < N-i-1; ++j){
			if (A[j] > A[j+1]){
				swap(A[j],A[j+1]);
				num++;
			}
		}
	}

	cout<<num;

}


// A0177873L
// XIA LIYI
// LAB(08)
// Aaryam

#include<cstring>
#include<math.h>
#include<iostream>
using namespace std;

int main(){
	
	freopen("1.in","r",stdin);

	int TC; cin>>TC;
	int N;


	for (int i=1; i <= TC; ++i){
		cin>>N;
		long A[N];

		cin>>A[0];
		long sum=A[0];
		for (int j=1; j < N;++j){
			long in;
			int x=0;
			long median;
			cin>>in;
			for (int k=0; k < j;++k ){
				if (in < A[k]){
					for (int m=j; m > k;--m){
						A[m]=A[m-1];
					}
					A[k]=in;
					k=j;
					x=1;
				}
			}
			if (x == 0)
				A[j] = in;
			if ((j+1) % 2 == 1)
				median=A[(j+1) / 2];
			else
				median=(A[(j+1)/2-1]+A[(j+1)/2])/2;
			sum+=median;

		}
		cout<<sum<<endl;

	}



}

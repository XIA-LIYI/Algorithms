// A0177873L
// XIA LIYI
// LAB(08)
// Aaryam

#include<iostream>
#include<math.h>

using namespace std;


void f(long A[], long n)
{
	long left,right,num;
	long middle,j,i;
	for (i = 1; i < n;i++)
	{
		left = 0;
		right =i-1;
		num=A[i];
		while (right >= left)
		{
			middle=(left+right)/2;
			if (num < A[middle])
				right=middle-1;
			else
				left=middle+1;
		}
		for (j= i-1;j>=left;j--)
			A[j+1]=A[j];
		A[left]=num;
	}
}
int main(){
	freopen("1.in","r",stdin);

	int TC;cin>>TC;

	for (int i = 1; i <= TC; ++i){

		long N; cin>>N;
		long A[N+1];
		cin>>A[0];
		long sum=A[0];

		for (long j = 1; j < N; ++j){

			long in; cin>>in;A[j]=in;
			long median;
			long pos;
			f(A,j+1);

			if ((j+1) % 2 == 0)
				median=(A[(j+1)/2-1]+A[(j+1)/2])/2;
			else
				median=A[(j+1)/2];
			sum+=median;

		}

		cout<<sum<<endl;
	}
}



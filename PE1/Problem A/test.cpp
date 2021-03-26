#include<iostream>
#include<string>
#include<vector>
#include<list>
#include<queue>
#include<algorithm>
#include<stack>
#include<deque>

using namespace std;
long median(long a, long b, long c){
	long A[3]={a,b,c};
	sort(A,A+3);
	return A[1];
}
void modulo(char chr[], long N){
	for (long i = 0; i < N; ++i)
		cout<<chr[i];
}
void Walk(long A[], long B[], long N){
	long i=0;

	while (B[i] == 0){

		B[i]=1;
		i=A[i];
		// cout<<i<<endl;
		if (i >= N){
			cout<<"Out";
			return;
		}
		else if (i == N-1){
			cout<<"Done";
			return;
		}
		
	}
	cout<<"Cyclic";
}
int main(){
	freopen("6.in","r",stdin);

	long N;cin>>N;
	long B[200000]={0};
	int t;cin>>t;
	long A[N];
	long even_sum=0,odd_sum=0;
	char chr[N];

	for (long i = 0; i < N; ++i){
		cin>>A[i];
		if (A[i] % 2 == 1)
			odd_sum+=A[i];
		else
			even_sum+=A[i];
		chr[i]=(A[i]%26)+'a';
	}

	if (t == 1){
		cout<<7;
		return 0;
	}
	else if (t == 2){
		if (A[0] > A[1]){
			cout<<"Bigger";
		}
		else if (A[0] < A[1]){
			cout<<"Smaller";
		}
		else{
			cout<<"Equal";
		}
		return 0;
	}
	else if (t == 3){
		long result=median(A[0],A[1],A[2]);
		cout<<result;
		return 0;
	}
	else if (t == 4){
		cout<<odd_sum+even_sum;
		return 0;
	}
	else if (t == 5){
		cout<<even_sum;
		return 0;
	}
	else if (t == 6){
		modulo(chr,N);
		return 0;
	}
	else if (t == 7){
		Walk(A,B,N);
		return 0;
	}
	
}

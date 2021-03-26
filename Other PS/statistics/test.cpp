#include<iostream>

using namespace std;

int main(){
	freopen("sample.in", "r", stdin);
	int i = 0;
	int N;
	while (cin >> N, !cin.eof()){
		i++;
		long max,min,range;
		long A;
		cin>>A;
		max=A;min=A;
		for (int i = 1; i < N; ++i){
			cin>>A;
			if (A > max)
				max=A;
			if (A < min)
				min=A;

		}
		range=max-min;
	    cout<<"Case "<<i<<": "<<min<<" "<<max<<" "<<range<<endl;
	}
}
#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

int main(){

	freopen("1.in","r",stdin);

	int N;cin>>N;

	for (int i = 1; i <= N; ++i){
		int S;cin>>S;
		int Blue[101]={0},Red[101]={0};
		int blue=0,red=0,max_blue=0,max_red=0,min_blue=100,min_red=100;

		for (int j = 0; j < S; ++j){
			int pos;
			string b;
			cin>>pos>>b;

			if (b[0] == 'B'){
				Blue[pos]+=1;
				blue+=1;
				if (pos > max_blue)
					max_blue=pos;
				if (pos < min_blue)
					min_blue=pos;
			}
			else{
				Red[pos]+=1;
				red+=1;
				if (pos > max_red)
					max_red=pos;
				if (pos < min_red)
					min_red=pos;
			}
		}

		int sum_length=0;
		int sum_knots=min(red,blue)*2;
		int sum_scopes=0;

		for (int m=max_blue; m >= min_blue; --m){
			sum_scopes+=Blue[m];
			sum_length+=(Blue[m]*m);
			if (sum_scopes >= min(red,blue)){
				sum_length-=((sum_scopes-min(red,blue))*m);
				break;
			}
		}

		sum_scopes=0;
		for (int m=max_red; m >= min_red; --m){
			sum_scopes+=Red[m];
			sum_length+=(Red[m]*m);
			if (sum_scopes >= min(red,blue)){
				sum_length-=((sum_scopes-min(red,blue))*m);
				break;
			}
		}
		sum_length=sum_length-sum_knots;
		cout<<"Case #"<<i<<": "<<sum_length<<endl;


	}


}
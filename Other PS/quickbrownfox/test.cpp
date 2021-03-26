#include<iostream>
#include<string>

using namespace std;

int main(){
	freopen("a.in", "r", stdin);
	int N; cin>>N;
	getchar();
	for (int i = 0; i < N; ++i){
		int A[26]={0};
		string B;
		getline(cin,B);
		for (auto x: B){
			if (x >= 'a' && x <='z'){
				A[x-'a']=1;
			}
			if (x >= 'A' && x <='Z'){
				A[x-'A']=1;
			}
		}
		bool check=true;
		for (int i = 0; i < 26; ++i){
			if (A[i] == 0){
				if (check == true){
					cout<<"missing ";
				}
				char chr='a'+i;
				cout<<chr;
				check=false;
			}
		}
		if (check == true) cout<<"pangram";
		cout<<endl;

	}

}
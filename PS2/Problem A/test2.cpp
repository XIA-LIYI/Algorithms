//XIA LIYI
//A0177873L
//Group 
#include<iostream>
#include<list>
#include<deque>
#include<vector>
#include<string>
#include <iterator>
using namespace std;

int main(){

	freopen("1.in","r",stdin);

	int N;cin>>N;

	for (int i = 0; i < N; ++i){

		list<char> lst;
		if (i == 0) getchar();
		string line;
		getline(cin,line);
		list<char> new_lst;
		bool start;

		for (long j = 0; j < line.length(); ++j){
			char temp=line[j];
			//cout<<temp<<" ";
			if (temp == '[')
				if (start == true){
					lst.splice(lst.end(), new_lst);
					new_lst.clear();
				}
				else
					start=true;
			else if (temp == ']') {
				if (start == true){

					lst.splice(lst.end(),new_lst);
					new_lst.clear();
					start=false;
				}
			}
			else if (temp == '<'){
				if (start == true){
					if (new_lst.size() != 0)
					    new_lst.pop_front();
				}
				else{
					if (lst.size() != 0)
						lst.pop_front();
				}
			}
			else{
				if (start == true){
					new_lst.push_front(temp);
				}
				else{
					lst.push_front(temp);
				}
			}
					
			
		}
		if (new_lst.size() != 0){
			lst.splice(lst.end(),new_lst);
			new_lst.clear();
		}
		lst.reverse();
		for (auto a: lst){cout<<a;}
 
			cout<<endl;

	}
}


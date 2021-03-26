//XIA LIYI
//A0177873L
//Group 08
//AAryam
#include<iostream>
#include<list>
#include<deque>
#include<queue>
#include<vector>
#include<string>
#include<iterator>
#include<algorithm>
#include<map>
#include<set>
using namespace std;


int main(){

    freopen("1.in","r",stdin);
    map<string, pair<long long,int> > list;
    set<pair<int, pair<long long, string> > > pq;

    long long N;cin>>N;

    for (long long i = 0; i < N; ++i){
    	int op;cin>>op;

    	if (op == 0){
    		string name; cin>>name;
    		int level; cin>>level;
    		list[name]=make_pair(N-i,level);
    		pq.insert(make_pair(level,make_pair(N-i,name)));
    	}
    	else if (op == 1){
    		string name;cin>>name;
    		int level;cin>>level;
    		pair<long long, int> unit=list[name];
    		list[name].second+=level;
    		pq.insert(make_pair(unit.second+level,make_pair(unit.first,name)));
    	}
    	else if (op == 2){
    		string name;cin>>name;
    		list.erase(name);
    	}
    	else if (op == 3){
    		while (1){
    			if (pq.size() == 0){
    				cout<<"The clinic is empty"<<endl;
    				break;
    			}
    			else if (list.count((*--pq.end()).second.second) == 0){
    				pq.erase(--pq.end());
    				continue;
    			}
    			else{
    				cout<<(*--pq.end()).second.second<<endl;
    				break;
    			}
    		}
    	}
    }
}
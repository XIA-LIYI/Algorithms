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
using namespace std;
int get_search(string name, list<pair<int, string> > *lst, int level){
    auto temp=lst->begin();
    for (int i = 0; i < lst->size(); ++i){
        if (temp->second == name){
            int temp1=temp->first;
            // lst->erase(temp);
            // lst->push_back(make_pair(level+temp1,name));
            temp->first+=level;
            return temp1;
        }
        temp++;
    }
}
int get_delete(string name, list<pair<int, string> > *lst){
    auto temp=lst->begin();
    for (int i = 0; i < lst->size();++i){
        if (temp->second == name){
            int temp1=temp->first;
            lst->erase(temp);
            return temp1;
        }
        temp++;

    }
}
int belong(string name){
    int result=0;
    if (name.length() >= 3){
        return (name[0]-'A')*729+(name[1]-'A')*27+(name[2]-'A');
    }
    else if (name.length() == 2){
        return (name[0]-'A')*729+(name[1]-'A')*27;
    }
    else{
        return (name[0]-'A')*729;
    }
}
bool comp(pair<int, pair<int,string> > a,pair<int, pair<int,string> > b){
	if (a.first < b.first){
		return true;
	}
	if (a.first == b.first){
		if (a.second.second > b.second.second)
			return true;
		else
			return false;
	}
    else
    	return false;
}

int main(){

    freopen("1.in","r",stdin);
    vector<pair<int,pair<int,string> > > lst;
    int k=0;
    vector<list<pair<int, string> > > vt(19683);
    long N; cin>>N;
    long num=0;
    make_heap(lst.begin(),lst.end(),comp);
    for (long i = 0;i < N; ++i){
        int op;cin>>op;
        if (op == 0){
        	string name;cin>>name;
        	int level;cin>>level;
        	lst.push_back(make_pair(level,make_pair(N-i, name)));
        	push_heap(lst.begin(),lst.end(),comp);
        	k++;
        	// push_heap(lst.begin(), lst.end(),comp);
        }
        else if (op == 1){
        	string name;cin>>name;
        	int level;cin>>level;
        	auto itr=lst.begin();
        	int index=get_search(name,&vt[belong(name)],level);
        	while (itr->second.second != name){
        	 	itr++;
        	}
        	// pair<int,pair<int,string> > temp=make_pair(itr->first+level,make_pair(itr->second.first,name));
        	// lst.erase(itr);
        	// lst.push_back(temp);
        	// push_heap(lst.begin(),lst.end(),comp);
        	itr->first+=level;
        	push_heap(lst.begin(),itr+1,comp);
          	//push_heap(lst.begin(),lst.end(),comp);
        }
        else if (op == 2){
        	string name;cin>>name;
        	auto itr=lst.begin();
        	list<pair<int, pair<int,string> > > lst1;
        	int i=0;
        	while (lst.back().second.second != name){
        		pop_heap(lst.begin(),lst.end()-i,comp);
        		++i;
        	}
        	lst.pop_back();
        	for (int j=i; j >= 0; --j)
        		push_heap(lst.begin(),lst.end()-j,comp);

        	// itr->first=0;
        	k--;
            
        }
        else if (op == 3){
        	if (k == 0){
        		cout<<"The clinic is empty"<<endl;
        	}
        	else{
        		// pop_heap(lst.begin(),lst.end(), greater<pair<int,pair<int,string> > > ());
        		// cout<<lst.back().second.second<<endl;
        		// make_heap(lst.begin(),lst.end(),greater<pair<int,pair<int,string> > > ());

        	cout<<lst[0].second.second<<endl;
        	}
        }
        // cout<<i<<endl;
        // for (auto x:lst)
        // 	cout<<x.first<<" "<<x.second.second<<endl;
        // cout<<endl;
    }
}
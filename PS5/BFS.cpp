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

int MIN;

int compute(vector<set<pair<int,int> > > map,int V, int k, int s, int t, int dis)  
{  
    //cout<<k<<" "<<s<<" "<<t<<" "<<dis<<endl;
    if (s == t){
            MIN=min(dis,MIN);
            return 1;
        }
    else if (dis > MIN){
        return 1;
    }
    else if (k == 0){
        return 1;
    }
    else{
    for (auto &i: map[s]){
        if (i.first == 1000000){
            continue;
        }
        else{
            if (compute(map,V,k-1,i.second,t,i.first+dis) == 0)
              return 0;          
        }

    }}
} 


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("1.in","r",stdin);

    int TC;cin>>TC;
    for (int i = 0; i < TC; i++){
        string line;getline(cin,line);
        int V;cin>>V;
        vector<set<pair<int, int> > > table(V);

        for (int j = 0; j < V; ++j){
            int X;cin>>X;
            for (int l = 0; l < X; ++l){
                int index;long long weight;cin>>index>>weight;
                table[j].insert(make_pair(weight,index));
            }
        }

        int Q;cin>>Q;
        for (int j = 0; j < Q; ++j){
            int s,t,k;cin>>s>>t>>k;
            //cout<<s<<t<<endl;
            MIN=1000000;
            if (k == 1)
                cout<<"-1\n";
            else{
                compute(table,V,k-1,s,t,0);
                if (MIN == 1000000)
                    cout<<"-1\n";
                else
                cout<<MIN<<"\n";
            }

        }
    if (i != TC-1)
        cout<<"\n";

    }
}
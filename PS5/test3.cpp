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

long long  MAX=100000000;

void compute(vector<vector<pair<long long, int> > > map, int n, int k, int s, int h)  
{  
    long long mini=MAX;
    vector<vector<pair<long long, int> > > map1=map;

    for(int t=0; t<n ; ++t) {
        //if (t != s && t !=h){
        for(int i=0; i<n; ++i)  
            for(int j=0; j<n; ++j){
                map1[i][j].first=min(map1[i][t].first+map1[t][j].first,map1[i][j].first);
                if (map1[i][j].first == map1[i][t].first+map1[t][j].first){
                    map1[i][j].second=map1[i][t].second+map1[t][j].second;
                if (i == s && h == j){
                    if (map1[i][j].first < mini && map1[i][j].second <=k)
                        mini=map1[i][j].first;
                }}
            }}
    
    map1=map;

    for(int t=0; t<n ; ++t) {
        //if (t != s && t !=h){
        for(int i=0; i<n; ++i)  
            for(int j=n-1; j>=0; --j){
                map1[i][j].first=min(map1[i][t].first+map1[t][j].first,map1[i][j].first);
                if (map1[i][j].first == map1[i][t].first+map1[t][j].first){
                    map1[i][j].second=map1[i][t].second+map1[t][j].second;
                if (i == s && h == j){
                    if (map1[i][j].first < mini && map1[i][j].second <=k)
                        mini=map1[i][j].first;
                }}
            }}

    map1=map;

    for(int t=0; t<n ; ++t) {
        //if (t != s && t !=h){
        for(int i=n-1; i>=0; --i)  
            for(int j=0; j<n; ++j){
                map1[i][j].first=min(map1[i][t].first+map1[t][j].first,map1[i][j].first);
                if (map1[i][j].first == map1[i][t].first+map1[t][j].first){
                    map1[i][j].second=map1[i][t].second+map1[t][j].second;
                if (i == s && h == j){
                    if (map1[i][j].first < mini && map1[i][j].second <=k)
                        mini=map1[i][j].first;
                }}
            }}
    map1=map;

    for(int t=0; t<n ; ++t) {
        //if (t != s && t !=h){
        for(int i=n-1; i>=0; --i)  
            for(int j=n-1; j>=0; --j){
                map1[i][j].first=min(map1[i][t].first+map1[t][j].first,map1[i][j].first);
                if (map1[i][j].first == map1[i][t].first+map1[t][j].first){
                    map1[i][j].second=map1[i][t].second+map1[t][j].second;
                if (i == s && h == j){
                    if (map1[i][j].first < mini && map1[i][j].second <=k)
                        mini=map1[i][j].first;
                }}
            }}
    map1=map;

    for(int t=n-1; t>=0 ; --t) {
        //if (t != s && t !=h){
        for(int i=0; i<n; ++i)  
            for(int j=0; j<n; ++j){
                map1[i][j].first=min(map1[i][t].first+map1[t][j].first,map1[i][j].first);
                if (map1[i][j].first == map1[i][t].first+map1[t][j].first){
                    map1[i][j].second=map1[i][t].second+map1[t][j].second;
                if (i == s && h == j){
                    if (map1[i][j].first < mini && map1[i][j].second <=k)
                        mini=map1[i][j].first;
                }}
            }}
        map1=map;

    for(int t=n-1; t>=0 ; --t) {
        //if (t != s && t !=h){
        for(int i=0; i<n; ++i)  
            for(int j=n-1; j>=0; --j){
                map1[i][j].first=min(map1[i][t].first+map1[t][j].first,map1[i][j].first);
                if (map1[i][j].first == map1[i][t].first+map1[t][j].first){
                    map1[i][j].second=map1[i][t].second+map1[t][j].second;
                if (i == s && h == j){
                    if (map1[i][j].first < mini && map1[i][j].second <=k)
                        mini=map1[i][j].first;
                }}
            }}

    map1=map;

    for(int t=n-1; t>=0 ; --t) {
        //if (t != s && t !=h){
        for(int i=n-1; i>=0; --i)  
            for(int j=0; j<n; ++j){
                map1[i][j].first=min(map1[i][t].first+map1[t][j].first,map1[i][j].first);
                if (map1[i][j].first == map1[i][t].first+map1[t][j].first){
                    map1[i][j].second=map1[i][t].second+map1[t][j].second;
                if (i == s && h == j){
                    if (map1[i][j].first < mini && map1[i][j].second <=k)
                        mini=map1[i][j].first;
                }}
            }}
    map1=map;

    for(int t=n-1; t>=0 ; --t) {
        //if (t != s && t !=h){
        for(int i=n-1; i>=0; --i)  
            for(int j=n-1; j>=0; --j){
                map1[i][j].first=min(map1[i][t].first+map1[t][j].first,map1[i][j].first);
                if (map1[i][j].first == map1[i][t].first+map1[t][j].first){
                    map1[i][j].second=map1[i][t].second+map1[t][j].second;
                if (i == s && h == j){
                    if (map1[i][j].first < mini && map1[i][j].second <=k)
                        mini=map1[i][j].first;
                }}
            }}

    if (mini == MAX)
        cout<<"-1\n";
    else
        cout<<mini<<"\n";

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("1.in","r",stdin);

    int TC;cin>>TC;
    for (int i = 0; i < TC; ++i){
        string line;getline(cin,line);
        int V;cin>>V;
        vector<vector<pair<long long,int> > > table(V);
        for (int a = 0; a < V; ++a){
            for (int b = 0; b < V; ++b){
                if (a == b){
                    table[a].push_back(make_pair(0,0));
                }
                else
                    table[a].push_back(make_pair(MAX,0));
            }
        }

        for (int j = 0; j < V; ++j){
            int X;cin>>X;
            for (int l = 0; l < X; ++l){
                int index,weight;cin>>index>>weight;
                table[j][index].first=weight;
                table[j][index].second=1;
            }
        }

        int Q;cin>>Q;
        
        for (int j = 0; j < Q; ++j){
            int s,t,k;cin>>s>>t>>k;
            if (s == t)
                cout<<0<<endl;
            else if (k == 1)
                cout<<"-1\n";
            else
                compute(table,V,k-1,s,t);
        }

        if (i != TC-1)
            cout<<"\n";
    }
}
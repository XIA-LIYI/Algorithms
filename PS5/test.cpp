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

typedef pair<int, long long> i;
typedef pair<pair<long long, int>,int> ii;
typedef vector<long long> vi;
typedef vector<ii> vii;

const long long inf = 1e9;


vector<long long> check(vector<vector<long long> > map, int n, int h)  
{  
    for(int t=0; t<n ; ++t)
        for(int i=0; i<n; ++i)  
            for(int j=0; j<n; ++j){
                map[i][j]=min(map[i][j],map[i][t]+map[t][j]);
            }

    vector<long long> vt(n);
    for (int i = 0;i < n; ++i){
        vt[i]=map[i][h];
    }
    return vt;
}
void Dijkstra(vector<vector<long long> > table2,vector<vector<pair<int, long long> > > AL, int V, int k,int s, int t) {
    vector<long long> vt=check(table2,V,t);
    priority_queue<ii, vector<ii>, greater<ii> > pq; pq.push(make_pair(make_pair(0, s),k));
    vi dist(V,inf); dist[s] = 0;
    // sort the pairs by non-decreasing distance from s
    while (!pq.empty()) {                          // main loop
        ii x= pq.top(); pq.pop();            // shortest unvisited u
        k = x.second;
        if (x.first.first > dist[x.first.second] || k <= 0) continue;                   // a very important check
        for (auto &y: AL[x.first.second]) {                 // all edges from u
            if (dist[x.first.second]+y.second >= dist[y.first] ||  vt[y.first] > k-1) continue;        // not improving, skip
            dist[y.first] = dist[x.first.second]+y.second;                       // relax operation
            pq.push(make_pair(make_pair(dist[y.first], y.first),k-1));                     // enqueue better pair
        }
        
    }

    if (dist[t] != inf){
        cout<<dist[t]<<endl;
    }
    else
        cout<<"-1"<<endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("1.in","r",stdin);

    int TC;cin>>TC;
    for (int i = 0; i < TC; ++i){
        string line;getline(cin,line);
        int V;cin>>V;
        vector<vector<pair<int, long long> > > table(V);
        vector<vector<long long> > table2(V,vector<long long> (V));

        for (int a = 0; a < V; ++a){
            for (int b = 0; b < V; ++b){
                if (a == b)
                    table2[a][b]=0;
                else
                table2[a][b]=inf;
            }
        }

        for (int j = 0; j < V; ++j){
            int X;cin>>X;
            for (int l = 0; l < X; ++l){
                int index,weight;cin>>index>>weight;
                table[j].push_back(make_pair(index,weight));
                table2[j][index]=1;
            }
        }

        int Q;cin>>Q;

        
        for (int j = 0; j < Q; ++j){
            int s,t,k;cin>>s>>t>>k;
            if (s == t)
                cout<<0<<endl;
            else if (k <= 1)
                cout<<"-1\n";
            else
                Dijkstra(table2,table,V,k-1,s,t);

        }

        if (i != TC-1)
            cout<<"\n";
    }
}
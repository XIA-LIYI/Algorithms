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

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

enum { UNVISITED, VISITED };

vector<vii> AL;
vector<vii> BL;
vi dfs_num;
int check = 0;

void dfs(int u,int target) {                                // normal usage
                             // this vertex is visited
    dfs_num[u] = VISITED;                          // mark u as visited
    for (auto &x : AL[u]){
        if (check == 1)
            return;                     // C++17 style, w ignored
        if (x.first == target){
        	check=1;
        	return;
        }
        if (dfs_num[x.first] == UNVISITED)                 // to avoid cycle
            dfs(x.first,target);
        }
    return;                                 // recursively visits v
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("sample-01.in","r",stdin);
    int r,c;cin>>r>>c;
    vector<int> table(r*c,-1);
    //vector<vector<int> > table(r*c, vector<int>(r*c));
    AL.assign(r*c, vii());
    BL.assign(r*c, vii());

    int a=1;
    int b=0;

    for (int i = 0; i < r; ++i){
    	string line;cin>>line;
    	int k=0;
    	for (int j = 0; j < c; ++j){
    		int unit=line[j]-'0';
    		table[i*c+k]=unit;
    		if (k > 0)
    			if (unit == table[i*c+k-1])
    		{
    			AL[i*c+k].push_back(make_pair(i*c+k-1,1));
    			AL[i*c+k-1].push_back(make_pair(i*c+k,1));
    		}
    		if (i > 0)
    			if (unit == table[i*c+k-c])
    		{
    			AL[i*c+k].push_back(make_pair(i*c+k-c,1));
    			AL[i*c+k-c].push_back(make_pair(i*c+k,1));
    		}
    		k++;
    	}
    }


    int n;cin>>n;

    for (int i = 0; i < n; ++i){
    	int r1,c1,r2,c2;cin>>r1>>c1>>r2>>c2;
    	check=0;
    	dfs_num.assign(r*c,UNVISITED);
    	int a,b;
    	a=(r1-1)*c+c1-1;
    	b=(r2-1)*c+c2-1;
    	if (table[a] != table[b]){cout<<"neither\n";continue;
		}
    	if (b == a)
    		check=1;
    	dfs(a,b);
    	if (check == 0){cout<<"neither\n";continue;}
    	if (table[(r1-1)*c+c1-1] == 1){
    		cout<<"decimal\n";
   		}
   		else
   			cout<<"binary\n";
    }
}

#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> point;

int main(){
	freopen("Islands-0002.in","r",stdin);
	
	int r,c;cin>>r>>c;
	vector<point> land;
	vector<int> water;
	vector<int> cloudy;
	vector<vector<char> > map(r,vector<char>(c));
	for (int i = 0; i < r; ++i){
		for (int j = 0; j < c; ++j){
			cin>>map[i][j];
			if (map[i][j] == 'L') land.push_back({i,j});
			//if (map[i][j] == 'C') cloudy.push_back({i,j});
		}
	}
	int min=0;
	vector<vector<bool> > visited(r,vector<bool>(c, false));  
	for (int i = 0; i < land.size(); ++i){
		point p=land[i];
		//cout<<p.first<<p.second<<endl<<endl;
		if (visited[p.first][p.second]) continue;
		min++;
		queue<point> q;q.push(p);
		while (!q.empty()){
			point p1=q.front();q.pop();
			int x=p1.first,y=p1.second;
			//cout<<x<<y<<endl;
			if (visited[x][y]) continue;
			visited[x][y]=true;
			//cout<<"DO";
			if (x > 0 && map[x-1][y] != 'W') q.push({x-1,y});
			if (y > 0 && map[x][y-1] != 'W') q.push({x,y-1});
			if (x < r-1 && map[x+1][y] != 'W') q.push({x+1,y}); 
			if (y < c-1 && map[x][y+1] != 'W') q.push({x,y+1});
		}
	}
	
	cout<<min;
}




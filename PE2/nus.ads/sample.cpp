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

int row,col;
vector<vector<char> > grid; 
vector<vector<bool> > visited; 

pair<int,int> TL,BR;

bool check(char x){
    if (x <= 'z' && x >= 'a') return true;
    else if ( x <= 'Z' && x >= 'A') return true;
    else if (x <= '9' && x >= '0') return true;
    else if (x == '!' || x == '?' || x == '+' || x == ' ' || x == ',' || x == '.') return true;
    else return false;
}

void getbounds(int i, int j){
    if (i < TL.first) TL.first = i;
    if (j < TL.second) TL.second = j;
    if (i > BR.first) BR.first = i;
    if (j > BR.second) BR.second = j;
    if (!visited[i][j]){
    visited[i][j]=true;

    if (i > 0 && grid[i-1][j] != '+') getbounds(i-1,j);
    if (j > 0 && grid[i][j-1] != '+') getbounds(i,j-1);
    if (i < row-1 && grid[i+1][j] != '+') getbounds(i+1,j);
    if (j < col-1 && grid[i][j+1] != '+') getbounds(i,j+1);
    }
}

void erase(){
    for (int i = TL.first; i <= BR.first; ++i)
        for (int j = TL.second; j <= BR.second; ++j)
            grid[i][j]=' ';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    freopen("1.in","r",stdin);

    cin>>row>>col;
    cin.get();
    vector<pair<int,int> > find;
    for (int i = 0 ; i < row; ++i){
        string line; getline(cin,line);
        vector<char> row1;
        vector<bool> row2;
        for (int j = 0; j < col; ++j){
            row1.push_back(line[j]);
            row2.push_back(false);
            if (check(line[j]) == false) find.push_back(make_pair(i,j)); 
        }
        grid.push_back(row1);
        visited.push_back(row2);
    }

    for (auto &x:find){
            int i = x.first;
            int j = x.second;
            if (visited[i][j]) continue;
            TL=make_pair(200,200);
            BR=make_pair(0,0);
            getbounds(i,j);
            
            if (TL.first == 0 || TL.second == 0 || BR.first == row-1 || BR.second == col-1) continue;
            TL.first--;TL.second--;
            BR.first++;BR.second++;
            //cout<<TL.first<<endl<<TL.second<<endl<<BR.first<<endl<<BR.second<<endl;
            erase();
        }

    for (int i = 0; i < row; ++i){
        for (int j = 0; j < col; ++j){
            cout<<grid[i][j];
        }
        cout<<endl;
    }


        
}
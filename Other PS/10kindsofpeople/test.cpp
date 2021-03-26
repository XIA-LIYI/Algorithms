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

typedef vector<int> vi;
typedef vector<bool> vii;
typedef vector<vii> vvii;

int check(vi &l, int x) {
	while (x != l[x]) x = l[x];
	return x;
}

void construct(vi &f, vi &g, int a, int b) {
	a = check(f, a);
	b = check(f, b);
	if (a == b) return;
	if (g[a] < g[b]) swap(a, b);
	g[a] += g[b];
	f[b] = a;
}

int main() {
	freopen("sample-01.in","r",stdin);
	
	int r, c;cin>>r>>c;

	vi f(r * c), g(r * c, 1);
	vvii a(r);
	for (int i = 0; i < r; i++) {
		a[i].assign(c, false);
		for (int j = 0; j < c; j++) {
			f[i * c + j] = i * c + j;
			char b;cin >> b;
			if (b == '1') a[i][j] = true;
		}
	}
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (j < c - 1 && a[i][j] == a[i][j + 1])
				construct(f, g, i * c + j, i * c + j + 1);
			if (i < r - 1 && a[i][j] == a[i + 1][j])
				construct(f, g, i * c + j, (i + 1) * c + j);
		}
	}

	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) { 
		int r1, c1, r2, c2;
		cin>>r1>>c1>>r2>>c2;
		r1--; c1--; r2--; c2--;
		//cout<<check(f,r1*c+c1)<<endl;
		//cout<<check(f,r2*c+c2)<<endl;
		if (check(f, r1 * c + c1) == check(f, r2 * c + c2)){
			if (a[r1][c1] == true)
				cout<<"decimal\n";
			else
				cout<<"binary\n";
		}
		else cout << "neither\n";
	}
}

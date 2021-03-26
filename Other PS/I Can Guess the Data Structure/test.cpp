#include<iostream>
#include<list>
#include<stack>
#include<queue>
#include<vector>
using namespace std;
int main(){

	freopen("1.in","r",stdin);
	int N;
	while (cin>>N){
		int condition=3;
		bool A[3]={true,true,true};
		vector<pair<int, int> > command;

		for (int i=0; i < N; ++i){
			int type;cin>>type;
			int number;cin>>number;
			command.push_back(make_pair(type,number));
		}
        stack<int> stk;
        queue<int> q;
        priority_queue<int> pq;

        for (int j = 0; j < N; j++) {
            if (command[j].first == 1) 
            	stk.push(command[j].second);
            else {
                if (stk.size() > 0 && stk.top() == command[j].second) 
                	stk.pop();
                else {
                    A[0] = false;
                    condition--;
                    break;   
                }
            }
        }


        for (int j = 0; j < N; j++) {
            if (command[j].first == 1) 
            	q.push(command[j].second);
            else {
                if (q.size() > 0 && q.front() == command[j].second) 
                	q.pop();
                else {
                    condition --;
                    A[1] = false;
                    break;
                }
            }
        }

        for (int j = 0; j < N; j++) {
            if (command[j].first == 1) 
            	pq.push(command[j].second);
            else {
                if (pq.size() > 0 && pq.top() == command[j].second) 
                	pq.pop();
                else {
                	A[2]=false;
                    condition --;
                    break;
                } 
            }
        }

        if (condition == 0) 
        	cout << "impossible\n";
        else if (condition > 1) 
        	cout << "not sure\n";
        else {
            if (A[0] == true) 
            	cout << "stack\n";
            else if (A[1] == true) 
            	cout << "queue\n";
            else 
            	cout << "priority queue\n";
        }


	}


}
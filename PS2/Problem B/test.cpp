#include<iostream>
#include<deque>
#include<vector>
#include<queue>

using namespace std;
int main(){

    freopen("1.in","r",stdin);
    deque<int> line1;
    deque<int> line2;
    long N; cin>>N;

    for (long i = 0; i < N; ++i){
        string command;
        cin>>command;
        long num;
        cin>>num;
        if (command == "get"){
            if (num < line1.size())
                cout<<line1[num]<<endl;
            else
            	cout<<line2[num-line1.size()]<<endl;
        }
        if (line1.size() > line2.size()){
        	if (command == "push_back")
        		line2.push_back(num);
            else if (command == "push_front"){
                line1.push_front(num);
                line2.push_front(line1.back());
                line1.pop_back();
            }
            else if (command == "push_middle")
            	line2.push_front(num);
        }
        else if (line1.size() < line2.size()){
        	if (command == "push_back"){
        		line2.push_back(num);
        		line1.push_back(line2.front());
        	}
            else if (command == "push_front"){
                line1.push_front(num);
            }
            else if (command == "push_middle")
            	line1.push_back(num);        	
        }
        else if (line1.size() == line2.size()){
        	if (command == "push_back"){
              	line2.push_back(num);
              	line1.push_back(line2.front());
              	line2.pop_front();
        	}
            else if (command == "push_front")
            	line1.push_front(num);
            else if (command == "push_middle")
            	line1.push_back(num);
        }


    }

    // for (auto i:vet)
    //     cout<<i<<endl;
}
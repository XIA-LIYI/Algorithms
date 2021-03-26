// A0177873L
// XIA LIYI
// LAB(08)
// Aaryam

#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
  
void process(long N, long A[]) 
{ 
 
    priority_queue<long> left; 
    priority_queue<long,vector<long>,greater<long> > right; 
  
    long median = A[0]; 
    left.push(A[0]); 
    long sum=A[0];
 
    for (int i=1; i < N; i++){ 
        long num = A[i]; 

        if (left.size() == right.size()){ 
            if (num > median){ 
                right.push(num); 
                median = right.top(); 
            } 
            else{ 
                left.push(num); 
                median = left.top(); 
            } 
        } 
        else if (left.size() > right.size()){ 
            if (num < median){ 
                right.push(left.top()); 
                left.pop(); 
                left.push(num); 
            } 
            else
                right.push(num); 
            median = (left.top() + right.top())/2; 
        } 
        else{ 
            if (num > median) { 
                left.push(right.top()); 
                right.pop(); 
                right.push(num); 
            } 
            else
                left.push(num); 
  
            median = (left.top() + right.top())/2; 
        } 
        //cout<<med<<endl;
        sum+=median; 
    } 
    cout<<sum<<endl;

} 
  
int main() 
{ 
    
    freopen("1.in","r",stdin);
    int TC;cin>>TC;

    for (int i = 1; i <= TC; i++){
    	long N;cin>>N;
        long line[N];

    	for (long j = 1; j <= N; j++)
    		cin>>line[j-1];
    	process(N,line);
    }
    return 0; 
}



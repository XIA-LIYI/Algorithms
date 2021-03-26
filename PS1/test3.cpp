// A0177873L
// XIA LIYI
// LAB(08)
// Aaryam

#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;

long search_max(long A[],long leng){
	return *max_element(A, A+leng);
}
long search_min(long A[], long leng){

	return *min_element(A, A+leng);
}
long search_pos_max(long A[],long n,long leng){
	return max_element(A, A+leng)-A;
}

long search_pos_min(long A[],long n,long leng){
	return min_element(A, A+leng)-A;
}
int main(){

	freopen("1.in","r",stdin);
	int TC;cin>>TC;
	long sum;

	for (int i=1; i<=TC; ++i){
		long N;cin>>N;
		long middle_left,middle_right;
		long leng=0;

		long left[50001],right[50001];
		cin>>middle_left>>middle_right;
		sum=middle_left;
		if (middle_left > middle_right){
			swap(middle_left,middle_right);
		}
		sum+=(middle_left+middle_right)/2;

		for (long j=3; j<= N; ++j){

            long in; 
		    cin>>in;

		    long pos;
			if (j % 2 == 0){
				if (in < middle_left){
					long compare=search_max(left,leng);
					if (in < compare){
					 	middle_left=compare;
						pos=search_pos_max(left,compare,leng);
						left[pos]=in;
					}
					else{
						middle_left=in;
					}
				}
				else if (in > middle_right){
					long compare=search_min(right,leng);
				    if (in > compare){
					 	middle_right= compare;
						pos=search_pos_min(right,compare,leng);
						right[pos]=in;
					}
					else{
						middle_right=in;
					}					
				}
			}
		    else{
		    	if (in < middle_left){
		    		right[leng]=middle_right;
		    		middle_right=middle_left;
		    		left[leng]=in;
		    		leng+=1;	    		
		        }
		    	else if (in > middle_right){
		    		left[leng]=middle_left;
		    		middle_left=middle_right;
		    		right[leng]=in;
		    		leng+=1;
		    		}
		    	else{
		    		left[leng]=middle_left;
		    		right[leng]=middle_right;
		    		middle_left=in;middle_right=in;
		    		leng+=1;
		    	}

		    }
		    sum+=(middle_left+middle_right)/2;
		    //cout<<middle_left<<" "<<middle_right<<" "<<sum<<endl;
		}

		cout<<sum<<endl;
		
	}
	

}



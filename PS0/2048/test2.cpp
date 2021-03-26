
#include<iostream>

using namespace std;

int main(){
	freopen("1.in","r",stdin);
	int a[4][4];
	for (int i = 0; i < 4; ++i){
		for (int j = 0; j < 4; ++j){
			scanf("%d", &a[i][j]);
		}
	}

    int move;
	scanf("%d", &move);
	int b[4][4];

	for (int i = 0; i < 16; ++i){
		printf("%d ", a[i/4][i%4]);
		if (i % 4 == 3)
			printf("\n");
	}
    
    if (move == 0){

		for (int i = 0; i < 4; ++i){
			int j=0, left=0,k;
			while (j < 4){
				if (a[i][k] == 0){
					k++;
				}
				else if (j == 3){
					b[i][j]=a[i][k];
					j++;

				}
				else if (a[i][k] == left){
					b[i][j]=2*left;
					left=0;
					j++;
					k++;
				}
				else if (a[i][k] == a[i][k+1]) {
					b[i][j]=2*a[i][k];
					k=k+2;
					j++;
				}
				else if ((a[i][k] != a[i][k+1]) && (a[i][k+1] != 0)){
					b[i][j]=a[i][k];
					k++;
					j++;
				}
				else if ((a[i][k]!= a[i][k+1]) && (a[i][k+1] == 0)){
					left=a[i][k];
					k++;
				}
			}

			for (int l=j; j < 4; ++j){
				b[i][l]=0;
			}
		}
	}
	for (int i = 0; i < 16; ++i){
		printf("%d ", b[i/4][i%4]);
		if (i % 4 == 3)
			printf("\n");
	}

}

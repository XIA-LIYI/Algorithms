#include <cstdio>
#include<math.h>
#include<stdio.h>
#include<iostream>

using namespace std;

int main(){
	
	freopen("6.in","r",stdin);
	int a[4][4];

	for (int i = 0; i < 4; ++i)
		for (int j = 0; j < 4; ++j)
			scanf("%d", &a[i][j]);
    
    int move;
	scanf("%d",&move);

	int k;
	int b[4][4];

	if (move == 0){

		for (int i=0; i < 4; ++i){
            int c[4];
            k=0;
            for (int j=0; j < 4; ++j){
            	if (a[i][j] != 0){
            		c[k]=a[i][j];
            		k++;
            	}
            }
            for (int j=k; j<4; ++j){
            	c[j]=0;
            }
		
			int m=0,n=0;

			while (m < 4){
				if (c[m] == 0){
					b[i][n]=0;
					m++;
					n++;
				}

				else if (m == 3){
					b[i][n]=c[m];
					m++;
					n++;
				}

				else if (c[m] == c[m+1]){
					b[i][n]=c[m]*2;
					m=m+2;
					n++;					
				}
				else if (c[m] != c[m+1]){
					b[i][n]=c[m];
					m++;
					n++;
				}

			}
			for (int l=n; l<4;++l){
				b[i][l]=0;
			}
		}
	}


	if (move == 1){

		for (int i=0; i < 4; ++i){
            int c[4];
            k=0;
            for (int j=0; j < 4; ++j){
            	if (a[j][i] != 0){
            		c[k]=a[j][i];
            		k++;
            	}
            }
            for (int j=k; j<4; ++j){
            	c[j]=0;
            }
		
			int m=0,n=0;

			while (m < 4){
				if (c[m] == 0){
					b[n][i]=0;
					m++;
					n++;
				}
				else if (m == 3){
					b[n][i]=c[m];
					m++;
					n++;
				}
				else if (c[m] == c[m+1]){
					b[n][i]=c[m]*2;
					m=m+2;
					n++;					
				}
				else if (c[m] != c[m+1]){
					b[n][i]=c[m];
					m++;
					n++;
				}

			}
			for (int l=n; l<4;++l){
				b[l][i]=0;
			}
		}
	}

	if (move == 2){

		for (int i=0; i < 4; ++i){
            int c[4];
            k=3;
            for (int j=3; j > -1; --j){
            	if (a[i][j] != 0){
            		c[k]=a[i][j];
            		k--;
            	}
            }
            for (int j=k; j>-1; --j){
            	c[j]=0;
            }
		
			int m=3,n=3;

			while (m > -1){
				if (c[m] == 0){
					b[i][n]=0;
					m--;
					n--;
				}
				else if (m == 0){
					b[i][n]=c[m];
					m--;
					n--;
				}
				else if (c[m] == c[m-1]){
					b[i][n]=c[m]*2;
					m=m-2;
					n--;					
				}
				else if (c[m] != c[m-1]){
					b[i][n]=c[m];
					m--;
					n--;
				}

			}
			for (int l=n; l>-1;--l){
				b[i][l]=0;
			}
		}
	}

	if (move == 3){

		for (int i=0; i < 4; ++i){
            int c[4];
            k=3;
            for (int j=3; j > -1; --j){
            	if (a[j][i] != 0){
            		c[k]=a[j][i];
            		k--;
            	}
            }
            for (int j=k; j>-1; --j){
            	c[j]=0;
            }
		
			int m=3,n=3;

			while (m > -1){
				if (c[m] == 0){
					b[n][i]=0;
					m--;
					n--;
				}
				else if (m == 0){
					b[n][i]=c[m];
					m--;
					n--;
				}
				else if (c[m] == c[m-1]){
					b[n][i]=c[m]*2;
					m=m-2;
					n--;					
				}
				else if (c[m] != c[m-1]){
					b[n][i]=c[m];
					m--;
					n--;
				}

			}
			for (int l=n; l>-1;--l){
				b[l][i]=0;
			}
		}
	}


	for (int i=0; i<16; ++i){
		printf("%d ",b[i/4][i%4]);
		if (i % 4 == 3 and i != 1){
			printf("\n");
		}
	}

	return 0;

}




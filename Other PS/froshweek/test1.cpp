#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

long long result = 0;

void merge(int a[], int low, int mid, int high) {
 
    int N = high-low+1;
    int b[N];
    int left = low, right = mid+1, bIdx = 0;

    while (left <= mid && right <= high)
        if (a[left] <= a[right])
            b[bIdx++]=a[left++];
        else{
            b[bIdx++]=a[right++];
            result+=mid-left+1;
        }
    while (left <= mid)
        b[bIdx++] = a[left++];
    while (right <= high)
        b[bIdx++] = a[right++];
    for (int k = 0; k < N; k++)
        a[low+k] = b[k];
}

void MergeSort(int a[], int low, int high) {
    if (low < high) {
        int mid = (low+high) / 2;
        MergeSort(a, low , mid ); 
        MergeSort(a, mid+1, high); 
        merge(a, low, mid, high);
    } 
}

int main(){


    freopen("E.0.in", "r", stdin);
    int n; cin >> n;
    int a[n];

    for (int i = 0; i < n; i++){
        int temp; cin >> a[i];
    }

    MergeSort(a, 0, n-1);

    // for (int i = 0; i < n; i++){
    //     cout<<a[i]<<" ";
    // }    
    cout<<result;

}
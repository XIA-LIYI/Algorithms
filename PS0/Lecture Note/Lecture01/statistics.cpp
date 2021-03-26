// there is one character bug in this code, submitting it verbatim will give you Wrong Answer

#include <bits/stdc++.h>
using namespace std;

int main() {
  int i, n, x, ma, mi, caseNo = 1;
  // let T be the number of test cases
  // the whole program is O(T * n) = O(Tn)
  while (scanf("%d", &n) != EOF) {
    // O(1+1+n+1 = n+3) ~=> O(n)
    ma = -1e9; // O(1)
    mi = 1e9; // O(1)
    for (i = 0; i < n; i++) { // O(n * (1+1+1) = n * 3 = 3n) ~> O(n)
      scanf("%d", &x); // O(1)
      if (x > ma) ma = x; // O(1)
      // ma = max(ma, x);
      mi = min(mi, x); // O(1)
    }
    printf("Case %d: %d %d %d\n", caseNo++, mi, ma, ma+mi); // O(1)
  }
  return 0;
}



/*
// various other permutations of valid answers

#include <bits/stdc++.h>
using namespace std;

int main() {
  int i, n, value, maxv, minv, A[35], caseNo = 1;
  while (scanf("%d", &n) != EOF) {
    // computation on the fly version
    // maxv = -1e9;
    // minv = 1e9;
    // for (i = 0; i < n; i++) {
    //   scanf("%d", &value);
    //   maxv = max(maxv, value);
    //   minv = min(minv, value);
    // }
    // -------------------------------------------------
    // array version: read in the array A, of n elements
    for (i = 0; i < n; i++) scanf("%d", &A[i]); // O(n)
    // maxv = A[0];
    // for (i = 1; i < n; i++)
    //   if (A[i] > maxv)
    //     maxv = A[i];
    maxv = *max_element(A, A+n); // O(n)
    // minv = A[0];
    // for (i = 1; i < n; i++)
    //   if (A[i] < minv)
    //     minv = A[i];
    minv = *min_element(A, A+n); // O(n)
    // we can also use minmax_element function
    printf("Case %d: %d %d %d\n", caseNo++, minv, maxv, maxv-minv); // total = O(3n+1) ~> O(n)
  }
  return 0;
}
*/

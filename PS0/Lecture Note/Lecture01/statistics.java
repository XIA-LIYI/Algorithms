// there is one character bug in this code, submitting it verbatim will give you Wrong Answer

import java.io.*;

class statistics {
  public static void main(String[] args) throws Exception {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    PrintWriter pw = new PrintWriter(System.out);
    int caseNo = 1;
    while (true) {
      String line = br.readLine();
      if (line == null) break;
      String[] token = line.split(" "); // tokenize the line based on paces
      int n = Integer.parseInt(token[0]); // the first token is n

      int[] X = new int[n];
      for (int i = 0; i < n; i++) // read the other n integers of this line into an array
        X[i] = Integer.parseInt(token[i+1]);

      int minval = 1000000;
      for (int i = 0; i < n; i++)
        if (X[i] < minval)
          minval = X[i];

      int maxval = -1000000;
      for (int value : X)
        if (value > maxval)
          maxval = value;

      // for (int i = 1; i <= n; i++) { // read n integers
      //   int x = sc.nextInt();
      //   // keep the running min
      //   // if (x < minval) minval = x;
      //   minval = Math.min(minval, x);
      //   // keep the running max
      //   if (x > maxval) maxval = x;
      // }

      pw.printf("Case %d: %d %d %d\n", caseNo, minval, maxval, maxval+minval);
      caseNo = caseNo++;
    }
    pw.close();
  }
}

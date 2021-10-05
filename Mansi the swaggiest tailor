/* Mansi is a tailor by calling. She is well known for making square-molded delightfully cut and
sewed pocket squares for suits and sherwanis.
The clients request huge measured pocket squares. Thus, presently Mansi is resolved to
get the greatest size out of the extraordinary material she purchases from her mysterious
vendor. She has a rectangular piece of silk and cotton blend fabric of length 'L' and Breadth
'B'.
Her mission is to separate it into 'N' square-formed material pieces every one of side length
'S'. So she can make pocket squares out of them of the greatest size.

Input:
The first line of the input contains T- the number of test cases. T lines follow. Each line of
the test case contains L followed by B.

Output:
S -the maximum length of each square-shaped handkerchief.

Sample Input:
1
40 30

Sample Output:
10*/


/* CODE */

#include<bits/stdc++.h>
using namespace std;
int GCD(int L, int B){
  if (B == 0)
  return L; 
  return gcd(B, L % B);
}
int main() {
  /* as mentioned in the question T is the number of TEst cases, first input taken
  required from the user */
  int T;
  cin>>T;
  while(T--) {
    /* ’L’, ‘B’ are the Length and Breadth of the rectangular cloth that mansi is
    working on */
    int L,B;
    cin>>L>>B;
    cout<<gcd(L,B)<<"\n";
    }
}

/*

Chef is really interested in the XOR operation. He wants to take a
sequence A0,A1,...,AN−1 and for each i from 0 to K−1 inclusive (in
this order, one by one), perform the following operation:
Let's denote a=Ai%N and b=A N−(i%N)−1 before this operation.
Change Ai%N to a⊕b, i.e. a XOR b
Since Chef is busy, he asked you to find the final sequence he
should get after performing these operations.
Input
- The first line of the input contains a single integer T denoting
the number of test cases. The description of T test cases follows.
- The first line of each test case contains two space-separated
integers N and K
- The second line contains N space-separated integers A0,A1,...,AN−1
Output
For each test case, print a single line containing N space-separated
integers ― the elements of the final sequence.
Example Input 1
22
12
Example Output 31
 
 */

#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n;
        long long int k;
        scanf("%d %lld", &n, &k);
        int arr[3*n], arr1[n];
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &arr[i]);
            arr1[i] = arr[i];
        }
       
        int z = k % (n * 3);

        for (int i = 0; i < z; i++)
        {
            int a = arr[i % n];
            int b = arr[n - (i % n) - 1];
            arr[i % n] = a ^ b;
        }
        
        if(n%2 != 0 && k >=(n+1)/2)
        {
            arr[(n-1)/2] = 0;
        }

        for (int i = 0; i < n; i++)
        {
            printf("%d ", arr[i]);
        }
        printf("\n");
    }
    return 0;
}

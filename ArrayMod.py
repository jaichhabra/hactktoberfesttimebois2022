"""
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
"""

def main():
    for _ in range(int(input())):
        (n, k) = map(int, input().split())
        arr = list(map(int, input().split()))
        arr1 = arr[::]
        if (k//n) % 3 == 1:
            for i in range(n//2):
                arr[n-i-1], arr[i]=arr[i], arr[i] ^ arr[n-i-1]
            if n%2 !=0:
                arr[n//2] = 0
        elif (k//n) % 3 == 2:
            for i in range(n//2):
                arr[i], arr[n-i-1] = arr[n-i-1], arr[i] ^ arr[n-i-1]
            if n%2 !=0:
                arr[n//2] = 0
        else:
            if n%2 !=0 and k > n//2:
                arr[n//2] = 0

        for i in range(k%n):
            arr[i] = arr[i] ^ arr[n-i-1]
        print(' '.join(map(str, arr)))
'''
        for i in range(k):
            arr1[(i%n)] = arr1[i%n] ^ arr1[(n-(i%n)-1)]
        print(' '.join(map(str, arr1)))
'''

if __name__ == '__main__':
    main()

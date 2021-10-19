"""
Chef wants to buy a new phone, but he is not willing to spend a lot
of money. Instead, he checks the price of his chosen model everyday
and waits for the price to drop to an acceptable value. So far, he
has observed the price for N
 days (numbers 1 through N); for each valid i, the price on the i-th
day was Pi dollars.
On each day, Chef considers the price of the phone to be good if it
is strictly smaller than all the prices he has observed during the
previous five days. If there is no record of the price on some of
the previous five days (because Chef has not started checking the
price on that day yet), then Chef simply ignores that previous day ―
we could say that he considers the price on that day to be infinite.
Now, Chef is wondering ― on how many days has he considered the
price to be good? Find the number of these days.
Input
- The first line of the input contains a single integer T denoting
the number of test cases. The description of T test cases follows.
- The first line of each test case contains a single integer N
- The second line contains N space-separated integers P1,P2,...,PN
Output
- For each test case, print a single line containing one integer ―
the number of days with a good price.
Example Input
1
7
375 750 723 662 647 656 619
Example Output
2
 """

def main():
    for _ in range(int(input())):
        n = int(input())
        arr = list(map(int, input().split()))
        ans = 0
        for i in range(n):
            count = 0
            if i < 5:
                for j in range(i):
                    if arr[i] < arr[j]:
                        count += 1
                    else:
                        break
                if count == i:
                    ans += 1

            else:
                for j in range(i - 5, i):
                    if arr[i] < arr[j]:
                        count += 1
                    else:
                        break
                if count == 5:
                    ans += 1
        print(ans)


if __name__ == '__main__':
    main()

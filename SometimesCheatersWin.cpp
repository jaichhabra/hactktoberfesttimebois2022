// Icarus is about to take part in a marathon. However, since he is extremely lazy, he is willing to cheat to reduce his work. The marathon has N hidden paths that Icarus knows about. These hidden paths will decrease OR increase X amount of distance from his run. He can only take consecutive paths and once he is back on the normal course, he will get caught if he tries to take the hidden paths again. Find the Maximum distance Icarus can remove from his run without being caught. If the paths just increase the distance Icarus has to run, then print 0.
// CONSTRAINTS:
// 1<=N<=100
// -100<=X<=100
// INPUT
// First Line contains m and n which denote the number of paths.
// Second Line contains n integers denoting the distance they increase or decrease. Negative numbers are shortcuts(decrease distance) , positive numbers are longcuts(increase distance).
// OUTPUT
// Output contains a positive integer denoting the max distance Icarus can remove from his run.
// EXAMPLES:
// Sample Input 1:
// 7
// 42 -5 -6 3 7 -11 1
// Sample Output 1:
// 12

// Sample Input 2:
// 5
// 1 1 1 1 1
// Sample Output 2:
// 0

// Sample Input 3:
// 10
// 7 -11 -31 -42 100 -100 100 20 20 41
// Sample Output 3:
// 100

// Solution
#include<iostream>
#include<vector>

using namespace std;

int main() {
    //NUMBER OF SHORTCUTS
    int n;
    cin>>n;
    //HOW MUCH DISTANCE EACH PATH INCREASES OR DECREASES
    vector<int> a(n);
    for(int i=0;i<n;i++) {
        cin>>a[i];
    }
    //INPUT DONE
    //LOGIC
    int maxcheat=1;
    int temp = 0;
    for(int i=0;i<n;i++) {
        temp+=a[i];
        if(maxcheat > temp) maxcheat = temp;
        if(temp > 0) temp = 0;
    }
    if(maxcheat == 1) cout<<0;
    else cout<<0-maxcheat;
    return 0;
}

// QUESTION 1: ICARUS’S ESCAPE
// Icarus is about to enter a labyrinth. It is a M x N matrix. Each cell denotes a room. Each room has an enemy with strength Pi. Icarus starts with a strength of X. He can steal the strength of a person if he enters the room they are in, however he can only enter a room ONCE, and ONLY if Icarus has more strength than the person in it. Icarus has to make it from the top left of the maze to the bottom right accumulating as much strength as possible. If it is not possible to reach the end, print -1.
// CONSTRAINTS:
// 2<=m,n<=10
// 1<=Pi , X<=100
// Arr[0][0] = Arr[m-1][n-1] = 0
// INPUT
// First Line contains m and n which denote the rows and columns of the maze
// Second Line contains the strength of enemies
// Third Line contains Icarus’s strength
// OUTPUT
// Output contains 1 line containing an integer.

// EXAMPLES:
// Sample Input 1:
// 3 3
// 0 3 2 6 7 14 3 8 0
// 5
// Sample Output 1:
// 32

// Sample Input 2:
// 3 3
// 0 10 2 10 3 1 1 9 0
// 5
// Sample Output 2:
// -1

// Sample Input 3:
// 3 3
// 0 1 1 1 1 1 1 1 0
// 2
// Sample Output 3:
// 9


// Solution

#include<iostream>
#include<vector>

using namespace std;

void maxStrength(vector<vector<int>> A, int i, int j, int m,int n,int &maxSum,int curSum) {
    if(i==m-1 && j==n-1) {
        if(curSum > maxSum) maxSum = curSum;
        return;
    } 
    //NOT TO ACCESS UNACCESSIBLE MEMORY
    if(i<0 || j<0 || i>=m || j>=n) return;
    //CHECK IF ALREADY VISITED THE ROOM OR TOO HIGH ENEMY THERE
    if(A[i][j] == -1 || A[i][j] >= curSum) return;
    //GO THROUGH ALL DIRECTIONS 
    curSum += A[i][j];
    A[i][j]=-1;
    //GO UP
    maxStrength(A,i-1,j,m,n,maxSum,curSum);
    //GO DOWN
    maxStrength(A,i+1,j,m,n,maxSum,curSum);
    //GO RIGHT
    maxStrength(A,i,j+1,m,n,maxSum,curSum);
    //GO LEFT
    maxStrength(A,i,j-1,m,n,maxSum,curSum);
}

int main() {
    int m,n;
    //ARRAY SIZE
    cin>>m>>n; 
    vector<vector<int>> A(m,vector<int>(n));
    for(int i=0;i<m;i++) {
        for(int j=0;j<n;j++) {
            //ARRAY INPUTS
            cin>>A[i][j]; 
        }
    }
    //YOUR STRENGTH
    int X; 
    cin>>X;
    int Xcopy = X;
    //INPUTS DONE
    //LOGIC
    maxStrength(A,0,0,m,n,X,X);
    if(X == Xcopy) cout<<-1;
    else cout<<X;
    return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int fib_recursion(int n)
{
    if(n<=1)return n;
    return fib_recursion(n-1) + fib_recursion(n-2);
}

int fib_dp(int n,int* f)
{
    f[0] = 0;
    f[1] = 1;
    //f[2] = f[1] + f[0] = 1+0 = 1
    //f[3] = f[2] + f[1] = 1+1 = 2
    for(int i=2;i<=n;i++)
    {
        f[i] = f[i-1] + f[i-2];
    }
}

//weights[] ={20,30,40}
//values[] = {100,200,50}
//n = 3
//maxCapacity = 50
int Knapsack_recursion(int* weights, int* values, int maxCapacity, int n)
{
    //base case
    if(n==0 || maxCapacity==0)return 0;
    //recursive case
    if(weights[n-1] > maxCapacity)return Knapsack_recursion(weights,values,maxCapacity, n-1);
    else
    {
        return max(
                Knapsack_recursion(weights,values,maxCapacity, n-1) ,
                values[n-1] +
                Knapsack_recursion(weights,values,maxCapacity - weights[n-1], n-1) );
    }
}

int Knapsack_dp(int* weights, int* values, int maxCapacity, int n)
{
    int dp[n+1][maxCapacity+1];
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=maxCapacity;j++)
        {
            if(i==0||j==0)dp[i][j] = 0;
            else if(j < weights[i-1])dp[i][j] = dp[i-1][j];
            else
            {
                dp[i][j] = max( values[i-1] + dp[i-1][j-weights[i-1]],
                                 dp[i-1][j] );
            }
        }
    }

    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=maxCapacity;j++)
        {
            cout<<dp[i][j]<<"\t";
        }
        cout<<"\n";
    }

    return dp[n][maxCapacity];
    //Code for finding the items
}

int main()
{
    int* weights = new int[5];
    int* values = new int[5];
    int maxCapacity = 10;
    weights[0] = 1;
    weights[1] = 2;
    weights[2] = 3;
    weights[3] = 4;
    weights[4] = 6;
    values[0] = 2;
    values[1] = 1;
    values[2] = 7;
    values[3] = 6;
    values[4] = 12;

    //cout<<Knapsack_dp(weights,values,maxCapacity,5);
    cout<<Knapsack_recursion(weights,values,maxCapacity,5);
}

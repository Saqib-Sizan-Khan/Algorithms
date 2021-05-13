#include<iostream>
#include<algorithm>

using namespace std;

int pp(int i,int j,int num[],char op[])
{
    if(i==j) return num[i];

    else
    {
        int m = -999;

        for(int k=i; k<j; k++)
        {
            int val;

            if(op[k] == '+')
            {
                val = pp(i,k,num,op) + pp(k+1,j,num,op);
            }
            else if(op[k] == '-')
            {
                val = pp(i,k,num,op) - pp(k+1,j,num,op);
            }
            else
            {
                val = pp(i,k,num,op) * pp(k+1,j,num,op);
            }

            if(val > m) m = val;
        }
        return m;
    }
}

int pp_dp(int num[],char op[],int n)
{
    int dp[n][n];
    int result = -1;

    //Base case initialization
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            dp[i][j] = -1;

            if(i==j) dp[i][j] = num[i];
        }
    }

    //setting other values in DP array
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(i!=j)
            {
                int val,m = -99999;

                if(i < j)
                {
                    for(int k=i; k<j; k++)
                    {
                        if(op[k] == '+')
                        {
                            val = dp[i][k] + dp[k+1][j];
                        }
                        else if(op[k] == '-')
                        {
                            val = dp[i][k] - dp[k+1][j];
                        }
                        else
                        {
                            val = dp[i][k] * dp[k+1][j];
                        }

                        if(val > m) m = val;
                    }

                    dp[i][j] = m;
                }

                else if(i > j)
                {
                    for(int k=j; k<i; k++)
                    {
                        if(op[k] == '+')
                        {
                            val = dp[j][k] + dp[k+1][i];
                        }
                        else if(op[k] == '-')
                        {
                            val = dp[j][k] - dp[k+1][i];
                        }
                        else
                        {
                            val = dp[j][k] * dp[k+1][i];
                        }

                        if(val > m) m = val;
                    }

                    dp[i][j] = m;
                }
            }
        }
    }

    //find the maximum from DP array
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            cout<<dp[i][j]<<"\t";

            if(dp[i][j] > result)
            {
                result = dp[i][j];
            }
        }
        cout<<"\n";
    }

    return result;
}

int main()
{
    int n;

    cin>>n;

    int num[n];

    for(int i=0; i<n; i++)
    {
        cin>>num[i];
    }

    char op[n-1];

    for(int i=0; i<n-1; i++)
    {
        cin>>op[i];
    }

    //int result = pp(0,n-1,num,op);

    int result = pp_dp(num,op,n);

    cout<<result<<endl;

    return 0;
}


#include<iostream>
#include<algorithm>

using namespace std;

int common_sequence(string s1,string s2,int l1,int l2)
{
    if(l1 == 0 || l2 == 0)return 0;


    if(s1[l1-1] == s2[l2-1])
    {
        return 1 + common_sequence(s1,s2,l1-1,l2-1);
    }

    else
    {
        return max(common_sequence(s1,s2,l1,l2-1),common_sequence(s1,s2,l1-1,l2));
    }
}

int DP_common_sequence(string s1,string s2,int m,int n)
{
    int r[m+1][n+1];

    for(int i=0; i<=m; i++)
    {
        for(int j=0; j<=n; j++)
        {
            if(i == 0 || j == 0)
            {
                r[i][j] = 0;
            }

            else if(s1[i-1] == s2[j-1])
            {
                r[i][j] = r[i-1][j-1] + 1;
            }

            else
            {
                r[i][j] = max(r[i-1][j],r[i][j-1]);
            }
        }
    }

    return r[m][n];
}

int main()
{
    string s1,s2;
    int l1,l2;

    cin>>s1;
    cin>>s2;

    l1 = s1.size();
    l2 = s2.size();

    //int result = common_sequence(s1,s2,l1,l2);

    int result = DP_common_sequence(s1,s2,l1,l2);

    cout<<result<<endl;
}


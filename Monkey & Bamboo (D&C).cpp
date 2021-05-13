#include<iostream>
#include<algorithm>

using namespace std;

bool find_min_energy(int d[],int r,int k)
{
    for(int i=0; i<r; i++)
    {
        if(d[i]==k)
        {
            k--;
        }

        else if(d[i] > k)
        {
            return false;
        }
    }

    return true;
}

int Searching(int low,int high,int d[],int rung)
{
    if(low == high)
    {
        return high;
    }

    int mid = (low+high)/2;
    int k = mid;

    if(find_min_energy(d,rung,k))
    {
        Searching(low,mid,d,rung);
    }

    else
    {
        Searching(mid+1,high,d,rung);
    }
}

int main()
{
    int rung,h,temp=0,small;

    cin>>rung;

    int d[rung];

    for(int i=0; i<rung; i++)
    {
        cin>>h;
        d[i] = h-temp;
        temp = h;

        if(i==0)
        {
            small = d[i];
        }

        if(small > d[i] && i!=0)
        {
            small = d[i];
        }
    }

    int low = small,high = h;

    int result = Searching(low,high,d,rung);

    cout<<result<<endl;

    return 0;
}

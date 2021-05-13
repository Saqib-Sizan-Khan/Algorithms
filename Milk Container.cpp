#include<iostream>
#include<algorithm>

using namespace std;

bool lowest_maximum(int b[],int v,int c,int k)
{
    int total = 0;

    for(int i=0; i<c; i++)
    {
        total += b[i];

        if(total > k)
        {
            total = 0;
            v--;
            i--;
        }

        if(v == 0)
        {
            return false;
        }
    }

    return true;
}

int Searching(int low,int high,int b[],int v,int c)
{
    if(low == high)
    {
        return low;
    }

    int mid = (low + high)/2;
    int k = mid;

    if(lowest_maximum(b,v,c,k))
    {
        Searching(low,mid,b,v,c);
    }

    else
    {
        Searching(mid+1,high,b,v,c);
    }
}

int main()
{
    int v,c,tq=0;

    cin>>c>>v;

    int b[c],small;

    for(int i=0; i<c; i++)
    {
        cin>>b[i];
        tq += b[i];

        if(i==0)
        {
            small = b[i];
        }

        if(small > b[i] && i!=0)
        {
            small = b[i];
        }
    }

    int low = small,high = tq;

    int result = Searching(low,high,b,v,c);

    cout<<result<<endl;

    return 0;
}

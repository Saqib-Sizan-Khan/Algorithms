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

int Searching_1(int arr[],int low,int high,int b[],int v,int c)
{
    if(low == high)
    {
        return arr[high];
    }

    int mid = (low+high)/2;
    int k = arr[mid];

    if(lowest_maximum(b,v,c,k))
    {
        Searching_1(arr,low,mid,b,v,c);
    }

    else
    {
        Searching_1(arr,mid+1,high,b,v,c);
    }
}

int Searching_2(int arr[],int low,int high,int d[],int rung)
{
    if(low == high)
    {
        return arr[high];
    }

    int mid = (low+high)/2;
    int k = arr[mid];

    if(find_min_energy(d,rung,k))
    {
        Searching_2(arr,low,mid,d,rung);
    }

    else
    {
        Searching_2(arr,mid+1,high,d,rung);
    }
}

void Milk_Problem()
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

    int arr[tq];

    for(int i=0; i<tq; i++)
    {
        arr[i] = i+1;
    }

    int low = small,high = tq;

    int result = Searching_1(arr,low,high,b,v,c);

    cout<<result<<endl;
}

void Monkey_Problem()
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

    int arr[h];

    for(int i=0; i<h; i++)
    {
        arr[i] = i+1;
    }

    int low = small,high = h;

    int result = Searching_2(arr,low,high,d,rung);

    cout<<result<<endl;
}

int main()
{
    int fun;

    cout<<"1.Milk Problem"<<endl;
    cout<<"2.Monkey_Problem"<<endl;

    cin>>fun;

    if(fun == 1)
    {
        Milk_Problem();
    }

    else if(fun == 2)
    {
        Monkey_Problem();
    }

    return 0;
}

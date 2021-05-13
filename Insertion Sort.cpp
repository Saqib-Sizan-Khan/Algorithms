
#include<iostream>
#include<algorithm>

using namespace std;

struct Item
{
    int v;
    int w;
    int Model;
};

int main()
{
    Item a[3];
    int n=3;

    for(int i=0;i<n;i++)
    {
        cin>>a[i].Model;
    }


    for(int i=0;i<n;i++)
    {
        cout<<a[i].Model<<" "<<i;
    }


}


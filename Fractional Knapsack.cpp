#include<iostream>
#include<algorithm>

using namespace std;

struct Item
{
    int weight;
    int value;
    double vw;
    int model_No;
};

bool Compare_Weight_Unit(Item a,Item b)
{
    if(a.vw != b.vw)
        return a.vw > b.vw;
}

int main()
{
    printf("Number of items: ");
    int n;
    cin>>n;
    cout<<"\n";

    Item item[n];

    for(int i=0; i<n; i++) //taking item inputs
    {
        Item a;

        printf("Weight of item %d: ",i+1);
        cin>>a.weight;

        while(a.weight == 0)
        {
            printf("Weight should be > 0: ",i+1);
            cin>>a.weight;
        }

        printf("Value of item %d: ",i+1);
        cin>>a.value;

        cout<<"\n";

        a.model_No = i+1;

        a.vw = a.value / a.weight;

        item[i] = a;
    }

    sort(item,item+n,Compare_Weight_Unit);  //sort the Item object

    printf("Maximum, capacity: ");
    int Capacity,Profit=0;
    cin>>Capacity;

    cout<<"\n";

    for(int i=0; i<n; i++)  // finding maximum profit
    {
        if(Capacity == 0) break;

        Item a = item[i];

        if(Capacity >= a.weight)
        {
            printf("Item %d %d kg\n",a.model_No,a.weight);
            Capacity -= a.weight;
            Profit += a.value;
        }

        else
        {
            int temp = Capacity * a.vw;
            printf("Item %d %d kg\n",a.model_No,Capacity);
            Capacity = 0;
            Profit += temp;
        }
    }

    printf("\nTotal Profit: %d\n",Profit);

    return 0;
}

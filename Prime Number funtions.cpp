#include<chrono>
#include<iostream>
#include<iomanip>
#include<math.h>
#include<string.h>

using namespace std;

bool is_prime(int num)
{
    if(num==1)
        return false;

    for(int i=2; i <= sqrt(num); i++)
    {
        if(num%i == 0)
        {
            return false;
        }
    }

    return true;
}

void print_primes(int n)
{
    for(int i=3; i<=n; i++)
    {
        if(is_prime(i) == true)
        {
            cout<<i<<" ";
        }
    }
    cout<<endl;
}

void Sieve_of_Eratosthenes(int n)
{
    bool p[n+1];

    memset(p,true,sizeof(p));

    for(int i=2; i<=sqrt(n); i++)
    {
        if(p[i] == true)
        {
            for(int j=i*i; j<=n; j += i)
            {
                p[j] = false;
            }
        }
    }

    for(int i=2; i<=n; i++)
    {
        if(p[i] == true)
        {
            cout<<i<<" ";
        }
    }

    cout<<endl;
}

int main()
{
    auto start = chrono::high_resolution_clock::now();

    //print_primes(1000);
    Sieve_of_Eratosthenes(1000);

    auto stop = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);

    cout<<setprecision(10)<<duration.count();
}


#include<bits/stdc++.h>
using namespace std;

const int MAX = 1000000;
bool prime[MAX+1];

void seive()
{
    for(int i=1;i<MAX;i++)prime[i]=true;

    for(int i=2;i<=sqrt(MAX);i++){

        for(int j=2;j*i<=MAX;j++){

            if(prime[i]==true)prime[i*j]=false;
        }
    }

    prime[0]=false;
    prime[1]=false;

}

int main(void)
{
    seive();

    int a;
    int counter = 0;

    while(cin >> a){

        counter = 0;

        for(int i=2;i<=a;i++){

            if(prime[i]==true)counter++;
        }
        cout << counter << endl;
    }

    return 0;
}

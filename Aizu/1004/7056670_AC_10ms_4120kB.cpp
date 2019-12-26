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

    int ar[10010];

    for(int i=0;i<10010;i++)ar[i]=i;

    while(cin >> a){

        int counter = 0;

        for(int i=1;i<=a;i++){

            if(prime[ar[i]]==true&&prime[ar[a-i+1]]==true)counter++;
        }

        cout << counter << endl;
    }

    return 0;
}

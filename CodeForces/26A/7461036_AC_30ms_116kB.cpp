// In the name of Allah the Most Merciful .

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

map<int,int>isDris;

bool isPrime[5000+10];
vector<int>prime;

void seive()
{
    for(int i=0;i<=5000;i++)isPrime[i] = true;
    isPrime[0]=true;
    isPrime[1]=true;

    for(int i=2;i<=3200;i++){

        for(int j=2;j*i<=3200;j++){

            if(isPrime[i]==true)isPrime[i*j]=false;
        }
        if(isPrime[i]==true){prime.push_back(i);}
    }

}

void preCal()
{
    seive();
    int si = prime.size();
    //cout << si << endl;

    for(int i=6;i<=3500;i++){

        int temp = i;
        int counter = 0;
        for(int j=0;j<si;j++){

           if(temp%prime[j]==0){counter++; while(temp%prime[j]==0){temp/=prime[j];}}
        }

        if(counter==2)isDris[i]=1;
    }
}


int main(void)
{
    preCal();

    int a;
    cin >> a;

    int counter = 0;

    for(int i=2;i<=a;i++)if(isDris[i]==1)counter++;

    cout << counter << endl;

    return 0;
}

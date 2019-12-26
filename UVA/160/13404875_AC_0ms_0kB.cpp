// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

bool is_prime(int x)
{
    if(x==2)return true;
    if(x<2)return false;
    if(x%2==0)return false;

    for(int i=3;i*i<=x;i+=2){

        if(x%i==0)return false;
    }

    return true;
}

int main(void)
{
    int n;
    while(scanf("%d",&n)==1){

        if(n==0)break;
        vector<int>v;

        for(int i=2;i<=100;i++){

            if(is_prime(i)==false)continue;
            int counter = 0;
            int temp = i;

            while(temp<=n){

                counter+=(n/temp);
                temp*=i;
            }

            if(counter>0)v.push_back(counter);
        }

        printf("%3d! =",n);

        for(int i=0;i<v.size();i++){

            if(i==15)printf("\n      ");
            printf("%3d",v[i]);
        }

        printf("\n");
    }
    return 0;
}

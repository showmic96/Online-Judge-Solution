#include<iostream>
#include<stdio.h>
#include<queue>
using namespace std;

typedef long long ll;

int main(void)
{
    ll a , temp;
    while(scanf("%lld",&a)!=EOF){
        if(!a)break;

        queue<ll>current;

        current.push(1);

        while(1){

            temp = current.front();
            current.pop();

            if(temp%a==0){

                
                break;
            }

            current.push(10*temp);
            current.push(10*temp+1);
        }

       printf("%lld\n",temp);

    }

    return 0;
}

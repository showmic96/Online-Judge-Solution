#include<bits/stdc++.h>
using namespace std;
#define MAX 1000000
bool prime[MAX+1];
void seive()
{
    prime[0]=false; prime[1]=false;
    for(int a=2;a<=MAX;a++)prime[a]=true;
    for(int a=2;a<=sqrt(MAX);a++){
        for(int b=2;a*b<=MAX;b++)
        {
            if(prime[a]==true)prime[a*b]=false;
        }
    }
}



int main(void)
{
    seive();
    long long a;
    while(cin >> a){
        if(!a)break;
        int j=0,k=0;
        long long l=a;

        for(long long b=2;b<=a/2;b++){
            if(a%b==0&&prime[b]==true){a=a/b;if(b!=k){j++;k=b;}b--;}
        }
        //cout << "yes";
        cout << l <<" : " <<  j+1 << endl;
    }
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
#define si 18409900
bool ar[si+1];
int prime[100000];
void seive()
{
    for(long long a=2;a<=si;a++)ar[a]=true;
    ar[0]=false;ar[1]=false;long long d=0;
    for(long long a=2;a<=sqrt(si);a++){
        for(long long b=2;b*a<=si;b++){
            if(ar[a]==true)ar[a*b]=false;
        }

    }
    for(long long a=2;a<si;a++)if(ar[a]==true&&ar[a+2]==true){prime[d]=a;d++;}
   // cout << d << endl;

}
int main(void)
{
    long long a;
    seive();
    while(cin >> a){
        cout << "(" << prime[a-1] <<", " << prime[a-1]+2 << ")" << endl;
    }
    return 0;
}

// In the name of Allah the most Merciful

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;


int main(void)
{
    ll n , m , sum,in1 , in2;
    cin >> n >> m;
    ll ar[n];
    cin >> ar[0];
    for(int i=1;i<n;i++){cin >> ar[i];ar[i]=ar[i]+ar[i-1];}
    while(m--){
        cin >> in1 >> in2;
        in1--;
        in2--;
        if(in2<in1)swap(in1 , in2);
        if(in1-1>=0)sum = ar[in2] - ar[in1-1];
        else sum = ar[in2];
        //cout << sum << endl;
        if(sum==0)cout << "Sim" << endl;
        else if(sum%2==0)cout << "Sim" << endl;
        else cout << "Nao" << endl;
    }
    return 0;
}

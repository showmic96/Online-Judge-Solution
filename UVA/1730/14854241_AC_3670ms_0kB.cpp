// In the name of Allah the Lord of the Worlds. 

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll ans[20000005];

void pre()
{
    for(int i=2;i<20000005;i++)ans[i] = 1;
    for(int i=2;i<20000005;i++)ans[i]+=i;
    
    ans[0] = 0;
    ans[1] = 0;
    
    for(int i=2;i<20000005;i++){
        
        for(int j=2*i;j<20000005;j+=i)ans[j]+=i;
    }
    
    for(int i=1;i<20000005;i++)ans[i]+=ans[i-1];
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    
    pre();
    
    int n;
    while(cin >> n){
        if(n==0)break;
        cout << ans[n] << endl;
    }
    return 0;
}
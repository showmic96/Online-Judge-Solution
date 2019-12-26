// In the name of Allah the most Merciful .

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int f(string ar)
{
    int val = 1 , ans = 0;
    for(int i=9;i>=1;i--){
        if(ar[i]!='.'){
            if(ar[i]=='o')ans+=val;
            val*=2;
        }
    }
    return ans;
}

int main(void)
{
    string ar;
    getline(cin , ar);
    while(getline(cin , ar)){
        if(ar[0]=='_')break;
        printf("%c",f(ar));
    }
    return 0;
}

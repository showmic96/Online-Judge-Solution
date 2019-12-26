// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

int ar[10000005];

bool Check(int n)
{
    int counter = 0;
    vector<int>v;

    while(n){

        v.push_back(n%10);
        n/=10;
        counter++;
    }

    reverse(v.begin() , v.end());

    bool check = true , taken[10] , dig[10];
    int now = 0;
    memset(taken , false ,sizeof(taken));
    memset(dig , false , sizeof(dig));

    for(int i=0;i<counter;i++){
        
        if(v[now]==0)return false;
        if(dig[v[now]])return false;
        dig[v[now]] = true;
        
        if(taken[now]==true)check = false;
        else{
            taken[now] = true;
            now = now+v[now];
            now%=counter;
        }
    }
    
    if(now!=0)check = false;
    
    return check;
}

int main(void)
{
    for(int i=9999999;i>9;i--){

        if(Check(i)==true)ar[i] = i;
        else ar[i] = ar[i+1];
    }

    int c = 0 , n;
    while(scanf("%d",&n)==1){

        if(!n)break;
        printf("Case %d: %d\n",++c , ar[n]);
    }
    return 0;
}

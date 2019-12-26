// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<int>gen(int a)
{
    vector<int>temp;
    map<int, int>mp;

    mp[a] = 1;
    temp.push_back(a);

    while(true){

        int sum = 0;

        while(a){
            sum+=(a%10)*(a%10);
            a/=10;
        }

        if(mp.find(sum)==mp.end()){

            mp[sum] = 1;
            temp.push_back(sum);
            a = sum;
        }
        else break;
    }

    return temp;
}

int main(void)
{
    int a , b;
    while(scanf("%d %d",&a , &b)==2){

        if(!a&&!b)break;

        vector<int>v1 = gen(a);
        vector<int>v2 = gen(b);
        map<int, int>mp;

        int ans = 1e9;

        for(int i=0;i<v1.size();i++){

            mp[v1[i]] = i+1;
        }

        for(int i=0;i<v2.size();i++){

            if(mp.find(v2[i])!=mp.end()){

                ans = min(ans , i+1+mp[v2[i]]);
            }
        }

        if(ans==1e9)ans = 0;
        printf("%d %d %d\n",a , b , ans);
    }
    return 0;
}

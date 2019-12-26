// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

int mp[26];

bool check()
{
    int odd_counter = 0;

    for(int i=0;i<26;i++)if(mp[i]%2==1)odd_counter++;

    if(odd_counter>1)return false;
    return true;
}

int main(void)
{
    int t , c = 0;
    scanf("%d",&t);
    while(t--){

        string ar;
        cin >> ar;

        int si = ar.size();
        long long counter = 0;

        for(int i=0;i<si;i++){

            memset(mp , 0 , sizeof(mp));

            for(int j=i;j<si;j++){

                mp[ar[j]-'a']++;
                if(check()==true)counter++;
            }
        }

        printf("Case %d: %lld\n",++c , counter);
    }
    return 0;
}

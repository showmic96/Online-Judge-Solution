// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int t = 0 , n;
    while(cin >> n){

        int counter = 0;

        for(int i=0;i<n;i++){

            string ar;
            cin >> ar;

            map<char,int>mp;

            int si = ar.size();

            for(int i=0;i<si;i++){

                mp[ar[i]]++;
            }

            vector<int>v;

            for(int i=0;i<26;i++){

                if(mp['a'+i]!=0){

                    v.push_back(mp['a'+i]);
                }
            }

            sort(v.begin() , v.end());

            si = v.size();

            for(int i=0;i<si-1;i++){

                if(v[i]==v[i+1])si=-1;
            }

            if(si==1)si=-1;
            if(si!=-1)counter++;
        }

        printf("Case %d: %d\n",++t , counter);
    }
    return 0;
}

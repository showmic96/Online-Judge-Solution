// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int n;
    while(scanf("%d",&n)==1){

        if(!n)break;
        map< vector<int> , int>mp;
        map< vector<int> , int>::iterator it;

        int mx = 0 , counter = 0;

        for(int i=0;i<n;i++){

            vector<int>v;
            for(int j=0;j<5;j++){

                int in;
                scanf("%d",&in);
                v.push_back(in);
            }

            sort(v.begin() , v.end());
            mp[v]++;
        }

        for(it=mp.begin();it!=mp.end();it++){

            if(it->second==mx){

                counter+=it->second;
            }
            if(it->second>mx){

                mx = it->second;
                counter = it->second;
            }
        }

        printf("%d\n",counter);
    }

    return 0;
}

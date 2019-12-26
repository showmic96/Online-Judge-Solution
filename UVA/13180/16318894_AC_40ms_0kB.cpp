// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(void)
{
    int n;
    while(scanf("%d",&n)==1){

        if(n==0)break;

        map<int , int>mp;
        mp[n]++;

        while(scanf("%d",&n)==1){

            if(n==0)break;
            mp[n]++;
        }

        int odd = 0 , val = 0 , mx = 0 , counter = 0;

        for(auto it = mp.begin();it!=mp.end();it++){

            counter+=it->second;
            if(it->second%2==1)odd++ , val = it->first;
            mx = max(mx , it->first);
        }

        if(odd>1)printf("NO\n");
        else if(odd==1&&mx!=val)printf("NO\n");
        else if(counter>1&&odd==0)printf("NO\n");
        else{

            vector<int>v1 , v2;
            for(auto it=mp.begin();it!=mp.end();it++){

                int temp = (it->second+1)/2;
                for(int i=0;i<temp;i++){

                    it->second--;
                    v1.push_back(it->first);
                }

                temp = it->second;
                for(int i=0;i<temp;i++){

                    it->second--;
                    v2.push_back(it->first);
                }
            }

            sort(v1.begin() , v1.end());
            sort(v2.begin() , v2.end());
            reverse(v2.begin() , v2.end());

            for(int i=0;i<v1.size();i++){

                if(i>0)printf(" ");
                printf("%d",v1[i]);
            }

            for(int i=0;i<v2.size();i++){

                printf(" ");
                printf("%d",v2[i]);
            }
            printf("\n");
        }
    }
    return 0;
}

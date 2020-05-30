// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int t;
    scanf("%d",&t);
    while(t--){

        int n , k;
        scanf("%d %d",&n , &k);
        vector<int>v(n) , mod(k);

        for(int i=0;i<n;i++)scanf("%d",&v[i]);
        for(int i=0;i<k;i++)mod[i] = i;
        int ans = 0;
        do{

            vector<int>temp;
            for(int i=0;i<n;i++){

                auto it = lower_bound(temp.begin() , temp.end() , v[i]);
                if(temp.end()==it){

                    if(v[i]%k==mod[(int)temp.size()%k])temp.emplace_back(v[i]);
                }
                else{

                    if(temp[it-temp.begin()]%k==v[i]%k)temp[it-temp.begin()] = v[i];
                }
            }

            ans = max(ans , (int)temp.size());

        }while(next_permutation(mod.begin() , mod.end()));

        if(ans<k)ans = 0;
        printf("%d\n",ans);
    }

    return 0;
}
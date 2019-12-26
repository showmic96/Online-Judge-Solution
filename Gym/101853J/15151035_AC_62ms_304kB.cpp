// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(void)
{
    int t;
    scanf("%d",&t);
    while(t--){
        
        int n;
        scanf("%d",&n);
        set<int>st;
        map<int,int>mp;
        
        for(int i=0;i<n;i++){
            
            int in;
            scanf("%d",&in);
            mp[in]++;
            st.insert(in);
        }
        
        vector<int>v;
        int mx = 0;
        for(set<int>::iterator it=st.begin();it!=st.end();it++){
            v.push_back(*it);
            mx = max(mx , mp[*it]);
        }
        
        for(int i=0;i<v.size()-1;i++){
            
            if(v[i]+1==v[i+1]){
                
                mx = max(mx , mp[v[i]]+mp[v[i+1]]);
            }
        }
        printf("%d\n",mx);                                  
    }
    return 0;
}
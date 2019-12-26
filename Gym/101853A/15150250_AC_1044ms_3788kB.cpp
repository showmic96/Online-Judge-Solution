// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(void)
{
    int t;
    scanf("%d",&t);
    while(t--){
        
        int n , q;
        scanf("%d %d",&n , &q);
        
        vector<int>v;
        map<int,int>mp;
        
        int counter = 0;
        
        for(int i=0;i<n;i++){
            
            int in;
            scanf("%d",&in);
            v.push_back(in);
            
            mp[in]++;
            if(mp[in]==1&&in!=0)counter++;
        }
        while(q--){
            
            int in;
            scanf("%d",&in);
            if(in==1){
                
                int in1 , in2;
                scanf("%d %d",&in1 , &in2);
                
                mp[v[in1-1]]--;
                if(mp[v[in1-1]]==0&&v[in1-1]!=0)counter--;
                
                v[in1-1] = in2;
                
                mp[in2]++;
                if(mp[in2]==1&&in2!=0)counter++;
            }
            else{
                
                printf("%d\n",counter);
            }
        }
    }
    return 0;
}
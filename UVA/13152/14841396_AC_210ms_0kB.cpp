// In the name of Allah the Lord of the Worlds. 

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(void)
{
    int t , c = 0;
    scanf("%d",&t);
    while(t--){
        
        int n;
        scanf("%d",&n);
        
        vector<int>v;
        map<int , int>mp;
        
        for(int i=0;i<n;i++){
            
            int in;
            scanf("%d",&in);
            v.push_back(in);
            
            mp[in]++;
        }
        
        int now = 0;
        string ans = "";
        
        bool check = true;
        
        for(int i=0;i<n;i++){
            
            if(mp[now+1]>0){
                
                ans+="(";
                now++;
                mp[now]--;
            }
            else if(mp[now-1]>0){
                
                ans+=")";
                now--;
                mp[now]--;
            }
            else{
                check = false;
                break;
            }
        }
        
        if(now!=0)check = false;
        
        for(int i=0;i<n;i++)if(mp[v[i]]>0)check = false;
        
        if(check==false)printf("Case %d: invalid\n",++c);
        else{
            
            printf("Case %d: ",++c);
            for(int i=0;i<ans.size();i++)printf("%c",ans[i]);
            printf("\n");
        }
    }
    return 0;
}
// In the name of Allah the Lord of the Worlds. 

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int n;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    
    int n , c = 0;
    while(cin >> n){
        
        if(n==0)break;
        char last = '0';
        
        bool check = true;
        set<char>st;
        map<char , int>mp;
        
        for(int i=0;i<n;i++){
            
            string ar , br;
            cin >> ar >> br;
            
            if(br.size()>ar.size()){
                
                check = false;
                continue;
            }
            
            
            for(int j=1;j<ar.size()-1;j++){
                
                if(j>=br.size()-1){
                    
                    if(mp[ar[j]]==1)check = false;
                    else mp[ar[j]] = -1;
                    break;
                }
                else{
                    
                    if(ar[j]==br[j]){
                        
                        if(mp[ar[j]]==-1)check = false;
                        else mp[ar[j]] = 1;
                        last = max(last , ar[j]);
                    }
                    else check = false;
                }
            }
        }
        
        for(int i=0;i<10;i++){
            
            char x = '0'+i;
            if(x>last)break;
            if(mp[x]!=-1)st.insert(x);
        }
        
        for(int i=0;i<26;i++){
            
            char x = 'A'+i;
            if(x>last)break;
            if(mp[x]!=-1)st.insert(x);
        }
        
        for(int i=0;i<26;i++){
            
            char x = 'a'+i;
            if(x>last)break;
            if(mp[x]!=-1)st.insert(x);
        }
        
        if(st.size()==0){
            
            for(int i=0;i<10;i++){
            
                char x = '0'+i;
                if(mp[x]!=-1){st.insert(x);break;}
            }
            if(st.size()!=0){}
            else for(int i=0;i<26;i++){
            
                char x = 'A'+i;
                if(mp[x]!=-1){st.insert(x);break;}
            }
            if(st.size()!=0){}
            else for(int i=0;i<26;i++){
            
                char x = 'a'+i;
                if(mp[x]!=-1){st.insert(x);break;}
            }
        }
        
        cout << "Case " << ++c << ": ";
        
        if(check==false||st.size()==0)cout << "I_AM_UNDONE" << endl;
        else{
            
            cout << "[";
            for(set<char>::iterator it = st.begin();it!=st.end();it++)cout << *it;
            cout << "]" << endl;
        }
    }
    return 0;
}
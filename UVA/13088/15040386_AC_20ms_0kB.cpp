// In the name of Allah the Lord of the Worlds. 

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    
    int t;
    cin >> t;
    while(t--){
        
        int ar[26];
        memset(ar , 0 , sizeof(ar));
        
        string in;
        cin >> in;
        
        for(int i=0;i<in.size();i++){
            
            ar[in[i]-'a']++;
        }
        
        int dif = 0;
        
        for(int i=0;i<26;i++){
            
            if(ar[i])dif++;
        }
        
        bool check = false;
        
        for(int i=0;i<26;i++){
            
            if(ar[i]){
                
                if(check==false){
                    for(int j=0;j<in.size()-dif+1;j++)cout << (char)('a'+i);
                    check = true;
                }
                else cout << (char)('a'+i);
            }
        }
        cout << endl;
    }
    
    return 0;
}
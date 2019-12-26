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
        
        string ar;
        cin >> ar;
        
        int n;
        cin >> n;
        map<char , char>mp;
        
        for(int i=0;i<255;i++)mp[(char)i] = (char)i;
        
        for(int i=0;i<n;i++){
            
            char x , y;
            cin >> x >> y;
            
            for(char j='A';j<='Z';j++){
                
                if(mp[j]==y)mp[j] = x;
            }
        }
        
        for(int j=0;j<1;j++){
            
            string temp = "";
            
            for(int i=0;i<ar.size();i++){
            
                temp+=mp[ar[i]];
            }
            
            ar = temp;
        }
        
        cout << ar << endl;
    }
    return 0;
}
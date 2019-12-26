#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll get(char x)
{
    if(x>='0'&&x<='9')return x-'0';
    return x-'A'+10;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    
    string ar;
    int n;
    while(cin >> ar >> n){
        
        if(ar=="0"&&n==0)break;
        
        ll now = 0;
        
        if(ar[0]=='0'&&ar[1]=='x'){
            
            for(int i=2;i<ar.size();i++){
                
                now*=16;
                now+=get(ar[i]);
            }
        }
        else if(ar[0]=='0'){
            
            for(int i=1;i<ar.size();i++){
                
                now*=8;
                now+=get(ar[i]);
            }
        }
        else{
            
            for(int i=0;i<ar.size();i++){
                
                now*=10;
                now+=get(ar[i]);
            }
        }
        
        int counter = 0;
        
        while(n--){
            
            string s;
            ll v;
            cin >> s >> v;
            
            if(s=="i"){
                
                if(now==v)counter++;
                now = v;
            }
            
            if(s=="++i"){
                
                ++now;
                if(v==now)counter++;
                now = v;
            }
            if(s=="--i"){
                
                --now;
                if(v==now)counter++;
                now = v;
            }
            
            
            if(s=="i++"){
                
                if(v==now)counter++;
                now = v;
                now++;
            }
            if(s=="i--"){
                
                if(v==now)counter++;
                now = v;
                now--;
            }
        }
        
        cout << counter << endl;
    }
    
    return 0;
}

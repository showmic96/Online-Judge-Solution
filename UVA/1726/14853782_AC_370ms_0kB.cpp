// In the name of Allah the Lord of the Worlds. 

#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    
    int t;
    cin >> t;
    while(t--){
        
        int n;
        cin >> n;
        
        vector<int>v1 , v2;    
        for(int i=0;i<n;i++){
            
            int a , b;
            string c;
            cin >> a >> b >> c;
            
            if(b==1&&c=="c"){
                v1.push_back(a);
            }
            if(b==0&&c=="i"){
                v2.push_back(a);
            }
        }
        
        sort(v1.begin() , v1.end());
        sort(v2.begin() , v2.end());
        
        int counter = 0;
        
        for(int i=0;i<v1.size();i++){
            
            counter+=lower_bound(v2.begin() , v2.end() , v1[i]) - v2.begin();
        }
        
        cout << counter << endl;
    }
    return 0;
}
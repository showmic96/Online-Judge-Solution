// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n;
    cin >> n;
    
    string ar = "" , ans = "";
    char x;
    for(int i=0;i<n;i++){
        
        cin >> x;
        ar+=x;
    }
    
    int i=0 , j=n-1;
    
    for(int i1=0;i1<n;i1++){
        
        if(ar[i]<ar[j]){
            
            ans+=ar[i];
            i++;
        }
        else if(ar[i]>ar[j]){
            
            ans+=ar[j];
            j--;
        }
        else{
            
            bool found = false;
            for(int j1=0;j1<n;j1++){
                
                if(i+j1>=j-j1)break;
                
                if(ar[i+j1]<ar[j-j1]){
                    
                    ans+=ar[i];
                    i++;
                    found = true;
                    break;
                }
                else if(ar[i+j1]>ar[j-j1]){
                    
                    ans+=ar[j];
                    j--;
                    found = true;
                    break;
                }
            }
            
            if(found==false){
                
                ans+=ar[i];
                i++;
            }
        }
    }
    for(int i=0;i<ans.size();i++){
        
        if(i>0&&i%80==0)cout << endl;
        cout << ans[i];
    }
    
    return 0;
}
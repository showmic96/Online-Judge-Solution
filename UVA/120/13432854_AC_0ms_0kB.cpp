// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string ar;
    while(getline(cin , ar)){

        cout << ar << endl;
        vector<int>v;
        stringstream ss(ar);
        int in;

        while(ss>>in){
            v.push_back(in);
        }

        vector<int>temp = v;
        sort(temp.begin() , temp.end());
        reverse(temp.begin() , temp.end());
        
        for(int i=0;i<temp.size();i++){
            
            if(is_sorted(v.begin() , v.end()))break;
            
            for(int j=0;j<temp.size();j++){
                
                if(temp[i]==v[j]){
                    
                    if(j==0){
                        
                        cout << i+1 << " ";
                        reverse(v.begin() , v.begin()+temp.size()-i);
                        
                    }
                    else{
                        
                        cout << temp.size()-j << " " << i+1 << " ";
                        reverse(v.begin() , v.begin()+j+1);
                        reverse(v.begin() , v.begin()+temp.size()-i);                  
                                        
                    }
                    
                    break;
                }
            }
        }
        
        cout << 0 << endl;
    }

    return 0;
}

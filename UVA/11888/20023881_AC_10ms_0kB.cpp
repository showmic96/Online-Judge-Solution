// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
string ar;
bool palin(int i , int j)
{
    while(i<j){
        if(ar[i]!=ar[j])return false;
        i++;j--;
    }
    return true;
}
int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int t;
    cin >> t;
    while(t--){
        cin >> ar;
        bool found = false;
        for(int i=0;i<ar.size();i++){
            if(ar[0]==ar[i]&&ar[i+1]==ar[ar.size()-1]){
                if(palin(0 , i)==true&&palin(i+1, ar.size()-1)==true){
                    cout << "alindrome" << endl;
                    found = true;
                    break;
                }
            }
        }
        if(found==false){
            if(palin(0 , ar.size()-1)==true){
                cout << "palindrome" << endl;
                found = true;
            }
        }
        if(found==false)cout << "simple" << endl;
    }
    return 0;
}

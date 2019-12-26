// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
string vow = "AUEOI";
string con = "JSBKTCLDMVNWFXGPYHQZR";

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t , c = 0;
    cin >> t;
    while(t--){
        string s1 = "" , s2 = "";
        int n , c1 = 0 , c2 = 0 , n1 = 0 , n2 = 0;
        cin >> n;
        for(int i=1;i<=n;i++){
            if(i%2){
                if(c1==21){
                    c1 = 1;
                    n1++;
                    s1+=vow[n1];
                }
                else{
                    c1++;
                    s1+=vow[n1];
                }
            }
            else{
                if(c2==5){
                    c2 = 1;
                    n2++;
                    s2+=con[n2];
                }
                else{
                    c2++;
                    s2+=con[n2];
                }
            }
        }
        cout << "Case " << ++c << ": ";
        sort(s1.begin() , s1.end());
        sort(s2.begin() , s2.end());
        c1 = 0 , c2 = 0;
        for(int i=1;i<=n;i++){
            if(i%2){
                cout << s1[c1];
                c1++;
            }
            else{
                cout << s2[c2];
                c2++;
            }
        }
        cout << endl;
    }
    return 0;
}

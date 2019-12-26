// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

char to_lower(char x)
{
    if(x>='A'&&x<='Z')return x+32;
    return x;
}

bool cmp(char a , char b)
{
    if(to_lower(a)==to_lower(b))return a<b;
    return to_lower(a) < to_lower(b);
}

int main(void)
{
    int t;
    cin >> t;
    while(t--){
        string ar;
        cin >> ar;
        sort(ar.begin(), ar.end() , cmp);
        cout << ar << endl;
        while(next_permutation(ar.begin() , ar.end() , cmp)){

            cout << ar << endl;
        }
        
        cout << endl;
    }
    return 0;
}

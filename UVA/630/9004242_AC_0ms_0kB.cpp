// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

char to_lower(char x)
{
    if(x>='A'&&x<='Z')return x+32;
    return x;
}

int main(void)
{
    int t;
    cin >> t;
    bool space = false;
    while(t--){

        if(space)cout << endl;
        space = true;

        int n;
        cin >> n;

        vector<string>v;
        string ar;

        for(int i=0;i<n;i++){

            cin >> ar;

            v.push_back(ar);
        }

        while(cin >> ar){

            if(ar=="END")break;

            cout << "Anagrams for: " << ar << endl;

            string temp1 = ar , temp2;

            int si = temp1.size();
            for(int i=0;i<si;i++){

                temp1[i] = to_lower(temp1[i]);
            }

            sort(temp1.begin() , temp1.end());

            int c = 0;
//cout << "YES";
            for(int i=0;i<n;i++){

                temp2 = v[i];

                si = temp2.size();

                for(int j=0;j<si;j++){

                    temp2[j] = to_lower(temp2[j]);
                }

                sort(temp2.begin() , temp2.end());
                if(temp1==temp2){

                    printf("%3d) ",++c);
                    cout << v[i] << endl;
                }
            }

            if(c==0)cout << "No anagrams for: " << ar << endl;
        }

    }

    return 0;
}

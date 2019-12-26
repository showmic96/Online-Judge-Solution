// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int t , c = 0;
    cin >> t;
    while(t--){

        int n1 , n2;
        cin >> n1 >> n2;

        vector<string>v;
        map<string,int>mp;

        getchar();

        for(int i=0;i<n1;i++){

            string ar;
            getline(cin , ar);
            v.push_back(ar);
        }

        int counter = 0;

        for(int i=0;i<n2;i++){

            string ar , temp;
            getline(cin , ar);

            for(int j=0;j<n1;j++){

                temp = v[j]+ar;

                if(mp[temp]==0){

                    counter++;
                    mp[temp] = 1;
                }
            }
        }

        printf("Case %d: %d\n",++c , counter);
    }
    return 0;
}

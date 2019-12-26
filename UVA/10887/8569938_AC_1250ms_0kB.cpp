// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

vector<string>first;
vector<string>second;
map<string , int>mp;
int n , m , n_t , m_t , counter;

void is_it(string ar)
{
    if(mp[ar]==0){

        counter++;
        mp[ar] = 1;
    }
}

void f(string ar)
{

    for(int i=0;i<m;i++){

        is_it(ar+second[i]);
    }
}

int main(void)
{
    int t;
    cin >> t;

    for(int i=0;i<t;i++){

        mp.clear();
        first.clear();
        second.clear();

        cin >> n >> m;
        n_t = n;
        m_t = m;

        getchar();

        while(n_t--){

            string ar;
            getline(cin , ar);
            first.push_back(ar);
        }

        while(m_t--){

            string ar;
            getline(cin , ar);
            second.push_back(ar);
        }
        counter = 0;

        for(int j=0;j<n;j++){

            f(first[j]);
        }

        printf("Case %d: ",i+1);
        cout << counter << endl;
    }
    return 0;
}

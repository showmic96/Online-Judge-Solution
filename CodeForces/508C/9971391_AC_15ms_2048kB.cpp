// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    cin.tie(0);

    int m , t , r;
    cin >> m >> t >> r;
    vector<int>v;

    for(int i=0;i<m;i++){

        int in;
        cin >> in;
        v.push_back(310+in);
    }

    int mid = 310;

    int visited[700];
    bool here[700];

    memset(visited , 0 , sizeof(visited));
    memset(here , false , sizeof(here));

    int counter = 0;
    bool check = true;

    for(int i=0;i<m;i++){

        int need = r - visited[v[i]];

        for(int j=v[i]-1;;j--){

            if(need<=0)break;

            if(here[j]==false){

                here[j] = true;
                counter++;
                need--;

                for(int k=j+1;k<=j+t;k++){

                    visited[k]++;
                    if(k==690)break;
                }
            }
        }

        if(visited[v[i]]>=r)continue;

        check = false;
        break;
    }

    if(check==true)cout << counter << endl;
    else cout << -1 << endl;

    return 0;
}

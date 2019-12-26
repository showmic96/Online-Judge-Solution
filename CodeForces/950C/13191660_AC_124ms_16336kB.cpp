// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<int>v[200005];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string ar;
    cin >> ar;

    int a = 0 , b = 0;
    bool check = true;
    queue<int>one , zero;

    for(int i=0;i<ar.size();i++){

        if(ar[i]=='0'){

            a++;
            b--;
            b = max(0 , b);

            zero.push(i);
        }

        if(ar[i]=='1'){

            a--;
            b++;
            if(a<0)check = false;
            one.push(i);
        }
    }

    if(b)check = false;
    int c = 0;


    if(check){

        set<int>zeb , alzeb;
        int c = 0;
        for(int i=0;i<ar.size();i++){

            if(ar[i]=='0'){

                if(alzeb.empty()){

                    v[c].push_back(i);
                    zeb.insert(c);
                    c++;
                }
                else{

                    set<int>::iterator it = alzeb.begin();

                    int temp = *it;

                    v[temp].push_back(i);

                    alzeb.erase(it);

                    zeb.insert(temp);
                }
            }

            else{

                set<int>::iterator it = zeb.begin();

                int temp = *it;

                v[temp].push_back(i);

                zeb.erase(*it);
                alzeb.insert(temp);
            }
        }

        printf("%d\n",c);
        for(int i=0;i<c;i++){

            printf("%d",v[i].size());

            for(int j=0;j<v[i].size();j++)printf(" %d",v[i][j]+1);
            printf("\n");
        }
    }

    else cout << -1 << endl;

    return 0;
}

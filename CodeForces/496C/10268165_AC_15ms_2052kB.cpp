// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

string ar[105];
int parent[105];

int main(void)
{
    int n , m , par = 2;
    cin >> n >> m;

    for(int i=0;i<n;i++){

        cin >> ar[i];
        parent[i] = 1;
    }

    char last = 'a';

    int counter = 0;

    for(int i=0;i<m;i++){

        bool check = true;

        for(int j=0;j<n-1;j++){

            if(parent[j]==parent[j+1]){

                if(ar[j][i]>ar[j+1][i])check = false;
            }

        }

        if(check==false){

            counter++;
            continue;
        }

        for(int j=1;j<n;j++){

            if(parent[j]==parent[j-1]){

                if(ar[j][i]==ar[j-1][i]){

                }

                else{

                    int p = parent[j-1];

                    for(int k=j-1;k>=0;k--){

                        if(parent[k]==p)parent[k] = par;
                        else break;
                    }

                    par++;
                }
            }
        }
    }

    cout << counter << endl;

    return 0;
}

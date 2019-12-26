#include<bits/stdc++.h>
using namespace std;

const long long INF = 1e9 , MAX = 1010;
typedef long long ll;
typedef unsigned long long LL;

char ar[MAX][MAX] , X;
int n , m;

void dfs(int i , int j)
{
    if(ar[i][j]!=X)return;
    if(i>=n||j>=m)return;
    if(i<0||j<0)return;

    ar[i][j]='.';

    dfs(i , j+1);
    dfs(i , j-1);
    dfs(i+1 , j);
    dfs(i-1 , j);
}

int main(void)
{
    int a;
    cin >> a;
    map<char,int>maping;

    for(int i=0;i<a;i++){

        maping.clear();

        cin >> n >> m ;
        int hi = 0;

        for(int j=0;j<n;j++)cin >> ar[j];

        for(int j=0;j<n;j++){

            for(int k=0;k<m;k++){

                if(ar[j][k]!='.'){

                    maping[ar[j][k]]++;

                    if(maping[ar[j][k]]>hi)hi = maping[ar[j][k]];

                    X = ar[j][k];

                    dfs(j , k);



                }
            }
        }

        printf("World #%d\n",i+1);

        for(int j=hi;j>=1;j--){

            for(int k=0;k<26;k++){

                if(maping['a'+k]==j){

                    cout << (char)('a'+k) << ": " << j << endl;
                }
            }
        }
    }


    return 0;
}

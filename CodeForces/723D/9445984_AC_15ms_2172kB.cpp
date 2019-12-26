// In the name of Allah the most Merciful .

#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
const int MAX = 55;
bool is_visited[MAX][MAX];
string ar[MAX];
int counter;
bool check;
int m , n , k;

struct myStruct{

    int x , y , c;
    myStruct(int xt , int yt , int ct){

        x = xt;
        y = yt;
        c= ct;
    }

};

void set_up()
{
    for(int i=0;i<MAX;i++){

        for(int j=0;j<MAX;j++)is_visited[i][j] = false;
        ar[i].clear();
    }

}

bool possible(int i , int j)
{
    if(i<0||j<0){check=false;return false;}
    if(i>=m||j>=n){check=false;return false;}

    if(ar[i][j]=='*')return false;
    if(is_visited[i][j]==true)return false;

    return true;
}

void dfs1(int i , int j)
{

    counter++;
    is_visited[i][j] = true;

    if(possible(i , j+1)==true)dfs1(i , j+1);
    if(possible(i , j-1)==true)dfs1(i , j-1);
    if(possible(i+1 , j)==true)dfs1(i+1 , j);
    if(possible(i-1 , j)==true)dfs1(i-1 , j);
}

void dfs2(int i , int j)
{
    if(ar[i][j]=='*')return;

    ar[i][j] = '*';
    counter++;

    dfs2(i , j+1);
    dfs2(i , j-1);
    dfs2(i+1 , j);
    dfs2(i-1 , j);
}

bool cmp(myStruct A , myStruct B)
{
    return A.c>B.c;
}

int main(void)
{
    cin >> m >> n >> k;

    set_up();
    vector<myStruct>v;

    for(int i=0;i<m;i++)cin >> ar[i];

    int d = 0;

    for(int i=0;i<m;i++){

        for(int j=0;j<n;j++){

            if(is_visited[i][j]==false&&ar[i][j]=='.'){

                check = true;
                counter = 0;
                dfs1(i , j);

                if(check==true){

                    v.push_back(myStruct(i , j , counter));
                }
            }
        }
    }

    sort(v.begin() , v.end() , cmp);

    int ans = 0;

    for(int i=k;i<v.size();i++){

        counter = 0;
        dfs2(v[i].x , v[i].y);
        ans += v[i].c;
    }

    cout << ans << endl;

    for(int i=0;i<m;i++)cout << ar[i] << endl;

    return 0;

}

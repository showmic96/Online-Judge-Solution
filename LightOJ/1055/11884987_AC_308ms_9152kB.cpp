// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

int level[11][11][11][11][11][11];
char ar[11][11];

int n;

bool possible(int i , int j)
{
    if(i<0||j<0)return false;
    if(i>=n||j>=n)return false;
    if(ar[i][j]=='#')return false;

    return true;
}

void bfs(int i1 , int i2 , int j1 , int j2 , int k1 , int k2)
{

    memset(level , 0 , sizeof(level));

    level[i1][i2][j1][j2][k1][k2] = 1;
    queue<int>current;
    current.push(i1);
    current.push(i2);
    current.push(j1);
    current.push(j2);
    current.push(k1);
    current.push(k2);

    while(!current.empty()){

        i1 = current.front();current.pop();
        i2 = current.front();current.pop();
        j1 = current.front();current.pop();
        j2 = current.front();current.pop();
        k1 = current.front();current.pop();
        k2 = current.front();current.pop();

        if(i1==j1&&i2==j2)continue;
        if(i1==k1&&i2==k2)continue;
        if(j1==k1&&j2==k2)continue;

        int ni1 = i1 , ni2 = i2 , nj1 = j1 , nj2 = j2 , nk1 = k1 , nk2 = k2;

        if(possible(i1+1 , i2)==true){

            ni1 = i1+1;
            ni2 = i2;
        }

        if(possible(j1+1 , j2)==true){

            nj1 = j1+1;
            nj2 = j2;
        }

        if(possible(k1+1 , k2)==true){

            nk1 = k1+1;
            nk2 = k2;
        }

        if(ni1==nj1&&ni2==nj2){

            ni1 = i1;
            ni2 = i2;
            nj1 = j1;
            nj2 = j2;
        }

        if(ni1==nk1&&ni2==nk2){

            ni1 = i1;
            ni2 = i2;
            nk1 = k1;
            nk2 = k2;
        }

        if(nj1==nk1&&nj2==nk2){

            nj1 = j1;
            nj2 = j2;
            nk1 = k1;
            nk2 = k2;

        }

        if(level[ni1][ni2][nj1][nj2][nk1][nk2]==0){

            level[ni1][ni2][nj1][nj2][nk1][nk2] = level[i1][i2][j1][j2][k1][k2] + 1;

            current.push(ni1);
            current.push(ni2);
            current.push(nj1);
            current.push(nj2);
            current.push(nk1);
            current.push(nk2);
        }


        ni1 = i1 , ni2 = i2 , nj1 = j1 , nj2 = j2 , nk1 = k1 , nk2 = k2;


        if(possible(i1-1 , i2)==true){

            ni1 = i1-1;
            ni2 = i2;
        }

        if(possible(j1-1 , j2)==true){

            nj1 = j1-1;
            nj2 = j2;
        }

        if(possible(k1-1 , k2)==true){

            nk1 = k1-1;
            nk2 = k2;
        }

        if(ni1==nj1&&ni2==nj2){

            ni1 = i1;
            ni2 = i2;
            nj1 = j1;
            nj2 = j2;
        }

        if(ni1==nk1&&ni2==nk2){

            ni1 = i1;
            ni2 = i2;
            nk1 = k1;
            nk2 = k2;
        }

        if(nj1==nk1&&nj2==nk2){

            nj1 = j1;
            nj2 = j2;
            nk1 = k1;
            nk2 = k2;

        }

        if(level[ni1][ni2][nj1][nj2][nk1][nk2]==0){

            level[ni1][ni2][nj1][nj2][nk1][nk2] = level[i1][i2][j1][j2][k1][k2] + 1;

            current.push(ni1);
            current.push(ni2);
            current.push(nj1);
            current.push(nj2);
            current.push(nk1);
            current.push(nk2);
        }

        ni1 = i1 , ni2 = i2 , nj1 = j1 , nj2 = j2 , nk1 = k1 , nk2 = k2;

        if(possible(i1 , i2-1)==true){

            ni1 = i1;
            ni2 = i2-1;
        }

        if(possible(j1 , j2-1)==true){

            nj1 = j1;
            nj2 = j2-1;
        }

        if(possible(k1 , k2-1)==true){

            nk1 = k1;
            nk2 = k2-1;
        }

        if(ni1==nj1&&ni2==nj2){

            ni1 = i1;
            ni2 = i2;
            nj1 = j1;
            nj2 = j2;
        }

        if(ni1==nk1&&ni2==nk2){

            ni1 = i1;
            ni2 = i2;
            nk1 = k1;
            nk2 = k2;
        }

        if(nj1==nk1&&nj2==nk2){

            nj1 = j1;
            nj2 = j2;
            nk1 = k1;
            nk2 = k2;

        }

        if(level[ni1][ni2][nj1][nj2][nk1][nk2]==0){

            level[ni1][ni2][nj1][nj2][nk1][nk2] = level[i1][i2][j1][j2][k1][k2] + 1;

            current.push(ni1);
            current.push(ni2);
            current.push(nj1);
            current.push(nj2);
            current.push(nk1);
            current.push(nk2);
        }

        ni1 = i1 , ni2 = i2 , nj1 = j1 , nj2 = j2 , nk1 = k1 , nk2 = k2;

        if(possible(i1 , i2+1)==true){

            ni1 = i1;
            ni2 = i2+1;
        }

        if(possible(j1 , j2+1)==true){

            nj1 = j1;
            nj2 = j2+1;
        }

        if(possible(k1 , k2+1)==true){

            nk1 = k1;
            nk2 = k2+1;
        }

        if(ni1==nj1&&ni2==nj2){

            ni1 = i1;
            ni2 = i2;
            nj1 = j1;
            nj2 = j2;
        }

        if(ni1==nk1&&ni2==nk2){

            ni1 = i1;
            ni2 = i2;
            nk1 = k1;
            nk2 = k2;
        }

        if(nj1==nk1&&nj2==nk2){

            nj1 = j1;
            nj2 = j2;
            nk1 = k1;
            nk2 = k2;

        }

        if(level[ni1][ni2][nj1][nj2][nk1][nk2]==0){



            level[ni1][ni2][nj1][nj2][nk1][nk2] = level[i1][i2][j1][j2][k1][k2] + 1;

            current.push(ni1);
            current.push(ni2);
            current.push(nj1);
            current.push(nj2);
            current.push(nk1);
            current.push(nk2);
        }

    }

}

int main(void)
{
    int t , tc = 0;
    scanf("%d",&t);
    while(t--){

        scanf("%d",&n);
        for(int i=0;i<n;i++)scanf("%s",&ar[i]);

        pair<int , int> a , b , c;
        vector<pair<int, int> > v;

        for(int i=0;i<n;i++){

            for(int j=0;j<n;j++){

                if(ar[i][j]=='A')a.first = i , a.second = j;
                if(ar[i][j]=='B')b.first = i , b.second = j;
                if(ar[i][j]=='C')c.first = i , c.second = j;
            }
        }

        bfs(a.first , a.second , b.first , b.second , c.first , c.second);

        for(int i=0;i<n;i++){

            for(int j=0;j<n;j++){

                if(ar[i][j]=='X')v.push_back(make_pair(i , j));
            }
        }

        int ans = 1e9;

        for(int i=0;i<3;i++){

            for(int j=0;j<3;j++){

                if(i==j)continue;

                for(int k=0;k<3;k++){

                    if(i==k||j==k)continue;

                    if(level[v[i].first][v[i].second][v[j].first][v[j].second][v[k].first][v[k].second]==0);
                    else ans = min(ans , level[v[i].first][v[i].second][v[j].first][v[j].second][v[k].first][v[k].second]);

                    if(level[v[j].first][v[j].second][v[i].first][v[i].second][v[k].first][v[k].second]==0);
                    else ans = min(ans , level[v[j].first][v[j].second][v[i].first][v[i].second][v[k].first][v[k].second]);

                    if(level[v[j].first][v[j].second][v[k].first][v[k].second][v[i].first][v[i].second]==0);
                    else ans = min(ans , level[v[j].first][v[j].second][v[k].first][v[k].second][v[i].first][v[i].second]);

                    if(level[v[i].first][v[i].second][v[k].first][v[k].second][v[j].first][v[j].second]==0);
                    else ans = min(ans , level[v[i].first][v[i].second][v[k].first][v[k].second][v[j].first][v[j].second]);

                    if(level[v[k].first][v[k].second][v[j].first][v[j].second][v[i].first][v[i].second]==0);
                    else ans = min(ans , level[v[k].first][v[k].second][v[j].first][v[j].second][v[i].first][v[i].second]);

                    if(level[v[k].first][v[k].second][v[i].first][v[i].second][v[j].first][v[j].second]==0);
                    else ans = min(ans , level[v[k].first][v[k].second][v[i].first][v[i].second][v[j].first][v[j].second]);

                }
            }
        }

        if(ans==1e9)printf("Case %d: trapped\n",++tc);
        else printf("Case %d: %d\n",++tc , ans-1);

    }
    return 0;
}

// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int n , m , dis[55][55][105] , si;

string ar[55] , br;

struct node{

    int x , y , l , cost;
    node(int _x , int _y , int _l , int _cost){

        x = _x;y=_y;l=_l;cost=_cost;
    }
};

bool operator<(node A , node B)
{
    return A.cost>B.cost;
}


bool possible(int i , int j)
{
    if(i<0||j<0||i>=n||j>=m)return false;
    if(ar[i][j]=='#')return false;
    return true;
}

void f(int i , int j , int l)
{
    dis[i][j][0] = 0;
    priority_queue<node>pq;

    pq.push(node(i , j , 0 , 0));

    while(!pq.empty()){

        i = pq.top().x;
        j = pq.top().y;
        l = pq.top().l;
        pq.pop();

        if(l>=100)continue;

        if(dis[i][j][l+1]>dis[i][j][l]+1){

            dis[i][j][l+1] = dis[i][j][l]+1;
            pq.push(node(i , j , l+1 , dis[i][j][l]+1));
        }

        if(possible(i+1 , j)==true){

            if(dis[i+1][j][l]>dis[i][j][l]+1){

                dis[i+1][j][l] = dis[i][j][l]+1;
                pq.push(node(i+1 , j , l , dis[i][j][l]+1));
            }
        }

        if(possible(i-1 , j)==true){

            if(dis[i-1][j][l]>dis[i][j][l]+1){

                dis[i-1][j][l] = dis[i][j][l]+1;
                pq.push(node(i-1 , j , l , dis[i][j][l]+1));
            }
        }

        if(possible(i , j+1)==true){

            if(dis[i][j+1][l]>dis[i][j][l]+1){

                dis[i][j+1][l] = dis[i][j][l]+1;
                pq.push(node(i , j+1 , l , dis[i][j][l]+1));
            }
        }

        if(possible(i , j-1)==true){

            if(dis[i][j-1][l]>dis[i][j][l]+1){

                dis[i][j-1][l] = dis[i][j][l]+1;
                pq.push(node(i , j-1 , l , dis[i][j][l]+1));
            }
        }

        if(l>=si)continue;

        if(br[l]=='U'){

            if(possible(i-1 , j)==true){

                if(dis[i-1][j][l+1]>dis[i][j][l]){

                    dis[i-1][j][l+1] = dis[i][j][l];
                    pq.push(node(i-1 , j , l+1 , dis[i][j][l]));
                }
            }

            else{

                if(dis[i][j][l+1]>dis[i][j][l]){

                    dis[i][j][l+1] = dis[i][j][l];
                    pq.push(node(i , j , l+1 , dis[i][j][l]));
                }
            }
        }

        if(br[l]=='D'){

            if(possible(i+1 , j)==true){

                if(dis[i+1][j][l+1]>dis[i][j][l]){

                    dis[i+1][j][l+1] = dis[i][j][l];
                    pq.push(node(i+1 , j , l+1 , dis[i][j][l]));
                }
            }

            else{

                if(dis[i][j][l+1]>dis[i][j][l]){

                    dis[i][j][l+1] = dis[i][j][l];
                    pq.push(node(i , j , l+1 , dis[i][j][l]));
                }
            }
        }

        if(br[l]=='L'){

            if(possible(i , j-1)==true){

                if(dis[i][j-1][l+1]>dis[i][j][l]){

                    dis[i][j-1][l+1] = dis[i][j][l];
                    pq.push(node(i , j-1 , l+1 , dis[i][j][l]));
                }
            }

            else{

                if(dis[i][j][l+1]>dis[i][j][l]){

                    dis[i][j][l+1] = dis[i][j][l];
                    pq.push(node(i , j , l+1 , dis[i][j][l]));
                }
            }
        }

        if(br[l]=='R'){

            if(possible(i , j+1)==true){

                if(dis[i][j+1][l+1]>dis[i][j][l]){

                    dis[i][j+1][l+1] = dis[i][j][l];
                    pq.push(node(i , j+1 , l+1 , dis[i][j][l]));
                }
            }

            else{

                if(dis[i][j][l+1]>dis[i][j][l]){

                    dis[i][j][l+1] = dis[i][j][l];
                    pq.push(node(i , j , l+1 , dis[i][j][l]));
                }
            }
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    for(int i=0;i<55;i++){

        for(int j=0;j<55;j++){

            for(int k=0;k<105;k++){

                dis[i][j][k] = 1e9;
            }
        }
    }

    cin >> n >> m;

    for(int i=0;i<n;i++)cin >> ar[i];
    cin >> br;

    si = br.size();
    int ans = 2e9;

    for(int i=0;i<n;i++){

        for(int j=0;j<m;j++){

            if(ar[i][j]=='R'){

                f(i , j , 0);
            }
        }
    }

    for(int i=0;i<n;i++){

        for(int j=0;j<m;j++){

            if(ar[i][j]=='E'){

                for(int k=0;k<105;k++){

                    ans = min(ans , dis[i][j][k]);
                }
            }
        }
    }

    cout << ans << endl;

    return 0;
}

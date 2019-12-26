// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

int a , b, c;
map<pair<int , int >  , int>level;

int bfs()
{
    queue<pair <int , int > >current;
    current.push(make_pair(0 , 0));
    level[make_pair(0 , 0)] = 0;

    while(!current.empty()){

         int i = current.front().first;
         int j = current.front().second;
         current.pop();

         //cout << i << " " << j << endl;
         if(level[make_pair(a , j)]==0){

            level[make_pair(a , j)] = level[make_pair(i , j)] + 1;

            if(a==c)return level[make_pair(i ,j)] + 1;

            current.push(make_pair(a , j));
         }

         if(level[make_pair(i , b)]==0){

            level[make_pair(i , b)] = level[make_pair(i , j)] + 1;

            if(b==c)return level[make_pair(i ,j)] + 1;

            current.push(make_pair(i , b));
         }

         if(level[make_pair(0 , j)]==0){

            level[make_pair(0 , j)] = level[make_pair(i , j)] + 1;

            if(0==c)return level[make_pair(i ,j)] + 1;

            current.push(make_pair(0 , j));
         }

         if(level[make_pair(i , 0)]==0){

            level[make_pair(i , 0)] = level[make_pair(i , j)] + 1;

            if(0==c)return level[make_pair(i ,j)] + 1;

            current.push(make_pair(i , 0));
         }

         if(i<a){

            int temp = min(a-i , j);

            if(level[make_pair(i+temp , j-temp)]==0){

                level[make_pair(i+temp ,j-temp)] = level[make_pair(i , j)] + 1;

                if(i+temp==c||j-temp==c)return level[make_pair(i ,j)] + 1;

                current.push(make_pair(i+temp , j-temp));
            }
         }

         if(j<b){

            int temp = min(i , b-j);
            //cout << i-temp << " " << j+temp << endl;
            if(level[make_pair(i-temp , j+temp)]==0){

                level[make_pair(i-temp ,j+temp)] = level[make_pair(i , j)] + 1;

                if(i-temp==c||j+temp==c)return level[make_pair(i ,j)] + 1;

                current.push(make_pair(i-temp , j+temp));
            }
         }
    }

    return -1;
}

int main(void)
{
    int t;
    scanf("%d",&t);
    while(t--){

        level.clear();

        scanf("%d %d %d", &a , &b , &c);

        printf("%d\n",bfs());
    }
    return 0;
}

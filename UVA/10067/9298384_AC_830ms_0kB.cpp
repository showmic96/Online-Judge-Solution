// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

map< pair <pair <int ,int> , pair<int , int> >, int>mp;

int s1 , s2 , s3 , s4 , e1, e2 , e3 , e4;

bool valid(int t1 , int t2 , int t3 , int t4){

    //cout << t1 << " " << t2 << " " << t3 << " " << t4 << endl;

    if(mp[make_pair(make_pair(t1 , t2) , make_pair(t3 , t4))]==0)return true;
    return false;
}

void bfs()
{
    queue<int>current;

    current.push(s1);
    current.push(s2);
    current.push(s3);
    current.push(s4);

    mp[make_pair(make_pair(s1 , s2) , make_pair(s3 , s4))] = 0;

    while(!current.empty()){

        int t1 = current.front();current.pop();
        int t2 = current.front();current.pop();
        int t3 = current.front();current.pop();
        int t4 = current.front();current.pop();

        if(t1==e1&&t2==e2&&t3==e3&&t4==e4)break;

        if(valid((t1+1)%10 , t2 , t3 , t4)==true){

            mp[make_pair(make_pair((t1+1)%10 , t2) , make_pair(t3 , t4))] = mp[make_pair(make_pair(t1 , t2) , make_pair(t3 , t4))] + 1;
            current.push((t1+1)%10);
            current.push(t2);
            current.push(t3);
            current.push(t4);
        }


        if(valid((t1-1+10)%10 , t2 , t3 , t4)==true){

            mp[make_pair(make_pair((t1-1+10)%10 , t2) , make_pair(t3 , t4))] = mp[make_pair(make_pair(t1 , t2) , make_pair(t3 , t4))] + 1;
            current.push((t1-1+10)%10);
            current.push(t2);
            current.push(t3);
            current.push(t4);
        }



        if(valid(t1, (t2+1)%10, t3 , t4)==true){

            mp[make_pair(make_pair(t1 , (t2+1)%10) , make_pair(t3 , t4))] = mp[make_pair(make_pair(t1 , t2) , make_pair(t3 , t4))] + 1;
            current.push(t1);
            current.push((t2+1)%10);
            current.push(t3);
            current.push(t4);
        }


        if(valid(t1, (t2-1+10)%10, t3 , t4)==true){

            mp[make_pair(make_pair(t1 , (t2-1+10)%10) , make_pair(t3 , t4))] = mp[make_pair(make_pair(t1 , t2) , make_pair(t3 , t4))] + 1;
            current.push(t1);
            current.push((t2-1+10)%10);
            current.push(t3);
            current.push(t4);
        }


        if(valid(t1 , t2 , (t3+1)%10 , t4)==true){

            mp[make_pair(make_pair(t1 , t2) , make_pair((t3+1)%10 , t4))] = mp[make_pair(make_pair(t1 , t2) , make_pair(t3 , t4))] + 1;
            current.push(t1);
            current.push(t2);
            current.push((t3+1)%10);
            current.push(t4);
        }


        if(valid(t1 , t2 , (t3-1+10)%10 , t4)==true){

            mp[make_pair(make_pair(t1 , t2) , make_pair((t3-1+10)%10 , t4))] = mp[make_pair(make_pair(t1 , t2) , make_pair(t3 , t4))] + 1;
            current.push(t1);
            current.push(t2);
            current.push((t3-1+10)%10);
            current.push(t4);
        }


        if(valid(t1, t2 , t3 , (t4+1)%10)==true){

            mp[make_pair(make_pair(t1 , t2) , make_pair(t3 , (t4+1)%10))] = mp[make_pair(make_pair(t1 , t2) , make_pair(t3 , t4))] + 1;
            current.push(t1);
            current.push(t2);
            current.push(t3);
            current.push((t4+1)%10);
        }


        if(valid(t1, t2 , t3 , (t4-1+10)%10)==true){

            mp[make_pair(make_pair(t1 , t2) , make_pair(t3 , (t4-1+10)%10))] = mp[make_pair(make_pair(t1 , t2) , make_pair(t3 , t4))] + 1;
            current.push(t1);
            current.push(t2);
            current.push(t3);
            current.push((t4-1+10)%10);
        }
    }
}

int main(void)
{
    //freopen("output.txt","w",stdout);
    int t;
    scanf("%d",&t);
    while(t--){

        scanf("%d %d %d %d %d %d %d %d",&s1 , &s2 , &s3 , &s4 , &e1 , &e2 , &e3 , &e4);

        int n;

        mp.clear();

        scanf("%d",&n);

        while(n--){

            int t1 , t2 , t3 , t4;
            scanf("%d %d %d %d",&t1 , &t2 , &t3 , &t4);

            mp[make_pair(make_pair(t1 , t2) , make_pair(t3 , t4))] = -1;
        }

        bfs();

        //mp[make_pair(make_pair(s1 , s2) , make_pair(s3 , s4))] = 0;

        int ans = mp[make_pair(make_pair(e1 , e2) , make_pair(e3 , e4))];
        if(ans==0)ans=-1;

        if(s1==e1&&s2==e2&&s3==e3&&s4==e4)ans = 0;

        printf("%d\n",ans);
    }
    return 0;
}

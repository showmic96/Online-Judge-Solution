// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

const int MAX = 2e5+9;
bool vis[MAX];
int ans[MAX];

bool cmp(pair<int , int>A , pair<int , int>B)
{
    return A.first>B.first;
}

int main(void)
{
    int n , last = 0 , mx = -1;
    scanf("%d",&n);
    vector<pair<int , int> >v(n) , ar(n);
    for(int i=0;i<n;i++){
        int in;
        scanf("%d",&in);
        v[i] = {in , i};
    }
    sort(v.begin() , v.end() , cmp);
    memset(vis , false ,sizeof(vis));

    for(int i=0;i<n;i++){

        int now = v[i].second;
        int val = v[i].first;
        if(now-1>=0&&now+1<n){
            if(vis[now-1]==true&&vis[now+1]==true){
                int t1 = ar[now-1].first;
                int t2 = ar[now+1].second;
                vis[now] = true;
                ar[t1].first = t1;
                ar[t1].second = t2;
                ar[t2].first = t1;
                ar[t2].second = t2;
                mx = max(mx , t2-t1+1);
            }
            else if(vis[now-1]==true){
                int t = ar[now-1].first;
                vis[now] = true;
                ar[now].first = t;
                ar[now].second = now;
                ar[t].first = t;
                ar[t].second = now;
                mx = max(mx , now-t+1);
            }
            else if(vis[now+1]==true){
                int t = ar[now+1].second;
                vis[now] = true;
                ar[now].first = now;
                ar[now].second = t;
                ar[t].first = now;
                ar[t].second = t;
                mx = max(mx , t-now+1);
            }
            else{
                vis[now] = true;
                ar[now].first = now;
                ar[now].second = now;
                mx = max(mx , 1);
            }
        }
        else if(now-1>=0){
            if(vis[now-1]==true){
                int t = ar[now-1].first;
                vis[now] = true;
                ar[now].first = t;
                ar[now].second = now;
                ar[t].first = t;
                ar[t].second = now;
                mx = max(mx , now-t+1);
            }
            else{
                vis[now] = true;
                ar[now].first = now;
                ar[now].second = now;
                mx = max(mx , 1);
            }
        }
        else if(now+1<n){
            if(vis[now+1]==true){
                int t = ar[now+1].second;
                vis[now] = true;
                ar[now].first = now;
                ar[now].second = t;
                ar[t].first = now;
                ar[t].second = t;
                mx = max(mx , t-now+1);
            }
            else{
                vis[now] = true;
                ar[now].first = now;
                ar[now].second = now;
                mx = max(mx , 1);
            }
        }
        else{
            vis[now] = true;
            ar[now].first = now;
            ar[now].second = now;
            mx = max(mx , 1);
        }
        while(last<mx)ans[last++] = val;
    }
    for(int i=0;i<n;i++)printf("%d ",ans[i]);
    return 0;
}

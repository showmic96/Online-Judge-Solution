// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
int ar[5005] , one[5005] , two[5005];

bool cmp(pair<int , int> A , pair<int , int> B)
{
    return A.first<B.first;
}

int main(void)
{
    int n , q , tot=0;
    scanf("%d %d",&n , &q);
    vector<pair<int , int> > v;
    for(int i=0;i<q;i++){
        int in1 , in2;
        scanf("%d %d",&in1 , &in2);
        ar[in1]++;
        ar[in2+1]--;
        v.push_back({in1 , in2});
    }

    for(int i=1;i<=5003;i++){

        ar[i]+=ar[i-1];
        if(ar[i]>0)tot++;
        if(ar[i]==1)one[i]++;
        if(ar[i]==2)two[i]++;

        one[i]+=one[i-1];
        two[i]+=two[i-1];
    }
    sort(v.begin() , v.end() , cmp);
    int ans = 0;
    for(int i=0;i<q;i++){

        for(int j=i+1;j<q;j++){

            int t1 = one[v[i].second]-one[v[i].first-1];
            int t2 = one[v[j].second]-one[v[j].first-1];
            int t3 = 0;

            if(v[j].first<=v[i].second){

                t3 = two[min(v[j].second, v[i].second)]-two[v[j].first-1];
            }

            ans = max(ans , tot-t1-t2-t3);
        }
    }
    printf("%d\n",ans);
    return 0;
}

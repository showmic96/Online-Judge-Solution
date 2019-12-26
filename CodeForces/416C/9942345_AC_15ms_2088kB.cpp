// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

struct myStruct{

    int c , p , id;

    myStruct(int ct , int pt , int idt){

        c = ct;
        p = pt;
        id = idt;
    }
};

bool operator<(myStruct A , myStruct B)
{
    return A.p > B.p;
}

struct data{

    int v , id;

    data(int vt , int idt){

        v = vt;
        id = idt;
    }
};

bool operator<(data A , data B)
{
    return A.v < B.v;
}

bool taken[1005];

int main(void)
{
    int n;
    scanf("%d",&n);
    memset(taken , false, sizeof(taken));
    vector<myStruct>v;

    for(int i=0;i<n;i++){

        int in1 , in2;
        scanf("%d %d",&in1 ,&in2);

        v.push_back(myStruct(in1 , in2 , i+1));
    }

    sort(v.begin() , v.end());

    int m;
    scanf("%d",&m);
    vector<int>d;
    vector<data>d2;

    for(int i=0;i<m;i++){

        int in;
        scanf("%d",&in);
        d.push_back(in);
        d2.push_back(data(in , i+1));
    }

    sort(d.begin() , d.end());
    sort(d2.begin() , d2.end());

    vector<pair<int, int> > ans;

    int total_profit = 0 , total_group = 0;

    for(int i=0;i<n;i++){

        int idx = lower_bound(d.begin() , d.end() , v[i].c) - d.begin();

        for(int j=idx;j<m;j++){

            if(taken[j]==false&&d[j]>=v[i].c){

                //cout << data[j] << " " << v[i].c << " " << v[i].p << endl;

                taken[j] = true;
                ans.push_back(make_pair(v[i].id , d2[j].id));
                total_group++;
                total_profit+=v[i].p;
                break;
            }
        }
    }

    printf("%d %d\n",total_group , total_profit);

    for(int i=0;i<total_group;i++){

        printf("%d %d\n",ans[i].first , ans[i].second);
    }

    return 0;
}

// In the name the Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

struct s{

    int first , second , id;
    s(int _first , int _second , int _id){

        first = _first;
        second = _second;
        id = _id;
    }
};

bool cmp(s A , s B)
{
    if(A.second==B.second){

        return A.id<B.id;
    }
    return A.second > B.second;
}

int main(void)
{
    int n;
    scanf("%d",&n);
    vector<s> v;

    for(int i=0;i<n;i++){

        int in1 , in2;
        scanf("%d %d",&in1 , &in2);
        v.push_back(s(in1 , in2 , i));
    }
    sort(v.begin() , v.end() , cmp);

    for(int i=0;i<n;i++)printf("%d %d\n",v[i].first , v[i].second);

    return 0;
}

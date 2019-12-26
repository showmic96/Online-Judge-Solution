// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

bool cmp(pair<int , int> A , pair<int , int> B)
{
    return A.first<B.first;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int s , n;
    vector<pair<int , int> > v;

    cin >> s >> n;

    for(int i=0;i<n;i++){

        int in1 , in2;
        cin >> in1 >> in2;
        v.push_back(make_pair(in1 , in2));
    }

    sort(v.begin() , v.end() , cmp);
    bool check = true;

    for(int i=0;i<n;i++){

        if(v[i].first>=s){

            check = false;
            break;
        }
        s+=v[i].second;
    }

    if(check==true)cout << "YES" << endl;
    else cout << "NO" << endl;

    return 0;
}

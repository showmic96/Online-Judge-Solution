// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(void)
{
    int n , a , b;
    vector<pair < int , int > > v;
    cin >> n >> a >> b;
    for(int i=0;i<n;i++){

        int in1 , in2;
        cin >> in1 >> in2;
        v.push_back(make_pair(in1 , in2));
    }

    int mx = 0;

    for(int i=0;i<n;i++){

        for(int j=i+1;j<n;j++){

            int x1 = v[i].first;
            int y1 = v[i].second;
            int x2 = v[j].first;
            int y2 = v[j].second;

            int area = (x1*y1) + (x2*y2);

            if(x1<=a&&x2<=a&&y1+y2<=b)mx = max(area , mx);
            if(x1<=a&&y2<=a&&y1+x2<=b)mx = max(area , mx);
            
            if(y1<=a&&y2<=a&&x1+x2<=b)mx = max(area , mx);
            if(y1<=a&&x2<=a&&x1+y2<=b)mx = max(area , mx);
            

            swap(a , b);

            if(x1<=a&&x2<=a&&y1+y2<=b)mx = max(area , mx);
            if(x1<=a&&y2<=a&&y1+x2<=b)mx = max(area , mx);
            
            if(y1<=a&&y2<=a&&x1+x2<=b)mx = max(area , mx);
            if(y1<=a&&x2<=a&&x1+y2<=b)mx = max(area , mx);
            

        }
    }

    cout << mx << endl;


    return 0;
}

// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int n;
    double x , y;
    cin >> n >> x >> y;
    set<double>data;
    for(int i=0;i<n;i++){

        double x_t , y_t;

        cin >> x_t >> y_t;

        if(y-y_t==0)data.insert(0);

        else if(x-x_t==0)data.insert(1e15);

        else data.insert((y-y_t)/(x-x_t));
    }

    cout << data.size() << endl;

    return 0;
}

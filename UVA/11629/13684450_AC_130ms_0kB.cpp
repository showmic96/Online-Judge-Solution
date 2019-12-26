// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

double round(double x)
{
    x*=10;
    x+=0.5;

    int now = floor(x);
    return (double)now/10.00;
}

int main(void)
{
    //ios::sync_with_stdio(0);
    //cin.tie(0);cout.tie(0);

    int n , m;
    cin >> n >> m;

    map<string , double>mp;

    for(int i=0;i<n;i++){

        string ar;
        double in;
        cin >> ar >> in;

        mp[ar] = in;
    }
    scanf("\n");
    for(int i=0;i<m;i++){

        string ar;
        getline(cin , ar);

        string t1 , t2;
        stringstream ss(ar);

        double counter = 0;

        while(ss >> t1){

            counter+=mp[t1];
            ss >> t2;

            if(t2!="+")break;
        }

        double temp;

        ss >> temp;

        temp = round(temp);
        counter = round(counter);

        cout << "Guess #" <<i+1 << " was";
        if(t2=="="){

            if(counter==temp)cout << " correct." << endl;
            else cout << " incorrect." << endl;
        }
        else if(t2=="<"){

            if(counter<temp)cout << " correct." << endl;
            else cout << " incorrect." << endl;
        }

        else if(t2==">"){

            if(counter>temp)cout << " correct." << endl;
            else cout << " incorrect." << endl;
        }

        else if(t2=="<="){

            if(counter<=temp)cout << " correct." << endl;
            else cout << " incorrect." << endl;
        }

        else if(t2==">="){

            if(counter>=temp)cout << " correct." << endl;
            else cout << " incorrect." << endl;
        }
    }

    return 0;
}

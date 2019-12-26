// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int t;
    cin >> t;
    while(t--){

        vector<int>x , y;

        int n;
        cin >> n;

        for(int i=0;i<n;i++){

            string ar;
            cin >> ar;

            if(ar=="p"){

                int in1 , in2;
                cin >> in1 >> in2;

                x.push_back(in1);
                y.push_back(in2);
            }

            if(ar=="c"){

                int in1 , in2 , in3;
                cin >> in1 >> in2 >> in3;

                x.push_back(in1+in3);
                x.push_back(in1-in3);
                y.push_back(in2+in3);
                y.push_back(in2-in3);
            }
            if(ar=="l"){

                int in1 , in2 , in3 , in4;
                cin >> in1 >> in2 >> in3 >> in4;

                x.push_back(in1);
                x.push_back(in3);
                y.push_back(in2);
                y.push_back(in4);
            }
        }

        sort(x.begin() , x.end());
        sort(y.begin() , y.end());

        cout << x[0] << " " << y[0] << " " << x[x.size()-1] << " " << y[y.size()-1] << endl;
    }
    return 0;
}

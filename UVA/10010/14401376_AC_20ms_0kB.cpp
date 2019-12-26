// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

string ar[55];

string get(string temp)
{
    string now = "";
    for(int i=0;i<temp.size();i++){

        if(temp[i]>='A'&&temp[i]<='Z')now+=temp[i] + 32;
        else now+=temp[i];
    }
    return now;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int t;
    cin >> t;
    bool blank = false;

    while(t--){

        if(blank==true)cout << endl;blank = true;

        int n , m;
        cin >> n >> m;

        for(int i=0;i<n;i++){

            cin >> ar[i];
            ar[i] = get(ar[i]);
        }

        int q;
        cin >> q;
        while(q--){

            string in;
            cin >> in;

            in = get(in);

            int i1 = 0 , j1 = 0;
            bool found = false;

            for(int i=0;i<n;i++){

                for(int j=0;j<m;j++){


                    int t = in.size();

                    string temp = "";

                    for(int k=0;k<t;k++){

                        if(j+k>=m)break;
                        temp+=ar[i][j+k];
                    }

                    if(temp==in){

                        i1 = i;
                        j1 = j;
                        found = true;
                        break;
                    }
                    temp = "";

                    for(int k=0;k<t;k++){

                        if(i+k>=n)break;
                        temp+=ar[i+k][j];
                    }

                    if(temp==in){

                        i1 = i;
                        j1 = j;
                        found = true;
                        break;
                    }
                    temp = "";

                    for(int k=0;k<t;k++){

                        if(j+k>=m)break;
                        if(i+k>=n)break;

                        temp+=ar[i+k][j+k];
                    }

                    if(temp==in){

                        i1 = i;
                        j1 = j;
                        found = true;
                        break;
                    }
                    temp = "";

                    for(int k=0;k<t;k++){

                        if(j-k<0)break;
                        temp+=ar[i][j-k];
                    }

                    if(temp==in){

                        i1 = i;
                        j1 = j;
                        found = true;
                        break;
                    }
                    temp = "";

                    for(int k=0;k<t;k++){

                        if(i-k<0)break;
                        temp+=ar[i-k][j];
                    }

                    if(temp==in){

                        i1 = i;
                        j1 = j;
                        found = true;
                        break;
                    }
                    temp = "";

                    for(int k=0;k<t;k++){

                        if(j-k<0)break;
                        if(i-k<0)break;
                        temp+=ar[i-k][j-k];
                    }

                    if(temp==in){

                        i1 = i;
                        j1 = j;
                        found = true;
                        break;
                    }
                    temp = "";

                    for(int k=0;k<t;k++){

                        if(j+k>=m)break;
                        if(i-k<0)break;
                        temp+=ar[i-k][j+k];
                    }

                    if(temp==in){

                        i1 = i;
                        j1 = j;
                        found = true;
                        break;
                    }
                    temp = "";

                    for(int k=0;k<t;k++){

                        if(i+k>=n)break;
                        if(j-k<0)break;
                        temp+=ar[i+k][j-k];
                    }

                    if(temp==in){

                        i1 = i;
                        j1 = j;
                        found = true;
                        break;
                    }
                }
                if(found==true)break;
            }

            cout << i1+1 << " " << j1+1 << endl;
        }
    }

    return 0;
}

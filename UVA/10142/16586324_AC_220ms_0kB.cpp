// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<int>v[10005];
string ar[1005];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int t;
    cin >> t;
    bool blank = false;

    while(t--){

        if(blank==true)cout << endl;blank = true;
        int n;
        cin >> n;

        cin.ignore();
        int now = 1;

        for(int i=0;i<n;i++){

            getline(cin , ar[i+1]);
        }

        string s;
        while(getline(cin , s)){

            if(s=="")break;

            stringstream ss(s);
            int temp;
            v[now].clear();

            while(ss>>temp){

                v[now].push_back(temp);
            }

            now++;
        }

        while(true){

            int vote[25];
            memset(vote , 0 , sizeof(vote));

            for(int i=1;i<now;i++){

                vote[v[i][0]]++;
            }

            int mx = 0 , mi = 1e9 , counter = 0;

            for(int i=0;i<25;i++){

                if(vote[i]>mx){

                    mx = vote[i];
                    counter = 1;
                }
                else if(vote[i]==mx)counter++;
            }

            if(mx>(now-1)/2){

                for(int i=0;i<25;i++){

                    if(vote[i]==mx){

                        cout << ar[i] << endl;
                        break;
                    }
                }
                break;
            }
            else{

                set<int>st;

                for(int i=0;i<25;i++){

                    if(vote[i]>0)st.insert(vote[i]);
                }

                if(st.size()==1){

                    for(int i=0;i<25;i++){

                        if(vote[i]>0)cout << ar[i] << endl;
                    }
                    break;
                }
                else{

                    for(int i=0;i<25;i++){

                        if(vote[i]>0)mi = min(mi , vote[i]);
                    }

                    for(int i=0;i<25;i++){

                        if(vote[i]==mi){

                            for(int j=1;j<now;j++){

                                for(int k=0;k<v[j].size();k++){

                                    if(v[j][k]==i){

                                        v[j].erase(v[j].begin()+k);
                                        break;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    return 0;
}

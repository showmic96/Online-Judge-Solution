// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int ar[4][55];
struct s{

    int i , r , c;
    s(int _i , int _r , int _c){

        i = _i;
        r = _r;
        c = _c;
    }
};

vector<s>v;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int n , k;
    cin >> n >> k;

    for(int i=0;i<4;i++){

        for(int j=0;j<n;j++){

            cin >> ar[i][j];
        }
    }

    while(k){

        bool check = false;

        for(int i=1;i<3;i++){

            for(int j=0;j<n;j++){

                if(ar[i][j]!=0){

                    if(i==1){

                        if(ar[i-1][j]==ar[i][j]){

                            v.push_back(s(ar[i][j] , i-1 , j));
                            k--;ar[i][j] = 0;
                            check = true;
                        }
                    }
                    else{

                        if(ar[i+1][j]==ar[i][j]){

                            v.push_back(s(ar[i][j] , i+1 , j));
                            k--;ar[i][j] = 0;
                            check = true;
                        }
                    }
                }
            }
        }

        for(int i=1;i<3;i++){

            for(int j=0;j<n;j++){

                if(ar[i][j]==0){

                    if(i==1){

                        if(j==0){

                            if(ar[i+1][j]!=0){

                                if(ar[i+1][j]==ar[i+2][j]){

                                    v.push_back(s(ar[i+1][j] , i+2 , j));
                                    k--;ar[i+1][j] = 0;
                                    check = true;
                                }
                                else{

                                    ar[i][j] = ar[i+1][j];
                                    v.push_back(s(ar[i+1][j] , i , j));
                                    ar[i+1][j] = 0;
                                    check = true;
                                }
                            }
                        }
                        else{

                            if(ar[i][j-1]!=0){

                                if(ar[i-1][j-1]==ar[i][j-1]){

                                    v.push_back(s(ar[i-1][j-1] , i-1 , j-1));
                                    k--;ar[i][j-1] = 0;
                                    check = true;
                                }
                                else{

                                    ar[i][j] = ar[i][j-1];
                                    v.push_back(s(ar[i][j-1] , i , j));
                                    ar[i][j-1] = 0;
                                    check = true;
                                }
                            }
                        }
                    }
                    else{

                        if(j==n-1){

                            if(ar[i-1][j]!=0){

                                if(ar[i-1][j]==ar[i-2][j]){

                                    v.push_back(s(ar[i-1][j] , i-2 , j));
                                    ar[i-1][j] = 0;k--;
                                    check = true;
                                }
                                else{

                                    ar[i][j] = ar[i-1][j];
                                    v.push_back(s(ar[i-1][j] , i , j));
                                    ar[i-1][j] = 0;
                                    check = true;
                                }
                            }
                        }
                        else{

                            if(ar[i][j+1]!=0){

                                if(ar[i+1][j+1]==ar[i][j+1]){

                                    v.push_back(s(ar[i+1][j+1] , i+1 , j+1));
                                    ar[i][j+1] = 0;k--;
                                    check = true;
                                }
                                else{

                                    ar[i][j] = ar[i][j+1];
                                    v.push_back(s(ar[i][j+1] , i , j));
                                    ar[i][j+1] = 0;
                                    check = true;
                                }
                            }
                        }
                    }
                }
            }
        }

        if(check==false)break;
    }

    if(!k){
        cout << v.size() << endl;
        for(int i=0;i<v.size();i++)cout << v[i].i << " " << v[i].r+1 << " " << v[i].c+1 << endl;
    }
    else cout << -1 << endl;

    return 0;
}

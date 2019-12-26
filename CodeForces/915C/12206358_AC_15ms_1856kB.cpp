// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string a , b;
    cin >> a >> b;

    int si1 = a.size() , si2 = b.size();

    if(si1<si2){

        sort(a.begin() , a.end());
        reverse(a.begin() , a.end());

        cout << a << endl;
    }

    else{

        string ans = a;
        int fr[10];
        memset(fr , 0 , sizeof(fr));

        for(int i=0;i<si1;i++){

            fr[a[i]-'0']++;
        }

        bool check = true;

        for(int i=0;i<si1;i++){
            int temp = b[i]-'0';

            if(check==false){

                for(int j=9;j>=0;j--){

                    if(fr[j]>0){

                        fr[j]--;
                        ans[i]='0'+j;
                        break;
                    }
                }
            }

            else{

                bool found = false;

                for(int j=temp;j>=0;j--){

                    if(fr[j]>0){

                        found = true;
                        fr[j]--;
                        ans[i]='0'+j;
                        if(j<temp)check = false;
                        break;
                    }
                }

                if(found==false){

                    check = false;

                    for(int j=i-1;j>=0;j--){

                        int t = ans[j]-'0';

                        fr[t]++;

                        bool f = false;

                        for(int k=t-1;k>=0;k--){

                            if(fr[k]>0){

                                f = true;
                                fr[k]--;
                                ans[j]='0'+k;
                                break;
                            }
                        }

                        if(f==true){
                            i = j;
                            break;
                        }
                    }
                }
            }
        }

        cout << ans << endl;
    }

    return 0;
}
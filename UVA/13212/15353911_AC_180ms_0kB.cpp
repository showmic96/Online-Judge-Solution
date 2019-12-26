// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll inv;

void Merge(int A[] , int p , int q , int r)
{
    int n1 = q-p+1;
    int n2 = r-q;

    int L[n1+5] , R[n2+5];
    for(int i=1;i<=n1;i++){

        L[i] = A[p+i-1];
    }
    for(int i=1;i<=n2;i++){

        R[i] = A[q+i];
    }

    L[n1+1] = 1e9;
    R[n2+1] = 1e9;
    int i = 1 , j = 1;
    for(int k=p;k<=r;k++){

        if(L[i]<=R[j]){

            A[k] = L[i];
            i = i+1;
        }
        else{

            A[k]=R[j];
            j = j+1;
            inv = inv+n1-i+1;
        }
    }
}

void MergeSort(int A[] , int p , int r)
{
    if(p<r){

        int q = (p+r)/2;
        MergeSort(A , p , q);
        MergeSort(A , q+1 , r);
        Merge(A , p , q , r);
    }
}

int main(void)
{
    int n;
    while(scanf("%d",&n)==1){

        if(n==0)break;
        int ar[n+10];

        inv = 0;

        for(int i=1;i<=n;i++){

            int in;
            scanf("%d",&ar[i]);
        }

        MergeSort(ar , 1 , n);

        printf("%lld\n",inv);
    }

    return 0;
}

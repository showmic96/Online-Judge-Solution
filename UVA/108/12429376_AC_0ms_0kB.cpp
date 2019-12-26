// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

int n;
int M[105][105];

int kadane(int* arr, int* start, int* finish, int n)
{

    int sum = 0, maxSum = INT_MIN, i;
    *finish = -1;

    int local_start = 0;

    for (i = 0; i < n; ++i)
    {
        sum += arr[i];
        if (sum < 0)
        {
            sum = 0;
            local_start = i+1;
        }
        else if (sum > maxSum)
        {
            maxSum = sum;
            *start = local_start;
            *finish = i;
        }
    }

    if (*finish != -1)
        return maxSum;

    maxSum = arr[0];
    *start = *finish = 0;

    for (i = 1; i < n; i++)
    {
        if (arr[i] > maxSum)
        {
            maxSum = arr[i];
            *start = *finish = i;
        }
    }
    return maxSum;
}


int findMaxSum()
{

    int maxSum = INT_MIN, finalLeft, finalRight, finalTop, finalBottom;

    int left, right, i;
    int temp[n], sum, start, finish;

    for (left = 0; left < n; ++left)
    {

        memset(temp, 0, sizeof(temp));


        for (right = left; right < n; ++right)
        {

            for (i = 0; i < n; ++i)
                temp[i] += M[i][right];

            sum = kadane(temp, &start, &finish, n);

            if (sum > maxSum)
            {
                maxSum = sum;
            }
        }
    }

    return maxSum;
}

int main(void)
{
    while(scanf("%d",&n)==1){

        for(int i=0;i<n;i++){

            for(int j=0;j<n;j++){

                scanf("%d",&M[i][j]);
            }
        }

        printf("%d\n",findMaxSum());
    }
    return 0;
}

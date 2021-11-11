    #include<bits/stdc++.h>
    using namespace std;
    bool findPartition(int a[], int n) 
    {
        int sum = 0;
        int i, j;
        for (i = 0; i < n; i++) 
        sum += a[i];
        if (sum % 2 != 0) 
        return false;
        bool subset[2][sum + 1];
        for (i = 0; i <= n; i++) 
        {
            for (j = 0; j <= sum; j++) 
            {
                if (j == 0) 
                subset[i % 2][j] = true;
                else if (i == 0)
                    subset[i % 2][j] = false;
                else if (a[i - 1] <= j)
                    subset[i % 2][j] =
                        subset[(i + 1) % 2][j - a[i - 1]] || subset[(i + 1) % 2][j];
                else
                    subset[i % 2][j] = subset[(i + 1) % 2][j];
            }
        }
        return subset[n % 2][sum / 2];
    }
    int main()
    {
        int n;
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }
        if(findPartition(a,n)==false)
        {
            cout<<"No"<<endl;
        }
        else
        cout<<"Yes"<<endl;
    }
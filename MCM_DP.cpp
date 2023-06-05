#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int MatrixChainMultiplication(const vector<int>& dims)
{
    int n = dims.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));

    for (int length = 2; length < n; length++)
    {
        for (int i = 1; i < n - length + 1; i++)
        {
            int j = i + length - 1;
            dp[i][j] = INT_MAX;

            for (int k = i; k < j; k++)
            {
                int cost = dp[i][k] + dp[k + 1][j] + dims[i - 1] * dims[k] * dims[j];
                if (cost < dp[i][j])
                    dp[i][j] = cost;
            }
        }
    }

    return dp[1][n - 1];
}

int main()
{
    int numMatrices;
    cout << "Enter the number of matrices: ";
    cin >> numMatrices;

    vector<int> dimensions(numMatrices + 1);

    cout << "Enter the dimensions of the matrices: \n";
    int rt, ct;
    for (int i = 0; i < numMatrices; i++)
    {
        cout << "Input the number of Rows, Columns for matrix " << i + 1 << ": ";
        cin >> rt >> ct;
        if (i == 0)
        {
            dimensions[i] = rt;
            dimensions[i + 1] = ct;
        }
        else
        {
            dimensions[i + 1] = ct;
        }
    }

    int minMultiplications = MatrixChainMultiplication(dimensions);

    cout << "Minimum number of multiplications required: " << minMultiplications << endl;

    return 0;
}

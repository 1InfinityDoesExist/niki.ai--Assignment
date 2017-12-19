#include<bits/stdc++.h>
using namespace std;

class Solution
{
private:
public:
    Solution();
    unsigned long long int task(unsigned long long int n);
};
Solution::Solution(){}
void multiplyFunction(unsigned long long int matrix1[2][2], unsigned long long int matrix2[2][2])
{
    unsigned long long int x = (matrix1[0][0] * matrix2[0][0])%1000000007 + (matrix1[0][1] * matrix2[1][0])%1000000007;
    unsigned long long int y = (matrix1[0][0] * matrix2[0][1])%1000000007 + (matrix1[0][1] * matrix2[1][1])%1000000007;
    unsigned long long int z = (matrix1[1][0] * matrix2[0][0])%1000000007 + (matrix1[1][1] * matrix2[1][0])%1000000007;
    unsigned long long int w = (matrix1[1][0] * matrix2[0][1])%1000000007 + (matrix1[1][1] * matrix2[1][1])%1000000007;

    matrix1[0][0] = x;
    matrix1[0][1] = y;
    matrix1[1][0] = z;
    matrix1[1][1] = w;
}
void power(unsigned long long int matrix1[2][2] , const unsigned long long int n)
{
    if(n == 0 || n == 1)
    {
        return;
    }
    unsigned long long int matrix2[2][2] = { {1, 1}, {1, 0} };
    power(matrix1, n/2);
    multiplyFunction(matrix1, matrix1);
    if(n%2 != 0)
    {
        multiplyFunction(matrix1, matrix2);
    }
}
unsigned long long int Solution::task(unsigned long long int n)
{
    unsigned long long int matrix[2][2] = { {1, 1}, {1, 0} };
    if(n == 0)
    {
        return 0;
    }
    if(n == 1)
    {
        return 2;
    }
    if(n == 2)
    {
        return 3;
    }
    power(matrix, n-2);
    return (matrix[0][0]*3 + matrix[0][1]*2)%1000000007;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Solution sol;
    int testCase;
    cin >> testCase;
    while(testCase--)
    {
        unsigned long long int n;
        cin >> n;
        unsigned long long int ans = sol.task(n);
        cout << ans << endl;
    }
    return 0;
}

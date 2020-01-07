using namespace std;
#include<bits/stdc++.h>
typedef long long int ll;

#define MOD 1000000007

struct Matrix
{
    int n, m;
    vector <vector <int>> mat;

    Matrix() {}

    Matrix(int _n, int _m)
    {
        n = _n, m = _m;
        mat = vector <vector <int>> (n, vector <int> (m));
    }

    void print()
    {
        cout << "MATRIX :: " << n << " " << m << endl;
        for(int i = 0; i < n; ++i)
        {
            for(int j = 0; j < m; ++j)
                printf("%d ", mat[i][j]);
            printf("\n");
        }
    }
    };

Matrix Multiply(Matrix a, Matrix b, int Mod)
{
    Matrix c = Matrix(a.n, b.m);
    for(int i = 0; i < a.n; ++i)
    {
        for(int j = 0; j < b.m; ++j)
        {
            c.mat[i][j] = 0;
            for(int k = 0; k < a.m; ++k)
            {
                c.mat[i][j] += (1LL * a.mat[i][k] * b.mat[k][j]) % Mod;
                c.mat[i][j] %= Mod;
            }
        }
    }
    return c;
}

Matrix Add(Matrix a, Matrix b, int Mod) {
    Matrix c = Matrix(a.n, a.n);
    for(int i = 0; i < a.n; ++i)
    {
        for(int j = 0; j < a.n; ++j)
        {
            c.mat[i][j] = a.mat[i][j] + b.mat[i][j];
            c.mat[i][j] %= Mod;
        }
    }
    return c;
}

Matrix Pow(Matrix a, ll p, int Mod) {
    if(p == 1)
        return a;

    Matrix x = Pow(a, p/2, Mod);

    x = Multiply(x, x, Mod);
    if(p&1)
        x = Multiply(x, a, Mod);

    return x;
}

ll calc(ll n)
{
    if(n < 2)
        return 1;

    Matrix M = Matrix(2, 2);
    M.mat[0][0] = 1;
    M.mat[0][1] = 1;
    M.mat[1][0] = 1;
    M.mat[1][1] = 0;
    
    Matrix A = Matrix(2, 1);
    A.mat[0][0] = 1;
    A.mat[1][0] = 0;
    
    M = Pow(M, n-1, MOD);
    M = Multiply(M, A, MOD);
    
    return (M.mat[0][0] + M.mat[1][0]) % MOD;
}

int main()
{
    ll n, m, x, y, t;

    cin >> t;
    while(t--)
    {
        cin >> n >> m;
        x = calc(n)-1;
        y = calc(m+1)-1;
        cout << (y - x + MOD) % MOD << endl;
    }

    return 0;
}

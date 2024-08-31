#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

// Fix the member variable references
#define a matrix

class Matrix {
public:
    vector<vector<int>> matrix;

    Matrix operator+(const Matrix& other) {
        Matrix result;

        int n = matrix.size();
        int m = matrix[0].size();

        for (int i = 0; i < n; i++) {
            vector<int> row;

            for (int j = 0; j < m; j++) {
                row.push_back(matrix[i][j] + other.matrix[i][j]);
            }
            result.matrix.push_back(row);
        }

        return result;
    }
};

int main() {
    int cases, k;
    cin >> cases;
    for (k = 0; k < cases; k++) {
        Matrix x;
        Matrix y;
        Matrix result;
        int n, m, i, j;
        cin >> n >> m;
        for (i = 0; i < n; i++) {
            vector<int> b;
            int num;
            for (j = 0; j < m; j++) {
                cin >> num;
                b.push_back(num);
            }
            x.a.push_back(b);  // Now 'a' refers to 'matrix'
        }
        for (i = 0; i < n; i++) {
            vector<int> b;
            int num;
            for (j = 0; j < m; j++) {
                cin >> num;
                b.push_back(num);
            }
            y.a.push_back(b);  // Now 'a' refers to 'matrix'
        }
        result = x + y;
        for (i = 0; i < n; i++) {
            for (j = 0; j < m; j++) {
                cout << result.a[i][j] << " ";  // Now 'a' refers to 'matrix'
            }
            cout << endl;
        }
    }
    return 0;
}

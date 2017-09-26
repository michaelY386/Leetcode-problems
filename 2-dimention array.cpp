#include <iostream>
#include <cstdio>
#include <vector>
#include <cstdlib>

using namespace std;

void Traverse(int direction, int i, int j, vector<vector<int>>& matrix,
            vector<vector<int>>& flag) {
    const int dx[] = {0, 1, 0, -1};
    const int dy[] = {1, 0, -1, 0};
    int m = matrix.size();
    int n = matrix[0].size();

    if (flag[i][j] || i < 0 || j < 0 || i >= m || j >= n) {
        return;
    }

    while (!flag[i][j] && j < n && i < m
            & j >= 0 && i >= 0) {
        flag[i][j] = 1;
        printf("%d ", matrix[i][j]);
        i+=dx[direction];
        j+=dy[direction];
    }
    i-=dx[direction];
    j-=dy[direction];
    direction = (direction + 1) % 4;
    i+=dx[direction];
    j+=dy[direction];

    Traverse(direction, i, j, matrix, flag);
}


int main() {
    //given a vector<vector<int>> matrix
    vector<vector<int>> matrix;
    int m = matrix.size();
    int n = matrix[0].size();

    vector<vector<int>> flag(m + 1, vector<int>(n + 1, 0));

    Traverse(0, 0, 0, matrix, flag);
}

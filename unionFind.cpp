vector<long long> fa;

//union_find
long long find(long long x) {
    if (fa[x] != x) {
        fa[x] = find(fa[x]);
    }    
    return fa[x];
}

void uJoin(long long x, long long y) {
    int fx = find(x);
    int fy = find(y);
    if (fx != fy) {
        fa[fx] = fy;    
    }
}

int solution(vector< vector<int> > &A) {
    // write your code in C++14 (g++ 6.2.0)
    int res = 0, k, down, right;
    long long tmp;
    int M = A.size(), N = A[0].size();
    fa.resize(M * N + 1, 0);

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            tmp = N * i + j;
            fa[tmp] = tmp;
        }
    }

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            k = A[i][j];
            down = i + 1, right = j + 1;
            if (down < M && A[down][j] == k) {
                uJoin(N * i + j, N * down + j);
            }
            if (right < N && A[i][right] == k) {
                uJoin(N * i + j, N * i + right);
            }
        }    
    }
    
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            tmp = N * i + j;
            if (fa[tmp] == tmp) res++;
        }
    }
    return res;   
}



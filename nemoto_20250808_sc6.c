#include <stdio.h>


int dfs(int x, int y);      // 深さ優先探索アルゴリズム関数

#define SIZE 5  //マップ作成時、チェック用配列数
int map[SIZE][SIZE] = {
    {0, 1, 0, 0, 0},
    {0, 1, 0, 1, 0},
    {0, 0, 0, 1, 0},
    {1, 1, 1, 1, 0},
    {0, 0, 0, 0, 0}
};

int visited[SIZE][SIZE] = {0};

// 上下左右の移動方向
int dx[4] = {0, 0, -1, 1};  // 左右
int dy[4] = {-1, 1, 0, 0};  // 上下


int main() {
    if (dfs(0, 0)) {
        printf("able\n");
    } else {
        printf("disable\n");
    }

    return 0;
}

// 深さ優先探索(アルゴリズムを理解できていないため、この関数はAIがメインで作成しています)
int dfs(int x, int y) {

    int nx;    //次の探索箇所に使用する変数
    int ny;    //次の探索箇所に使用する変数
    int i;    //次の探索箇所に使用する変数

    // 範囲外ならdisableを返す
    if (x < 0 || x >= SIZE || y < 0 || y >= SIZE) {
        return 0;
    }
    //障害物、訪問済みならdisableを返す
    if (map[y][x] == 1 || visited[y][x]){
         return 0;
    }
    // ゴールに到達
    if (x == 4 && y == 4) {
        return 1;
    }
    //訪れた個所にチェックをつける
    visited[y][x] = 1;

    // 4方向に探索
    for (i = 0; i < 4; i++) {
        nx = x + dx[i];
        ny = y + dy[i];
        if (dfs(nx, ny)) {
            return 1; // 到達できたらすぐに成功
        }
    }

    return 0;
}

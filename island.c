695. 岛屿的最大面积

https://leetcode-cn.com/problems/max-area-of-island/


//BFS
typedef struct {
    int x;
    int y;
} Position;

Position queue[2500];

int px[4] = {-1, 1, 0, 0};
int py[4] = {0, 0, -1, 1};

int maxAreaOfIsland(int** grid, int gridSize, int* gridColSize)
{
    int i, j, k;
    Position tmp;
    int index = -1;
    int trail = 0;

    int max = 0;
    int count = 0;

    int row = gridSize;
    int col = gridColSize[0];

    for (i = 0; i < row; i++) {
        for (j = 0; j < col; j++) {
            if (grid[i][j] == 1) {
                index++;
                queue[index].x = i;
                queue[index].y = j;
                grid[i][j] = '*';
                count++;

                while (trail <= index) {
                    tmp = queue[trail++];

                    for (k = 0; k < 4; k++) {
                        if (((tmp.x + px[k] >= 0) && (tmp.y + py[k] >= 0) && (tmp.x + px[k] < row) && (tmp.y + py[k] < col)) &&
                            (grid[tmp.x + px[k]][tmp.y + py[k]] == 1)) {
                            index++;
                            queue[index].x = tmp.x + px[k];
                            queue[index].y = tmp.y + py[k];
                            grid[tmp.x + px[k]][tmp.y + py[k]] = -1;
                            count++;
                        }
                    }
                }

                index = -1;
                trail = 0;
                max = max > count ? max : count;
                count = 0;
            }
        }
    }

    return max;
}
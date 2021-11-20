
200. 岛屿数量

https://leetcode-cn.com/problems/number-of-islands/


typedef struct {
    int x;
    int y;
} Position;

Position queue[90000] = {0};
int numIslands(char** grid, int gridSize, int* gridColSize)
{
    int row = gridSize;
    int col = gridColSize[0];

    int islandCnt = 0;
    Position tmp;
    int index = -1;
    int trail = 0;

    int i, j;

    for (i = 0; i < row; i++) {
        for (j = 0; j < col; j++) {
            if (grid[i][j] == '0') {
                continue;
            }

            islandCnt++;
            grid[i][j] = '0';

            index++;
            queue[index].x = i;
            queue[index].y = j;

            while (trail <= index) {
                tmp = queue[trail++];
                if ((tmp.x + 1 < row) && (grid[tmp.x + 1][tmp.y] == '1')) {
                    index++;
                    queue[index].x = tmp.x + 1;
                    queue[index].y = tmp.y;
                    grid[tmp.x + 1][tmp.y] = '0';
                }

                if ((tmp.x - 1 >= 0) && (grid[tmp.x - 1][tmp.y] == '1')) {
                    index++;
                    queue[index].x = tmp.x - 1;
                    queue[index].y = tmp.y;
                    grid[tmp.x - 1][tmp.y] = '0';
                }

                if ((tmp.y + 1 < col) && (grid[tmp.x][tmp.y + 1] == '1')) {
                    index++;
                    queue[index].x = tmp.x;
                    queue[index].y = tmp.y + 1;
                    grid[tmp.x][tmp.y + 1] = '0';
                }

                if ((tmp.y - 1 >= 0) && (grid[tmp.x][tmp.y - 1] == '1')) {
                    index++;
                    queue[index].x = tmp.x;
                    queue[index].y = tmp.y - 1;
                    grid[tmp.x][tmp.y - 1] = '0';
                }
            }

            trail = 0;
            index = -1;
        }
    }

    return islandCnt;
}







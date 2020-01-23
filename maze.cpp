
#include<bits/stdc++.h>
using namespace std;

#define MAX 50
#define X_MAX MAX
#define Y_MAX MAX

int Map[X_MAX][Y_MAX];



#define MA 10   //迷宫的规模不能过小

//挖洞法造迷宫，为了包围，只能为奇数行列,过小的地图无法生成迷宫
#if MA<5
#undef  MA
#define MA 6
#endif
#if !(MA%2)
#define  M (MA+1)
#else
#define  M MA
#endif

using namespace std;


//迷宫格子类型，记录了是否被挖过
class Grid {

public:
    //是否访问 是否为空
    bool cell, dig;
    int em;

};
struct Node
{
    int X, Y;

    bool operator==(const Node& n)
    {
        return (this->X == n.X) && (this->Y == n.Y);
    }

};


Grid maze[M][M];

#pragma region 网上抄的一段挖洞法造迷宫，懒得自己弄


//用来存放路径的栈
stack<int> row_s, col_s;


//初始化迷宫格子
void Init() {

    for (int i = 0; i < M; i++) {

        for (int j = 0; j < M; j++) {

            maze[i][j].dig = false;

            if (i % 2 != 0 && j % 2 != 0)

                maze[i][j].cell = true;
        }

    }

    row_s.push(1);    col_s.push(1);

    srand(static_cast<unsigned int> (time(0)));

    maze[1][0].cell = true;

    maze[M - 2][M - 1].cell = true;



}

//判断周围情况，没有可挖的格子时返回-1
int DirRand() {

    vector <int> dirlist;        //用来记录可选择的方向

    int result = 0;
    int row = row_s.top(), col = col_s.top();

    //0 up, 1 down, 2 left, 3 right
    if (row - 2 > 0 && !maze[row - 2][col].dig)
        dirlist.push_back(0);

    if (row + 2 < M - 1 && !maze[row + 2][col].dig)
        dirlist.push_back(1);

    if (col - 2 > 0 && !maze[row][col - 2].dig)
        dirlist.push_back(2);

    if (col + 2 < M - 1 && !maze[row][col + 2].dig)
        dirlist.push_back(3);

    if (dirlist.size() == 0)
        result = -1;
    else
        result = dirlist[rand() % ((int)dirlist.size())];
    return
        result;

}
//制造迷宫
void GenMaze() {

    while (!row_s.empty() && !col_s.empty()) {
        int dir = DirRand();
        int row = row_s.top(), col = col_s.top();

        if (dir != -1) {     //前进

            if (dir == 0) {

                maze[row - 2][col].dig = maze[row - 1][col].dig = true;

                row_s.push(row - 2);
                col_s.push(col);

            }
            else if (dir == 1) {

                maze[row + 2][col].dig = maze[row + 1][col].dig = true;

                row_s.push(row + 2);
                col_s.push(col);

            }
            else if (dir == 2) {

                maze[row][col - 2].dig = maze[row][col - 1].dig = true;

                row_s.push(row);
                col_s.push(col - 2);

            }
            else if (dir == 3) {

                maze[row][col + 2].dig = maze[row][col + 1].dig = true;

                row_s.push(row);

                col_s.push(col + 2);
            }
        }
        else {

            row_s.pop();
            col_s.pop();        //后退

        }

    }

}
//输出迷宫
void OutMaze() {      //输出迷宫

    for (int i = 0; i < M; i++) {

        for (int j = 0; j < M; j++) {
            if (maze[i][j].em == 3) {
                printf("%2c", '*');
                continue;
            }
            if (maze[i][j].cell || maze[i][j].dig) {
                printf("%2c", ' ');
                if (maze[i][j].em != 3)
                    maze[i][j].em = true;
            }
            else {

                //为了保证对齐，墙壁和道路宽都是2个字符
                cout << "■";
                if (maze[i][j].em != 3)
                    maze[i][j].em = false;
            }
        }
        cout << endl;
    }
}

//保存迷宫路径
stack<Node> path;

//已经查找的点
vector<Node> closelist;

//查看该点是否查找过 返回1在  返回0不在
bool FindCloseList(Node n)
{
    auto var = find(closelist.begin(), closelist.end(), n);
    return !(var == closelist.end());
}


#pragma endregion

//该函数可以抠出来放在自己程序，需要地图地图数组 起始坐标(beginX,beginY)终点坐标(endX,endY)，结果保留在一个栈中
//有待优化 在迷宫有环的时候，找到的路径不一定是最短的，问题先放在这，以后有时间再想办法
//返回>1为找到  返回0为没找到
int FindMaze(int beginX, int beginY, int endX, int endY) {

    int kbz = 1;
    //待查找的节点
    stack<Node> lopenlist;
    //节点不在地图范围
    if (beginX < 0 || beginY < 0 || beginX >= M || beginY >= M)
        return 0;
    //起始点加入寻找列表
    closelist.push_back({ beginX,beginY });

    //找到节点
    if ((beginX == endX) && (beginY == endY)) {
        //将该节点添加到路径
        path.push({ beginX,beginY });
        return 1;
    }
#pragma region 查找目标节点周围四个节点，如果要增加斜线功能，可以在此添加

    //检查(beginX,beginY+1)节点
    if (beginY + 1 < M  && maze[beginX][beginY + 1].em == 1) {
        //该节点没找过 加入待查找节点列表
        if (!FindCloseList({ beginX,beginY + 1 })) {

            lopenlist.push({ beginX,beginY + 1 });
        }
    }
    //检查(beginX,beginY-1)节点
    if (beginY - 1 >= 0 && maze[beginX][beginY - 1].em == 1)
    {
        if (!FindCloseList({ beginX,beginY - 1 })) {

            lopenlist.push({ beginX,beginY - 1 });
        }
    }
    //检查(beginX-1,beginY)节点
    if (beginX - 1 >= 0 && maze[beginX - 1][beginY].em == 1) {

        if (!FindCloseList({ beginX - 1,beginY })) {

            lopenlist.push({ beginX - 1,beginY });
        }
    }
    //检查(beginX+1,beginY)节点
    if (beginX + 1 < M  &&maze[beginX + 1][beginY].em == 1) {
        if (!FindCloseList({ beginX + 1,beginY })) {

            lopenlist.push({ beginX + 1,beginY });

        }
    }
#pragma endregion

    //遍历每一个待查找的节点
    while (!lopenlist.empty())
    {
        //取出一个节点
        int x = lopenlist.top().X;
        int y = lopenlist.top().Y;
        lopenlist.pop();
        //递归查找
        auto k = FindMaze(x, y, endX, endY);
        //找到就证明该节点为路径点，加入路径栈中
        if (k)
        {
            path.push({ beginX,beginY });
            return kbz + k;
        }
    }
    return 0;
}



int main() {
    //初始化
    Init();
    //制造迷宫
    GenMaze();
    //输出迷宫
    OutMaze();
    //寻找路径
    if (!FindMaze(1, 0, M - 2, M - 1))
    {
        cout << "没找到出口";
        return -1;
    }
    //依次从栈中取出每一个路径
    while (!path.empty())
    {
        cout << "(" << path.top().X << "," << path.top().Y << ")";
        maze[path.top().X][path.top().Y].em = 3;
        path.pop();
        if (!path.empty())
            cout << ",";
    }
    cout << endl;
    cout << "--------------------------------------------" << endl;

    OutMaze();
    system("pause");
    return 0;

}

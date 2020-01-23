
#include<bits/stdc++.h>
using namespace std;

#define MAX 50
#define X_MAX MAX
#define Y_MAX MAX

int Map[X_MAX][Y_MAX];



#define MA 10   //�Թ��Ĺ�ģ���ܹ�С

//�ڶ������Թ���Ϊ�˰�Χ��ֻ��Ϊ��������,��С�ĵ�ͼ�޷������Թ�
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


//�Թ��������ͣ���¼���Ƿ��ڹ�
class Grid {

public:
    //�Ƿ���� �Ƿ�Ϊ��
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

#pragma region ���ϳ���һ���ڶ������Թ��������Լ�Ū


//�������·����ջ
stack<int> row_s, col_s;


//��ʼ���Թ�����
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

//�ж���Χ�����û�п��ڵĸ���ʱ����-1
int DirRand() {

    vector <int> dirlist;        //������¼��ѡ��ķ���

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
//�����Թ�
void GenMaze() {

    while (!row_s.empty() && !col_s.empty()) {
        int dir = DirRand();
        int row = row_s.top(), col = col_s.top();

        if (dir != -1) {     //ǰ��

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
            col_s.pop();        //����

        }

    }

}
//����Թ�
void OutMaze() {      //����Թ�

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

                //Ϊ�˱�֤���룬ǽ�ں͵�·����2���ַ�
                cout << "��";
                if (maze[i][j].em != 3)
                    maze[i][j].em = false;
            }
        }
        cout << endl;
    }
}

//�����Թ�·��
stack<Node> path;

//�Ѿ����ҵĵ�
vector<Node> closelist;

//�鿴�õ��Ƿ���ҹ� ����1��  ����0����
bool FindCloseList(Node n)
{
    auto var = find(closelist.begin(), closelist.end(), n);
    return !(var == closelist.end());
}


#pragma endregion

//�ú������Կٳ��������Լ�������Ҫ��ͼ��ͼ���� ��ʼ����(beginX,beginY)�յ�����(endX,endY)�����������һ��ջ��
//�д��Ż� ���Թ��л���ʱ���ҵ���·����һ������̵ģ������ȷ����⣬�Ժ���ʱ������취
//����>1Ϊ�ҵ�  ����0Ϊû�ҵ�
int FindMaze(int beginX, int beginY, int endX, int endY) {

    int kbz = 1;
    //�����ҵĽڵ�
    stack<Node> lopenlist;
    //�ڵ㲻�ڵ�ͼ��Χ
    if (beginX < 0 || beginY < 0 || beginX >= M || beginY >= M)
        return 0;
    //��ʼ�����Ѱ���б�
    closelist.push_back({ beginX,beginY });

    //�ҵ��ڵ�
    if ((beginX == endX) && (beginY == endY)) {
        //���ýڵ���ӵ�·��
        path.push({ beginX,beginY });
        return 1;
    }
#pragma region ����Ŀ��ڵ���Χ�ĸ��ڵ㣬���Ҫ����б�߹��ܣ������ڴ����

    //���(beginX,beginY+1)�ڵ�
    if (beginY + 1 < M  && maze[beginX][beginY + 1].em == 1) {
        //�ýڵ�û�ҹ� ��������ҽڵ��б�
        if (!FindCloseList({ beginX,beginY + 1 })) {

            lopenlist.push({ beginX,beginY + 1 });
        }
    }
    //���(beginX,beginY-1)�ڵ�
    if (beginY - 1 >= 0 && maze[beginX][beginY - 1].em == 1)
    {
        if (!FindCloseList({ beginX,beginY - 1 })) {

            lopenlist.push({ beginX,beginY - 1 });
        }
    }
    //���(beginX-1,beginY)�ڵ�
    if (beginX - 1 >= 0 && maze[beginX - 1][beginY].em == 1) {

        if (!FindCloseList({ beginX - 1,beginY })) {

            lopenlist.push({ beginX - 1,beginY });
        }
    }
    //���(beginX+1,beginY)�ڵ�
    if (beginX + 1 < M  &&maze[beginX + 1][beginY].em == 1) {
        if (!FindCloseList({ beginX + 1,beginY })) {

            lopenlist.push({ beginX + 1,beginY });

        }
    }
#pragma endregion

    //����ÿһ�������ҵĽڵ�
    while (!lopenlist.empty())
    {
        //ȡ��һ���ڵ�
        int x = lopenlist.top().X;
        int y = lopenlist.top().Y;
        lopenlist.pop();
        //�ݹ����
        auto k = FindMaze(x, y, endX, endY);
        //�ҵ���֤���ýڵ�Ϊ·���㣬����·��ջ��
        if (k)
        {
            path.push({ beginX,beginY });
            return kbz + k;
        }
    }
    return 0;
}



int main() {
    //��ʼ��
    Init();
    //�����Թ�
    GenMaze();
    //����Թ�
    OutMaze();
    //Ѱ��·��
    if (!FindMaze(1, 0, M - 2, M - 1))
    {
        cout << "û�ҵ�����";
        return -1;
    }
    //���δ�ջ��ȡ��ÿһ��·��
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

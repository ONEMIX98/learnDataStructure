/* 用顺序存储结构（数组）存储，操作数据 */

/* 定义顺序结构 */
typedef int Position;
typedef struct LNode *List;
struct LNode{
	ElementType Data[MaxSize];
	Position Last;
};

/* 初始化 */
List MakeEmpty() /* 输出指向顺序存储结构的指针 */
{
	List L;

	L = (List)malloc(sizeof(struct LNode));
	L->Last = -1; /* -1表示初始化的数组没有元素，
					实际值创建后自行设定（注意Last与MaxSize不等价） */ 
                                                  
	return L;
}

/* 根据值查找 */
#define ERROR -1

Position Find(List L, ElementType X)
{
	Position i;

	while(i <= L->Last && L->Data[i] == X)
	{
		i++;
	}

	if (i > L->Last) return ERROR; /*如果没找到返回错误信息*/
	else return i; /* 找到后返回的是存储位置 */
}

/* 插入 */

bool insert( List L, ElementType X, Position P )
{
/* 在L的指定位置P之前插入X, 注意P，Last都是数组下标 */
	Position i;
	if (L->Last == MaxSize - 1) /* 判断是否表满 */		
	{
		printf("表满\n");
		return false;
	}

	if (P < 0 || P > L->Last + 1) /* 判断位置是否合法，注意插入元素应与原元素连续 */
	{
		printf("位置不合法\n");
		return false;
	}
	for (i = L->Last; i >= P; i--) /* 从最后一个元素开始操作 */
	{
		L->Data[i+1] = L->Data[i]; /* P及之后的元素依次往后挪 */
	}
	L->Data[P] = X; /* 插入新元素X */
	L->Last++; /* Last依然应为最后一个元素的位置*/
	return true;
}	

/* 删除 */
bool Delete( List L, Position P)
{
	Position i;
	if (P < 0 || P >= L->Last+1) /* 检查位置合法性 */
	{
		printf("位置%d没有元素\n", P);
		return false;
	}
	for (i = P+1; i <= L->Last; i++)
		L->Data[i+1] = L->Data[i]; /* 把P+1及之后的元素依次向前挪一位*/
	L->Last--; /* Last仍指向最后元素 */
	return true;
}	

/* 用链式存储结构存储数据 */

/* 定义链式存储结构 */
typedef struct LNode *List;

/* ？？？怎样让List Next储存下一个节点的地址？ */
struct LNode
{
	ElementType Data;
	List Next; 
};

struct LNode L;
List PtrL; /* List 是指向LNode结构的指针类型，PtrL是指向LNode的指针实例 */

/* 求表长 */
int Length (List PtrL)
{
	List p = PtrL; /* p指向表的第一个结点,注意PtrL储存的是第一个结点的地址，而不是自己的地址！ */
	int j = 0;
	while(p) /* 循环条件：p指向最后一个元素 */
	{
		p = p->Next;
		j++; /* 当前p指向的是第j个结点 */
	}
	return j;
}

/* 按序号查找：FindKth,找到了就返回指向该节点的指针，没找着就返回空指针 */
List FindKth(int K, List PtrL)
{
	List p = PtrL;
	int i = 1;
	while(p != NULL && i < K){
		p = p->Next;
		i++;
	}
	if( i == K ) return p;
				/* 找到第K个，返回指针 */
	else return NULL;
				/* 否则返回空 */
}

/* 按值查找 */
List Find(ElementType X, List PtrL)
{
	List p = PtrL;
	while (p != NULL && p->Data != X)
		p = p->Next;
	return p; /* 找到就返回指针，没找到就返回空指针 */
}

/* 插入:输入链表头指针，插入数据和插入位置，输出插入后的链表头指针 */
/* 把新节点插在i-1个节点之后 */
Link Insert(List PtrL, ElementType X, int i)
{
	List s, p;
	if ( i == 1) /* 如果i等于1，即将该节点放在链表头 */
	{
		s = (List)malloc(sizeof(struct LNode)); /* 分配内存 */
		s->Next = PtrL; 
		s->Data = X;
		return s; /* 新表头指针 */
	}
}	
	
	p = FindKth(i-1, PtrL); /* 查找第N-1个节点 */
	if (p == NULL){ /* 第N-1个不存在 */
		printf("参数错误！\n");
		return NULL;
	}else{
		s = (List)malloc(sizeof(struct LNode));
		s->Data = X;
		s->Next = p->Next; /* 新节点的链指向i-1节点后面那个节点 */
		p->Next = s; /* i-1节点的链指向新节点 */
		return PtrL; /* 新表头指针 */
	}

/* 删除：删除第i个节点 */
List Delete(int i, List PtrL)
/* 输入要删除的结点位置和链表头指针，输出删除后的链表头指针 */
{
	List p, s; /* s 指向要删除的结点，p指向前一个结点，目的是将p->Next修改为下下个结点的地址 */
	if (i == 1)   /* 当结点为第一个的时候 （想一想，为什么要讨论这种情况？ --> 因为FindKth(i-1, PtrL)中的i-1!=0 */
	{
		s = PtrL;  /* s指向链表第一个结点 */ 
		if (PtrL != NULL) PtrL = PtrL -> Next; /* 如果不判断条件直接做执行语句会报错吗？ */
		else return NULL;
		free(s);   /* 释放被删除结点 */
		return PtrL;
	}
	
	p = FindKth(i-1, PtrL) /* 找到第i-1个结点 */
	if (p == NULL)
	{
		printf("%d个结点不存在\n", i-1); return NULL;
	}else if(p->Next == NULL){
		printf("%d个结点不存在\n", i); return NULL;
	}else{
	s = p->Next;
	p->Next = s->Next;
	free(s);
	return PtrL;	
	}
}	
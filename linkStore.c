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
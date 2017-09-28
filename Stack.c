/* 定义一个栈: 一般由一个一位数组和一个记录栈顶元素位置的变量组成 */
#define MaxSize 
typedef struct SNode *Stack;
struct SNode
{
	ElementType Data[MaxSize];
	int Top; /* Top 是栈的最上面一个元素的数组下标值 */
};

/* 入栈 */
void Push(Stack PtrS, ElementType item) /* 输入指向栈的头指针和入栈的元素，实现入栈操作 */
{
	if (PtrS->Top == MaxSize-1) /* 判断是否栈满 */
	{
		printf("栈已满\n"); return;
	}else{
		PtrS->Data[++(PtrS->Top)] = item /* !!++(PtrS->Top)的括号很重要！！++(PtrS->Top)做了两件事：(PtrS->Top)++, PtrS->Data[PtrS->Top] = item; */
		return;
	}
}

/* 出栈：输入栈的头指针，输出栈顶元素 */
ElementType Pop(Stack PtrS){
	if (PtrS->Top == -1) /*判断是否为空栈*/
	{
		printf("堆栈空！\n"); return ERROR;
	}else
		return PtrS->Data[(PtrS->Top)--]
}
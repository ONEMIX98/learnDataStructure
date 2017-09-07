#include <stdio.h>
// #include <stdlib.h> /*产生随机数*/
// #include <time.h> /*产生随机数*/

/*题目要求：返回一个序列的最大子列和以及该子列的第一个和最后一个数*/

/*在线处理求最大子列和，注意在线处理的含义：每输入一个数据就进行及时处理，在任何一个地方终止输入，算法都能正确给出当前的解*/
/*时间复杂度：T(N) = N*/
/*定义结构struct让函数返回多个值*/
typedef struct{
  int MaxSum, first_num, last_num;
} TResult;
TResult maxSubSeqSum3(int A[], int N){

  int i;
  TResult data;
  int ThisSum = 0;
  data.MaxSum = 0;
  data.first_num = A[0];
  data.last_num = A[N-1];
  int change_first_num = 1;
  for (i=0; i<N; i++)
  {
    ThisSum += A[i]; /*不断向当前子列和加入项*/
    if(ThisSum > data.MaxSum)
    {
      data.MaxSum = ThisSum;
      data.last_num = A[i];
      if(change_first_num)/*当前子列和大于最大子列和且为一个新的子列*/
      {
        data.first_num = A[i];
        change_first_num = 0;
      }
    }//若当前子列和大于最大子列和，则更新最大子列和
    else if (ThisSum < 0)
    {
      ThisSum = 0; //若当前子列和为负数，则一定不会使之后的子列和增大，故舍弃之
      change_first_num = 1;/*寻找新的子列，则第一个数可能改变*/
    }
  }
  /*若序列为0和负数的组合，则返回0 0 0*/
  int have_zero = 0;
  for (i = 0; i < N; i++) /*判断是否有0*/
  {
    if (A[i] == 0){
      have_zero = 1;
      break; /*若有0则提前结束循环*/
    }
  }
  if (have_zero && data.MaxSum == 0 ) /*有0且MaxSum = 0, 说明为0和负数的组合*/
  data.first_num = data.last_num = 0;
  return data;
}

int main(){

  // int A[] = {4, -3, 5, -2, -1, 2, 6, -2}, N;
  // N = sizeof(A)/sizeof(int);
  int N, i;
  scanf("%d", &N);
  int A[N];
  // srand(time(NULL));
  for (i = 0; i<N; i++)
    scanf("%d", &A[i]);
    // {
    // A[i] = rand() % 51 + (-25); /* [-25，25]之间的随机数 51表示多少个数，-25表示最小值*/
    // printf("%d ",A[i]);}
  TResult ret = maxSubSeqSum3(A, N);
  printf("%d %d %d", ret.MaxSum, ret.first_num, ret.last_num);


}

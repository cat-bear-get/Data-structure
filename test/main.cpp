#include <stdio.h>
#include "SqList.h"
#include "HomeWork.h"

/*********************************
 * 顺序表测试
 */
void TestSqList()
{
    SqList L;
    InitSqList(L);
    int value1[15] = {1, 2, 3, 4, 5,
                      6, 7, 8, 9, 10,
                      11, 12, 13, 14, 15};
    int value2[15] = {2, 2, 3, 4, 5,
                      6, 5, 5, 3, 10,
                      11, 3, 13, 5, 15};
    printf("顺序表\n");
    PutIntoSqList(L, value1, 15);

    int del_min_value = 0;
    Del_Min(L, del_min_value);
    printf("\tDelValue=%d\n", del_min_value);
    PrintSqList(L,"删除最小元素后的顺序表");

    Reverse(L);
    PrintSqList(L,"逆序排列后的顺序表");

    InitSqList(L);
    printf("顺序表\n");
    PutIntoSqList(L, value1, 15);

    int del_value = 10;
    Del_x_1(L, del_value);
    PrintSqList(L,"删除元素10后的顺序表");

    int s2 = 3, t2 = 7;
    Del_s_t2(L, s2, t2);
    PrintSqList(L,"删除3~~7后的顺序表");

    InitSqList(L);
    PutIntoSqList(L, value2, 15);
    int s = 3, t = 7;
    Del_s_t(L, s, t);
    PrintSqList(L,"删除3~~7后的顺序表");

    int value3[11] = {1, 2, 2, 2, 2, 3, 3, 3, 4, 4, 5};
    InitSqList(L);
    printf("顺序表\n");
    PutIntoSqList(L, value3, 11);
    Delete_Same(L);
    PrintSqList(L,"删除相同元素后顺序表");

    int value4[4]={1,2,4,5},value5[4]={1,3,8,9};
    SqList A,B,C;
    InitSqList(A);InitSqList(B);InitSqList(C);
    PutIntoSqList(A,value4,4);PutIntoSqList(B,value5,4);
    PrintSqList(A,"顺序表(A)");PrintSqList(B,"顺序表(B)");
    Merge(A,B,C);
    PrintSqList(C,"合并后的顺序表为");

    int value6[8]={1,2,3,4,5,6,7,8};
    Exchange(value6,4,4,8);
    printf("交换后的数组\n");
    for (int i = 0; i < 8; i++)
    {
        printf("value6[%d]=%d\n",i,value6[i]);
    }
    printf("#################################\n");

    
}
int main()
{
    TestSqList();
    return 0;
}
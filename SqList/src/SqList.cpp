#include <iostream>
#include "SqList.h"

/**
 * @brief 初始化顺序表
 * @param L 自定义的顺序表
 */
void InitSqList(SqList &L)
{
    for (int i = 0; i < MaxSize; ++i)
    {
        L.data[i] = 0;
        //        int *a = &(L->data[i]);
        //        printf("data[%d]->%d\n", i, a);
    }
    L.length = 0;
}
/**
 * @brief 在顺序表的位序i处插入元素e
 * @param L 自定义的顺序表
 * @param i 位序
 * @param e 待插入的元素的值
 */
bool ListInsert(SqList &L, int i, int e)
{
    if (i < 1 || i > L.length + 1)
    {
        printf("插入位置非法\n\n");
        return false;
    }
    if (L.length >= MaxSize)
    {
        printf("顺序表已满\n\n");
        return false;
    }
    for (int j = L.length; j >= i; j--)
    {
        L.data[j] = L.data[j - 1];
    }
    L.data[i - 1] = e;
    L.length++;
    return true;
}
/**
 * @brief 在顺序表的位序i处删除元素并取出该元素
 * @param L 自定义的顺序表
 * @param i 位序
 * @param e 取出元素的数值
 * @return 成功取出则返回true，否则返回false
 */
bool ListDelete(SqList &L, int i, int &e)
{
    if (i < 1 || i > L.length)
    {
        printf("删除位置非法");
        return false;
    }
    e = L.data[i - 1];
    for (int j = i; j < L.length; ++j)
    {
        L.data[j - 1] = L.data[j];
    }
    L.length--;
    return true;
}

/**
 * @brief 在顺序表中按位查找第i位的值
 * @param L 自定义的顺序表
 * @param i 待查找数的值
 * @return 返回查到的数值
 */
int GetElem(SqList &L, int i)
{
    int elem = 0;
    elem = L.data[i - 1];
    return elem;
}
/**
 * @brief 在顺序表中按值查找第i位的值
 * @param L 自定义的顺序表
 * @param e 待查找数的值
 */
int LocateElem(SqList &L, int e)
{
    int i;
    for (i = 0; i < L.length; ++i)
    {
        if (L.data[i] == e)
            return i;
    }
    return printf("找不到相应的值\n");
}
/**
 * @brief 给自定义的顺序表传入值并打印
 * @param L 自定义的顺序表
 * @param value_length 传入值的个数
 * @return 成功执行则返回true，否则返回false
 */
bool PutIntoSqList(SqList &L, int *value, int value_length)
{
    for (int i = 0; i < value_length; i++)
    {
        L.data[i] = value[i];
        L.length++;
    }
    if (L.length > MaxSize)
    {
        return false;
    }
    for (int i = 0; i < L.length; i++)
    {
        printf("data[%d] = %d\n", i, L.data[i]);
    }
    return true;
}
/**
 * @brief 打印顺序表中的元素
 * @param L 自定义的顺序表
 * @param str 顺序表简介
 */
void PrintSqList(SqList L, char const *str)
{
    printf("#################################\n");
    printf("%s\n", str);
    for (int i = 0; i < L.length; i++)
    {
        printf("data[%d] = %d\n", i, L.data[i]);
    }
    printf("#################################\n");
}
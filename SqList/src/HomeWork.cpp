/**
 * @file HomeWork.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-06-19
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "HomeWork.h"

/**
 * @brief exp2.2.3-1：从顺序表中制除具有最小值的元素（假设唯一）并由画数返回被删元素的值。
 * 空出的位五由聂后一个元素填补，若顺序表为空，则显示出错信息并退出运行。
 * @param L 自定义的顺序表
 * @param value 顺序表中的最小值元素
 * @return 操作成功则返回true，否则返回false
 */
bool Del_Min(SqList &L, int &value)
{
    if (L.length == 0)
        return false;
    value = L.data[0];
    int pos = 0;
    for (int i = 0; i < L.length; i++)
    {
        if (L.data[i] < value)
        {
            value = L.data[i];
            pos = i;
        }
    }
    L.data[pos] = L.data[L.length - 1];
    L.length--;
    return true;
}
/**
 * @brief exp2.2.3-2:设计一个高效算法,
 * 将顺序表L的所有元素逆置,要求算法的空间复杂度为O(1)。
 * @param L 自定义的顺序表
 */
void Reverse(SqList &L)
{
    int temp;
    for (int i = 0; i < L.length / 2; i++)
    {
        temp = L.data[i];
        L.data[i] = L.data[L.length - i - 1];
        L.data[L.length - i - 1] = temp;
    }
}
/**
 * @brief exp2.2.3-3(1):对长度为n的顺序表L,编写一个时间复杂度为O(n)、空间复杂度为O(1)的算法,
 * 该算法删除线性表中所有值为x的数据元素。
 * @param L 自定义的顺序表
 * @param value 待删除元素的值
 * @attention 用k记录顺序表L中不等于x的元素个数(即需要保存的元素个数),
 * 扫描时将不等于x的元素移动到下标k的位置,并更新太值。扫描结束后修改L的长度。
 */
void Del_x_1(SqList &L, int value)
{
    int k = 0, i;
    for (i = 0; i < L.length; i++)
    {
        if (value != L.data[i])
        {
            L.data[k] = L.data[i];
            k++;
        }
    }
    L.length = k;
}
/**
 * @brief exp2.2.3-3(2):对长度为n的顺序表L,编写一个时间复杂度为O(n)、空间复杂度为O(1)的算法,
 * 该算法删除线性表中所有值为x的数据元素。
 * @param L 自定义的顺序表
 * @param value 待删除元素的值
 * @attention 用k记录顺序表L中等于x的元素个数,边扫描L边统计k,
 * 并将不等于x的元素前移k个位置。扫描结束后修改L的长度。
 */
void Del_x_2(SqList &L, int value)
{
    int k = 0, i;
    while (i < L.length)
    {
        if (L.data[i] == value)
        {
            k++;
        }
        else
        {
            L.data[i - k] = L.data[i];
        }
        i++;
    }
    L.length = L.length - k;
}
/**
 * @brief exp2.2.3-4:从有序顺序表中删除其值在给定值s与t之间(要求s<t)的所有元素,
 * 若s或t不合理或顺序表为空,则显示出错信息并退出运行。
 * @param s 区域的下界
 * @param t 区域的上界
 * @return 删除成功则返回true，否则返回false
 */
bool Del_s_t2(SqList &L, int s, int t)
{
    int i, j;
    if (s >= t || L.length == 0)
    {
        return false;
    }
    for (i = 0; i < L.length && L.data[i] < s; i++)
        ;
    if (i >= L.length)
    {
        return false;
    }
    for (j = 0; j < L.length && L.data[j] <= t; j++)
        ;
    for (; j < L.length; i++, j++)
    {
        L.data[i] = L.data[j];
    }
    L.length = i;
    return true;
}
/**
 * @brief exp2.2.3-5:从顺序表中删除其值在给定值s与t之间(包括s和t,要求s<t)的所有元素,
 * 若s或t不合理或顺序表为空,则显示出错信息并退出运行。
 * @param s 区域的下界
 * @param t 区域的上界
 * @return 删除成功则返回true，否则返回false
 */
bool Del_s_t(SqList &L, int s, int t)
{
    int k = 0, i;
    if (L.length == 0 || s >= t)
    {
        return false;
    }
    for (i = 0; i < L.length; i++)
    {
        if (L.data[i] >= s && L.data[i] <= t)
        {
            k++;
        }
        else
            L.data[i - k] = L.data[i];
    }
    L.length -= k;
    return true;
}
/**
 * @brief exp2.2.3-6:从有序顺序表中删除所有其值重复的元素,使表中所有元素的值均不同。
 * @param L 自定义的顺序表
 */
bool Delete_Same(SqList &L)
{
    if (L.length == 0)
        return false;
    int i, j;
    for (i = 0, j = 1; j < L.length; j++)
    {
        if (L.data[i] != L.data[j])
        {
            L.data[++i] = L.data[j];
        }
    }
    L.length = i + 1;
    return true;
}
/**
 * @brief exp2.2.3-7:将两个有序顺序表合并为一个新的有序顺序表,并由函数返回结果顺序表。
 * @param A 顺序表A
 * @param B 顺序表B
 * @param C 新的顺序表C
 */
bool Merge(SqList A, SqList B, SqList &C)
{
    if (A.length + B.length > MaxSize)
    {
        return false;
    }
    int i = 0, j = 0, k = 0;
    while (i < A.length && j < B.length)
    {
        if (A.data[i] <= B.data[j])
            C.data[k++] = A.data[i++];
        else
            C.data[k++] = B.data[j++];
    }
    while (i < A.length)
    {
        C.data[k++] = A.data[i++];
    }
    while (j < B.length)
    {
        C.data[k++] = B.data[j++];
    }
    C.length = k;
    return true;
}
/**
 * @brief exp2.2.3-8：例题的实现方法函数
 * @param A 一个一维数组
 * @param left 左边的顺序表
 * @param right 右边的顺序表
 * @param arraySize A数组长度
 */
void Reverse(DataType *A, int left, int right, int arraySize)
{
    if (left >= right || right >= arraySize)
    {
        return;
    }
    int mid = (left + right) / 2;
    for (int i = 0; i <= mid - left; i++)
    {
        DataType temp = A[left + i];
        A[left + i] = A[right - i];
        A[right - i] = temp;
    }
}
/**
 * @brief exp2.2.3-8:已知在一维数组A[m+n]中依次存放两个线性表（a1,a2,a3,…,am）和（b1,b2,b3,…,bn)。
 * 編写一个函数,将数组中两个顺序表的位置互换,即将(b1,b2,b3,…,bn)放在(a1,a2,a3,…,am)的前面。
 * @param A 一个一维数组
 * @param m 线性表(1)的长度
 * @param n 线性表(2)的长度
 * @param arraySize 数组的长度
 */
void Exchange(DataType *A, int m, int n, int arraySize)
{
    Reverse(A, 0, m + n - 1, arraySize);
    Reverse(A, 0, n - 1, arraySize);
    Reverse(A, n, m + n - 1, arraySize);
}
/**
 * @brief exp2.2.3-9:线性表（a1,a2,a3,…,an）中的元素递増有序且按顺序存储于计算机内。
 * 要求设计一个算法，完成用最少时间在表中查找数值为x的元素,若找到,则将其与后继元素位置相交换,
 * 若找不到,则将其插入表中并使表中元素仍递增有序。
 * @param A 自定义的线性表
 * @param n 线性表的长度
 * @param x 待查找的元素
 */
bool SearchExchangeInsert(int *A, int n, int x)
{
    if (n > MaxSize)
    {
        return false;
    }
    int low = 0, high = n - 1, mid, i;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (A[mid] == x)
            break;
        else if (A[mid] < x)
            low = mid + 1;
        else
            high = mid - 1;
    }
    if (A[mid] == x && mid != n - 1)
    {
        int temp;
        temp = A[mid];
        A[mid] = A[mid + 1];
        A[mid + 1] = temp;
    }
    if (low > high)
    {
        for (i = n - 1; i > high; i--)
        {
            A[i + 1] = A[i];
        }
        A[i + 1] = x;
    }
}


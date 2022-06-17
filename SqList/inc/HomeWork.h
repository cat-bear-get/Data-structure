#pragma once
#include "SqList.h"

typedef int DataType;

bool Del_Min(SqList &L, int &value);
void Reverse(SqList &L);
void Del_x_1(SqList &L, int value);
void Del_x_2(SqList &L, int value);
bool Del_s_t2(SqList &L, int s, int t);
bool Del_s_t(SqList &L, int s, int t);
bool Delete_Same(SqList &L);
bool Merge(SqList A, SqList B, SqList &C);
void Exchange(DataType *A,int m,int n,int arraySize);
bool SearchExchangeInsert(int *A, int n, int x);

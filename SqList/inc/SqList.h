#pragma once

#define MaxSize 15

typedef struct
{
    int data[MaxSize];
    int length;
} SqList;

typedef int DataType;

void InitSqList(SqList &L);
bool ListInsert(SqList &L, int i, int e);
bool ListDelete(SqList &L, int i, int &e);
int GetElem(SqList &L, int i);
int LocateElem(SqList &L, int e);
bool PutIntoSqList(SqList &L, int *value, int value_length);
void PrintSqList(SqList L, char const *);

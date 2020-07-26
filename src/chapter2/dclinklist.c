﻿#include <chapter2/dclinklist.h>

Status InitList_DC(DCLinklist *L)
{
    // 为头结点分配内存空间.
    *L = malloc(sizeof(DCNode));
    // 内存分配失败.
    if (!(*L))
    {
        exit(OVERFLOW);
    }

    (*L)->data = -1;
    (*L)->next = (*L);
    (*L)->prior = (*L);

    return OK;
} // InitList_DC

Status HeadInsert_DC(DCLinklist *L, ElemType e)
{
    // 创建新结点.
    DCNode *s = malloc(sizeof(DCNode));

    // 为新结点赋值.
    s->data = e;

    // 1. 新结点指向后继结点.
    s->next = (*L)->next;

    // 2. 后继结点指向新结点.
    (*L)->next->prior = s;

    // 3. 新结点指向前驱结点.
    s->prior = (*L);

    // 4. 前驱结点指向新结点.
    (*L)->next = s;

    return OK;
} // HeadInsert_DC

Status TailInsert_DC(DCLinklist *L, ElemType e)
{
    // 这是新结点.
    DCNode *s = malloc(sizeof(DCNode));
    s->data = e;

    // 由于 L 是双向循环链表, 所以不用 O(n) 遍历找到合适的位置.

    // 1. 新结点指向后继结点.
    s->next = (*L);

    // 3. 新结点指向前驱结点.
    s->prior = (*L)->prior;

    // 4. 前驱结点指向新结点.
    (*L)->prior->next = s;

    // 2. 后继结点指向新结点.
    (*L)->prior = s;

    return OK;
} // TailInsert_DC

DCNode *GetElem_DC(DCLinklist L, int i)
{
    if (i < 0 || i > ListLength_DC(L))
    {
        printf("索引越界\n");
        return NULL;
    }

    int counter = 0;
    DCNode *p = L;

    while (counter < i)
    {
        p = p->next;
        ++counter;
    }

    return p;
} // GetElem_DC

DCNode *LocateElem_DC(DCLinklist L, ElemType e)
{
    DCNode *p = L->next;

    while (p->data != e)
    {
        p = p->next;
    }

    return p;
} // LocateElem_DC

Status ListInsert_DC(DCLinklist *L, int i, ElemType e)
{
    if (i < 1 || i > ListLength_DC(*L) + 1)
    {
        printf("插入位置非法\n");
        return ERROR;
    }

    // 新结点的前驱结点.
    DCNode *p = GetElem_DC(*L, i - 1);

    // 这是要插入的结点.
    DCNode *s = malloc(sizeof(DCNode));
    s->data = e;

    // 1. 新结点指向后继结点.
    s->next = p->next;

    // 2. 前驱结点指向新结点.
    p->next = s;

    return OK;
} // ListInsert_DC

Status ListDelete_DC(DCLinklist *L, int i)
{
    if (i < 1 || i > ListLength_DC(*L))
    {
        printf("删除位置非法\n");
        return ERROR;
    }

    // 被删除结点的前驱结点.
    DCNode *p = GetElem_DC(*L, i - 1);

    // 这是要删除的结点.
    DCNode *q = p->next;

    // 前驱结点跳过被删除的结点.
    p->next = q->next;

    // 后继结点跳过被删除的结点.
    q->next->prior = p;

    // 删除结点 q.
    free(q);

    return OK;
} // ListDelete_DC

int ListLength_DC(DCLinklist L)
{
    int length = 0;
    DCNode *p = L->next;

    while (p->data != -1)
    {
        ++length;
        p = p->next;
    }

    return length;
} // ListLength_DC

void PrintList_DC(DCLinklist L)
{
    DCNode *p = L->next;

    while (p->data != -1)
    {
        printf("%d->", p->data);
        p = p->next;
    }

    return;
} // PrintList_DC

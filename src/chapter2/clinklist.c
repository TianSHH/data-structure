﻿#include <chapter2/clinklist.h>

Status InitList_C(CLinklist *L)
{
    // 为头结点分配内存空间.
    (*L) = malloc(sizeof(CNode));
    // 内存分配失败.
    if (!(*L))
    {
        exit(OVERFLOW);
    }

    (*L)->data = -1;
    (*L)->next = (*L);

    return OK;
} // InitList_C

Status HeadInsert_C(CLinklist *L, ElemType e)
{
    // 创建新结点.
    CNode *s = malloc(sizeof(CNode));

    // 为新结点赋值.
    s->data = e;

    // 1. 新结点指向后继结点.
    s->next = (*L)->next;

    // 2. 前驱结点指向新结点.
    (*L)->next = s;

    return OK;
} // HeadInsert_C

Status TailInsert_C(CLinklist *L, ElemType e)
{
    CNode *p = (*L)->next;

    // 找到到合适的位置.
    while (p->next->data != -1)
    {
        p = p->next;
    }

    // 这是新结点.
    CNode *s = malloc(sizeof(CNode));
    s->data = e;

    // 1. 新结点指向后继结点.
    s->next = p->next;

    // 2. 前驱结点指向新结点.
    p->next = s;

    return OK;
} // TailInsert_C

CNode *GetElem_C(CLinklist L, int i)
{
    if (i < 0 || i > ListLength_C(L))
    {
        printf("索引越界\n");
        return NULL;
    }

    int counter = 0;
    CNode *p = L;

    while (counter < i)
    {
        p = p->next;
        ++counter;
    }

    return p;
} // GetElem_C

CNode *LocateElem_C(CLinklist L, ElemType e)
{
    CNode *p = L->next;

    while (p->data != e)
    {
        p = p->next;
    }

    return p;
} // LocateElem_C

Status ListInsert_C(CLinklist *L, int i, ElemType e)
{
    if (i < 1 || i > ListLength_C(*L) + 1)
    {
        printf("插入位置非法\n");
        return ERROR;
    }

    // 新结点的前驱结点.
    CNode *p = GetElem_C(*L, i - 1);

    // 这是要插入的结点.
    CNode *s = malloc(sizeof(CNode));
    s->data = e;

    // 1. 新结点指向后继结点.
    s->next = p->next;

    // 2. 前驱结点指向新结点.
    p->next = s;

    return OK;
} // ListLength_C

Status ListDelete_C(CLinklist *L, int i)
{
    if (i < 1 || i > ListLength_C(*L))
    {
        printf("删除位置非法\n");
        return ERROR;
    }

    // 被删除结点的前驱结点.
    CNode *p = GetElem_C(*L, i);

    // 这是要删除的结点.
    CNode *q = p->next;

    // 跳过被删除结点.
    p->next = q->next;

    // 删除结点 q.
    free(q);

    return OK;
} // ListDelete_C

int ListLength_C(CLinklist L)
{
    int length = 0;
    CNode *p = L->next;

    while (p->data != -1)
    {
        ++length;
        p = p->next;
    }

    return length;
} // ListLength_C

void PrintList_C(CLinklist L)
{
    CNode *p = L->next;

    while (p->data != -1)
    {
        printf("%d->", p->data);
        p = p->next;
    }

    return;
} // PirintList_C

Status DelAll(CLinklist *L)
{
    CNode *p, *pre;
    CNode *minp, *minpre;

    // ! 当链表不为空时, 是 != (*L) 不是 != NULL.
    while ((*L)->next != (*L))
    {
        // p 为工作指针, pre 指向 p 的前驱.
        p = (*L)->next, pre = (*L);

        // minp 指向数据元素最小的结点, minpre 记录其前驱.
        minp = p, minpre = pre;

        // 循环一趟.
        while (p != (*L))
        {
            // 找到更小的结点, 更新 minp 和 minpre.
            if (p->data < minp->data)
            {
                minp = p;
                minpre = pre;
            }

            // 工作之中前进一.
            pre = p;
            p = p->next;
        }

        // 输出找到的最小值.
        printf("%d,", minp->data);

        // 并且删除最小值结点.
        minpre->next = minp->next;
        free(minp);
    }

    // 最后删除头结点.
    free((*L));

    return OK;
} // DelAll

﻿/**
 * @file  : linklist.h
 * @brief : 单链表
 * @author: 田世豪
 * @date  : 2020-1-25
 * */

#pragma once

#include <chapter1/status.h>
#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;

// 结点类型
typedef struct LNode
{
    ElemType data;
    struct LNode *next;
} LNode, *LinkList;

/**
 * 构造一个空的线性链表 L. 只有头结点.
 * @param L 指向未初始化过的链表的指针.
 */
Status InitList_L(LinkList *L);

/**
 * @brief 头插法.
 * @param L 指向已存在链表的指针.
 * @param e 要插入的数据元素.
 */
Status HeadInsert(LinkList *L, ElemType e);

/**
 * @brief 尾插法.
 * @param L 指向已存在链表的指针.
 * @param e 要插入的数据元素.
 */
Status TailInsert(LinkList *L, ElemType e);

/**
 * @brief 按序号查找结点值.
 * @param L 链表.
 * @param i 序号.
 * @return 返回指向符合要求结点的指针, 否则返回 NULL.
 */
LNode *GetElem(LinkList L, int i);

/**
 * 打印链表.
 * @param L 待打印链表.
 */
void PrintList_L(LinkList L);

// // 依次对 L 的每个元素调用函数 visit(). 一旦 visit() 失败, 则操作失败.
// Status ListTraverse(LinkList L, Status (*visit)(ElemType));

// /***************************利用基本操作实现的高级操作******************************/

// // 在线性链表 L 第 i 个元素之前插入数据元素 e
// Status ListInsert_L(LinkList *L, int i, ElemType e);

// // 已知单线性链表 La 和 Lb 的元素按值非递减排列.
// // 归并 La 和 Lb 得到新的单线性链表 Lc, Lc 的元素也按值非线性递减排列.
// Status MergeList_L(LinkList *La, LinkList *Lb, LinkList *Lc, Status (*compare)(ElemType, ElemType));

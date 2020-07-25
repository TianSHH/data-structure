﻿#include <chapter3/linkqueue.h>
#include <chapter3/sqqueue.h>
#include <chapter3/sqstack.h>

void UseSqstack();
void UseSqqueue();
void UseLinkqueue();

int main()
{
    UseSqstack();

    return 0;
}

void UseSqstack()
{
    if (MatchBrackets())
    {
        printf("match\n");
    }
    else
    {
        printf("not match\n");
    }

    return;
}

// void UseSqqueue()
// {
//     SqQueue Q;
//     InitQueue_Sq(&Q);

//     PrintQueue_Sq(Q);

//     EnQueue_Sq(&Q, 1);
//     EnQueue_Sq(&Q, 2);
//     EnQueue_Sq(&Q, 3);
//     EnQueue_Sq(&Q, 4);
//     EnQueue_Sq(&Q, 5);

//     PrintQueue_Sq(Q);

//     QElemType e;

//     DeQueue_Sq(&Q, &e);
//     PrintQueue_Sq(Q);
//     printf("front of queue is %d\n", e);
//     printf("length = %d\n", QueueLength_Sq(Q));
//     DeQueue_Sq(&Q, &e);
//     PrintQueue_Sq(Q);
//     printf("front of queue is %d\n", e);
//     printf("length = %d\n", QueueLength_Sq(Q));
//     DeQueue_Sq(&Q, &e);
//     PrintQueue_Sq(Q);
//     printf("front of queue is %d\n", e);
//     printf("length = %d\n", QueueLength_Sq(Q));
//     DeQueue_Sq(&Q, &e);
//     PrintQueue_Sq(Q);
//     printf("front of queue is %d\n", e);
//     printf("length = %d\n", QueueLength_Sq(Q));
//     DeQueue_Sq(&Q, &e);
//     PrintQueue_Sq(Q);
//     printf("front of queue is %d\n", e);
//     printf("length = %d\n", QueueLength_Sq(Q));
//     DeQueue_Sq(&Q, &e);
//     PrintQueue_Sq(Q);
//     printf("front of queue is %d\n", e);
//     printf("length = %d\n", QueueLength_Sq(Q));

//     return;
// }

void UseLinkqueue()
{
    LinkQueue Q;
    InitQueue_L(&Q);
    QElemType e;

    printf("length = %d\n", QueueLength(Q));

    EnQueue(&Q, 1);
    EnQueue(&Q, 2);
    EnQueue(&Q, 3);
    EnQueue(&Q, 4);

    printf("length = %d\n", QueueLength(Q));

    DeQueue(&Q, &e);
    printf("e = %d\n", e);
    printf("length = %d\n", QueueLength(Q));

    PrintQueue_L(Q);

    GetHead(Q, &e);
    printf("e = %d\n", e);
    printf("length = %d\n", QueueLength(Q));

    printf("length = %d\n", QueueLength(Q));

    ClearQueue(&Q);

    PrintQueue_L(Q);

    if (DeQueue(&Q, &e))
        printf("wrong\n");
    else
        printf("bingo\n");

    DestoryQueue_L(&Q);

    return;
}
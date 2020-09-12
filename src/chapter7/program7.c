﻿/**
 * @file program7.c
 * @author tianshihao4944@126.com
 * @brief 第七章代码测试.
 * @version 0.1
 * @date 2020-09-12
 * @copyright Copyright (c) 2020
 */

#include <chapter7/mgraph/mgraph.h>

void WriteGraph(MGraph *G);
void ReadGraph(MGraph *G);
Status Visit(int i);
void UseMgraph();

int main()
{
    UseMgraph();

    return 0;
}

void UseMgraph()
{
    MGraph G;

    CreateGraph_M(&G);

    PrintAdjMatrix(G);

    DFSTraverse(G, Visit);
    BFSTraverse(G, Visit);

    return;
}

void WriteGraph(MGraph *G)
{
    FILE *fp = fopen("./mgraph.bin", "wb");

    fwrite(G, sizeof(*G), 1, fp);

    fclose(fp);

    return;
} // WriteGraph

void ReadGraph(MGraph *G)
{
    FILE *fp = fopen("./mgraph.bin", "rb");

    fread(G, sizeof(*G), 1, fp);

    return;
} // ReadGraph

Status Visit(int i)
{
    printf("%d ", i);

    return OK;
}
#define MaxVertexNum 100
typedef struct ArcNode{     //边表结点
    int adjvex;             //指向的顶点位置
    struct ArcNode *next;   //指向下一条弧的指针
    int weight;             //权值
}ArcNode;


#define MaxVertexNum 100
//邻接矩阵表示法
typedef struct MGraph {
    char Vex[MaxVertexNum];
    int Edge[MaxVertexNum][MaxVertexNum];
    int vexnum, arcnum;
} MGraph;
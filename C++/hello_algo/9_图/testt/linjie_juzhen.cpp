/*
*基于邻接矩阵实现的无向图类
*/
#include <vector>
#include <bits/stdc++.h>

using std::vector;

class GraphAdjMat
{
private:
    /* data */
    vector<int> vertices;                   //顶点列表，元素代表顶点值，索引代表顶点索引
    vector<vector<int>> adjMat;             //邻接矩阵，行列索引对应顶点索引
public:
    GraphAdjMat(const vector<int> &vertices, const vector<vector<int>> &edges){
        //添加顶点
        for (int val : vertices)
        {
            /* code */
            addVertex(val);
        }
        
    }
    
    //获取顶点数量
    int size() const{
        return vertices.size();
    }

    //添加顶点
    void addVertex(int val){
        int n = size();     //获取顶点数量
        //向顶点列表中添加新的顶点值
        vertices.push_back(val);
        //在邻接矩阵中添加一行
        adjMat.emplace_back(vector<int>(n,0));
        //在邻接矩阵中添加一列
        for (vector<int> &row:adjMat)
        {
            /* code */
            row.push_back(0);
        }
        
    }




};

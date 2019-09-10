class Graphm{
private:
	int numVertex, numEdge;
	int** matrix;//pointer to adjacency matrix
	int* mark;
public:
	Graphm(int numVert) {     Init(numVert);	}
	~Graphm() ;
    void Init(int n);
    void print();
	int n() { return numVertex; }
	int e() { return numEdge; }
	int first(int v) ;
	int next(int v, int w);
	void setEdge(int v1, int v2, int wt);
	void delEdge(int v1, int v2);
	bool isEdge(int i, int j)    { return matrix[i][j] != 0;   }
	int weight(int v1, int v2)  {   return matrix[v1][v2];  }
	int getMark(int v)  {   return mark[v]; }
	void setMark(int v, int val)    {   mark[v] = val;	}
};
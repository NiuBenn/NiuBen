typedef struct Node
{
	int weight;                //权值
	int parent;                //父节点的序号，为0的是根节点
	int lchild, rchild;         //左右孩子节点的序号，为0的是叶子节点
}HTNode, *HuffmanTree;          //用来存储赫夫曼树中的所有节点
typedef char **HuffmanCode;    //用来存储每个叶子节点的赫夫曼编码


							   //根据给定数量的权值构造一棵赫夫曼树
HuffmanTree create_HuffmanTree(int *, int);

//从所有节点中选出权值最小的根节点，并将其在数组中的序号返回
//该函数主要是供select_minium函数调用
int min(HuffmanTree, int);

//从所有节点中选出权值最小的两个根节点，并将其序号分别保存在后两个参数中
void select_minium(HuffmanTree, int, int &, int &);

//从叶子节点到根节点逆向求每个字符的赫夫曼编码
void HuffmanCoding(HuffmanTree, HuffmanCode &, int);

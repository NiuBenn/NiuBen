typedef struct Node
{
	int weight;                //Ȩֵ
	int parent;                //���ڵ����ţ�Ϊ0���Ǹ��ڵ�
	int lchild, rchild;         //���Һ��ӽڵ����ţ�Ϊ0����Ҷ�ӽڵ�
}HTNode, *HuffmanTree;          //�����洢�շ������е����нڵ�
typedef char **HuffmanCode;    //�����洢ÿ��Ҷ�ӽڵ�ĺշ�������


							   //���ݸ���������Ȩֵ����һ�úշ�����
HuffmanTree create_HuffmanTree(int *, int);

//�����нڵ���ѡ��Ȩֵ��С�ĸ��ڵ㣬�������������е���ŷ���
//�ú�����Ҫ�ǹ�select_minium��������
int min(HuffmanTree, int);

//�����нڵ���ѡ��Ȩֵ��С���������ڵ㣬��������ŷֱ𱣴��ں�����������
void select_minium(HuffmanTree, int, int &, int &);

//��Ҷ�ӽڵ㵽���ڵ�������ÿ���ַ��ĺշ�������
void HuffmanCoding(HuffmanTree, HuffmanCode &, int);

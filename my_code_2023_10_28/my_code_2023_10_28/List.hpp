/*
1.实现线性表的:
	1.1.插入、删除（拓展：可以修改原顺序表内某个元素的数据）
	1.2.求表长（拓展：求出表的容量）
	1.3.查找给定值 e、查找第 i 个位置元素
	1.4.要求编写的程序以菜单方式工作；
2.用链式存储结构实现一元多项式的相加运算；
3.利用双向链表实现通讯录的建立、删除、检索和列表，并可保存至文件，可重新装入。
*/
namespace limou
{
	template<typename T>
	class SeqTable
	{
	public:
		SeqTable()
		{

		}
		~SeqTable()
		{

		}
	private:
		int _arr;
		int _size;
		int _capacity;
	};

	template<typename T>
	class LinkTable
	{
	public:
		LinkTable()
		{

		}
		~LinkTable()
		{

		}
	private:
		int _node;
		int _size;
		int _capacity;
	};
}
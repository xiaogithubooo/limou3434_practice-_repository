/*
1.ʵ�����Ա��:
	1.1.���롢ɾ������չ�������޸�ԭ˳�����ĳ��Ԫ�ص����ݣ�
	1.2.�������չ��������������
	1.3.���Ҹ���ֵ e�����ҵ� i ��λ��Ԫ��
	1.4.Ҫ���д�ĳ����Բ˵���ʽ������
2.����ʽ�洢�ṹʵ��һԪ����ʽ��������㣻
3.����˫������ʵ��ͨѶ¼�Ľ�����ɾ�����������б����ɱ������ļ���������װ�롣
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
#define _CRT_SECURE_NO_WARNINGS 1
int main()
{
	//int i = 0;
	//const int* p = &i;
	//i = 100;
	//p = 100;
	//*p = 100;

	//int j = 10;
	//int* pj = &j;
	//const int * const * const ppj = &pj;
	//��const int* * ppj��const���ε�һ��*������*ppjָ������ݣ��ǲ���ͨ��*ppj�޸ĵ�
	//��int * const * ppj��const���εڶ���*������ppjָ������ݣ��ǲ���ͨ��ppj�޸ĵ�
	//��int * * const ppj��const����ppj������ppj�������һ��constֵ���ǲ����Ա�ֱ���޸ĵ�

	int x = 10;
	int* px = &x;
	const int * * ppx = &px;
	**ppx = 100;
	*ppx = 100;
	ppx = 100;

	int y = 10;
	int* py = &y;
	int * const * ppy = &py;
	**ppy = 100;
	*ppy = 100;
	ppy = 100;
	
	int z = 10;
	int* pz = &z;
	int* * const ppz = &pz;
	**ppz = 100;
	*ppz = 100;
	ppz = 100;

	int k = 10;
	int* pk = &k;
	const int * const * const ppk = &pk;
	**ppk = 100;
	*ppk = 100;
	ppk = 100;

	int k = 10;
	int* pk = &k;
	int** ppk = &pk;
	//const int * * * pppk = &ppk;//const���ε�һ��*������**pppkָ��һ��constֵ��ָ���������int����������ͨ��**pppk���ı���ָ�������
	//int * const * * pppk = &ppk;//const���εڶ���*������*pppkָ��һ��constֵ��ָ���������int*����������ͨ��*pppk���ı���ָ�������
	//int * * const * pppk = &ppk;//const���ε�����*������pppkָ��һ��constֵ��ָ���������int**����������ͨ��pppk���ı���ָ�������
	//int * * * const pppk = &ppk;//const����pppk������pppk�����ܱ�ֱ���޸ģ������������int***����������ֱ���޸�pppk���������
	//***pppk = 100;
	//**pppk = 100;
	//*pppk = 100;
	//pppk = 100;

	return 0;
}
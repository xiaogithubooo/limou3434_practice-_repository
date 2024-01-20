//ʹ�� const_cast <> �ĵ�������
#include <iostream>

struct type
{
    int _i;

    type(int i) :
        _i(3)
    {}

    void f(int v) const //2.2.չ���ȼ��� const type const * this
    {
        //this->_i = v;                    //2.3.�������this ��ָ�� const ��ָ��
        const_cast<type*>(this)->_i = v;   //2.4.���ڵ��õĶ����� const������������ OK �ģ��޸�û�д���Σ��
    }
};

int main()
{
    //1.ʹ����ͨ����������ʱ
    int i = 3;                 //1.1.������ i Ϊ const
    const int& rci = i;        //1.2.�����ã��������õĶ���ȴ���� const ���͵ģ�
    //rci = 4;                 //1.3.�޸�ʧ�ܣ����� i ���������Ա��޸ģ���������ʹ���˳����ã������޷��޸ģ����������޸��� i Ҳ����ʲôΣ�գ�
    const_cast<int&>(rci) = 4; //1.4.�޸ĳɹ������� i ���޸Ĳ������Σ�գ��Ͼ� i ����Ϳ��Ա��޸ģ�ֻ��Ҫ��֤ rci ������ò����޸� i ֵ����
    std::cout << "i = " << i << '\n';

    //2.ʹ���û����Զ�������ʱ
    type t(3);
    t.f(4); //2.1.���� struct ��û�ж���� const �� f()��ֻ�� const ���͵� f()����˻���� const �汾�� f()
    std::cout << "type::_i = " << t._i << '\n';

    //3.������������ʱ const type t����ôʹ�� t.f(4) ������δ������Ϊ�������Ҫ����ע��

    return 0;
}
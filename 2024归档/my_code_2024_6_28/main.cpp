// ʹ�� override ���⸸���麯��©д virtual ���²������û�Ԥ�ڵ���Ϊ
#include <iostream>
#include <string>
using namespace std;

class Person {
public:
    /* ����©д virtual �ؼ��� */ void buyTicket(const std::string& name) {
        cout << "��ͨƱ-" << name << ": ��Ʊ-ȫ��" << endl;
    }
};

class Student : public Person {
public:
    virtual void buyTicket(const std::string& name) override {
        cout << "ѧ��Ʊ-" << name << ": ��Ʊ-���" << endl;
    }
};

class Child : public Person {
public:
    virtual void buyTicket(const std::string& name) override {
        cout << "��ͯƱ-" << name << ": ��Ʊ-���" << endl;
    }
};

int main() {
    Student student;
    Child child;

    Person& person_ref_1 = student;
    Person& person_ref_2 = child;
    Person* person_ptr_1 = &student;
    Person* person_ptr_2 = &child;

    person_ref_1.buyTicket("limou");
    person_ref_2.buyTicket("gimou");

    person_ptr_1->buyTicket("limou");
    person_ptr_2->buyTicket("gimou");

    return 0;
}

/** ���Ա�������, �õ����½��
 * ѧ��Ʊ-limou: ��Ʊ-���
 * ��ͯƱ-gimou: ��Ʊ-���
 * ѧ��Ʊ-limou: ��Ʊ-���
 * ѧ��Ʊ-gimou: ��Ʊ-���
 */
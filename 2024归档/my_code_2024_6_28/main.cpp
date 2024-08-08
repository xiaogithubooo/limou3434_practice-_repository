// 使用 override 避免父类虚函数漏写 virtual 导致不符合用户预期的行为
#include <iostream>
#include <string>
using namespace std;

class Person {
public:
    /* 这里漏写 virtual 关键字 */ void buyTicket(const std::string& name) {
        cout << "普通票-" << name << ": 买票-全价" << endl;
    }
};

class Student : public Person {
public:
    virtual void buyTicket(const std::string& name) override {
        cout << "学生票-" << name << ": 买票-半价" << endl;
    }
};

class Child : public Person {
public:
    virtual void buyTicket(const std::string& name) override {
        cout << "儿童票-" << name << ": 买票-免费" << endl;
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

/** 尝试编译运行, 得到以下结果
 * 学生票-limou: 买票-半价
 * 儿童票-gimou: 买票-免费
 * 学生票-limou: 买票-半价
 * 学生票-gimou: 买票-免费
 */
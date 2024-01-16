//类描述和对象创建

//主类内使用 Person 对象
public class Main {
    public static void main(String[] args) {
        Person per = new Person(); //使用 new 语法创建
        per.name = "limou3434";
        per.age = 18;

        System.out.println("姓名:" + per.GetName());
        System.out.println("年龄:" + per.GetAge());
    }
}
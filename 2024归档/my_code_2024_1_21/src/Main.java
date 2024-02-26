import Person
//主类的主函数
public class Main {
    public static void main(String[] args) {
        Person per = new Person(); //使用 new 语法创建（实例化对象）
        per.name = "limou3434";
        per.age = 18;

        System.out.println("姓名:" + per.GetName());
        System.out.println("年龄:" + per.GetAge());
    }
}

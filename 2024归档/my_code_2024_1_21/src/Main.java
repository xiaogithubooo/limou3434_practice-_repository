class Student {
    public String name;
    public String gender;
    public int age;
    public double score;
    public static String school = "limou school";

    public void Init(String name, String gender, int age, double score) {
        this.name = name;
        this.gender = gender;
        this.age = age;
        this.score = score;
    }

    public static void ShowSchool() {
        System.out.println(Student.school);
    }
}

public class Main {
    public static void main(String[] args) {
        // 静态成员变量可以直接通过类名访问
        System.out.println(Student.school);
        Student s1 = new Student();
        Student s2 = new Student();
        Student s3 = new Student();
        s1.Init("Li leilei", "男", 18, 3.8);
        s2.Init("Han MeiMei", "女", 19, 4.0);
        s3.Init("Jim", "男", 18, 2.6);
        // 也可以通过对象访问：但是 school 是三个对象共享的
        Student.ShowSchool();
    }
}
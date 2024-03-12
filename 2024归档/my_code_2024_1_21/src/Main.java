class Outer {
    // 实例内部类/非静态内部类
    public int data_1 = 1;
    public int data_2 = 2;
    public static int data_3 = 3;

    public void Test_1() {
        System.out.println("Outer::test_1()");
    }

    static class Inner {
        public int data_3 = 4;
        public int data_4 = 5;
        public static int data_5 = 6;

        public void Test_2() {
            System.out.println("Inner::test_2()");
            // 静态内部类无法访问外部类成员，因为其本身不需要使用外部类来创建实例对象
            // System.out.println(data_1);
            // System.out.println(data_2);

            // 但是依旧是有方法的，可以创建一个外部类成员
            Outer o = new Outer();
            System.out.println(o.data_1);

            System.out.println(data_3);
            System.out.println(data_4);
            System.out.println(data_5);
        }
    }
}

public class Main {
    public static void main(String[] args) {
        Outer.Inner in = new Outer.Inner(); // 无需实例化外部类对象就可以使用
        in.Test_2();
    }
}
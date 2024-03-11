class MyClass {
    // 实例内部类/非静态内部类
    public int data = 1;
    class Sub {
        public int data = 2;

        public void Func() {
            System.out.println(this.data); // 获取内部对象
            System.out.println(MyClass.this.data); //获取外部对象
        }
    }
}

public class Main {
    public static void main(String[] args) {

        MyClass mc = new MyClass();
        mc.new Sub().Func();
    }
}
class A {
    public void func(String val) {
        System.out.println("A->" + val);
    }

    public void test() { // 暗含参数 A this
        func("1");
    }
}

class B extends A {
    public void func(String val) {
        System.out.println("B->" + val);
    }

    // 继承有调用
    // public void test(A this)
    //     func("1");
    // }
}

public class Main {
    public static void main(String[] args) {
        B b = new B();
        b.test(); // 尽管不是父类引用, 这里的最终结果也是 B->1
    }
}

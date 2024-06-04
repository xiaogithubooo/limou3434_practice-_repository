class Parent {
    @Override
    public String toString() {
        return "Parent's toString()";
    }
}

class Child extends Parent {
    // 子类没有实现 toString() 方法
    String name;
    public String toString() {
        return getClass().getName() + "[name=" + this.name + "]";
    }
}

public class Main {
    public static void main(String[] args) {
        Child child = new Child();
        System.out.println(child.getClass() + " - " + child.getClass().getName());
        System.out.println(child.toString());
    }
}



//1、测试溢出问题
public class Main {
    public static void main(String[] args) {
        System.out.println(Integer.MAX_VALUE+" "+Integer.MIN_VALUE);//Integer是int的包装类,简单理解为int的puls版本,这里可以计算出int所能存储的最大值和最小值
        System.out.println(2147483648);//报错
        System.out.println(2147483647 + 1);//不报错，但是类似C语言会回到最小值
    }
}//其他类型也有同样的问题
//2、测试单精度浮点数存储问题
class Main1 {
    public static void main(String[] args) {
        float b = 3.14;//报错
        System.out.println(b);

        float a = 3.14f;//不报错
        System.out.println(a);
    }
}
//3、测试强制类型转换
class Main2 {
    public static void main(String[] args) {
        int a = 10;
        long b = 100L;
        b = a;
        a = (int)b;//编译器没有报错
        System.out.println(a);
    }
}
//4、测试字符串与整型之间的转化
class Main3 {
    public static void main(String[] args) {
        //int转化为String
        int number = 100;
        //方法一
        String str1 = number+"hello";
        System.out.println(str1);
        //方法二
        String str2 = String.valueOf(number);
        System.out.println(str2);

        //String转化为int
        String str3 = "100";
        int num = Integer.parseInt(str3);
        System.out.println(num);
    }
}
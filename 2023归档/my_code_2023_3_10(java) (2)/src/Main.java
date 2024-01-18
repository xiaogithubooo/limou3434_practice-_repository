
public class Main {
    public static void main(String[] args) {
        int a = 1;
        int b = 2;
        System.out.println(a / b);               //0
        System.out.println((float)a / b);        //0.5
        System.out.println(a / (float)b);        //0.5
        System.out.println((float)(a / b));      //0
        System.out.println(1 / 2);               //0.5
        System.out.println(1.0 / 2);             //0.5
        System.out.println(1 / 2.0);             //0.5
    }
}
class Main1 {
    public static void main(String[] args) {
        int a = 10;
        int b = 3;
        System.out.println(a % b);         //1
        System.out.println(-a % b);        //-1
        System.out.println(a % -b);        //1
        System.out.println(-a % -b);      //-1
    }
}
////类型不匹配会发生自动匹配
class Main2 {
    public static void main(String[] args) {
        int a = 10;
        double b = 12.5;
        a += b;
        //a = (int)(a + b);//和这条语句等价
        System.out.println(a);
    }
}
//注意C语言和Java的不同
class Main3 {
    public static void main(String[] args) {
        int a = 10;
        a = ++a;
        System.out.println(a);
    }
}
//注意C语言和Java的不同

class Main4 {
    public static void main(String[] args) {
        int a = 11;
        int b = 12;
        if(5 < a < 10){//尽管在C语言中也不会这么写，但是C语言还能勉强运行，而Java直接无法使用，因为在Java里bool值不是一个具体的值（不像C语言，非零为真），没有办法与数值比较。因此还能得出另外一个结论，在if这种语法结构的括号中，不能直接使用数字，而是应该使用能得到true和false
            //某些代码
        }
    }
}
//注意C语言和Java的不同
class Main5 {
    public static void main(String[] args) {
        int a = 10;
        a = a++;
        System.out.println(a);//输出10，但是若是前置++就是11，这点和C语言区别很大
    }
}
//注意C语言和Java的不同
class Main6 {
    public static void main(String[] args) {
        int a = 10;
        if( a > 3 && a < 11){
            System.out.println(a);
        }
        System.out.println(!(a > 0));
    }
}
//注意C语言和Java的不同
class Main7 {
    public static void main(String[] args) {
        int a = 10;
        if( a > 3 && a < 11){
            System.out.println(a);
        }
        System.out.println(!(a > 0));//不能直接写!0
    }
}
//注意C语言和Java的不同
class Main8 {
    public static void main(String[] args) {
        int a = (10 > 5) ? 1 : 0;
        System.out.println(a);
    }
}
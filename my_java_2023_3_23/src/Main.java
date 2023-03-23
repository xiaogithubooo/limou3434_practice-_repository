import java.util.Scanner; // 需要导入util包
public class Main {
    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        System.out.println("请输入你的姓名：");
        String name = sc.nextLine();

        System.out.println("请输入你的年龄：");
        int age = sc.nextInt();

        System.out.println("请输入你的工资：");
        float salary = sc.nextFloat();

        System.out.println("你的信息如下：");
        System.out.println("姓名: "+name+"\n"+"年龄："+age+"\n"+"工资："+salary);

        sc.close(); // 注意, 要记得调用关闭方法
    }
}

//    public static void main(String[] args) {
//        int i = 1;
//
//        int A = 0;
//        int B = 0;
//        int C = 0;
//
//        while(i <= 100){
//            A += i;
//            i++;
//            if(i%2 == 0){
//                B += i;
//            }
//        }
//        C = A - B;
//        System.out.println(A+" "+B+" "+C);
//    }

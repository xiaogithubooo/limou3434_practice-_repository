import java.io.Console;

public class Main {
    public static void main(String[] args) {
        // 获取控制台对象
        Console console = System.console();

        if (console != null) {
            // 读取用户输入的用户名
            String username = console.readLine("请输入用户名：");

            // 读取用户输入的密码（不显示在控制台上）
            char[] password = console.readPassword("请输入密码：");

            // 对用户输入的用户名和密码进行处理
            System.out.println("用户名：" + username);
            System.out.println("密码：" + new String(password));
        } else {
            System.out.println("未能获取控制台对象");
        }
    }
}

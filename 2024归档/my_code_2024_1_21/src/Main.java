public class Main {
    public static void main(String[] args) {
        String str = "Hello 👋"; // 这里的 👋 是一个Emoji字符，使用了Unicode代理对
        int length = str.length(); // 会返回7或更多，因为Emoji表情符号是用代理对表示的
        int codePointCount = str.codePointCount(0, str.length()); // 更准确地反映了"用户感知"的字符数量
        System.out.println(length);
        System.out.println(codePointCount);
    }
}

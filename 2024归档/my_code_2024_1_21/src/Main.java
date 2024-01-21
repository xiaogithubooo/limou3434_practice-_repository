//自定义构造方法
class Data {
    public int _year;
    public int _month;
    public int _day;

    Data()
    {}

    public void SetData(int year, int month, int day) {
        _year = year;
        _month = month;
        _day = day;
        this.Print(); //设定好值后就打印
    }

    public void Print() {
        System.out.println(_year + " " + _month + " " + _day);
    }
}

public class Main {
    public static void main(String[] args) {
        Data d = new Data();
        d.Print();
    }
}

/* 输出结果
带参数的构造方法
不带参数的构造方法
2000 1 1
*/
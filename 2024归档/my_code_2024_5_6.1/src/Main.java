import javafx.application.Application;
import javafx.geometry.Insets;
import javafx.geometry.Pos;
import javafx.scene.Scene;
import javafx.scene.control.*;
import javafx.scene.layout.GridPane;
import javafx.stage.Stage;

public class Main extends Application {

    @Override
    public void start(Stage primaryStage) {
        // 设置舞台标题
        primaryStage.setTitle("进制转换器");

        // 设置网格布局
        GridPane grid = new GridPane();
        grid.setAlignment(Pos.CENTER); // 对齐方式
        grid.setHgap(10);
        grid.setVgap(10);
        grid.setPadding(new Insets(25, 25, 25, 25));

        // 输入文本框
        TextField inputTextField = new TextField();
        grid.add(inputTextField, 0, 0);

        // 输入开关组
        ToggleGroup inputGroup = new ToggleGroup();

        RadioButton binaryRadioButton = new RadioButton("2");
        binaryRadioButton.setToggleGroup(inputGroup);
        grid.add(binaryRadioButton, 0, 1);

        RadioButton octalRadioButton = new RadioButton("8");
        octalRadioButton.setToggleGroup(inputGroup);
        grid.add(octalRadioButton, 0, 2);

        RadioButton decimalRadioButton = new RadioButton("10");
        decimalRadioButton.setToggleGroup(inputGroup);
        grid.add(decimalRadioButton, 0, 3);
        decimalRadioButton.setSelected(true);

        RadioButton hexRadioButton = new RadioButton("16");
        hexRadioButton.setToggleGroup(inputGroup);
        grid.add(hexRadioButton, 0, 4);

        // 输出文本框
        TextField resultTextField = new TextField();
        resultTextField.setEditable(false); // 禁止输入
        grid.add(resultTextField, 1, 0);

        // 输出开关组
        ToggleGroup outputGroup = new ToggleGroup();

        RadioButton binaryOutputRadioButton = new RadioButton("2");
        binaryOutputRadioButton.setToggleGroup(outputGroup);
        grid.add(binaryOutputRadioButton, 1, 1);

        RadioButton octalOutputRadioButton = new RadioButton("8");
        octalOutputRadioButton.setToggleGroup(outputGroup);
        grid.add(octalOutputRadioButton, 1, 2);

        RadioButton decimalOutputRadioButton = new RadioButton("10");
        decimalOutputRadioButton.setToggleGroup(outputGroup);
        grid.add(decimalOutputRadioButton, 1, 3);
        decimalOutputRadioButton.setSelected(true);

        RadioButton hexOutputRadioButton = new RadioButton("16");
        hexOutputRadioButton.setToggleGroup(outputGroup);
        grid.add(hexOutputRadioButton, 1, 4);

        // 转化按钮
        Button convertButton = new Button("转换");
        grid.add(convertButton, 0, 5, 2, 1);
        GridPane.setHalignment(convertButton, javafx.geometry.HPos.CENTER);

        // 按钮事件绑定
        convertButton.setOnAction(e -> {
            try {
                String input = inputTextField.getText();
                int inputBase = Integer.parseInt(((RadioButton) inputGroup.getSelectedToggle()).getText());
                int outputBase = Integer.parseInt(((RadioButton) outputGroup.getSelectedToggle()).getText());

                int inputValue = Integer.parseInt(input, inputBase); // 输出 inputBase 进制下 input 对应的十进制整数
                String result = Integer.toString(inputValue, outputBase); // 把十进制整数转化为 outputBase 进制下的字符串
                resultTextField.setText(result.toUpperCase());
            } catch (NumberFormatException ex) {
                resultTextField.setText("输入格式错误");
            }
        });

        // 设置舞台和网格布局
        Scene scene = new Scene(grid, 400, 250);
        primaryStage.setScene(scene);
        primaryStage.show();
    }

    public static void main(String[] args) {
        launch(args);
    }
}


//import javafx.application.Application;
//import javafx.geometry.Insets;
//import javafx.scene.Scene;
//import javafx.scene.control.Label;
//import javafx.scene.control.TextField;
//import javafx.scene.layout.GridPane;
//import javafx.stage.Stage;
//
//// JavaFX 应用程序
//public class Main extends Application {
//    // JavaFX 应用程序的入口方法
//    @Override
//    public void start(Stage primaryStage) { // 应用程序的主舞台 Stage
//        // 设置主舞台标题
//        primaryStage.setTitle("简单计算器");
//
//        // 创建网格布局容器
//        GridPane grid = new GridPane();
//        grid.setPadding(new Insets(10, 10, 10, 10)); // 内边距
//        grid.setHgap(5); // 水平间隔为 5 像素
//        grid.setVgap(5); // 垂直间隔为 5 像素
//
//        // 创建三个文本框和两个标签
//        TextField operand1TextField = new TextField();
//        operand1TextField.setPromptText("操作数1");
//        GridPane.setConstraints(operand1TextField, 0, 0); // 网格布局中的位置
//
//        Label plusLabel = new Label("+"); // 加号标签
//        GridPane.setConstraints(plusLabel, 1, 0); // 网格布局中的位置
//
//        TextField operand2TextField = new TextField();
//        operand2TextField.setPromptText("操作数2");
//        GridPane.setConstraints(operand2TextField, 2, 0); // 网格布局中的位置
//
//        Label equalsLabel = new Label("="); // 等号标签
//        GridPane.setConstraints(equalsLabel, 3, 0); // 网格布局中的位置
//
//        TextField resultTextField = new TextField();
//        resultTextField.setEditable(false); // 禁止输入
//        resultTextField.setPromptText("结果");
//        GridPane.setConstraints(resultTextField, 4, 0); // 网格布局中的位置
//
//        // 给文本框 1 设置事件处理器(默认回车触发), 传递三个按钮对象
//        operand1TextField.setOnAction(e -> {
//            calculateResult(operand1TextField, operand2TextField, resultTextField);
//        });
//
//        // 给文本框 2 设置事件处理器(默认回车触发), 传递三个按钮对象
//        operand2TextField.setOnAction(e -> {
//            calculateResult(operand1TextField, operand2TextField, resultTextField);
//        });
//
//        // 将上面绑定好事件、设置好网格编号的所有控件设置进网格对象中, 并且交给舞台显示
//        grid.getChildren().addAll(operand1TextField, plusLabel, operand2TextField, equalsLabel, resultTextField);
//        primaryStage.setScene(new Scene(grid, 300, 60));
//        primaryStage.show();
//    }
//
//    // 按钮事件的回调方法
//    private void calculateResult(TextField operand1TextField, TextField operand2TextField, TextField resultTextField) {
//        try {
//            double operand1 = Double.parseDouble(operand1TextField.getText()); // 解析字符串为 double
//            double operand2 = Double.parseDouble(operand2TextField.getText()); // 解析字符串为 double
//            double result = operand1 + operand2; // 计算出结果
//            resultTextField.setText(Double.toString(result)); // 将计算结果设置进第三个文本框中
//        } catch (NumberFormatException ex) { // 捕捉 NumberFormatException 类型的错误
//            resultTextField.setText("输入格式错误");
//        }
//    }
//
//    public static void main(String[] args) {
//        launch(args);
//    }
//}
//
//
////public class Main {
////    public static void main(String[] args) {
////        String[] strings = {"string", "starting", "strong", "street", "stir", "studeng", "soft", "string"};
////
////        int startWithStCount = 0;
////        int endWithNgCount = 0;
////
////        for (String str : strings) {
////            if (str.startsWith("st")) {
////                startWithStCount++;
////            }
////            if (str.endsWith("ng")) {
////                endWithNgCount++;
////            }
////        }
////
////        System.out.println("以\"st\"开头的字符串数量：" + startWithStCount);
////        System.out.println("以\"ng\"结尾的字符串数量：" + endWithNgCount);
////    }
////}
////
//////import java.util.Scanner;
//////
//////public class Main {
//////    public static void main(String[] args) {
//////        Scanner scanner = new Scanner(System.in);
//////        int[] numbers = new int[10];
//////
//////        System.out.println("请输入10个整数：");
//////        for (int i = 0; i < numbers.length; i++) {
//////            System.out.print("整数 " + (i + 1) + ": ");
//////            numbers[i] = scanner.nextInt();
//////        }
//////
//////        int sum = 0;
//////        for (int num : numbers) {
//////            sum += num;
//////        }
//////
//////        double average = (double) sum / numbers.length;
//////        System.out.println("平均值为：" + average);
//////
//////        scanner.close();
//////    }
//////}
//////
//////
////////// Animal.java
////////class Animal {
////////    private String name;
////////    private String species;
////////    private int age;
////////    private String gender;
////////
////////    public Animal(String name, String species, int age, String gender) {
////////        this.name = name;
////////        this.species = species;
////////        this.age = age;
////////        this.gender = gender;
////////    }
////////
////////    public void displayInfo() {
////////        System.out.println("Name: " + name);
////////        System.out.println("Species: " + species);
////////        System.out.println("Age: " + age);
////////        System.out.println("Gender: " + gender);
////////    }
////////
////////    public String getName() {
////////        return name;
////////    }
////////}
////////
////////// Zoo.java
////////class Zoo {
////////    private String name;
////////    private String location;
////////    private Animal[] animals;
////////
////////    public Zoo(String name, String location) {
////////        this.name = name;
////////        this.location = location;
////////        this.animals = new Animal[10]; // 假设最多能容纳10只动物
////////    }
////////
////////    public void addAnimal(Animal animal) {
////////        for (int i = 0; i < animals.length; i++) {
////////            if (animals[i] == null) {
////////                animals[i] = animal;
////////                System.out.println(animal.getName() + " has been added to the zoo.");
////////                return;
////////            }
////////        }
////////        System.out.println("The zoo is full. Cannot add more animals.");
////////    }
////////
////////    public void displayAnimals() {
////////        System.out.println("Animals in " + name + ":");
////////        for (Animal animal : animals) {
////////            if (animal != null) {
////////                animal.displayInfo();
////////                System.out.println("-------------------");
////////            }
////////        }
////////    }
////////}
////////
////////public class Main {
////////    public static void main(String[] args) {
////////        Zoo zoo = new Zoo("My Zoo", "City Center");
////////
////////        // 添加一些动物
////////        Animal lion = new Animal("Leo", "Lion", 5, "Male");
////////        zoo.addAnimal(lion);
////////
////////        Animal elephant = new Animal("Ellie", "Elephant", 10, "Female");
////////        zoo.addAnimal(elephant);
////////
////////        // 显示动物园中的动物信息
////////        zoo.displayAnimals();
////////    }
////////}
//////
//////
////////// 基本员工父类
////////class Employee {
////////    private String name; // 员工姓名
////////    private int birthMonth; // 员工生日
////////    private double salary; //基本工资
////////
////////    //无参构造
////////    public Employee() {
////////    }
////////
////////    //靠姓名和生日的构造
////////    public Employee(String name, int birthMonth) {
////////        this.name = name;
////////        this.birthMonth = birthMonth;
////////    }
////////
////////    // 获取员工基本工作
////////    public double getSalary() {
////////        return salary;
////////    }
////////
////////    public void setSalary(double salary) {
////////        this.salary = salary;
////////    }
////////
////////    // 获取员工姓名
////////    public String getName() {
////////        return name;
////////    }
////////
////////    // 设置员工姓名
////////    public void setName(String name) {
////////        this.name = name;
////////    }
////////
////////    // 获取员工生日
////////    public int getBirthMonth() {
////////        return birthMonth;
////////    }
////////
////////    // 设置员工生日
////////    public void setBirthMonth(int birthMonth) {
////////        this.birthMonth = birthMonth;
////////    }
////////
////////    // 打印员工基本信息
////////    public void showInfo() {
////////        System.out.println("Name: " + name);
////////        System.out.println("Birth Month: " + birthMonth);
////////        System.out.println("Salary: " + salary);
////////    }
////////}
////////
////////// 小时工资员工
////////class HourlyEmployee extends Employee {
////////    private double hourlyWage; // 每小时的工资
////////    private double hoursWorked; // 每月工作的小时数
////////
////////    // 无参构造
////////    public HourlyEmployee() {
////////    }
////////
////////    // 根据员工姓名、生日、小时工资、统计小时
////////    public HourlyEmployee(String name, int birthMonth, double hourlyWage, double hoursWorked) {
////////        super(name, birthMonth);
////////        this.hourlyWage = hourlyWage;
////////        this.hoursWorked = hoursWorked;
////////    }
////////
////////    // 重载父类的 getSalary() 方法, 传入这个月的月份数来得到工资
////////    public double getSalary(int month) {
////////        double salary = hourlyWage * hoursWorked;
////////        if (month == getBirthMonth()) { //是生日
////////            if (hoursWorked > 160) {
////////                salary = salary * 1.5 + 100;
////////            } else {
////////                salary += 100;
////////            }
////////        } else if (hoursWorked > 160) { //非生日
////////            salary *= 1.5;
////////        }
////////        return salary;
////////    }
////////
////////    // 获取工作每小时工资
////////    public double getHourlyWage() {
////////        return hourlyWage;
////////    }
////////
////////    // 设置工作每小时工资
////////    public void setHourlyWage(double hourlyWage) {
////////        this.hourlyWage = hourlyWage;
////////    }
////////
////////    // 获取工作的总小时
////////    public double getHoursWorked() {
////////        return hoursWorked;
////////    }
////////
////////    // 设置工作的总小时
////////    public void setHoursWorked(double hoursWorked) {
////////        this.hoursWorked = hoursWorked;
////////    }
////////
////////    // 重写员工信息显示方法
////////    @Override
////////    public void showInfo() {
////////        super.showInfo();
////////        System.out.println("Hourly Wage: " + hourlyWage);
////////        System.out.println("Hours Worked: " + hoursWorked);
////////    }
////////}
////////
////////// 固定工资员工
////////class SalesEmployee extends Employee {
////////    private double salesAmount; // 固定工资
////////    private double commissionRate; // 月薪
////////
////////    // 无参构造
////////    public SalesEmployee() {
////////    }
////////
////////    //姓名、生日、固定工资、月薪构造
////////    public SalesEmployee(String name, int birthMonth, double salesAmount, double commissionRate) {
////////        super(name, birthMonth);
////////        this.salesAmount = salesAmount;
////////        this.commissionRate = commissionRate;
////////    }
////////
////////    //重载父类的 getSalary()
////////    public double getSalary(int month) {
////////        double salary = salesAmount * commissionRate;
////////        if (month == getBirthMonth()) {
////////            salary += 100;
////////        }
////////        return salary;
////////    }
////////
////////    public double getSalesAmount() {
////////        return salesAmount;
////////    }
////////
////////    public void setSalesAmount(double salesAmount) {
////////        this.salesAmount = salesAmount;
////////    }
////////
////////    public double getCommissionRate() {
////////        return commissionRate;
////////    }
////////
////////    public void setCommissionRate(double commissionRate) {
////////        this.commissionRate = commissionRate;
////////    }
////////
////////    @Override
////////    public void showInfo() {
////////        super.showInfo();
////////        System.out.println("Sales Amount: " + salesAmount);
////////        System.out.println("Commission Rate: " + commissionRate);
////////    }
////////}
////////
////////// 销售工资员工
////////class SalariedEmployee extends Employee {
////////    private double fixedSalary;
////////
////////    public SalariedEmployee() {
////////    }
////////
////////    public SalariedEmployee(double fixedSalary) {
////////        this.fixedSalary = fixedSalary;
////////    }
////////
////////    public SalariedEmployee(String name, int birthMonth, double fixedSalary) {
////////        super(name, birthMonth);
////////        this.fixedSalary = fixedSalary;
////////    }
////////
////////    public double getSalary(int month) {
////////        double salary = fixedSalary;
////////        if (month == getBirthMonth()) {
////////            salary += 100;
////////        }
////////        return salary;
////////    }
////////
////////    public double getFixedSalary() {
////////        return fixedSalary;
////////    }
////////
////////    public void setFixedSalary(double fixedSalary) {
////////        this.fixedSalary = fixedSalary;
////////    }
////////
////////    @Override
////////    public void showInfo() {
////////        super.showInfo();
////////        System.out.println("Fixed Salary: " + fixedSalary);
////////    }
////////}
////////
////////// TestEmployee.java
////////public class Main {
////////    public static void main(String[] args) {
////////        HourlyEmployee hourlyEmployee = new HourlyEmployee("John", 5, 20, 180);
////////        hourlyEmployee.showInfo();
////////        System.out.println("Salary for May: " + hourlyEmployee.getSalary(5));
////////
////////        SalesEmployee salesEmployee = new SalesEmployee("Alice", 8, 100000, 0.1);
////////        salesEmployee.showInfo();
////////        System.out.println("Salary for August: " + salesEmployee.getSalary(8));
////////
////////        SalariedEmployee salariedEmployee = new SalariedEmployee("Bob", 10, 5000);
////////        salariedEmployee.showInfo();
////////        System.out.println("Salary for October: " + salariedEmployee.getSalary(10));
////////    }
////////}

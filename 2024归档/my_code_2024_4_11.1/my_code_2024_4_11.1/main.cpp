#include <iostream>
#include <source_location>

//void myFunction(const std::source_location& location = std::source_location::current())
//{
//    std::cout   << "Function called from file: "<< location.file_name()
//                << ", line: " << location.line()
//                << ", function: " << location.function_name() 
//                << std::endl;
//}
//
//int main()
//{
//    myFunction();
//    return 0;
//}


// 定义一个宏来包装调用函数的语句，传入__LINE__
#define CALL_FUNCTION() myFunction(__LINE__)

void myFunction(int line) {
    std::cout << "This function is called from line " << line << std::endl;
}

int main() {
    CALL_FUNCTION();  // 调用宏
    return 0;
}
#include <iostream>
#include <cstdlib>
#include <fstream>
#include "../cpp-httplib/httplib.h"

int main(int argc, char const* argv[]) {
    using namespace httplib;
    Client cli(argv[1], atoi(argv[2]));

    //1.发送 GET 请求
    auto res_get = cli.Get("/my_get");
    if (res_get->status == 200) {
        std::cout << "get success" << std::endl;
        std::cout << "返回响应的状态码: " << res_get->status << std::endl;
        std::cout << "返回响应具体内容: " << res_get->body << std::endl;
    } else {
        std::cout << "get error" << std::endl;
    }

    //2.发送 POST 请求
    //读取文件内容
    std::ifstream file("example.txt", std::ios::binary);
    if (!file.is_open()) {
        std::cout << "open error" << std::endl;
        return 1;
    }

    //读取文件内容到字符串
    std::stringstream buffer;
    buffer << file.rdbuf(); //使用 rdbuf() 获取文件流的底层缓冲区, 类似 read()
    std::string file_content = buffer.str();

    MultipartFormData item;
    item.name = "file"; //表单字段名
    item.filename = "example.txt"; //作为文件名
    item.content = file_content.c_str(); //文件内容
    item.content_type = "text/plain"; //文件格式
    MultipartFormDataItems items;
    items.push_back(item);

    //发送 POST 请求上传文件, 并且返回 res 响应
    auto res = cli.Post("/my_post", items);

    if (res && res->status == 200) {
        std::cout << "port success" << std::endl;
        std::cout << "返回响应的状态码: " << res_get->status << std::endl;
        std::cout << "服务端响应具体内容" << res->body << std::endl;
    } else {
        std::cout << "port error" << std::endl;
    }

    return 0;
}

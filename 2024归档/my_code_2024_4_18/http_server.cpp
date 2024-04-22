#include <iostream>
#include <string>
#include <cstdlib>
#include "../cpp-httplib/httplib.h"

int main(int argc, char const* argv[]) {
    using namespace httplib;
    Server svr;

    svr.Get(R"(/my_get)", [](const Request& req, Response& res) {
            std::cout << "a get request." << std::endl;
            res.set_content("hello world!", "text/plain");
            res.status = 200;
        }
    );

    svr.Post(R"(/my_post)", [](const Request& req, Response& res) {
            std::cout << "a post request." << std::endl;
            auto ret = req.has_file("file");
            if (!ret) 
            {
                std::cout << "not file upload.\n";
                res.status = 404;
                return;
            }
                
            const auto& file = req.get_file_value("file");
            std::cout
                << file.filename << std::endl
                << file.content_type << std::endl
                << file.content << std::endl;
        
            std::string message = "The file is ";
            message += file.filename;
            message += "-";
            message += file.content_type;
            message += "\n";
            message += file.content;
            
            res.set_content(message.c_str(), "text/plain");
            res.status = 200;
        }
    );

    svr.listen("0.0.0.0", atoi(argv[1]));
    
    return 0;
}

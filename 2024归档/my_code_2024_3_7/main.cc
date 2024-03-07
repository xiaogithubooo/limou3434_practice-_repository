//main.cc 内部
#include <iostream>
#include <string>
#include <unistd.h>
#include <mysql/mysql.h>

const std::string host = "127.0.0.1"; //也可以使用 localhost
const std::string user = "eimou";
const std::string passwd = "MYSQLWishuxue31415ei_"; //这里我隐去了我的密码
const std::string db = "conn";
const unsigned int port = 3306;

int main()
{
    //1.获取客户端版本信息
    std::cout << "mysql client Version " << mysql_get_client_info() << std::endl; 
    
    //2.初始化，获得一个句柄
    MYSQL* mySql = mysql_init(nullptr);
    if (mySql == nullptr)
    {
        std::cerr << "mysql_init() error" << std::endl;
        exit(1);
    }
    
    //3.修改本客户端的对应字符集，避免传输过程中出现乱码
    mysql_set_character_set(mySql, "utf8");

    //4.连接数据库
    if (mysql_real_connect(
        mySql, //内部包含套接字信息   
        host.c_str(), //连接主机 IP
        user.c_str(), //用户
        passwd.c_str(), //密码
        db.c_str(), //对应的数据库
        port, //端口号
        nullptr, //域间套接字
    	0 //客户端标志
    ) == nullptr)
    {
        std::cerr << "mysql_real_connrct() error" << std::endl;
        exit(2);
    }
    
    //5.操作数据库
    std::string sql;
    while(true)
    {
        std::cout << "insert sql >>> "; 
        
        if (!std::getline(std::cin, sql))
        {
            break;
        }
        
        if (sql == "quit" || sql == "exit")
        {
            std::cout << "bye~" << std::endl;
            break;
        }
        
        if (mysql_query(mySql, sql.c_str()) != 0)
        {
            std::cerr << "mysql_query() error" << std::endl;
            exit(3);
        }
         
        //6.读取
        MYSQL_RES* res = mysql_store_result(mySql); //MYSQL_RES 是一个类型，指向的对象可以保存查询的数据，把数据全部当作字符串存储起来，可以看作一个 char** arr[]，每个元素都是一个 char* arr[]
		if (res == nullptr)
        {
            std::cerr << "mysql_store_result() error" << std::endl;
            exit(4);
        }
        else
        {
            //读取行数和列数
            my_ulonglong rows = mysql_num_rows(res);
            my_ulonglong fields = mysql_num_fields(res);
            std::cout << "rows: " << rows << "fields: " << fields << std::endl;
            
            //读取具体的行内内容
            //该函数行为类似 C++ 的迭代器
            for (int i = 0; i < rows; i++)
            {
                MYSQL_ROW row = mysql_fetch_row(res); //每次遍历自动移动行
                for (int j = 0; j < fields; j++)
                {
                    std::cout << row[j] << "\t";
                }
                std::cout << "\n";
            }
        }
    }
    
    //7.释放句柄
    mysql_close(mySql);
    
    return 0;
}
const express = require('express');
const app = express();
const PORT = 8083;

// 添加CORS中间件
app.use((req, res, next) => {
    res.header('Access-Control-Allow-Origin', '*'); // 允许来自所有域的请求
    res.header('Access-Control-Allow-Headers', 'Origin, X-Requested-With, Content-Type, Accept');
    next();
});

// 定义一个 GET 接口, 返回一个字符串
app.get('/', (req, res) => {
    res.send('Hello, World!');
});

// 启动服务器, 监听 127.0.0.1:8082
app.listen(PORT, '127.0.0.1', () => {
    console.log(`Server is running on http://127.0.0.1:${PORT}`);
});

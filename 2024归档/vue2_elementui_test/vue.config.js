const { defineConfig } = require('@vue/cli-service')
module.exports = defineConfig({
  transpileDependencies: true,
  devServer: {
    host: '127.0.0.1', // 更改 ip
    port: 8080 // 更换 ip
  }
})

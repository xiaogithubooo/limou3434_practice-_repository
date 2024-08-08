<!-- HomeView.vue -->
<template>
  <div class="home">
    <img alt="Vue logo" src="../assets/logo.png">
    <HelloWorld msg="Welcome to Your Vue.js App"/> <!-- 在这里使用子组件, 同时传入属性值(3.最后用子组件) -->
  </div>
</template>

<script>
import HelloWorld from '@/components/HelloWorld.vue' // 这里的 @ 通常代指 /src 目录, 这里成功导入了子组件(1.先导入子组件)

export default {
  name: 'HomeView',
  components: { // 这里注册了子组件, 和之前使用 Vue.component() 类似(2.再注册子组件)
    HelloWorld
  }
}
</script>

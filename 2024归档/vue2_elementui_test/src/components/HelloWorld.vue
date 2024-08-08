<!-- HelloWorld.vue -->
<template>
  <div class="hello"> <!-- 模板部分 -->
    <h1>{{ msg }}</h1>
    <p>
      For a guide and recipes on how to configure / customize this project,<br>
      check out the
      <a href="https://cli.vuejs.org" rel="noopener" target="_blank">vue-cli documentation</a>.
    </p>
    <h3>Installed CLI Plugins</h3>
    <ul>
      <li><a href="https://github.com/vuejs/vue-cli/tree/dev/packages/%40vue/cli-plugin-babel" rel="noopener"
             target="_blank">babel</a></li>
      <li><a href="https://github.com/vuejs/vue-cli/tree/dev/packages/%40vue/cli-plugin-router" rel="noopener"
             target="_blank">router</a></li>
      <li><a href="https://github.com/vuejs/vue-cli/tree/dev/packages/%40vue/cli-plugin-eslint" rel="noopener"
             target="_blank">eslint</a></li>
    </ul>
    <h3>Essential Links</h3>
    <ul>
      <li><a href="https://vuejs.org" rel="noopener" target="_blank">Core Docs</a></li>
      <li><a href="https://forum.vuejs.org" rel="noopener" target="_blank">Forum</a></li>
      <li><a href="https://chat.vuejs.org" rel="noopener" target="_blank">Community Chat</a></li>
      <li><a href="https://twitter.com/vuejs" rel="noopener" target="_blank">Twitter</a></li>
      <li><a href="https://news.vuejs.org" rel="noopener" target="_blank">News</a></li>
    </ul>
    <h3>Ecosystem</h3>
    <ul>
      <li><a href="https://router.vuejs.org" rel="noopener" target="_blank">vue-router</a></li>
      <li><a href="https://vuex.vuejs.org" rel="noopener" target="_blank">vuex</a></li>
      <li><a href="https://github.com/vuejs/vue-devtools#vue-devtools" rel="noopener" target="_blank">vue-devtools</a>
      </li>
      <li><a href="https://vue-loader.vuejs.org" rel="noopener" target="_blank">vue-loader</a></li>
      <li><a href="https://github.com/vuejs/awesome-vue" rel="noopener" target="_blank">awesome-vue</a></li>
    </ul>
  </div>
</template>

<script>
export default { // 导出一个默认对象
  name: 'HelloWorld', // name 关键字设置了子组件的名字
  props: { // props 关键字设置组件可以接受的属性, 其实就是我们之前在 Vue.js 基础中学习的子组件内部的数据
    msg: String // 这里的 msg 就是子组件所能接受的属性, 这里指定了类型必须是 String
  }
}
// 之前的代码中我们是按照下面这种方式定义一个子组件的, 其实和上面类似
// -- 代码片段 --
// Vue.component('Child', {
// props: ['mess1', 'mess2'],
//     template: `
//             <div>
//                 <span>{{ mess1 }}</span><br>
//                 <span>{{ mess2 }}</span>
//             </div>
//         `
// })
//
// new Vue({
//   el: '#app'
// })
// -- 代码片段 --
</script>

<!-- Add "scoped" attribute to limit CSS to this component only -->
<style scoped>
h3 {
  margin: 40px 0 0;
}

ul {
  list-style-type: none;
  padding: 0;
}

li {
  display: inline-block;
  margin: 0 10px;
}

a {
  color: #42b983;
}
</style>

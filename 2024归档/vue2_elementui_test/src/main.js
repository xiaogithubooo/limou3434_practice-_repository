// main.js
import Vue from 'vue'
import App from './App.vue'
import router from './router'
import ElementUI from 'element-ui';
import 'element-ui/lib/theme-chalk/index.css';

Vue.use(ElementUI);

Vue.config.productionTip = false

new Vue({
  router,
  render: h => h(App) // 创建一个 App 组件的虚拟节点, 并将其渲染为实际的 DOM 元素, h 实际上就是 createElement()
}).$mount('#app') // 这种挂载是手动挂载, 可以等待 vue 实例创建后再手动挂载, 从最终效果上和 el 差不多

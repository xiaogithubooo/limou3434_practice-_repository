<!-- App.vue -->
<template>
  <div id="app">
    <nav> <!-- 这个 nav 只是一个语义标签, 主要是用在页面中的导航链接部分, 它通常包含一组链接, 用户可以通过这些链接在网站或应用的不同部分之间进行导航, 主要是为了增加代码可读性和搜索引擎 SEO 友好的 -->
      <router-link to="/">Home</router-link> <!-- 显示 Home 视图链接 -->
      |
      <router-link to="/about">about</router-link> <!-- 显示 about 视图链接 -->
      |
      <router-link to="/button">button</router-link> <!-- 显示 about 视图链接 -->
      |
      <router-link to="/table">table</router-link> <!-- 显示 about 视图链接 -->
      |
      <router-link to="/pagination">pagination</router-link> <!-- 显示 about 视图链接 -->
      |
      <router-link to="/dialog">dialog</router-link> <!-- 显示 about 视图链接 -->
      |
      <router-link to="/from">from</router-link> <!-- 显示 about 视图链接 -->
      |
      <router-link to="/container">container</router-link> <!-- 显示 about 视图链接 -->
      |
      <router-link to="/navMenu">navMenu</router-link> <!-- 显示 about 视图链接 -->
      |
      <router-link to="/ajax">ajax</router-link> <!-- 显示 about 视图链接 -->
    </nav>
    <router-view/> <!-- 页面/视图的显示地点 -->
  </div>
</template>

<style>
#app {
  font-family: Avenir, Helvetica, Arial, sans-serif;
  -webkit-font-smoothing: antialiased;
  -moz-osx-font-smoothing: grayscale;
  text-align: center;
  color: #2c3e50;
}

nav {
  padding: 30px;
}

nav a {
  font-weight: bold;
  color: #2c3e50;
}

nav a.router-link-exact-active {
  color: #42b983;
}
</style>
<script setup lang="ts">
</script>
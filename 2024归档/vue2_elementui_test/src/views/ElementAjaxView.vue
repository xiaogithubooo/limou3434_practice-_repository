<!-- EllementAjaxView.vue -->
<template>
  <div>
    <h1>测试 Express 服务器</h1>
    <button @click="fetchData">获取数据</button>
    <div v-if="loading">加载中...</div>
    <div v-if="error" class="error">错误: {{ error }}</div>
    <div v-if="data">
      <h2>返回的数据:</h2>
      <pre>{{ data }}</pre>
    </div>
  </div>
</template>

<script>
import axios from 'axios';

export default {
  data() {
    return {
      data: null,
      error: null,
      loading: false,
    };
  },
  methods: {
    async fetchData() {
      this.loading = true;
      this.error = null;
      try {
        const response = await axios.get('http://127.0.0.1:8083/');
        this.data = response.data;
      } catch (err) {
        this.error = err.message;
      } finally {
        this.loading = false;
      }
    },
  },
};
</script>

<style scoped>
.error {
  color: red;
}
</style>

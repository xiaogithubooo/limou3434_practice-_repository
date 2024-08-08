<!-- ElementPaginationView.vue -->
<template>
  <!-- 表格部分 -->
  <div>
    <el-table :data="currentPageData" border style="width: 100%">
      <el-table-column
          label="日期"
          prop="date"
          width="180">
      </el-table-column>
      <el-table-column
          label="姓名"
          prop="name"
          width="180">
      </el-table-column>
      <el-table-column
          label="地址"
          prop="address">
      </el-table-column>
    </el-table>

    <!-- 分页部分 -->
    <el-pagination
        :key="paginationKey"
        :page-size="pageSize"
        :total="totalItems"
        background
        layout="sizes, prev, pager, next, jumper, total"
        @current-change="handlePageChange"
        @size-change="handleSizeChange">
    </el-pagination>
  </div>
</template>

<script>
export default {
  data() {
    return {
      currentPage: 1, // 当前页码
      pageSize: 10, // 默认每页显示的条目数为 10
      paginationKey: 0, // 新增的 key 属性, 由于 key 值被修改, 可以强迫组件重新渲染
      tableData: [ // 需要渲染的大量数组
        {date: '2016-05-02', name: '王小虎', address: '上海市普陀区金沙江路 1518 弄'},
        {date: '2016-05-04', name: '王小虎', address: '上海市普陀区金沙江路 1517 弄'},
        {date: '2016-05-01', name: '王小虎', address: '上海市普陀区金沙江路 1519 弄'},
        {date: '2016-05-03', name: '王小虎', address: '上海市普陀区金沙江路 1516 弄'},
        {date: '2017-05-02', name: '李小龙', address: '北京市朝阳区望京街 1518 弄'},
        {date: '2017-05-04', name: '李小龙', address: '北京市朝阳区望京街 1517 弄'},
        {date: '2017-05-01', name: '李小龙', address: '北京市朝阳区望京街 1519 弄'},
        {date: '2017-05-03', name: '李小龙', address: '北京市朝阳区望京街 1516 弄'},
        {date: '2018-06-12', name: '张三', address: '广州市天河区体育西路 20 号'},
        {date: '2018-06-15', name: '张三', address: '广州市天河区体育西路 21 号'},
        {date: '2018-06-18', name: '张三', address: '广州市天河区体育西路 22 号'},
        {date: '2018-06-20', name: '张三', address: '广州市天河区体育西路 23 号'},
        {date: '2019-07-22', name: '赵四', address: '深圳市南山区科技园 1 号'},
        {date: '2019-07-25', name: '赵四', address: '深圳市南山区科技园 2 号'},
        {date: '2019-07-28', name: '赵四', address: '深圳市南山区科技园 3 号'},
        {date: '2019-07-30', name: '赵四', address: '深圳市南山区科技园 4 号'},
        {date: '2020-08-05', name: '王五', address: '杭州市西湖区文三路 100 号'},
        {date: '2020-08-08', name: '王五', address: '杭州市西湖区文三路 101 号'},
        {date: '2020-08-11', name: '王五', address: '杭州市西湖区文三路 102 号'},
        {date: '2020-08-13', name: '王五', address: '杭州市西湖区文三路 103 号'},
        {date: '2021-09-10', name: '刘德华', address: '广州市越秀区中山五路 10 号'},
        {date: '2021-09-15', name: '刘德华', address: '广州市越秀区中山五路 11 号'},
        {date: '2021-09-20', name: '刘德华', address: '广州市越秀区中山五路 12 号'},
        {date: '2021-09-25', name: '刘德华', address: '广州市越秀区中山五路 13 号'},
        {date: '2022-10-01', name: '张学友', address: '上海市静安区南京西路 100 号'},
        {date: '2022-10-05', name: '张学友', address: '上海市静安区南京西路 101 号'},
        {date: '2022-10-10', name: '张学友', address: '上海市静安区南京西路 102 号'},
        {date: '2022-10-15', name: '张学友', address: '上海市静安区南京西路 103 号'},
        {date: '2023-11-01', name: '周杰伦', address: '北京市海淀区中关村大街 1 号'},
        {date: '2023-11-05', name: '周杰伦', address: '北京市海淀区中关村大街 2 号'},
        {date: '2023-11-10', name: '周杰伦', address: '北京市海淀区中关村大街 3 号'},
        {date: '2023-11-15', name: '周杰伦', address: '北京市海淀区中关村大街 4 号'},
        {date: '2024-12-01', name: '陈奕迅', address: '深圳市福田区福华路 50 号'},
        {date: '2024-12-05', name: '陈奕迅', address: '深圳市福田区福华路 51 号'},
        {date: '2024-12-10', name: '陈奕迅', address: '深圳市福田区福华路 52 号'},
        {date: '2024-12-15', name: '陈奕迅', address: '深圳市福田区福华路 53 号'}
      ]
    };
  },
  computed: { // 计算属性方法
    totalItems() {
      return this.tableData.length; // 返回数据总条数
    },
    currentPageData() { // 当组件需要数据进行渲染时, 这里动态计算最多显示的条目个数数组, 然后再做返回
      const start = (this.currentPage - 1) * this.pageSize;
      const end = start + this.pageSize;
      return this.tableData.slice(start, end); // 获取当前页的数据
    }
  },
  methods: { // 普通方法
    handlePageChange(page) { // 当页面发生改变时触发
      this.currentPage = page; // 数据模型中存储一份页面数据, 导致同步被触发, 使得之前缓存的计算属性 currentPageData() 被重新进行计算
    },
    handleSizeChange(size) { // 当用户选择不同的最大显示条数时触发
      this.pageSize = size; // 数据模型中存储一份页面数据, 导致同步被触发, 使得之前缓存的计算属性 currentPageData() 被重新进行计算
      this.currentPage = 1; // 并且切换每页条数后默认重置为第一页
      this.paginationKey += 1; // 改变 key 以重新渲染分页组件
    }
  }
}
</script>

<style scoped>
/* 你的样式可以写在这里 */
</style>

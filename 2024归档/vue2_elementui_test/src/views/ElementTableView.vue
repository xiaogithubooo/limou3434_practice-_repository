<!-- ElementTableView.vue -->
<template>
  <el-table :data="tableData" border style="width: 100%">
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
</template>

<script>
export default {
  data() {
    return {
      tableData: [{
        date: '2016-05-02',
        name: '王小虎',
        address: '上海市普陀区金沙江路 1518 弄'
      }, {
        date: '2016-05-04',
        name: '王小虎',
        address: '上海市普陀区金沙江路 1517 弄'
      }, {
        date: '2016-05-01',
        name: '王小虎',
        address: '上海市普陀区金沙江路 1519 弄'
      }, {
        date: '2016-05-03',
        name: '王小虎',
        address: '上海市普陀区金沙江路 1516 弄'
      }]
    }
  }
}
</script>
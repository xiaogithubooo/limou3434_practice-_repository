<!-- ElementNavMenuView.vue -->
<template>
  <div>
    <el-container>
      <el-aside width="200px">
        <el-menu
            :collapse="isCollapse"
            :default-active="activeMenu"
            @close="handleClose"
            @open="handleOpen"
            @select="handleSelect">
          <el-menu-item index="1">
            <i class="el-icon-setting"></i>
            <span slot="title">导航一</span>
          </el-menu-item>
          <el-menu-item index="2">
            <i class="el-icon-setting"></i>
            <span slot="title">导航二</span>
          </el-menu-item>
          <el-menu-item index="3">
            <i class="el-icon-setting"></i>
            <span slot="title">导航三</span>
          </el-menu-item>
          <el-menu-item index="4">
            <i class="el-icon-setting"></i>
            <span slot="title">导航四</span>
          </el-menu-item>
          <el-menu-item index="5">
            <i class="el-icon-setting"></i>
            <span slot="title">导航五</span>
          </el-menu-item>
          <el-menu-item index="6">
            <i class="el-icon-setting"></i>
            <span slot="title">导航六</span>
          </el-menu-item>
          <el-menu-item index="7">
            <i class="el-icon-setting"></i>
            <span slot="title">导航七</span>
          </el-menu-item>
          <el-menu-item index="8">
            <i class="el-icon-setting"></i>
            <span slot="title">导航八</span>
          </el-menu-item>
          <el-menu-item index="9">
            <i class="el-icon-setting"></i>
            <span slot="title">导航九</span>
          </el-menu-item>
        </el-menu>
      </el-aside>
      <el-container>
        <el-header>
          <el-radio-group v-model="isCollapse" style="margin-bottom: 20px;">
            <el-radio-button :label="false">展开</el-radio-button>
            <el-radio-button :label="true">收起</el-radio-button>
          </el-radio-group>
        </el-header>
        <el-main>
          <component :is="currentComponent"></component>
        </el-main>
        <el-footer>备案号: xxxx 制作人: limou3434 邮箱: 898738804@qq.com</el-footer>
      </el-container>
    </el-container>
  </div>
</template>

<script>
// 在这里引入其他组件
import NavContentOne from "@/views/NavMenuItem/NavContentOne.vue";
import NavContentTwo from "@/views/NavMenuItem/NavContentTwo.vue";
import NavContentThree from "@/views/NavMenuItem/NavContentThree.vue";
import NavContentFour from "@/views/NavMenuItem/NavContentFour.vue";
import NavContentFive from "@/views/NavMenuItem/NavContentFive.vue";
import NavContentSix from "@/views/NavMenuItem/NavContentSix.vue";
import NavContentSeven from "@/views/NavMenuItem/NavContentSeven.vue";
import NavContentEight from "@/views/NavMenuItem/NavContentEight.vue";
import NavContentNine from "@/views/NavMenuItem/NavContentNine.vue";

export default {
  data() {
    return {
      isCollapse: false, // 默认为展开
      activeMenu: '1', // 默认选中第一个菜单项
    };
  },
  computed: {
    currentComponent() {
      switch (this.activeMenu) {
        case '1':
          return NavContentOne;
        case '2':
          return NavContentTwo;
        case '3':
          return NavContentThree;
        case '4':
          return NavContentFour;
        case '5':
          return NavContentFive;
        case '6':
          return NavContentSix;
        case '7':
          return NavContentSeven;
        case '8':
          return NavContentEight;
        case '9':
          return NavContentNine;
        default:
          return NavContentOne;
      }
    }
  },
  methods: {
    handleOpen(key, keyPath) {
      console.log(key, keyPath); // 当展开时, 这里会输出控制台的回调信息
    },
    handleClose(key, keyPath) {
      console.log(key, keyPath); // 当关闭时, 这里会输出控制台的回调信息
    },
    handleSelect(key) { // 当选中某个菜单项时, 这里会修改数据模型中的数据
      this.activeMenu = key;
    },
  }
}
</script>

<style scoped>
/* 可以在这里添加样式 */
</style>

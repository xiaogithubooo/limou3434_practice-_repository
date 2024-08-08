// index.js
import Vue from 'vue'
import VueRouter from 'vue-router'
import HomeView from '../views/HomeView.vue'
import ButtonView from '../views/ElementButtonView.vue'
import TableView from '../views/ElementTableView.vue'
import PaginationView from '../views/ElementPaginationView.vue'
import DialogView from '../views/ElementDialogView.vue' // 注意这里要导入
import FromView from '../views/ElementFormView.vue' // 注意这里要导入
import Container from '../views/ElementContainerView.vue' // 注意这里要导入
import NavMenu from '../views/ElementNavMenuView.vue' // 注意这里要导入
import Ajax from '../views/ElementAjaxView.vue' // 注意这里要导入

Vue.use(VueRouter)

// 定义路由映射
const routes = [
    {
        path: '/',
        name: 'home', // 这里的 name 是路由名字, 路由名字可以让路由修改的时候不是硬编码设置, 方便业务随时进行修改
        component: HomeView // 注册子组件, 也就是视图
    },
    {
        path: '/about',
        name: 'about',
        // 下面这种动态加载实际上是懒加载, 只有用户实际访问了 /about 路径时, 才会进行下载和渲染, 可以提高用户的响应速度
        component: () => import(/* webpackChunkName: "about" */ '../views/AboutView.vue') // 这也是为什么之前我们设置的 about 没有设置 name 的原因
    },
    { // 下面是新增加的路由
        path: '/button',
        name: 'button', // 这里的 name 是路由名字, 路由名字可以让路由修改的时候不是硬编码设置, 方便业务随时进行修改
        component: ButtonView // 注册子组件, 也就是视图
    },
    { // 下面是新增加的路由
        path: '/table',
        name: 'table', // 这里的 name 是路由名字, 路由名字可以让路由修改的时候不是硬编码设置, 方便业务随时进行修改
        component: TableView // 注册子组件, 也就是视图
    }
    ,
    { // 下面是新增加的路由
        path: '/pagination',
        name: 'pagination', // 这里的 name 是路由名字, 路由名字可以让路由修改的时候不是硬编码设置, 方便业务随时进行修改
        component: PaginationView // 注册子组件, 也就是视图
    }
    ,
    { // 下面是新增加的路由
        path: '/dialog',
        name: 'dialog', // 这里的 name 是路由名字, 路由名字可以让路由修改的时候不是硬编码设置, 方便业务随时进行修改
        component: DialogView // 注册子组件, 也就是视图
    }
    ,
    { // 下面是新增加的路由
        path: '/from',
        name: 'from', // 这里的 name 是路由名字, 路由名字可以让路由修改的时候不是硬编码设置, 方便业务随时进行修改
        component: FromView // 注册子组件, 也就是视图
    }
    ,
    { // 下面是新增加的路由
        path: '/container',
        name: 'container', // 这里的 name 是路由名字, 路由名字可以让路由修改的时候不是硬编码设置, 方便业务随时进行修改
        component: Container // 注册子组件, 也就是视图
    }
    ,
    { // 下面是新增加的路由
        path: '/navMenu',
        name: 'navMenu', // 这里的 name 是路由名字, 路由名字可以让路由修改的时候不是硬编码设置, 方便业务随时进行修改
        component: NavMenu // 注册子组件, 也就是视图
    }
    ,
    { // 下面是新增加的路由
        path: '/ajax',
        name: 'ajax', // 这里的 name 是路由名字, 路由名字可以让路由修改的时候不是硬编码设置, 方便业务随时进行修改
        component: Ajax // 注册子组件, 也就是视图
    }
]

// 设置路由管理
const router = new VueRouter({
    routes
})

// 把路由实例对象导出, 等待后续交给 vue 实例进行路由注入
export default router

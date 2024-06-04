// index.js
import React, { StrictMode } from "react"; // 先不管这个, 导入 React 模块用的
import { createRoot } from "react-dom/client"; // 先不管这个, 导入 React DOM 模块用的
import "./styles.css"; // 先不管, 反正会自动根据 css 的文件内容来生成对应样式

import MyApp from "./MyApp";

const root = createRoot(document.getElementById("root"));
root.render(
  <StrictMode>
    <MyApp />
  </StrictMode>
);
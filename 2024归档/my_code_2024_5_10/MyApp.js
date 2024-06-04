// MyApp.js
// 制作 MyButton 组件
function MyButton() {
    return (
        <button>
            I'm a button
        </button>
    );
}

// 使用 MyButton 组件
export default function MyApp() {
    return (
        <div>
            <h1>Welcome to my app</h1>
            <MyButton />
        </div>
    );
}
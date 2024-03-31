//获取验证码, 并且在 60s 内禁止重复获取
function BindEmailCaptchaClick() {
    $('#captcha-btn').click(function (event) {
        //阻止默认的表单事件提交
        event.preventDefault();
        
        //获取用户填入的邮箱
        let email = $('#exampleInputEmail1').val(); 
    
        let $this = $(this) //包装 this 就得到 jq 对象, 这里就代表当前获取到的按钮对象
    
        //发送 ajax 请求获取响应
        $.ajax({
            url: '/auth/email_captcha?email='+email, //请求 URL
            method: 'GET', //请求方式
            success: function (result) { //成功处理
                console.log(result);
                let code = result['code'];
                if (code == 200) {
                    $this.off("click"); //取消当前按钮绑定的点击事件
                    let countdown = 60; //倒计时
                    var timer = setInterval(function () {
                        $this.text('获取验证码'+'('+countdown+')') //修改按钮的内容倒计时的值
                        countdown = countdown - 1;
                        if (countdown <= 0) {
                            clearInterval(timer) //清除定时器
                            $this.text('获取验证码') //同时把按钮文本恢复
                            BindEmailCaptchaClick(); //重新递归本代码, 绑定点击事件
                        }
                    }, 1000) //间隔 1s
                    alert('发送成功, 请注意查收');
                }
                else {
                    alert('发送错误, 请联系站长');
                }
            },
            fail: function (error) { //错误处理
                console.log(error);
            }
        }); 
    });
}

//该函数可以在 HTML 文档加载完后再执行
$(function () { 
    BindEmailCaptchaClick();
});
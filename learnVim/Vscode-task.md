

[toc]

# Vscode C++ 一键编译运行

## 编写 task.json

```
{
    // See https://go.microsoft.com/fwlink/?LinkId=733558
    // for the documentation about the tasks.json format
    "version": "2.0.0",
    "tasks": [
        {
            //给task起的一个名称
            "label": "build",
            //我们要执行shell命令
            "type": "shell",
            //shell命令
            "command": "gcc",
            //shell命令参数
            "args": [
                "./test.c",
                "-o./test"
            ],
            "group": {
                "kind": "build",
                "isDefault": true
            },
            "presentation": {
                //shell命令输出的内容并不弹出来提醒
                "reveal": "silent"
            }
        },
        {
            "label": "run",
            "type": "shell",
            "command": "./test",
            //依赖build task(刚刚创建的那个)，执行该task之前先执行build
            "dependsOn": [
                "build"
            ],
            "presentation": {
                "echo": true,
                "reveal": "always",
                //自动聚焦
                "focus": true,
                //共享控制台，利用之前的控制台，并不重新创建
                "panel": "shared",
                "showReuseMessage": true,
                //启动之前清理控制台输出
                "clear": true
            }
        }
    ]
}
```

## 绑定快捷键

```
{
    "key": "ctrl+shift+r",
    "command": "workbench.action.tasks.runTask",
    "args": "run"
}
```


# References
1. [VSCODE 一键编译运行_syk的博客-CSDN博客_vscode怎么编译运行](https://blog.csdn.net/qq_30690821/article/details/84502287)

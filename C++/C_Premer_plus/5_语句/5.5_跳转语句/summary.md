## do while语句
先执行循环体后检查条件：

语法形式如下所示：
```C++
do
{
    statement
}
while (condition)
```

# :christmas_tree:跳转语句
跳转语句中断当前的执行过程。C++语言提供了4种跳转语句:break、continue、goto和return
## :jack_o_lantern: break语句

break语句负责终止离他最近的while、do while、for或switch语句。

## :jack_o_lantern: continue语句
continue语句，终止**最近**的循环中的当前迭代并立即开始下一次迭代。

continue语句只能出现在for、while和do while循环的内部，或者嵌套在此类循环里的语句或块的内部

## :jack_o_lantern: goto语句

goto语句的作用是从goto语句无条件跳转到同一函数的另一条语句。

>语法形式：
`goto label;`
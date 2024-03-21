# 条件运算符

按照如下形式使用：

> `cond? expr1:expr2;`

例如：

`string finalgrade = (grade < 60) ? "fail" : "pass";`

## 嵌套条件运算符

```C++
finalgrade = (grade > 90)? "high pass"
                         :(grade < 60) ? "fail" : "pass"; 
```
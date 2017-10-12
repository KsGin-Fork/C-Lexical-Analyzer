# C语言词法分析器

**一&emsp; C语言词法结构**

1. C词法内容

    + C语言标识符
        
        控制标识符 `do` , `while` , `if` , `else` , `switch` , `case` , `return` , `continue`
        
        类型标识符 `int` , `float` , `long` , `unsigned` , `short` , `double` , `char` , `struct` , `union`
        
        特殊标识符 `main`
        
        符号标识符 `+` , `-` , `*` , `/` , `[` , `]` , `{` , `}` , `(` , `)` , `&`
         
     + C语言变量
        
        + 变量规则
            
            C语言中，变量必须以`_`或者字母开头，中间多个字母或者数字或者下划线
            
        + 文法描述
            
            `W = ( letter | _ ) ( letter | _ | digits)*`
            
            `letter = { a | ... | z | A | ... | Z }`
            
            `digits = { 0 | ... | 9 }`
            
        + 正则表达式描述
            
            `/[a-zA-z_][a-zA-z0-9_]*/`

**二&emsp; 项目文件描述**

1. `/main.c` 主文件

2. `/lexical.h` 词法分析类声明

3. `/lexical.cpp` 词法分析类实现

4. `/test.h` 测试代码

5. `/run/output.txt` 输出文件

6. `/run/input.txt` 输入文件，一个完整的C语言程序源文件

7. `/readme.md` 项目综述

8. `/CMakeLists.txt` CMake编译配置文件

9. `/cmake-build-debug` CMake运行文件

**三&emsp; 项目方法描述**

1. `main` 主启动方法
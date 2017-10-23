# C语言词法分析器

**一&emsp; C语言词法结构**

1. C词法内容

    + C语言标识符
        
        控制标识符 `do` , `while` , `if` , `else` , `switch` , `case` , `return` , `continue` , `register` , `break` ,`for`
        
        类型标识符 `int` , `float` , `long` , `unsigned` , `short` , `double` , `char` , `struct` , `union` , `enum` , `typedef`, `signed`
        
        特殊标识符 `const` , `extern` , `default` , `static` , `volatile`
        
        符号标识符 `+` , `-` , `*` , `/` , `[` , `]` , `{` , `}` , `(` , `)` , `&` , `&&` , `>` , `<` , `=` , `.` , `|` , `||`
         
     + C语言变量
        
        + 变量规则
            
            C语言中，变量必须以`_`或者字母开头，中间多个字母或者数字或者下划线
            
        + 文法描述
            
            `W = ( word | _ ) ( word | _ | digits)*`
            
            `word = { a | ... | z | A | ... | Z }`
            
            `digits = { 0 | ... | 9 }`
            
        + 正则表达式描述
            
            `/[a-zA-z_][a-zA-z0-9_]*/`

**二&emsp; 项目文件描述**

1. `/main.c` 主文件

2. `/lexical.h` 词法分析类声明

3. `/lexical.cpp` 词法分析类实现

4. `/test.h` 测试代码

5. `/mfstream.h` 文件操作声明

6. `/mfstream.cpp` 文件操作实现

5. `/run/output.txt` 输出文件

6. `/run/input.txt` 输入文件，一个完整的C语言程序源文件

7. `/readme.md` 项目综述

8. `/CMakeLists.txt` CMake编译配置文件

9. `/cmake-build-debug` CMake运行文件

**三&emsp; 项目方法描述**

1. `main` 主启动方法
2. `read_file` 读文件
3. `write_file` 写文件
4. `parse` 解析入口函数（传入待解析代码串，返回二元组）

**四&emsp; 项目进度** 

1. 基本解析 ✔
2. 其他

**五&emsp; 表**

| value | token |
| :---: | :---: |
|   .   |   0   |
|   +   |   1   |
|   -   |   2   |
|   *   |   3   |
|   /   |   4   |
|   (   |   5   |
|   )   |   6   |
|   [   |   7   |
|   ]   |   8   |
|   {   |   9  |
|   }   |   10  |
|   &   |   11  |
|   &&  |   12  |
|   <   |   13  |
|   &#62;   |   14  |
|   =   |   15  |
|   :   |   16  |
|   #   |   17  |
|   ?   |   18  |
|   %   |   19  |
|   !   |   20  |
|   '   |   21  |
|   "   |   22  |
|   &#124;   |   23  |
|   &#124;&#124;   |   24  |
|  (digits) |   25   |
|  (word) |   26   |
|  int    |   27   |
|  float  |   28   |
|  double |   29   |
|  char   |   30   |
|  long   |   31   |
|  short  |   32   |
|  struct |   33   |
|  union  |   34   |
|  unsigned  |  35  |
|   do     |    36  |
|  while   |    37  |
|   if     |    38  |
|  else   |    39 |
|  switch |   40  |
|  case  |    41  |
|  return |   42  |
|  continue |   43  |
|  register |   44   |
|  break    |   45   |
|  for      |   46   |
|  enum     |   47   |
|  typedef  |   48   |
|  signed   |   49   |
|  const    |   50   |
|  default  |   51   |
|  extern   |   52   |
|  static   |   53   |
|  volatile |   54   |


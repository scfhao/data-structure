#  数据结构

《数据结构（C语言版）》（ISBN 978-7-302-14751-0/严蔚敏，吴伟明编著/清华大学出版社）书中各数据结构完整版代码（个人整理，尽个人最大限度尊重书中原有代码）。

1. `common.h/common.c`中定义了各数据结构通用的代码。
2. 每一个文件夹对应一个数据结构。例如，文件夹`SqList`中的代码为线性顺序表相关代码，其中`SqList.h/SqList.c`为顺序表的实现代码，`SqListTest.h/SqListTest.c`为顺序表的测试代码，在`main.c`中`main()`函数中调用`SqListTest.h`中的`testSqList()`函数来测试顺序表的各项功能。
3. 全部代码在 macOS/Xcode/clang 环境下编译通过。
4. 程序默认运行最新数据结构的测试代码，可在`main.c`修改。
5. 本仓库正在更新中。

## 索引

SqList: 顺序表
USqList: 类型通用顺序表
Array: 数组

...



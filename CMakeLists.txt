cmake_minimum_required(VERSION 3.15)
project(c_raise C)

set(CMAKE_C_STANDARD 99)

#默认无配置就是编译出 Debug版本。如下显式配置 Debug 或 Release
SET(CMAKE_BUILD_TYPE "Debug")
#SET(CMAKE_BUILD_TYPE "Release")

#设置变量，关联了源文件
SET(MyLibraySource library.c library.h)
#添加静态库，会生成 libhello_static.a
#add_library(hello_static STATIC ${MyLibraySource})

#添加动态库，会生成 libhello.so,  mac-os会生成 libhello.dylib
ADD_LIBRARY(hello SHARED ${MyLibraySource})
#VERSION 指代动态库版本, SOVERSION 指代 API 版本。   生成 libhello.1.2.dylib
SET_TARGET_PROPERTIES(hello PROPERTIES VERSION 1.2 SOVERSION 1)

#第一个是执行程序名字，后面可关联多个源文件
#add_executable(c_raise main.c
add_executable(c_raise
#        c01/指针步长.c
#        c01/指针的间接赋值.c
#        c01/指针的输入和输出特性.c
#        c01/字符串操作.c
#        c01/格式化字符串_sprintf.c
#        c02/CallocMallocRealloc.c.c
#        c02/sscanf.c
#        c02/const使用.c
#        c02/二级指针做函数参数_输入特性.c
#        c02/二级指针做函数参数_输出特性.c
#        c02/二级指针练习.c
#        c03/一维数组.c
#        c03/二维数组.c
#        c03/指针数组_选择排序.c
#        c03/结构体嵌套一级指针.c
#        c03/结构体嵌套一级指针复写.c
#        c03/结构体嵌套二级指针.c
#        c04/函数指针.c
#        c04/静态链表.c
        c04/LinkList.c c04/LinkList.h c04/动态链表.c)

#向执行程序，链接 静态、动态 库
#TARGET_LINK_LIBRARIES(c_raise hello_static)
TARGET_LINK_LIBRARIES(c_raise hello)

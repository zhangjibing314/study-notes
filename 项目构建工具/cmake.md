* 目录
    * CMake基础
    * CMake常用选项

------------------
# CMake基础  
## CMakeLists.txt文件结构和基础语法
CMakeLists.txt通过一系列CMake指令来描述构建过程,如：
1. 执行CMake的最低版本要求：
```cmake
cmake_minimum_required(VERSION <version>)
#示例
cmake_minimum_required(VERSION 3.10)
```
2. 定义项目名和使用的编程语言
```cmake
project(<project_name> [<language>...])
#示例
project(myobj CXX)
```
3. 指定要生成的目标文件和对应的源文件
```cmake
add_executable(<target> <source_files>...)
# 示例
add_executable(myapp main.cpp other.cpp)
```
4. 创建一个库以及对应的源文件
```cmake
add_library(<lib_name> <source_files>...)
# 示例：创建静态库
add_library(my_static_lib STATIC library.cpp)
```
5. 链接目标文件与其他库
```cmake
target_link_libraries_(<target> <other_lib_name>...)
```
6. 添加头文件搜索路径
```cmake
include_directories(<dirs>...)
# 示例
include_directories(${PROJECT_SOURCE_DIR}/include)
```
7. 设置变量值
```cmake
set(<variable> <value>)
```
8. 设置目标属性
```cmake
target_include_directories(TARGET target_name
                          [BEFORE | AFTER]
                          [SYSTEM] [PUBLIC | PRIVATE | INTERFACE]
                          [items1...])
#示例
target_include_directories(MyExecutable PRIVATE ${PROJECT_SOURCE_DIR}/include)
```
9. 安装规则
```cmake
install(TARGETS target1 [target2 ...]
        [RUNTIME DESTINATION dir]
        [LIBRARY DESTINATION dir]
        [ARCHIVE DESTINATION dir]
        [INCLUDES DESTINATION [dir ...]]
        [PRIVATE_HEADER DESTINATION dir]
        [PUBLIC_HEADER DESTINATION dir])
# 示例
install(TARGETS MyExecutable RUNTIME DESTINATION bin)
```
10. 查找库和包
```cmake
# 示例
cmake_minimum_required(VERSION 3.10)
project(MyProject CXX)
# 查找 Boost 库
find_package(Boost REQUIRED)
# 添加源文件
add_executable(MyExecutable main.cpp)
# 链接 Boost 库
target_link_libraries(MyExecutable Boost::Boost)
```
## 变量和缓存
1. 普通变量
```cmake
# 定义
set(MY_VAR "Hello World")
# 使用
message(STATUS "MY_VAR=%{MY_VAR}")
```
2. 缓存变量
缓存变量存储在 CMake 的缓存文件中，用户可以在 CMake 配置时修改这些值。缓存变量通常用于用户输入的设置，例如编译选项和路径。
```cmake
#定义
set(MY_CACHE_VAR "DefaultValue" CACHE STRING "A cache variable")
# 使用
message(STATUS "Cache variable MY_CACHE_VAR is ${MY_CACHE_VAR}")
```
---------------------------------------
# CMake常用选项  
```cmake
# 1. 指定生成器,如Ninja:
cmake -G "Ninja" ..
# 2. 指定构建类型:
cmake -DCMAKE_BUILD_TYPE=Release ..
# 3. cmake生成编译数据库
ccmake -DCMAKE_EXPORT_COMPILE_COMMANDS=ON
```


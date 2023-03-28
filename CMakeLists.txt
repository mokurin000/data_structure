cmake_minimum_required(VERSION 3.5)

project(data_structure VERSION 1.0.0)

set(CMAKE_C_STANDARD 23)
set(CMAKE_C_STANDARD_REQUIRED True)

# 设置头文件搜索路径
include_directories(${PROJECT_SOURCE_DIR}/src)

# 添加源文件
file(GLOB_RECURSE HEADERS "${PROJECT_SOURCE_DIR}/src/linked_list/ops.h")
file(GLOB_RECURSE SOURCES "${PROJECT_SOURCE_DIR}/src/linked_list/ops.c")
file(GLOB_RECURSE HEADERS "${PROJECT_SOURCE_DIR}/src/linked_list/type.h")

# 创建可执行文件
add_executable(${PROJECT_NAME} "${PROJECT_SOURCE_DIR}/src/main.c")

# 设置项目作者信息
set(CPACK_PACKAGE_VENDOR "poly000")
set(CPACK_RESOURCE_FILE_LICENSE "LICENSE")

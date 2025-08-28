cmake_minimum_required(VERSION 3.29)
project(MyTest)  # 项目的名称

set(CMAKE_CXX_STANDARD 20)

# 添加可执行文件，包含你的源文件
add_executable(main main.cpp Login.cpp Admin.cpp Export.cpp Grade.cpp Information.cpp Statistics.cpp Student.cpp Teacher.cpp
        User.h
        User.cpp
        Logger.h
        Logger.cpp
        Announcement.h
        Announcement.cpp)

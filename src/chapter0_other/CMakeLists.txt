add_executable(other main.cpp)

add_executable(other2 main2.cpp)
set_target_properties(other2 PROPERTIES
    CXX_STANDARD 11
)

find_package(Python3 COMPONENTS Interpreter Development)

message(STATUS "Python3_FOUND = ${Python3_FOUND}")
message(STATUS "Python3_INCLUDE_DIRS = ${Python3_INCLUDE_DIRS}")
message(STATUS "Python3_LIBRARIES = ${Python3_LIBRARIES}")

add_executable(cpp_withpython cpp_withpython.cpp)
target_include_directories(cpp_withpython PRIVATE ${Python3_INCLUDE_DIRS})
target_link_libraries(cpp_withpython ${Python3_LIBRARIES})


add_executable(other3 branch_predictor.cpp)

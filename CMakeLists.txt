cmake_minimum_required(VERSION 3.20)
project(cpp VERSION 1.1)

#message (STATUS "Hello, cmake")
#message (STATUS ${CMAKE_PROJECT_NAME})
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

#set (My_VARIABLE 5)

#function (my_function first_argument)
        #foreach(argument IN LISTS ARGV)
            #message ("Variable is : " ${argument})
        #endforeach()   
#endfunction()

#my_function(${My_VARIABLE} 4 3 2 1)
#find_program(CPPCHECK cppcheck)
 
# If nothing is found, the result will be <VAR>-NOTFOUND
#if(CPPCHECK)

#endif()

add_subdirectory(Ezzoo)

#add_subdirectory(CppCheck)


add_executable(${PROJECT_NAME} sand_box.cpp)
target_link_libraries(${PROJECT_NAME} PUBLIC Ezzoo)

target_compile_definitions(${PROJECT_NAME} PRIVATE EZZOO_WINDOWS)
target_compile_definitions(${PROJECT_NAME} PRIVATE BUILD_DLL)
set(IS_DEBUG $<IF:$<CONFIG:Debug>,1,0>) #we can generate any precompile definition if need in my code 
target_compile_definitions(${PROJECT_NAME} PRIVATE CONFIGURATION=${IS_DEBUG})#definitions for preprocessor macros
#Generator Expression
#set(IS_DEBUG $<IF:$<CONFIG:Debug>,1,0>) #we can generate any precompile definition if need in my code 
#target_compile_definitions(${PROJECT_NAME} PRIVATE CONFIGURATION=${IS_DEBUG}) #definitions for preprocessor macros

#target_compile_definitions(${PROJECT_NAME} PRIVATE EZZOO_WINDOWS)
#find_program(CPPCHECK cppcheck)
#if (CPPCHECK)
#set(CMAKE_CXX_CPPCHECK "cppcheck")
#message (STATUS "CPPCHECK installed and works")
#endif()

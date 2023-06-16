project (Ezzoo)


file(GLOB_RECURSE  HEADERS "${CMAKE_CURRENT_SOURCE_DIR}/include/*.h")
file(GLOB_RECURSE SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")
add_library(${PROJECT_NAME} ${HEADERS} ${SOURCES})

#file(GLOB_RECURSE EXAMPLE_FILES CONFIGURE_DEPENDES "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")

#configuring files name only by looping
#foreach(EXAMPLE_FILE IN LISTS EXAMPLE_FILES)

        #get_filename_component(NAME_ONLY ${EXAMPLE_FILE} NAME_WE) #show name of the file without directory path
        #message(STATUS ${NAME_ONLY})

#endforeach()

#target_compile_options(${PROJECT_NAME} PRIVATE -O2) choose compiler options to use durind building project
#target_link_options(${PROJECT_NAME} PRIVATE any option for compiler flags)

target_include_directories(${PROJECT_NAME} PUBLIC ./src PUBLIC ./include)
add_subdirectory(spdlog)
add_subdirectory(glfw)
add_subdirectory(glad)
add_subdirectory(imgui)
add_subdirectory(glm)

target_link_libraries(${PROJECT_NAME} PUBLIC spdlog)
target_link_libraries(${PROJECT_NAME} PUBLIC glfw)
target_link_libraries(${PROJECT_NAME} PUBLIC glad)
target_link_libraries(${PROJECT_NAME} PUBLIC imgui)
target_link_libraries(${PROJECT_NAME} PUBLIC opengl32)
target_link_libraries(${PROJECT_NAME} PUBLIC glm)




#target_link_libraries(${PROJECT_NAME} PUBLIC CppCheck)
#Generator Expression
#set(IS_DEBUG $<IF:$<CONFIG:Debug>,1,0>) #we can generate any precompile definition if need in my code 
#target_compile_definitions(${PROJECT_NAME} PRIVATE CONFIGURATION=${IS_DEBUG}) #definitions for preprocessor macros


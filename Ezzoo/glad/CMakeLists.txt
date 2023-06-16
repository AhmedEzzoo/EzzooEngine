project (glad LANGUAGES C)


add_library(${PROJECT_NAME} 
                    include/glad/glad.h
                    include/KHR/khrplatform.h 
                    src/glad.c)

target_include_directories(${PROJECT_NAME} PUBLIC include/  PUBLIC src/)                    
message (STATUS "Build glad")

﻿project(sort)

add_executable(${PROJECT_NAME} program.c)

set_target_properties(${PROJECT_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")

add_library(sort_dynamic SHARED
    sort.c
)
    
target_link_libraries(${PROJECT_NAME} PUBLIC
    sort_dynamic
)

﻿add_library(sqqueue STATIC
    sqqueue.c
)

set_target_properties(sqqueue PROPERTIES ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/obj")

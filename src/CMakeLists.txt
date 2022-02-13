add_library(gps_analysis STATIC)


target_sources(gps_analysis
        PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/gps_ans.c
        )

target_include_directories(gps_analysis
        INTERFACE
        ${CMAKE_CURRENT_SOURCE_DIR}
        )
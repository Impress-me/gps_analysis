add_executable(gps_test)

target_sources(gps_test
        PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/gps_test.c
        )

target_link_libraries(gps_test
        PRIVATE
        gps_analysis
        )
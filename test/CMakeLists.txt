project(polygon_intersection_test)
add_executable(polygon_intersection_test test.cpp)

target_link_libraries(${PROJECT_NAME} PUBLIC polygon_intersection)

set_target_properties(${PROJECT_NAME}
        PROPERTIES
        OUTPUT_NAME "polygon_intersection_test"
        )

install(TARGETS ${PROJECT_NAME}
        CONFIGURATIONS Release
        DESTINATION rel/bin)

install(TARGETS ${PROJECT_NAME}
        CONFIGURATIONS Debug
        DESTINATION dbg/bin)

add_custom_target(install_${PROJECT_NAME}
        "${CMAKE_COMMAND}" --build "${CMAKE_BINARY_DIR}" --target install
        DEPENDS ${PROJECT_NAME}
        COMMENT "Installing ${PROJECT_NAME}")

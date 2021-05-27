project(polygon_intersection_test)
add_executable(polygon_intersection_test test.cpp)
find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})
target_link_libraries(polygon_intersection_test ${OpenCV_LIBS})
target_link_libraries(polygon_intersection_test polygon_intersection)

install(TARGETS polygon_intersection_test DESTINATION bin)
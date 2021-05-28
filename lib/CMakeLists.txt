
PROJECT(polygon_intersection)
add_library(polygon_intersection poligon.h poligon.cpp)
set_property(TARGET polygon_intersection PROPERTY CXX_STANDARD 17)

find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

target_link_libraries(polygon_intersection ${OpenCV_LIBS})

set_target_properties(${PROJECT_NAME}
        PROPERTIES
        PUBLIC_HEADER poligon.h
        OUTPUT_NAME "poligon"
        CXX_STANDARD 11
        )

target_include_directories(${PROJECT_NAME} PRIVATE .)

install(TARGETS ${PROJECT_NAME}
        CONFIGURATIONS Debug
        LIBRARY
        DESTINATION dbg/lib
        PUBLIC_HEADER
        DESTINATION dbg/include)

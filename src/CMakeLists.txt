add_library(polygon_intersection poligon.h poligon.cpp)
set_property(TARGET polygon_intersection PROPERTY CXX_STANDARD 17)

find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

target_link_libraries(polygon_intersection ${OpenCV_LIBS})

install(TARGETS polygon_intersection DESTINATION lib)
install(FILES poligon.h DESTINATION include)

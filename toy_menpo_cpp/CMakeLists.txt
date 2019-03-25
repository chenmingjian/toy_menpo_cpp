cmake_minimum_required(VERSION 2.6)

project(toy_menpo_cpp)


file(GLOB_RECURSE CURRENT_HEADERS  *.h *.hpp)
source_group("Include" FILES ${CURRENT_HEADERS}) 

include_directories(./include)


aux_source_directory(./src SRC_DIR)

find_package(OpenCV REQUIRED)
message(STATUS "OpenCV library status:")
message(STATUS "    version: ${OpenCV_VERSION}")
message(STATUS "    libraries: ${OpenCV_LIBS}")
message(STATUS "    include path: ${OpenCV_INCLUDE_DIRS}")
message(STATUS "${OpenCV_INSTALL_PATH}")

include_directories(${OpenCV_INCLUDE_DIRS})
link_directories(${OpenCV_INSTALL_PATH}/x64/vc15/bin)
# link_directories(${Opencv})

add_executable(test tset.cpp ${SRC_DIR} ${INCLUDE_DIR} ${CURRENT_HEADERS})
target_link_libraries(test ${OpenCV_LIBS})

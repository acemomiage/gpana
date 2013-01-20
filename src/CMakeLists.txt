cmake_minimum_required(VERSION 2.8)
project(gpana)
# version number
set(GPANA_VERSION_MAJOR 0)
set(GPANA_VERSION_MINOR 1)
configure_file(
  "${PROJECT_SOURCE_DIR}/version.h.in"
  "${PROJECT_SOURCE_DIR}/version.h")

# misc
set(CMAKE_CXX_FLAGS "-Wall")

# for GTK+-3.0
find_package(PkgConfig REQUIRED)
# pkg_check_modules(GTK3 REQUIRED gtk+-3.0)
# include_directories(${GTK3_INCLUDE_DIRS})
# link_directories(${GTK3_LIBRARY_DIRS})
# add_definitions(${GTK3_CFLAGS_OTHER})

# for GKT+-2.x
pkg_check_modules(GTK2 REQUIRED gtk+-2.0)
include_directories(${GTK2_INCLUDE_DIRS})
link_directories(${GTK2_LIBRARY_DIRS})
add_definitions(${GTK2_CFLAGS_OTHER})



# executable command
add_executable(gpana
  "${PROJECT_SOURCE_DIR}/gpana.c"
  )

# Libraries
#target_link_libraries(gpana ${GTK3_LIBRARIES})
target_link_libraries(gpana ${GTK2_LIBRARIES})

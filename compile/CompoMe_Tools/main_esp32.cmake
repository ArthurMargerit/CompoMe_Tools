SET(CMAKE_CXX_STANDARD 11)

include("${CMAKE_CURRENT_LIST_DIR}/compile/CompoMe_Tools/var.cmake")
include("${CMAKE_CURRENT_LIST_DIR}/compile/CompoMe_Tools/import.cmake")
include("${CMAKE_CURRENT_LIST_DIR}/compile/CompoMe_Tools/links.cmake")

idf_component_register(SRCS ${src_file} INCLUDE_DIRS "${_include_directories}" REQUIRES "${_links_lib}")
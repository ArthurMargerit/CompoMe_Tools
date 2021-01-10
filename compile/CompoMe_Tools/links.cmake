set(_links_lib "")

include("${CMAKE_CURRENT_LIST_DIR}/Ext_links.cmake" OPTIONAL)



list(APPEND _links_dir "-L/home/ruhtra/compo/Test/gen/cpp_before/CompoMe_Log/lib")
list(APPEND _links_lib "CompoMe_Log")
include("/home/ruhtra/compo/Test/gen/cpp_before/CompoMe_Log/compile/CompoMe_Log/Ext_links.cmake" OPTIONAL)



list(APPEND _links_dir "-L/home/ruhtra/compo/Test/gen/cpp_before/CompoMe/lib")
list(APPEND _links_lib "CompoMe")
include("/home/ruhtra/compo/Test/gen/cpp_before/CompoMe/compile/CompoMe/Ext_links.cmake" OPTIONAL)





list(APPEND _links_dir "-L/home/ruhtra/compo/build/CompoMe_Swig/lib")
list(APPEND _links_lib "CompoMe_Swig")
include("/home/ruhtra/compo/build/CompoMe_Swig/compile/CompoMe_Swig/Ext_links.cmake" OPTIONAL)



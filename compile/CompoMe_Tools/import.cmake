set(_include_directories "")
set(_include_directories_swig "")

list(APPEND _include_directories      "./inc")
list(APPEND _include_directories_swig "./swig")

include("./compile/CompoMe_Tools/Ext_import.cmake" OPTIONAL)



###############################################################################
list(APPEND _include_directories      "/home/ruhtra/compo/Test/gen/cpp_before/CompoMe_Log/inc")
list(APPEND _include_directories_swig "/home/ruhtra/compo/Test/gen/cpp_before/CompoMe_Log/swig")
include("/home/ruhtra/compo/Test/gen/cpp_before/CompoMe_Log/compile/CompoMe_Log/Ext_import.cmake" OPTIONAL)



###############################################################################
list(APPEND _include_directories      "/home/ruhtra/compo/Test/gen/cpp_before/CompoMe/inc")
list(APPEND _include_directories_swig "/home/ruhtra/compo/Test/gen/cpp_before/CompoMe/swig")
include("/home/ruhtra/compo/Test/gen/cpp_before/CompoMe/compile/CompoMe/Ext_import.cmake" OPTIONAL)





###############################################################################
list(APPEND _include_directories      "/home/ruhtra/compo/Test/gen/cpp_before/CompoMe_Swig/inc")
list(APPEND _include_directories_swig "/home/ruhtra/compo/Test/gen/cpp_before/CompoMe_Swig/swig")
include("/home/ruhtra/compo/Test/gen/cpp_before/CompoMe_Swig/compile/CompoMe_Swig/Ext_import.cmake" OPTIONAL)



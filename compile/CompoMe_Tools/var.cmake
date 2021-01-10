set(compo_project_name "CompoMe_Tools")
set(compo_lib_name "CompoMe_Tools")

set(src_file src/Types/CompoMe/Config/Result_state.cpp 
src/Data/CompoMe_Tools.cpp 
src/Structs/CompoMe/Config/Result_get.cpp 
src/Structs/CompoMe/Config/Result_get_serialization.cpp 
src/Structs/CompoMe/Config/Result_get_get_set.cpp 
src/Structs/CompoMe/Config/Result_get_function.cpp 
src/Structs/CompoMe/Config/Result_get_fac.cpp 
src/Structs/CompoMe/Config/Result_get_builder.cpp 
src/Interfaces/CompoMe/Config/AccessData/AccessData.cpp 
src/Interfaces/CompoMe/Config/AccessData/AccessData_fake_stream.cpp 
src/Interfaces/CompoMe/Config/AccessData/AccessData_caller_stream.cpp 
src/Components/CompoMe/Config/DataProvider.cpp 
src/Components/CompoMe/Config/DataProvider_serialization.cpp 
src/Components/CompoMe/Config/DataProvider_function.cpp 
src/Components/CompoMe/Config/DataProvider_get_set.cpp 
src/Components/CompoMe/Config/DataProvider_fac.cpp 
src/Components/CompoMe/Config/DataProvider_AccessData_access.cpp 
src/Components/CompoMe/Config/DataProvider_AccessData_access_get_set.cpp 
src/Components/CompoMe/Config/DataProvider_AccessData_access_fac.cpp 
src/Components/CompoMe/Config/DataProvider_AccessData_access_function.cpp)

set(inc_file inc/Types/CompoMe/Config/Result_state.hpp 
inc/Data/CompoMe_Tools.hpp 
inc/Structs/CompoMe/Config/Result_get.hpp 
inc/Structs/CompoMe/Config/Result_get_fac.hpp 
inc/Structs/CompoMe/Config/Result_get_builder.hpp 
inc/Interfaces/CompoMe/Config/AccessData/AccessData.hpp 
inc/Interfaces/CompoMe/Config/AccessData/AccessData_fake_stream.hpp 
inc/Interfaces/CompoMe/Config/AccessData/AccessData_caller_stream.hpp 
inc/Components/CompoMe/Config/DataProvider.hpp 
inc/Components/CompoMe/Config/DataProvider_fac.hpp 
inc/Components/CompoMe/Config/DataProvider_AccessData_access.hpp)

set(swig_file )

list(APPEND CMAKE_MODULE_PATH "compile")
list(APPEND CMAKE_MODULE_PATH $ENV{COMPOME_PATH}/tool)
message($ENV{COMPOME_PATH}/tool)

include(${CMAKE_CURRENT_LIST_DIR}/Int_var.cmake OPTIONAL)

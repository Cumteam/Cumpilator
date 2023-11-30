add_library (cum_lib "src/cum_lib.cpp")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET cum PROPERTY CXX_STANDARD 20)
endif()

target_include_directories(
	cum_lib
	PUBLIC
	"include"
)
add_executable (cum "src/main.cpp" )

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET cum PROPERTY CXX_STANDARD 20)
endif()

target_include_directories (
	cum
	PUBLIC
	"include"
)

target_link_libraries (
	cum
	PRIVATE
	cum_lib
)
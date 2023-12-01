add_library (
	cum_lib 
	"include/assembly/lexer/asm_lexer.hpp"
	"include/assembly/parser/asm_parser.hpp"
	"include/c/lexer/c_lexer.hpp"
	"include/c/parser/c_parser.hpp"
	"include/general/token.hpp"
	"include/preprocessor/lexer/preprocessor_lexer.hpp"
	"include/preprocessor/parser/preprocessor_parser.hpp"
	"include/constants.hpp"
	"src/cum_lib.cpp"
)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET cum PROPERTY CXX_STANDARD 20)
endif()

target_include_directories(
	cum_lib
	PUBLIC
	"include"
)
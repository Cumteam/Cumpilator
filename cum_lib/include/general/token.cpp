#include "token.hpp"

namespace cumpilator{
	namespace tok {
		constexpr inline static token::create_token(
			token_t type, std::string value, tok::loc location, tok::token_flags flags)
			const noexcept 
		{
			return std::make_unique<token>(type, value, location, flags);
		}
		
	}	// !namespace tok
}	// !namespace cumpilator
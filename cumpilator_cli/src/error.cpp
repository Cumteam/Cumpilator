/// This file implements the error codes used by the cli.

#include <string>
#include <system_error>

#include "error.h"

namespace cli
{
	const char* error_category::name() const noexcept
	{
		return "cli_error";
	}

	std::string error_category::message(int ev) const
	{
		switch (static_cast<error>(ev))
		{
		case error::none:
			return "No error";
		case error::invalid_command:
			return "Invalid command";
		case error::invalid_option:
			return "Invalid option";
		case error::invalid_argument:
			return "Invalid argument";
		case error::invalid_value:
			return "Invalid value";
		case error::missing_argument:
			return "Missing argument";
		case error::missing_value:
			return "Missing value";
		case error::unexpected_argument:
			return "Unexpected argument";
		case error::unexpected_value:
			return "Unexpected value";
		case error::unexpected_option:
			return "Unexpected option";
		default:
			return "Unknown error";
		}
	}

	std::error_code make_error_code(error e)
	{
		return std::error_code(static_cast<int>(e), error_category());
	}
}
#pragma once

/// This file is used to define the error codes used by the CLI library.
/// The error codes are defined in the cli::error enum class.

#include <string>
#include <system_error>

namespace cli
{
	/// @brief The error codes used by the CLI library.
	enum class error : uint32_t
	{
		/// @brief No error.
		none = 0,

		/// @brief The command is not valid.
		invalid_command,

		/// @brief The option is not valid.
		invalid_option,

		/// @brief The option was not expected.
		unexpected_option,

		/// @brief The value is not valid.
		invalid_value,

		/// @brief The value is missing.
		missing_value,

		/// @brief The value was not expected.
		unexpected_value,

		/// @brief The argument is not valid.
		invalid_argument,

		/// @brief The argument is missing.
		missing_argument,

		/// @brief The argument was not expected.
		unexpected_argument,
	};

	/// @brief The error category used by the CLI library.
	class error_category : public std::error_category
	{
	public:
		const char* name() const noexcept override;

		std::string message(int ev) const override;
	};

	/// @brief Create a generic error code from a CLI error.
	/// @param e CLI error.
	/// @return Generic error code.
	std::error_code make_error_code(error e);
}

namespace std
{
	template<>
	struct is_error_code_enum<cli::error> : true_type {};
}
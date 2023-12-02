#pragma once

/// This file defines the class representing the version command.
/// The version command is resposible to allow the user to compile files.

#include <string>
#include <vector>

#include "command.h"

namespace cli
{
	namespace commands
	{
		class version : public command
		{
		public:
			version();

			std::pair<bool, std::string> parse_arguments(const std::vector<std::string>& arguments) override;

			std::string get_name() const override;
			std::string alias() const override;
			std::string get_help_message() const override;

			std::pair<bool, std::string> execute() const override;
		};
	}
}

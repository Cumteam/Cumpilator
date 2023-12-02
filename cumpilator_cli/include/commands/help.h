#pragma once

/// This file defines the class representing the build command.
/// The build command is resposible to allow the user to compile files.

#include <string>
#include <vector>

#include "command.h"

namespace cli
{
	namespace commands
	{
		class help : public command
		{
		public:
			help();

			std::pair<bool, std::string> parse_arguments(const std::vector<std::string>& arguments) override;

			std::string get_name() const override;
			std::string alias() const override;
			std::string get_help_message() const override;

			std::pair<bool, std::string> execute() const override;

		private:
			std::string m_command_name;
		};
	}
}

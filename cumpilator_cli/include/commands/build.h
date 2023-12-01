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
		class build : public command
		{
		public:
			build();

			std::pair<bool, std::string> parse_arguments(const std::vector<std::string>& arguments) override;

			std::string get_name() const override;
			std::string alias() const override;
			std::string get_help_message() const override;

			std::pair<bool, std::string> execute() const override;

		private:
			std::vector<std::string> m_options;
			std::vector<std::string> m_files;
		};
	}
}
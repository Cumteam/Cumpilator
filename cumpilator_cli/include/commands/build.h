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
		struct build_option
		{
			enum class type
			{
				output,
				output_format,
				assembly,
				include_path,
				library_path,
				link,
				no_std_lib
			};

			type m_type;
			std::string m_value;
		};

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
			std::vector<build_option> m_options;
			std::vector<std::string> m_files;
		};
	}
}

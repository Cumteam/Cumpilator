#pragma once

/// This file defines the base class for all commands.
/// The command class is used to represent a command argument.

#include <string>
#include <vector>

namespace cli
{
	namespace commands
	{
		/// @brief The base class for all commands.
		class command
		{
		public:
			/// @brief Construct a new command object.
			/// @param name Name of the command. This will be used to call the command.
			/// @param alias Shorter name for the command.
			/// @param arguments The arguments for the command.
			command();
			virtual ~command();


			virtual std::pair<bool, std::string> parse_arguments(const std::vector<std::string>& args) const;

			/// @brief Get the name of the command.
			/// @return The name of the command.
			virtual std::string get_name() const;

			/// @brief Get the alias of the command.
			/// @return The alias of the command.
			virtual std::string get_alias() const;

			/// @brief Execute the command.
			virtual void execute();

		protected:
			std::string name;
			std::string alias;
			std::vector<std::string> arguments;
		};
	}
}
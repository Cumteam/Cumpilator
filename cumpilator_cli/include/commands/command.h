#pragma once

/// This file defines the base class for all commands.
/// The command class is used to represent a command argument.

#include <string>

namespace cumpilator_cli
{
	/// @brief The base class for all commands.
	class command
	{
	public:
		command();
		virtual ~command();

		/// @brief Get the name of the command.
		/// @return The name of the command.
		virtual std::string get_name() const;

		virtual void execute() = 0;

	private:
		std::string name;
	};
}
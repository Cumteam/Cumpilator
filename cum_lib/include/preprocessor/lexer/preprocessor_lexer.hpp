/**
 * @file preprocessor_lexer.hpp
 * @author Mideky
 * @brief
 *	Le lexer du préprocesseur C++ permet de transformer un fichier texte en une liste de token.

 *
 * @version 0.1
 * @date 2023-12-01
 *
 * @copyright Copyright (c) 2023
 */
#pragma once

#include "../../general/token.hpp"

namespace cumpilator {
	class file_entry;
	class preprocessor;
	
	class preprocessor_lexer
	{
	protected:
		preprocessor_lexer() = delete;
		~preprocessor_lexer() = delete;
	private:

	};
	
}	// !namespace cumpilator


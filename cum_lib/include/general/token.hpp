/**
 * @file token.hpp
 * @author Mideky
 * @brief
 *	La classe token est une classe qui repr�sente un token en C++ pour l'analyse lexicale.
 *
 * @version 0.1
 * @date 2023-12-01
 *
 * @copyright Copyright (c) 2023
 */
#pragma once

#include <string>
#include <vector>
#include <memory>
#include <ctype.h>
#include <cassert>

namespace cumpilator {
	namespace tok {

		using source_location = uint32_t;

        enum class token_t
        {
            And,
            Asterisk,
            Comma,
            Comment,
            DifferentTo,
            Dot,
            DoubleQuote,
            Equal,
            EqualTo,
            EndOfFile,
            GreaterThan,
            Identifier,
            LeftCurlyBrace,
            LeftParenthesis,
            LeftShift,
            LessThan,
            LogicAnd,
            LogicNot,
            LogicOr,
            Minus,
            Modulus,
            Not,
            Number,
            Or,
            Pipe,
            Plus,
            RightCurlyBrace,
            RightParenthesis,
            RightShift,
            SemiColon,
            SingleQuote,
            Slash,
            Unknown,
            COUNT
        };

		/// @brief  Les tokens sont des objets qui repr�sentent les �l�ments d'un fichier texte.
		///         Pour l'analyse lexicale, on utilise un lexer qui va transformer un fichier texte en une liste de token,
		///         pour une meilleure analyse lexicale nous utiliserons des flags pour chaque token.
		///         Un flag c'est une mani�re de r�pertorier les diff�rents types de token.
        enum class token_flags {
            start_of_line = 0x01,           //Au d�but de la ligne ou seulement apr�s un espace.
                                            //En consid�rant la ligne apr�s les macroexpansions.
            leading_space = 0x02,           //Les espaces existent avant le token.
			                                //En consid�rant les espaces apr�s les macroexpansions.
			disable_expand = 0x04,          //Le token ne peut pas �tre macroexpand.
            needs_cleaning = 0x08,          //Le token contient un �chappement de nouvelle ligne ou tabulation.
            leading_empty_macro = 0x10,     //Un macro vide existe avant le token.
			has_ud_suffix = 0x20,           //Le token a un suffixe d'entier non standard.
			has_ucn = 0x40,                 //Le token contient un nombre universel de caract�res, caract�re d'�chappement.
			ignored_comma = 0x80,           //Le token n'est pas un s�parateur d'arguments macro 
			                                //et ne doit pas �tre remplac� par un espace.
			stringified_in_macro = 0x100,   //Le token est une cha�ne de caract�re ou un caract�re litt�ral par
                                            //La stringification ou caract�risation par macroop�ration.
			comma_after_elied = 0x200,      //Le token est une virgule apr�s un �lision.
            is_editor_placeholder = 0x400,  //Le token est un place-holder.
            COUNT = 11                      
        };

		struct loc {
			tok::source_location line;	// Num�ro de ligne
			tok::source_location column;	// Num�ro de colonne
		};

		class token {
		public:
			/// @brief  Le type du token d�fini conceptuellement ce qu'il repr�sente 
            ///         pour le compilateur et la fa�on dont il r�agir en cons�quence. 
            tok::token_t type;	

			///	@brief  La valeur du token est la valeur qu'il repr�sente dans le code source.
			std::string value;		

			/// @brief  L'emplacement du token est l'endroit o� il se trouve dans le code source.
			tok::loc location;		

			/// @brief  Les flags sont des informations suppl�mentaires par rapport au token
            tok::token_flags flags;

			token(std::string value) : type(tok::token_t::Unknown), value(value), flags(tok::token_flags::start_of_line) {}

            constexpr inline static token create_token(   tok::token_t type, std::string value, 
                                            tok::loc location, tok::token_flags flags  ) const noexcept;
		};	// !class token
	}	// !namespace tok
}	// !namespace cumpilator
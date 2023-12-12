/**
 * @file token.hpp
 * @author Mideky
 * @brief
 *	La classe token est une classe qui représente un token en C++ pour l'analyse lexicale.
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

		/// @brief  Les tokens sont des objets qui représentent les éléments d'un fichier texte.
		///         Pour l'analyse lexicale, on utilise un lexer qui va transformer un fichier texte en une liste de token,
		///         pour une meilleure analyse lexicale nous utiliserons des flags pour chaque token.
		///         Un flag c'est une manière de répertorier les différents types de token.
        enum class token_flags {
            start_of_line = 0x01,           //Au début de la ligne ou seulement après un espace.
                                            //En considérant la ligne après les macroexpansions.
            leading_space = 0x02,           //Les espaces existent avant le token.
			                                //En considérant les espaces après les macroexpansions.
			disable_expand = 0x04,          //Le token ne peut pas être macroexpand.
            needs_cleaning = 0x08,          //Le token contient un échappement de nouvelle ligne ou tabulation.
            leading_empty_macro = 0x10,     //Un macro vide existe avant le token.
			has_ud_suffix = 0x20,           //Le token a un suffixe d'entier non standard.
			has_ucn = 0x40,                 //Le token contient un nombre universel de caractères, caractère d'échappement.
			ignored_comma = 0x80,           //Le token n'est pas un séparateur d'arguments macro 
			                                //et ne doit pas être remplacé par un espace.
			stringified_in_macro = 0x100,   //Le token est une chaîne de caractère ou un caractère littéral par
                                            //La stringification ou caractérisation par macroopération.
			comma_after_elied = 0x200,      //Le token est une virgule après un élision.
            is_editor_placeholder = 0x400,  //Le token est un place-holder.
            COUNT = 11                      
        };

		struct loc {
			tok::source_location line;	// Numéro de ligne
			tok::source_location column;	// Numéro de colonne
		};

		class token {
		public:
			/// @brief  Le type du token défini conceptuellement ce qu'il représente 
            ///         pour le compilateur et la façon dont il réagir en conséquence. 
            tok::token_t type;	

			///	@brief  La valeur du token est la valeur qu'il représente dans le code source.
			std::string value;		

			/// @brief  L'emplacement du token est l'endroit où il se trouve dans le code source.
			tok::loc location;		

			/// @brief  Les flags sont des informations supplémentaires par rapport au token
            tok::token_flags flags;

			token(std::string value) : type(tok::token_t::Unknown), value(value), flags(tok::token_flags::start_of_line) {}

            constexpr inline static token create_token(   tok::token_t type, std::string value, 
                                            tok::loc location, tok::token_flags flags  ) const noexcept;
		};	// !class token
	}	// !namespace tok
}	// !namespace cumpilator
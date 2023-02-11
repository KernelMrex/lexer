#include "lib/lexer/CLexer.hpp"
#include <cstdlib>

inline static const std::map<Token::Type, std::string> tokenTypeNamesViewMap{
	{ Token::Type::ERROR, "ERROR" },
	{ Token::Type::END_OF_FILE, "END_OF_FILE" },
	{ Token::Type::ARITH_OP, "ARITH_OP" },
	{ Token::Type::SEPARATOR, "SEPARATOR" },
	{ Token::Type::ASSIGN, "ASSIGN" },
	{ Token::Type::BRACKET, "BRACKET" },
	{ Token::Type::ID, "ID" },
	{ Token::Type::IO_OP, "IO_OP" },
	{ Token::Type::TYPE, "TYPE" },
	{ Token::Type::STRING, "STRING" },
	{ Token::Type::INT, "INT" },
	{ Token::Type::FLOAT, "FLOAT" },
	{ Token::Type::IF_OP, "IF_OP" },
	{ Token::Type::LOOP_OP, "LOOP_OP" },
};

int main()
{
	CLexer lexer(std::cin);

	Token token;
	do
	{
		token = lexer.Next();
		std::cout << tokenTypeNamesViewMap.at(token.type) << ' ' << token.lexem << ' ' << token.line << ' ' << token.column << std::endl;
	} while (token.type != Token::Type::END_OF_FILE);

	return EXIT_SUCCESS;
}
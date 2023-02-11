#include "../../../src/lib/lexer/CLexer.hpp"
#include <gtest/gtest.h>

TEST(CLexerTest, CorrectlyHandlesArithmeticOpSum)
{
	std::istringstream iss("+\n++");
	CLexer lexer(iss);
	Token token;

	token = lexer.Next();
	ASSERT_EQ(token.type, Token::Type::ARITH_OP);
	ASSERT_EQ(token.lexem, "+");
	ASSERT_EQ(token.line, 1);
	ASSERT_EQ(token.column, 1);

	token = lexer.Next();
	ASSERT_EQ(token.type, Token::Type::ARITH_OP);
	ASSERT_EQ(token.lexem, "+");
	ASSERT_EQ(token.line, 2);
	ASSERT_EQ(token.column, 1);

	token = lexer.Next();
	ASSERT_EQ(token.type, Token::Type::ARITH_OP);
	ASSERT_EQ(token.lexem, "+");
	ASSERT_EQ(token.line, 2);
	ASSERT_EQ(token.column, 2);

	token = lexer.Next();
	ASSERT_EQ(token.type, Token::Type::END_OF_FILE);
	ASSERT_EQ(token.lexem, "");
	ASSERT_EQ(token.line, 2);
	ASSERT_EQ(token.column, 3);
}

TEST(CLexerTest, CorrectlyHandlesArithmeticOpSub)
{
	std::istringstream iss("-\n--");
	CLexer lexer(iss);
	Token token;

	token = lexer.Next();
	ASSERT_EQ(token.type, Token::Type::ARITH_OP);
	ASSERT_EQ(token.lexem, "-");
	ASSERT_EQ(token.line, 1);
	ASSERT_EQ(token.column, 1);

	token = lexer.Next();
	ASSERT_EQ(token.type, Token::Type::ARITH_OP);
	ASSERT_EQ(token.lexem, "-");
	ASSERT_EQ(token.line, 2);
	ASSERT_EQ(token.column, 1);

	token = lexer.Next();
	ASSERT_EQ(token.type, Token::Type::ARITH_OP);
	ASSERT_EQ(token.lexem, "-");
	ASSERT_EQ(token.line, 2);
	ASSERT_EQ(token.column, 2);

	token = lexer.Next();
	ASSERT_EQ(token.type, Token::Type::END_OF_FILE);
	ASSERT_EQ(token.lexem, "");
	ASSERT_EQ(token.line, 2);
	ASSERT_EQ(token.column, 3);
}

TEST(CLexerTest, CorrectlyHandlesArithmeticOpMul)
{
	std::istringstream iss("*\n**");
	CLexer lexer(iss);
	Token token;

	token = lexer.Next();
	ASSERT_EQ(token.type, Token::Type::ARITH_OP);
	ASSERT_EQ(token.lexem, "*");
	ASSERT_EQ(token.line, 1);
	ASSERT_EQ(token.column, 1);

	token = lexer.Next();
	ASSERT_EQ(token.type, Token::Type::ARITH_OP);
	ASSERT_EQ(token.lexem, "*");
	ASSERT_EQ(token.line, 2);
	ASSERT_EQ(token.column, 1);

	token = lexer.Next();
	ASSERT_EQ(token.type, Token::Type::ARITH_OP);
	ASSERT_EQ(token.lexem, "*");
	ASSERT_EQ(token.line, 2);
	ASSERT_EQ(token.column, 2);

	token = lexer.Next();
	ASSERT_EQ(token.type, Token::Type::END_OF_FILE);
	ASSERT_EQ(token.lexem, "");
	ASSERT_EQ(token.line, 2);
	ASSERT_EQ(token.column, 3);
}

TEST(CLexerTest, CorrectlyHandlesArithmeticOpDiv)
{
	std::istringstream iss("/\n//");
	CLexer lexer(iss);
	Token token;

	token = lexer.Next();
	ASSERT_EQ(token.type, Token::Type::ARITH_OP);
	ASSERT_EQ(token.lexem, "/");
	ASSERT_EQ(token.line, 1);
	ASSERT_EQ(token.column, 1);

	token = lexer.Next();
	ASSERT_EQ(token.type, Token::Type::ARITH_OP);
	ASSERT_EQ(token.lexem, "/");
	ASSERT_EQ(token.line, 2);
	ASSERT_EQ(token.column, 1);

	token = lexer.Next();
	ASSERT_EQ(token.type, Token::Type::ARITH_OP);
	ASSERT_EQ(token.lexem, "/");
	ASSERT_EQ(token.line, 2);
	ASSERT_EQ(token.column, 2);

	token = lexer.Next();
	ASSERT_EQ(token.type, Token::Type::END_OF_FILE);
	ASSERT_EQ(token.lexem, "");
	ASSERT_EQ(token.line, 2);
	ASSERT_EQ(token.column, 3);
}

TEST(CLexerTest, CorrectlyHandlesSeparatorSemicolon)
{
	std::istringstream iss(";");
	CLexer lexer(iss);
	Token token;

	token = lexer.Next();
	ASSERT_EQ(token.type, Token::Type::SEPARATOR);
	ASSERT_EQ(token.lexem, ";");
	ASSERT_EQ(token.line, 1);
	ASSERT_EQ(token.column, 1);
}

TEST(CLexerTest, CorrectlyHandlesSeparatorComma)
{
	std::istringstream iss(",");
	CLexer lexer(iss);
	Token token;

	token = lexer.Next();
	ASSERT_EQ(token.type, Token::Type::SEPARATOR);
	ASSERT_EQ(token.lexem, ",");
	ASSERT_EQ(token.line, 1);
	ASSERT_EQ(token.column, 1);
}

TEST(CLexerTest, CorrectlyHandlesAssign)
{
	std::istringstream iss("=");
	CLexer lexer(iss);
	Token token;

	token = lexer.Next();
	ASSERT_EQ(token.type, Token::Type::ASSIGN);
	ASSERT_EQ(token.lexem, "=");
	ASSERT_EQ(token.line, 1);
	ASSERT_EQ(token.column, 1);
}

TEST(CLexerTest, CorrectlyHandlesBracketOpening)
{
	std::istringstream iss("(");
	CLexer lexer(iss);
	Token token;

	token = lexer.Next();
	ASSERT_EQ(token.type, Token::Type::BRACKET);
	ASSERT_EQ(token.lexem, "(");
	ASSERT_EQ(token.line, 1);
	ASSERT_EQ(token.column, 1);
}

TEST(CLexerTest, CorrectlyHandlesBracketClosing)
{
	std::istringstream iss(")");
	CLexer lexer(iss);
	Token token;

	token = lexer.Next();
	ASSERT_EQ(token.type, Token::Type::BRACKET);
	ASSERT_EQ(token.lexem, ")");
	ASSERT_EQ(token.line, 1);
	ASSERT_EQ(token.column, 1);
}

TEST(CLexerTest, CorrectlyHandlesId)
{
	std::istringstream iss("test");
	CLexer lexer(iss);
	Token token;

	token = lexer.Next();
	ASSERT_EQ(token.type, Token::Type::ID);
	ASSERT_EQ(token.lexem, "test");
	ASSERT_EQ(token.line, 1);
	ASSERT_EQ(token.column, 1);
}

TEST(CLexerTest, CorrectlyHandlesMultipleIdWithSeparator)
{
	std::istringstream iss("test;test2");
	CLexer lexer(iss);
	Token token;

	token = lexer.Next();
	ASSERT_EQ(token.type, Token::Type::ID);
	ASSERT_EQ(token.lexem, "test");
	ASSERT_EQ(token.line, 1);
	ASSERT_EQ(token.column, 1);

	token = lexer.Next();
	ASSERT_EQ(token.type, Token::Type::SEPARATOR);
	ASSERT_EQ(token.lexem, ";");
	ASSERT_EQ(token.line, 1);
	ASSERT_EQ(token.column, 5);

	token = lexer.Next();
	ASSERT_EQ(token.type, Token::Type::ID);
	ASSERT_EQ(token.lexem, "test2");
	ASSERT_EQ(token.line, 1);
	ASSERT_EQ(token.column, 6);
}

TEST(CLexerTest, CorrectlyHandlesIOOPRead)
{
	std::istringstream iss("READ");
	CLexer lexer(iss);
	Token token;

	token = lexer.Next();
	ASSERT_EQ(token.type, Token::Type::IO_OP);
	ASSERT_EQ(token.lexem, "READ");
	ASSERT_EQ(token.line, 1);
	ASSERT_EQ(token.column, 1);
}

TEST(CLexerTest, CorrectlyHandlesIOOPWrite)
{
	std::istringstream iss("WRITE");
	CLexer lexer(iss);
	Token token;

	token = lexer.Next();
	ASSERT_EQ(token.type, Token::Type::IO_OP);
	ASSERT_EQ(token.lexem, "WRITE");
	ASSERT_EQ(token.line, 1);
	ASSERT_EQ(token.column, 1);
}

TEST(CLexerTest, CorrectlyHandlesMultipleIOOPRead)
{
	std::istringstream iss("READ;WRITE");
	CLexer lexer(iss);
	Token token;

	token = lexer.Next();
	ASSERT_EQ(token.type, Token::Type::IO_OP);
	ASSERT_EQ(token.lexem, "READ");
	ASSERT_EQ(token.line, 1);
	ASSERT_EQ(token.column, 1);

	token = lexer.Next();
	ASSERT_EQ(token.type, Token::Type::SEPARATOR);
	ASSERT_EQ(token.lexem, ";");
	ASSERT_EQ(token.line, 1);
	ASSERT_EQ(token.column, 5);

	token = lexer.Next();
	ASSERT_EQ(token.type, Token::Type::IO_OP);
	ASSERT_EQ(token.lexem, "WRITE");
	ASSERT_EQ(token.line, 1);
	ASSERT_EQ(token.column, 6);
}

TEST(CLexerTest, CorrectlyHandlesTypeInt)
{
	std::istringstream iss("int");
	CLexer lexer(iss);
	Token token;

	token = lexer.Next();
	ASSERT_EQ(token.type, Token::Type::TYPE);
	ASSERT_EQ(token.lexem, "int");
	ASSERT_EQ(token.line, 1);
	ASSERT_EQ(token.column, 1);
}

TEST(CLexerTest, CorrectlyHandlesTypeFloat)
{
	std::istringstream iss("float");
	CLexer lexer(iss);
	Token token;

	token = lexer.Next();
	ASSERT_EQ(token.type, Token::Type::TYPE);
	ASSERT_EQ(token.lexem, "float");
	ASSERT_EQ(token.line, 1);
	ASSERT_EQ(token.column, 1);
}

TEST(CLexerTest, CorrectlyHandlesTypeString)
{
	std::istringstream iss("string");
	CLexer lexer(iss);
	Token token;

	token = lexer.Next();
	ASSERT_EQ(token.type, Token::Type::TYPE);
	ASSERT_EQ(token.lexem, "string");
	ASSERT_EQ(token.line, 1);
	ASSERT_EQ(token.column, 1);
}

TEST(CLexerTest, CorrectlyHandlesString)
{
	std::istringstream iss("'something in the string'");
	CLexer lexer(iss);
	Token token;

	token = lexer.Next();
	ASSERT_EQ(token.type, Token::Type::STRING);
	ASSERT_EQ(token.lexem, "'something in the string'");
	ASSERT_EQ(token.line, 1);
	ASSERT_EQ(token.column, 1);
}

TEST(CLexerTest, CorrectlyHandlesMultipleStrings)
{
	std::istringstream iss("'abs''edf'");
	CLexer lexer(iss);
	Token token;

	token = lexer.Next();
	ASSERT_EQ(token.type, Token::Type::STRING);
	ASSERT_EQ(token.lexem, "'abs'");
	ASSERT_EQ(token.line, 1);
	ASSERT_EQ(token.column, 1);

	token = lexer.Next();
	ASSERT_EQ(token.type, Token::Type::STRING);
	ASSERT_EQ(token.lexem, "'edf'");
	ASSERT_EQ(token.line, 1);
	ASSERT_EQ(token.column, 6);
}

TEST(CLexerTest, CorrectlyHandlesEmptyString)
{
	std::istringstream iss("''");
	CLexer lexer(iss);
	Token token;

	token = lexer.Next();
	ASSERT_EQ(token.type, Token::Type::STRING);
	ASSERT_EQ(token.lexem, "''");
	ASSERT_EQ(token.line, 1);
	ASSERT_EQ(token.column, 1);
}

TEST(CLexerTest, CorrectlyHandlesUnclosedString)
{
	std::istringstream iss("'unclosed string");
	CLexer lexer(iss);
	Token token;

	token = lexer.Next();
	ASSERT_EQ(token.type, Token::Type::ERROR);
	ASSERT_EQ(token.lexem, "");
	ASSERT_EQ(token.line, 1);
	ASSERT_EQ(token.column, 16);
}

TEST(CLexerTest, CorrectlyHandlesIntZero)
{
	std::istringstream iss("0");
	CLexer lexer(iss);
	Token token;

	token = lexer.Next();
	ASSERT_EQ(token.type, Token::Type::INT);
	ASSERT_EQ(token.lexem, "0");
	ASSERT_EQ(token.line, 1);
	ASSERT_EQ(token.column, 1);
}

TEST(CLexerTest, CorrectlyHandlesIntHexNumber)
{
	std::istringstream iss("0x1234567890abcdef");
	CLexer lexer(iss);
	Token token;

	token = lexer.Next();
	ASSERT_EQ(token.type, Token::Type::INT);
	ASSERT_EQ(token.lexem, "0x1234567890abcdef");
	ASSERT_EQ(token.line, 1);
	ASSERT_EQ(token.column, 1);
}

TEST(CLexerTest, CorrectlyHandlesIntInvalidHexNumberWithEmptyNumberPart)
{
	std::istringstream iss("0x");
	CLexer lexer(iss);
	Token token;

	token = lexer.Next();
	ASSERT_EQ(token.type, Token::Type::ERROR);
	ASSERT_EQ(token.lexem, "");
	ASSERT_EQ(token.line, 1);
	ASSERT_EQ(token.column, 3);
}

TEST(CLexerTest, CorrectlyHandlesIntInvalidHexNumberWithInvalidChars)
{
	std::istringstream iss("0x0123456789abcdefg");
	CLexer lexer(iss);
	Token token;

	token = lexer.Next();
	ASSERT_EQ(token.type, Token::Type::ERROR);
	ASSERT_EQ(token.lexem, "");
	ASSERT_EQ(token.line, 1);
	ASSERT_EQ(token.column, 19);
}

TEST(CLexerTest, CorrectlyHandlesIntOctNumber)
{
	std::istringstream iss("0o1234567");
	CLexer lexer(iss);
	Token token;

	token = lexer.Next();
	ASSERT_EQ(token.type, Token::Type::INT);
	ASSERT_EQ(token.lexem, "0o1234567");
	ASSERT_EQ(token.line, 1);
	ASSERT_EQ(token.column, 1);
}

TEST(CLexerTest, CorrectlyHandlesIntInvalidOctNumberWithEmptyNumberPart)
{
	std::istringstream iss("0o");
	CLexer lexer(iss);
	Token token;

	token = lexer.Next();
	ASSERT_EQ(token.type, Token::Type::ERROR);
	ASSERT_EQ(token.lexem, "");
	ASSERT_EQ(token.line, 1);
	ASSERT_EQ(token.column, 3);
}

TEST(CLexerTest, CorrectlyHandlesIntInvalidOctNumberWithInvalidChars)
{
	std::istringstream iss("0o012345678");
	CLexer lexer(iss);
	Token token;

	token = lexer.Next();
	ASSERT_EQ(token.type, Token::Type::ERROR);
	ASSERT_EQ(token.lexem, "");
	ASSERT_EQ(token.line, 1);
	ASSERT_EQ(token.column, 11);
}

TEST(CLexerTest, CorrectlyHandlesIntBinNumber)
{
	std::istringstream iss("0b01");
	CLexer lexer(iss);
	Token token;

	token = lexer.Next();
	ASSERT_EQ(token.type, Token::Type::INT);
	ASSERT_EQ(token.lexem, "0b01");
	ASSERT_EQ(token.line, 1);
	ASSERT_EQ(token.column, 1);
}

TEST(CLexerTest, CorrectlyHandlesIntInvalidBinNumberWithEmptyNumberPart)
{
	std::istringstream iss("0b");
	CLexer lexer(iss);
	Token token;

	token = lexer.Next();
	ASSERT_EQ(token.type, Token::Type::ERROR);
	ASSERT_EQ(token.lexem, "");
	ASSERT_EQ(token.line, 1);
	ASSERT_EQ(token.column, 3);
}

TEST(CLexerTest, CorrectlyHandlesIntInvalidBinNumberWithInvalidChars)
{
	std::istringstream iss("0b012");
	CLexer lexer(iss);
	Token token;

	token = lexer.Next();
	ASSERT_EQ(token.type, Token::Type::ERROR);
	ASSERT_EQ(token.lexem, "");
	ASSERT_EQ(token.line, 1);
	ASSERT_EQ(token.column, 5);
}

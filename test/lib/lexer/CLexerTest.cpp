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
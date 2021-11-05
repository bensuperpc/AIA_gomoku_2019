/*
** EPITECH PROJECT, 2019
** IA_Gomoku
** File description:
** tests
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <iostream>
#include <sstream>
#include "Gomoku.hpp"

int error(void);
void redirect_all_stdout(void);

void redirect_all_stdout(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(test_gomoku, START_cmd_test)
{
    const std::string START_OK = "OK - everything is good";
    std::string expected = START_OK + static_cast<std::string>("\n9,9\nnone\n");
    Gomoku gomoku_class;

    // Save old buff
    std::streambuf *oldCoutStreamBuf = std::cout.rdbuf();
    std::streambuf *oldCerrStreamBuf = std::cerr.rdbuf();
    std::streambuf *oldCinStreamBuf = std::cin.rdbuf();

    // Create buff
    std::ostringstream strCout;
    std::ostringstream strCerr;
    std::istringstream strCin("START 20\nBEGIN\nEND");

    // Redirect buff
    std::cout.rdbuf(strCout.rdbuf());
    std::cerr.rdbuf(strCerr.rdbuf());
    std::cin.rdbuf(strCin.rdbuf());

    int ret = gomoku_class.get_command();
    cr_assert_eq(ret, 1, "Result: %i, expected: %i", ret, 1);

    // Save in std::string
    std::string out = strCout.str();
    std::string err = strCerr.str();

    // Restore std::cout
    std::cout.rdbuf(oldCoutStreamBuf);
    std::cerr.rdbuf(oldCerrStreamBuf);
    std::cin.rdbuf(oldCinStreamBuf);
    cr_assert_str_eq(out.c_str(), expected.c_str(), "Result: %s, expected: %s", out.c_str(), expected.c_str());
}

Test(test_gomoku, END_cmd, .init = redirect_all_stdout)
{
    std::string message = "END";
    std::string expected = "none\n";
    Gomoku gomoku_class;
    int ret = gomoku_class.get_command(message);
    cr_assert_eq(ret, 1, "Result: %i, expected: %i", ret, 1);
    cr_assert_stdout_eq_str(expected.c_str(), "Wrong output !");
}

Test(test_gomoku, START_Value_1, .init = redirect_all_stdout)
{
    const std::string START_OK = "OK - everything is good";
    std::string message = "START 20";
    std::string expected = START_OK + static_cast<std::string>("\n");
    Gomoku gomoku_class;
    int ret = gomoku_class.get_command(message);
    cr_assert_eq(ret, 0, "Result: %i, expected: %i", ret, 0);
    cr_assert_stdout_eq_str(expected.c_str(), "Wrong output !");
}

Test(test_gomoku, START_Value_2, .init = redirect_all_stdout)
{
    const std::string START_OK = "OK - everything is good";
    std::string message = "START 12";
    std::string expected = START_OK + static_cast<std::string>("\n");
    Gomoku gomoku_class;
    int ret = gomoku_class.get_command(message);
    cr_assert_eq(ret, 0, "Result: %i, expected: %i", ret, 0);
    cr_assert_stdout_eq_str(expected.c_str(), "Wrong output !");
}

Test(test_gomoku, START_Value_3, .init = redirect_all_stdout)
{
    const std::string START_ERR = "ERROR - unsupported size or other error";
    std::string message = "START 1";
    std::string expected = START_ERR + static_cast<std::string>("\n");
    Gomoku gomoku_class;
    int ret = gomoku_class.get_command(message);
    cr_assert_eq(ret, 84, "Result: %i, expected: %i", ret, 84);
    cr_assert_stdout_eq_str(expected.c_str(), "Wrong output !");
}

Test(test_gomoku, START_already_started_1, .init = redirect_all_stdout)
{
    const std::string START_OK = "OK - everything is good";
    std::string message = "START 5";
    std::string expected = START_OK + static_cast<std::string>("\n");
    Gomoku gomoku_class;
    int ret = gomoku_class.get_command(message);
    cr_assert_eq(ret, 0, "Result: %i, expected: %i", ret, 0);
    cr_assert_stdout_eq_str(expected.c_str(), "Wrong output !");
}

Test(test_gomoku, START_already_started_2, .init = redirect_all_stdout)
{
    const std::string START_OK = "OK - everything is good";
    std::string message = "START 15";
    std::string expected = START_OK + static_cast<std::string>("\n");
    Gomoku gomoku_class;
    int ret = gomoku_class.get_command(message);
    cr_assert_eq(ret, 0, "Result: %i, expected: %i", ret, 0);
    cr_assert_stdout_eq_str(expected.c_str(), "Wrong output !");
}

Test(test_gomoku, START__empty_Value_1, .init = redirect_all_stdout)
{
    const std::string START_ERR = "ERROR - unsupported size or other error";
    std::string message = "START";
    std::string expected = START_ERR + static_cast<std::string>("\n");
    Gomoku gomoku_class;
    int ret = gomoku_class.get_command(message);
    cr_assert_eq(ret, 84, "Result: %i, expected: %i", ret, 84);
    cr_assert_stdout_eq_str(expected.c_str(), "Wrong output !");
}

Test(test_gomoku, START__empty_Value_2, .init = redirect_all_stdout)
{
    const std::string START_ERR = "ERROR - unsupported size or other error";
    std::string message = "START ";
    std::string expected = START_ERR + static_cast<std::string>("\n");
    Gomoku gomoku_class;
    int ret = gomoku_class.get_command(message);
    cr_assert_eq(ret, 84, "Result: %i, expected: %i", ret, 84);
    cr_assert_stdout_eq_str(expected.c_str(), "Wrong output !");
}

Test(test_gomoku, START__empty_Value_3, .init = redirect_all_stdout)
{
    const std::string START_ERR = "ERROR - unsupported size or other error";
    std::string message = "START                ";
    std::string expected = START_ERR + static_cast<std::string>("\n");
    Gomoku gomoku_class;
    int ret = gomoku_class.get_command(message);
    cr_assert_eq(ret, 84, "Result: %i, expected: %i", ret, 84);
    cr_assert_stdout_eq_str(expected.c_str(), "Wrong output !");
}

Test(test_gomoku, START__wrong_Value_1, .init = redirect_all_stdout)
{
    const std::string START_ERR = "ERROR - unsupported size or other error";
    std::string message = "START 0";
    std::string expected = START_ERR + static_cast<std::string>("\n");
    Gomoku gomoku_class;
    int ret = gomoku_class.get_command(message);
    cr_assert_eq(ret, 84, "Result: %i, expected: %i", ret, 84);
    cr_assert_stdout_eq_str(expected.c_str(), "Wrong output !");
}

Test(test_gomoku, START__wrong_Value_2, .init = redirect_all_stdout)
{
    const std::string START_ERR = "ERROR - unsupported size or other error";
    std::string message = "START 4";
    std::string expected = START_ERR + static_cast<std::string>("\n");
    Gomoku gomoku_class;
    int ret = gomoku_class.get_command(message);
    cr_assert_eq(ret, 84, "Result: %i, expected: %i", ret, 84);
    cr_assert_stdout_eq_str(expected.c_str(), "Wrong output !");
}

Test(test_gomoku, START__wrong_Value_3, .init = redirect_all_stdout)
{
    const std::string START_ERR = "ERROR - unsupported size or other error";
    std::string message = "START 21";
    std::string expected = START_ERR + static_cast<std::string>("\n");
    Gomoku gomoku_class;
    int ret = gomoku_class.get_command(message);
    cr_assert_eq(ret, 84, "Result: %i, expected: %i", ret, 84);
    cr_assert_stdout_eq_str(expected.c_str(), "Wrong output !");
}

Test(test_gomoku, START__wrong_Value_4, .init = redirect_all_stdout)
{
    const std::string START_ERR = "ERROR - unsupported size or other error";
    std::string message = "START 60";
    std::string expected = START_ERR + static_cast<std::string>("\n");
    Gomoku gomoku_class;
    int ret = gomoku_class.get_command(message);
    cr_assert_eq(ret, 84, "Result: %i, expected: %i", ret, 84);
    cr_assert_stdout_eq_str(expected.c_str(), "Wrong output !");
}

Test(test_gomoku, RESTART_cmd, .init = redirect_all_stdout)
{
    const std::string RESTART_OK = "OK";
    std::string message = "RESTART";
    std::string expected = RESTART_OK + static_cast<std::string>("\n");
    Gomoku gomoku_class;
    int ret = gomoku_class.get_command(message);
    cr_assert_eq(ret, 0, "Result: %i, expected: %i", ret, 0);
    cr_assert_stdout_eq_str(expected.c_str(), "Wrong output !");
}

Test(test_gomoku, Display_1)
{
    const std::string START_OK = "OK - everything is good\n";
    std::string expected = START_OK + static_cast<std::string>("4,4\n");
    expected = expected
               + "*********************\n |  2  0  0  0  0  |\n |  0  2  0  0  0  |\n |  0  0  2  0  0  |\n |  0  0  0 "
                 " 2  0  "
                 "|\n |  0  0  0  0  1  |\n*********************\n";
    expected = expected + static_cast<std::string>("none\n");
    std::string commands = "START 5\nBOARD\n0,0,2\n1,1,2\n2,2,2\n3,3,2\nDONE\nDISPLAY\nEND\n";
    Gomoku gomoku;

    // Save old buff
    std::streambuf *oldCoutStreamBuf = std::cout.rdbuf();
    std::streambuf *oldCinStreamBuf = std::cin.rdbuf();

    // Create buff
    std::ostringstream strCout;
    std::istringstream strCin(commands);

    // Redirect buff
    std::cout.rdbuf(strCout.rdbuf());
    std::cin.rdbuf(strCin.rdbuf());

    int ret = gomoku.get_command();
    cr_assert_eq(ret, 1, "Result: %i, expected: %i", ret, 1);

    // Save in std::string
    std::string out = strCout.str();
    // Restore std::cout
    std::cout.rdbuf(oldCoutStreamBuf);
    std::cin.rdbuf(oldCinStreamBuf);
    cr_assert_str_eq(out.c_str(), expected.c_str(), "Result: %s, expected: %s", out.c_str(), expected.c_str());
}
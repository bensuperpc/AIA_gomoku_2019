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

Test(test_attack, basic_attack_1)
{
    const std::string START_OK = "OK - everything is good\n";
    std::string expected = START_OK + static_cast<std::string>("0,4\nnone\n");
    std::string commands = "START 20\nBOARD\n0,0,2\n0,1,2\n0,2,2\n0,3,2\nDONE\nEND\n";
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

Test(test_attack, basic_attack_2)
{
    const std::string START_OK = "OK - everything is good\n";
    std::string expected = START_OK + static_cast<std::string>("4,4\nnone\n");
    std::string commands = "START 20\nBOARD\n0,0,2\n1,1,2\n2,2,2\n3,3,2\nDONE\nEND\n";
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

Test(test_attack, basic_attack_3)
{
    const std::string START_OK = "OK - everything is good\n";
    std::string expected = START_OK + static_cast<std::string>("15,15\nnone\n");
    std::string commands = "START 20\nBOARD\n19,19,2\n18,18,2\n17,17,2\n16,16,2\nDONE\nEND\n";
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

Test(test_attack, basic_attack_4)
{
    const std::string START_OK = "OK - everything is good\n";
    std::string expected = START_OK + static_cast<std::string>("3,3\nnone\n");
    std::string commands = "START 20\nTURN 0,0\nTURN 1,1\nBOARD\n2,2,1\nDONE\nEND\n";
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
    cr_assert_str_neq(out.c_str(), expected.c_str(), "Result: %s, expected: %s", out.c_str(), expected.c_str());
}

Test(test_attack, basic_attack_5)
{
    const std::string START_OK = "OK - everything is good\n";
    std::string expected = START_OK + static_cast<std::string>("MESSAGE PLAYER WIN\nnone\n");
    std::string commands = "START 20\nBOARD\n19,19,2\n18,18,2\n17,17,2\n16,16,2\n15,15,2\nDONE\nEND\n";
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

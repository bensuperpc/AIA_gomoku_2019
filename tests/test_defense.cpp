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

Test(test_attack, basic_defense_1)
{
    const std::string START_OK = "OK - everything is good\n";
    std::string expected = START_OK + static_cast<std::string>("0,4\nnone\n");
    std::string commands = "START 20\nBOARD\n0,0,1\n0,1,1\n0,2,1\n0,3,1\nDONE\nEND\n";
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

Test(test_attack, basic_defense_2)
{
    const std::string START_OK = "OK - everything is good\n";
    std::string expected = START_OK + static_cast<std::string>("4,4\nnone\n");
    std::string commands = "START 20\nBOARD\n0,0,1\n1,1,1\n2,2,1\n3,3,1\nDONE\nEND\n";
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

Test(test_attack, basic_defense_3)
{
    const std::string START_OK = "OK - everything is good\n";
    std::string expected = START_OK + static_cast<std::string>("15,15\nnone\n");
    std::string commands = "START 20\nBOARD\n19,19,1\n18,18,1\n17,17,1\n16,16,1\nDONE\nEND\n";
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

Test(test_attack, basic_defense_4)
{
    const std::string START_OK = "OK - everything is good\n";
    std::string expected = START_OK + static_cast<std::string>("15,4\nnone\n");
    std::string commands = "START 20\nBOARD\n19,0,1\n18,1,1\n17,2,1\n16,3,1\nDONE\nEND\n";
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

Test(test_attack, mix_defense_1)
{
    const std::string START_OK = "OK - everything is good\n";
    std::string expected = START_OK + static_cast<std::string>("15,4\nnone\n");
    std::string commands = "START "
                           "20\nBOARD\n19,0,1\n18,1,1\n17,2,1\n16,3,1\n0,0,1\n1,1,1\n2,2,1\n19,"
                           "19,2\n18,18,2\n17,17,2\nDONE\nEND\n";
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

Test(test_attack, basic_defense_same_lengh_1)
{
    const std::string START_OK = "OK - everything is good\n";
    std::string expected = START_OK + static_cast<std::string>("4,4\nnone\n");
    std::string commands = "START "
                           "20\nBOARD\n19,19,2\n18,18,2\n17,17,2\n16,16,2\n0,"
                           "0,1\n1,1,1\n2,2,1\n3,3,1\nDONE\nEND\n";
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

Test(test_attack, basic_defense_same_lengh_2)
{
    const std::string START_OK = "OK - everything is good\n";
    std::string expected = START_OK + static_cast<std::string>("1,4\nnone\n");
    std::string commands = "START "
                           "20\nBOARD\n0,0,2\n0,1,2\n0,2,2\n0,3,2\n1,0,1\n1,1,"
                           "1\n1,2,1\n1,3,1\nDONE\nEND\n";
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

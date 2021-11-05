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

Test(test_attack, basic_divers_1)
{
    const std::string START_OK = "OK - everything is good\n";
    std::string expected = START_OK + static_cast<std::string>("MESSAGE PLAYER WIN\nnone\n");
    std::string commands
        = "START "
          "20\nBOARD\n10,11,2\n8,8,1\n6,9,2\n7,7,1\n10,10,2\n6,6,1\n5,5,2\n5,6,1\n7,3,2\n4,6,1\n7,6,2\n3,6,1\n2,6,2\n2,"
          "5,1\n1,3,2\n1,4,1\n4,7,2\n0,3,1\n8,13,2\n0,2,1\n11,11,2\n0,1,1\n0,4,2\n0,0,1\n7,12,2\n0,5,1\n12,12,2\n13,13,"
          "1\n0,7,2\n2,3,1\n4,1,2\n3,2,1\n1,6,2\n0,6,1\n3,7,2\n1,0,1\n1,7,2\n2,0,1\n2,7,2\nDONE\nEND\n";
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

/*
Test(test_attack, basic_divers_2)
{
    const std::string START_OK = "OK - everything is good\n";
    std::string expected = START_OK + static_cast<std::string>("MESSAGE PLAYER WIN\nnone\n");
    std::string commands
        = "START "
          "20\nBOARD\n10,11,2\n8,8,1\n6,9,2\n7,7,1\n10,10,2\n6,6,1\n5,5,2\n5,6,1\n7,3,2\n4,6,1\n7,6,2\n3,6,1\n2,6,2\n2,"
          "5,1\n1,3,2\n1,4,1\n4,7,2\n0,3,1\n8,13,2\n0,2,1\n11,11,2\n0,1,1\n0,4,2\n0,0,1\n7,12,2\n0,5,1\n12,12,2\n13,13,"
          "1\n0,7,2\n2,3,1\n4,1,2\n3,2,1\n1,6,2\n0,6,1\n3,7,2\n1,0,1\n1,7,2\n2,0,1\n2,7,2\nDONE\nEND\n";
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
*/
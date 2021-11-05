/*
** EPITECH PROJECT, 2019
** IA_Gomoku
** File description:
** tests
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <cstdint>
#include "AI.hpp"

Test(ai_tests, simple_1)
{
    AI glados = AI();
    cr_assert(1);
}

Test(ai_tests, simple_2)
{
    std::string str = "glados";
    AI glados = AI(str);
    cr_assert_str_eq(
        glados.name.c_str(), str.c_str(), "The result was %s. Expected %s", glados.name.c_str(), str.c_str());
}

Test(ai_tests, simple_3)
{
    std::string str = "";
    AI glados = AI(str);
    cr_assert_str_eq(
        glados.name.c_str(), str.c_str(), "The result was %s. Expected %s", glados.name.c_str(), str.c_str());
}

Test(ai_tests, set_pawn_1)
{
    AI glados = AI();
    glados.set_board_size(10);
    glados.enemy_set_pawn(1, 2);
    // Message de retour
    cr_assert(1);
}

Test(ai_tests, set_pawn_2)
{
    AI glados = AI();
    glados.set_board_size(5);
    glados.enemy_set_pawn(1, 2);
    // Message de retour
    cr_assert(1);
}

Test(ai_tests, set_pawn_wrong_pos_1)
{
    AI glados = AI();
    glados.set_board_size(5);
    glados.enemy_set_pawn(20, 2);
    // Message de retour
    cr_assert(1);
}

Test(ai_tests, set_pawn_wrong_pos_2)
{
    AI glados = AI();
    glados.set_board_size(5);
    glados.enemy_set_pawn(0, 20);
    // Message de retour
    cr_assert(1);
}

Test(ai_tests, set_pawn_board_unset)
{
    AI glados = AI();
    glados.enemy_set_pawn(1, 2);
    // Message de retour
    cr_assert(1);
}
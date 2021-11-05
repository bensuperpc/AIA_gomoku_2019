/*
** EPITECH PROJECT, 2019
** IA_Gomoku
** File description:
** tests
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "Board/Board.hpp"

Test(board_tests, simple_1)
{
    size_t size = 10;
    Board simple_board(size);
    cr_assert_eq(
        simple_board.get_board_size(), size, "The result was %i. Expected %i", simple_board.get_board_size(), size);
}

Test(board_tests, simple_2)
{
    size_t size = 0;
    Board simple_board(size);
    cr_assert_eq(
        simple_board.get_board_size(), size, "The result was %i. Expected %i", simple_board.get_board_size(), size);
}

Test(board_tests, simple_3)
{
    size_t size = 30;
    Board simple_board(size);
    cr_assert_eq(
        simple_board.get_board_size(), size, "The result was %i. Expected %i", simple_board.get_board_size(), size);
}

Test(board_tests, reset_1)
{
    size_t size = 0;
    Board simple_board(size);
    simple_board.reset_board();
    cr_assert_eq(simple_board.get_board_size(), 0, "The result was %i. Expected %i", simple_board.get_board_size(), 0);
}

Test(board_tests, reset_2)
{
    size_t size = 5;
    Board simple_board(size);
    simple_board.reset_board();
    cr_assert_eq(
        simple_board.get_board_size(), size, "The result was %i. Expected %i", simple_board.get_board_size(), size);
}

Test(board_tests, simple_default_constr_1)
{
    Board simple_board();
    cr_assert_not_null(simple_board);
}

Test(board_tests, simple_default_constr_2)
{
    Board simple_board;
    cr_assert_eq(simple_board.get_board_size(), 0, "The result was %i. Expected %i", simple_board.get_board_size(), 0);
}

Test(board_tests, simple_set_board_size_1)
{
    size_t size = 5;
    Board simple_board;
    simple_board.set_size_board(size);
    cr_assert_eq(
        simple_board.get_board_size(), size, "The result was %i. Expected %i", simple_board.get_board_size(), size);
}

Test(board_tests, simple_set_board_size_2)
{
    size_t size = 5;
    Board simple_board;
    simple_board.set_size_board(size);
    cr_assert_eq(
        simple_board.get_board_size(), size, "The result was %i. Expected %i", simple_board.get_board_size(), size);
}

Test(board_tests, get_cells_count_1)
{
    size_t size = 5;
    size_t exp_res = 25;
    Board simple_board = Board(size);
    cr_assert_eq(simple_board.get_cells_count(), exp_res, "The result was %i. Expected %i",
        simple_board.get_cells_count(), exp_res);
}

Test(board_tests, get_cells_count_2)
{
    size_t size = 20;
    size_t exp_res = 400;
    Board simple_board = Board(size);
    cr_assert_eq(simple_board.get_cells_count(), exp_res, "The result was %i. Expected %i",
        simple_board.get_cells_count(), exp_res);
}

Test(board_tests, get_cells_count_3)
{
    size_t size = 0;
    size_t exp_res = 0;
    Board simple_board = Board(size);
    cr_assert_eq(simple_board.get_cells_count(), exp_res, "The result was %i. Expected %i",
        simple_board.get_cells_count(), exp_res);
}

Test(board_tests, get_cells_count_4)
{
    size_t size = 1;
    size_t exp_res = 1;
    Board simple_board = Board(size);
    cr_assert_eq(simple_board.get_cells_count(), exp_res, "The result was %i. Expected %i",
        simple_board.get_cells_count(), exp_res);
}

Test(board_tests, is_playable_1)
{
    size_t size = 3;
    Board simple_board = Board(size);
    cr_assert_eq(
        simple_board.is_playable_pos(0, 0), 1, "The result was %i. Expected %i", simple_board.is_playable_pos(0, 0), 1);
}

Test(board_tests, is_playable_2)
{
    size_t size = 20;
    Board simple_board = Board(size);
    cr_assert_eq(simple_board.is_playable_pos(15, 15), 1, "The result was %i. Expected %i",
        simple_board.is_playable_pos(15, 15), 1);
}

Test(board_tests, is_playable_1_error_pos)
{
    size_t size = 10;
    Board simple_board = Board(size);
    cr_assert_eq(simple_board.is_playable_pos(15, 15), -1, "The result was %i. Expected %i",
        simple_board.is_playable_pos(15, 15), -1);
}

Test(board_tests, is_playable_unplayable_1)
{
    size_t size = 20;
    Board simple_board = Board(size);
    simple_board.set_force_pawn(15, 15, simple_board.AI_PAWN);
    cr_assert_eq(simple_board.is_playable_pos(15, 15), 0, "The result was %i. Expected %i",
        simple_board.is_playable_pos(15, 15), 0);
}

Test(board_tests, is_playable_unplayable_2)
{
    size_t size = 20;
    Board simple_board = Board(size);
    simple_board.set_force_pawn(15, 15, simple_board.PLAYER_PAWN);
    simple_board.set_force_pawn(0, 0, simple_board.AI_PAWN);
    cr_assert_eq(simple_board.is_playable_pos(15, 15), 0, "The result was %i. Expected %i",
        simple_board.is_playable_pos(15, 15), 0);
    cr_assert_eq(simple_board.get_pawn(0, 0), simple_board.AI_PAWN, "The result was %i. Expected %i",
        simple_board.get_pawn(0, 0), simple_board.AI_PAWN);
}

Test(board_tests, reset_unplay_1)
{
    Board simple_board = Board(20);
    for (int i = 0; i < 19; i++) {
        simple_board.set_force_pawn(i, 19 - i, i + 3);
        simple_board.set_force_pawn(19 - i, i, 19 - i + 3);
    }
    simple_board.reset_unplay();
    for (int x = 0; x < 19; x++) {
        for (int y = 0; y < 19; y++) {
            cr_assert_eq(simple_board.is_playable_pos(x, y), 1, "The result was %i. Expected %i",
                simple_board.is_playable_pos(x, y), 1);
        }
    }
}

/*
** EPITECH PROJECT, 2019
** IA_Gomoku
** File description:
** tests
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <cstdint>
#include <math.h>
#include "Board/Board.hpp"
#include "Board/BoardRTree.hpp"

Test(board_rtree_tests, simple_1)
{
    BoardRTree btree = BoardRTree();
    cr_assert(1);
}

Test(board_rtree_tests, simple_2)
{
    Board b_board(20);
    BoardRTree btree(b_board);
    cr_assert(1);
}

Test(board_rtree_tests, generate_leafs_1)
{
    size_t depth = 2;
    BoardRTree btree = BoardRTree(Board(10), depth, true);
    cr_assert_eq(btree.get_cells_count(), 100, "The result was %i. Expected %i", btree.get_cells_count(), 100);
    cr_assert_eq(btree.number_leafs(), 10000, "The result was %i. Expected %i", btree.number_leafs(), 10000);
    cr_assert(1);
}

Test(board_rtree_tests, generate_leafs_2)
{
    size_t depth = 1;
    Board b_board = Board(5);
    BoardRTree btree = BoardRTree(b_board, depth, true);
    cr_assert_eq(btree.number_leafs(), btree.get_cells_count(), "The result was %i. Expected %i", btree.number_leafs(),
        btree.get_cells_count());
}

Test(board_rtree_tests, generate_leafs_3)
{
    size_t depth = 0;
    Board b_board = Board(5);
    BoardRTree btree = BoardRTree(b_board, depth, true);
    cr_assert_eq(btree.number_leafs(), 0, "The result was %i. Expected %i", btree.number_leafs(), 0);
}

Test(board_rtree_tests, generate_leafs_4)
{
    size_t depth = 5;
    Board b_board = Board(0);
    BoardRTree btree = BoardRTree(b_board, depth, true);
    cr_assert_eq(b_board.get_cells_count(), 0, "The result was %i. Expected %i", b_board.get_cells_count(), 0);
    cr_assert_eq(btree.number_leafs(), 0, "The result was %i. Expected %i", btree.number_leafs(), 0);
}

Test(board_rtree_tests, generate_leafs_5)
{
    size_t depth = 3;
    Board b_board = Board(4);
    BoardRTree btree = BoardRTree(b_board, depth, true);
    cr_assert_eq(b_board.get_cells_count(), 16, "The result was %i. Expected %i", b_board.get_cells_count(), 16);
    cr_assert_eq(btree.number_leafs(), 3616, "The result was %i. Expected %i", btree.number_leafs(), 3616);
}

Test(board_rtree_tests, generate_leafs_6)
{
    size_t depth = 5;
    Board b_board = Board(1);
    BoardRTree btree = BoardRTree(b_board, depth, true);
    cr_assert_eq(b_board.get_cells_count(), 1, "The result was %i. Expected %i", b_board.get_cells_count(), 1);
    cr_assert_eq(btree.number_leafs(), 1, "The result was %i. Expected %i", btree.number_leafs(), 1);
}

Test(board_rtree_tests, generate_leafs_7)
{
    size_t depth = 3;
    Board b_board = Board(5);
    BoardRTree btree = BoardRTree(b_board, depth, true);
    cr_assert_eq(b_board.get_cells_count(), 25, "The result was %i. Expected %i", b_board.get_cells_count(), 25);
    cr_assert_eq(btree.number_leafs(), 14425, "The result was %i. Expected %i", btree.number_leafs(), 14425);
}

Test(board_rtree_tests, generate_leafs_8)
{
    size_t depth = 100;
    Board b_board = Board(2);
    BoardRTree btree = BoardRTree(b_board, depth, true);
    cr_assert_eq(b_board.get_cells_count(), 4, "The result was %i. Expected %i", b_board.get_cells_count(), 4);
    cr_assert_eq(btree.number_leafs(), 64, "The result was %i. Expected %i", btree.number_leafs(), 64);
}

Test(board_rtree_tests, generate_leafs_9)
{
    size_t depth = 3;
    Board b_board = Board(3);
    BoardRTree btree = BoardRTree(b_board, depth, true);
    cr_assert_eq(b_board.get_cells_count(), 9, "The result was %i. Expected %i", b_board.get_cells_count(), 9);
    cr_assert_eq(btree.number_leafs(), 585, "The result was %i. Expected %i", btree.number_leafs(), 585);
}

Test(board_rtree_tests, generate_leafs_10)
{
    size_t depth = 2;
    Board b_board = Board(10);
    BoardRTree btree = BoardRTree(b_board, depth, true);
    cr_assert_eq(b_board.get_cells_count(), 100, "The result was %i. Expected %i", b_board.get_cells_count(), 100);
    cr_assert_eq(btree.number_leafs(), 10000, "The result was %i. Expected %i", btree.number_leafs(), 10000);
}

Test(board_rtree_tests, free_leafs_1)
{
    size_t depth = 1;
    Board b_board = Board(5);
    BoardRTree btree = BoardRTree(b_board, depth, true);
    btree.free_leafs();
    cr_assert_eq(btree.number_leafs(), 0, "The result was %i. Expected %i", btree.number_leafs(), 0);
}

Test(board_rtree_tests, free_leafs_2)
{
    size_t depth = 0;
    Board b_board = Board(5);
    BoardRTree btree = BoardRTree(b_board, depth, true);
    btree.free_leafs();
    cr_assert_eq(btree.number_leafs(), 0, "The result was %i. Expected %i", btree.number_leafs(), 0);
}

Test(board_rtree_tests, free_leafs_3)
{
    size_t depth = 2;
    Board b_board = Board(3);
    BoardRTree btree = BoardRTree(b_board, depth, true);
    btree.free_leafs();
    cr_assert_eq(btree.number_leafs(), 0, "The result was %i. Expected %i", btree.number_leafs(), 0);
}

Test(board_rtree_tests, get_pointer_leafs_empty_coor_1)
{
    size_t depth = 0;
    BoardRTree btree = BoardRTree(Board(5), depth, true);
    std::vector<size_t> coor;
    BoardRTree *btree_ptr = btree.get_pointer_leafs(coor);
    if (btree_ptr == nullptr)
        cr_expect(1);
    else
        cr_expect(0);
    cr_assert_eq(btree.number_leafs(), 0, "The result was %i. Expected %i", btree.number_leafs(), 0);
    cr_assert_eq(btree.leafs.size(), 0, "The result was %i. Expected %i", btree.leafs.size(), 0);
}

Test(board_rtree_tests, get_pointer_leafs_empty_coor_2)
{
    size_t depth = 5;
    BoardRTree btree = BoardRTree(Board(2), depth, true);
    std::vector<size_t> coor;
    BoardRTree *btree_ptr = btree.get_pointer_leafs(coor);
    if (btree_ptr == nullptr)
        cr_expect(1);
    else
        cr_expect(0);
    cr_assert_eq(btree.number_leafs(), 64, "The result was %i. Expected %i", btree.number_leafs(), 64);
    cr_assert_eq(btree.leafs.size(), 4, "The result was %i. Expected %i", btree.leafs.size(), 4);
}

Test(board_rtree_tests, get_pointer_leafs_1)
{
    size_t depth = 3;
    BoardRTree btree = BoardRTree(Board(3), depth, true);
    std::vector<size_t> coor = {2, 3, 0};
    BoardRTree *btree_ptr = btree.get_pointer_leafs(coor);
    btree_ptr->value_board = 2;
    cr_assert_eq(btree.number_leafs(), 585, "The result was %i. Expected %i", btree.number_leafs(), 585);
    cr_assert_eq(btree.leafs.size(), 9, "The result was %i. Expected %i", btree.leafs.size(), 9);
    cr_assert_eq(btree_ptr->value_board, btree.leafs[2].leafs[3].leafs[0].value_board, "The result was %i. Expected %i",
        btree_ptr->value_board, btree.leafs[2].leafs[3].leafs[0].value_board);
}

Test(board_rtree_tests, get_pointer_leafs_2)
{
    size_t depth = 20;
    BoardRTree btree = BoardRTree(Board(2), depth, true);
    std::vector<size_t> coor = {2};
    BoardRTree *btree_ptr = btree.get_pointer_leafs(coor);
    btree_ptr->value_board = 2;
    cr_assert_eq(btree.number_leafs(), 64, "The result was %i. Expected %i", btree.number_leafs(), 64);
    cr_assert_eq(btree.leafs.size(), 4, "The result was %i. Expected %i", btree.leafs.size(), 4);
    cr_assert_eq(btree_ptr->value_board, btree.leafs[2].value_board, "The result was %i. Expected %i",
        btree_ptr->value_board, btree.leafs[2].value_board);
}
/*
** EPITECH PROJECT, 2019
** IA_Gomoku
** File description:
** BoardRTree.hpp
*/

#include <iostream>
#include <ostream>
#include "Board/BoardRTree.hpp"

BoardRTree::BoardRTree()
{
    leafs.reserve(400);
}

BoardRTree::BoardRTree(Board board_go, size_t depth, bool is_ai_play)
{
    uint8_t value_pawn = (is_ai_play ? AI_PAWN : PLAYER_PAWN);
    bool isaiplay = (is_ai_play ? false : true);
    board_go.reset_unplay();
    Expected_play(board_go, value_pawn);
    this->set_cells(board_go.get_cells());
    if (depth == 0)
        return;
    depth--;
    leafs.reserve(get_board_size() * 3);
    for (uint8_t x = 0; x < get_board_size(); x++) {
        for (uint8_t y = 0; y < get_board_size(); y++) {
            if (board_go.is_playable_pos(x, y) == PLAYED)
                continue;
            // On reset la board avec celle par defaut
            board_go.set_pawn(x, y, value_pawn);
            played_pos_x = x;
            played_pos_y = y;

            // On ajoute la board dans la liste
            leafs.emplace_back(board_go, depth, isaiplay);
            board_go.set_force_pawn(x, y, board_go.UNSET_PAWN);
        }
    }
}

void BoardRTree::Expected_play(Board &board_go, const uint8_t &value_pawn)
{
    for (uint8_t x = 0; x < board_go.get_board_size(); x++) {
        for (uint8_t y = 0; y < board_go.get_board_size(); y++) {
            Set_experted_play(board_go, x, y, value_pawn);
        }
    }
}

void BoardRTree::Set_experted_play(Board &board_go, const uint8_t &posx, const uint8_t &posy, const uint8_t &value_pawn)
{
    if (board_go.get_pawn(posx, posy) == value_pawn) {
        // Mettre la valeur "50" dans toutes les directions
        for (uint8_t i = 0; i < vect_pos.size(); i++) {
            board_go.set_pawn(posx + vect_pos[i].first, posy + vect_pos[i].second, 50);
        }
    }
}

BoardRTree::BoardRTree(Board board_go)
{
    cells = board_go.get_cells();
}

BoardRTree::~BoardRTree()
{
}

void BoardRTree::free_leafs()
{
    leafs.clear();
    leafs.shrink_to_fit();
}

size_t BoardRTree::number_leafs()
{
    size_t size = 0;
    number_leafs_count_rec(this, size);
    return size;
}

void BoardRTree::number_leafs_count_rec(BoardRTree *selected_board_rtree, size_t &size)
{
    if (selected_board_rtree->leafs.size() > 0) {
        for (size_t i = 0; i < selected_board_rtree->leafs.size(); i++) {
            size++;
            number_leafs_count_rec(&selected_board_rtree->leafs[i], size);
        }
    }
}

BoardRTree *BoardRTree::get_pointer_leafs(const std::vector<size_t> &coor)
{
    BoardRTree *board_rtree_ptr = this;
    if (coor.size() == 0)
        return nullptr;
    for (size_t coors : coor) {
        if (board_rtree_ptr->leafs.size() > coors) {
            board_rtree_ptr = &board_rtree_ptr->leafs[coors];
        } else {
            return nullptr;
        }
    }
    return board_rtree_ptr;
}

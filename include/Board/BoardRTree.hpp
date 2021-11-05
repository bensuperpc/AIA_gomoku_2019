/*
** EPITECH PROJECT, 2019
** epitech, 2019
** File description:
** >Board.h
*/

#ifndef _BOARD_RTREE_H_
#define _BOARD_RTREE_H_

#include <cstdint>
#include <memory>
#include <vector>
#include "Board.hpp"

class BoardRTree : public Board {
  public:
    // Variables
    std::vector<BoardRTree> leafs;
    bool ai_win = false;
    // La valeur de la board
    uint16_t value_board = 0;
    uint8_t played_pos_x;
    uint8_t played_pos_y;

    // Fonctions
    void free_leafs();
    size_t number_leafs();
    BoardRTree *get_pointer_leafs(const std::vector<size_t> &);
    void Expected_play(Board &, const uint8_t &);
    void Set_experted_play(Board &, const uint8_t &, const uint8_t &, const uint8_t &);

    // Constructeurs
    BoardRTree();
    BoardRTree(Board);
    BoardRTree(Board, size_t);
    BoardRTree(Board, size_t, bool);

    // Destructeurs
    ~BoardRTree();

  private:
    void number_leafs_count_rec(BoardRTree *, size_t &);
    std::vector<std::pair<short, short>> vect_pos {
        {0, -1},  // UP
        {0, 1},   // DOWN
        {-1, 0},  // LEFT
        {1, 0},   // RIGHT
        {1, 1},   // RIGHT and DOWN
        {-1, 1},  // LEFT and DOWN
        {-1, -1}, // LEFT and UP
        {1, -1}   // RIGHT and UP
    };

  protected:
};

#endif
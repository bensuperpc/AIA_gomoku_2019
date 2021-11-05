/*
** EPITECH PROJECT, 2019
** epitech, 2019
** File description:
** >Board.hpp
*/

#ifndef _BOARD_H_
#define _BOARD_H_

#include <cstdint>
#include <cstddef>
#include <vector>

class Board {
  public:
    // Fonctions
    size_t get_board_size();
    size_t get_cells_count();
    void reset_board();
    std::vector<std::vector<uint8_t>> get_cells();
    void set_cells(std::vector<std::vector<uint8_t>>);

    void operator<<(Board &);
    void operator>>(Board &);

    // Variables
    enum
    {
        ERRPOS = -1,
        PLAYED = 0,
        PLAYABLE = 1
    };
    enum
    {
        UNSET_PAWN = 0,
        AI_PAWN = 1,
        PLAYER_PAWN = 2
    };

    // Creer une Board de taille X et Y
    void set_size_board(size_t &);
    void set_force_pawn(const uint8_t &, const uint8_t &, const uint8_t &);
    void set_pawn(const uint8_t &, const uint8_t &, const uint8_t &);
    void set_pawn_exp(const uint8_t &, const uint8_t &, const uint8_t &);
    void reset_unplay();
    uint8_t get_pawn(const uint8_t &, const uint8_t &);
    bool is_valid_pos(const uint8_t &, const uint8_t &);
    int is_playable_pos(const uint8_t &, const uint8_t &);

    std::pair<uint8_t, uint8_t> getmaxvaluepos();
    std::pair<uint8_t, uint8_t> get_first_playble();

    // Constructeurs
    Board();
    Board(const size_t &);

    // destructeurs
    ~Board();

  private:
    // La Board
    // Variables de jeu
  protected:
    std::vector<std::vector<uint8_t>> cells;
};

#endif
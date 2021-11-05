/*
** EPITECH PROJECT, 2019
** epitech, 2019
** File description:
** >define
*/

#ifndef _Ai_H_
#define _Ai_H_

#define LEAFS_COUNT_MAX_Ai 6

#include <chrono>
#include <cstdint>
#include <random>
#include <string>
#include <vector>
#include "Board/Board.hpp"
#include "Board/BoardRTree.hpp"

class AI {
  public:
    // Variables
    std::string name = "";
    enum
    {
        AI_PLAY_ASS2 = 3,
        PLAYER_PLAY_ASS3 = 4,
        AI_PLAY_ASS3 = 5,
        PLAYER_PLAY_ASS4 = 6,
        AI_PLAY_ASS4 = 7,
        PLAYER_PLAY_ASS5 = 8,
        AI_PLAY_ASS5 = 9,
    };
    size_t DEPTH = 3;
    // L'etat du plateau actuellement
    Board current_board;
    BoardRTree exected_board;
    // vector<thread*> thread_worker;

    // Fonctions
    void reset();
    void generate_expected_board(const size_t &);
    void enemy_set_pawn(uint8_t, uint8_t);
    void random_play();
    void force_set_pawn(const uint8_t &, const uint8_t &, const uint8_t &);
    short check_assembly(const uint8_t &, const uint8_t &, const std::pair<short, short> &);
    std::pair<short, short> add_pair(std::pair<short, short>, const short &);
    void check_every_direc(uint8_t, uint8_t);
    void update_board();
    void AI_play();

    // Les coups que l'IA va jouer
    std::string commands_get();

    // Les variables en lectures seules : public
    size_t get_board_size();
    uint8_t get_pawn(uint8_t, uint8_t);
    void set_board_size(size_t);
    bool is_game_started();
    bool is_Ai_turn();
    bool is_size_board_are_set();
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

    // Constructeurs
    AI();
    AI(std::string str);

    // destructeurs
    ~AI();

  private:
    // Variables de jeu
    // La tAille du jeu
    uint8_t board_size = 0;
    bool board_generated = false;
    bool game_started = false;
    bool Ai_turn = false;
    size_t number_turn = 0;
    std::string commands = "";
    // Functions
  protected:
};

#endif
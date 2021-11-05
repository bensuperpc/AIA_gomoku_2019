/*
** EPITECH PROJECT, 2019
** IA_Gomoku
** File description:
** AI.cpp
*/

#include "AI.hpp"

AI::AI()
{
}

AI::AI(std::string str)
{
    name = str;
}

void AI::enemy_set_pawn(uint8_t posx, uint8_t posy)
{
    if (current_board.get_board_size() < posx || current_board.get_board_size() < posy)
        return;
    if (game_started == false)
        return;
    if (current_board.is_playable_pos(posx, posy) != 1)
        return;
    current_board.set_force_pawn(posx, posy, current_board.PLAYER_PAWN);
    AI_play();
}

void AI::AI_play()
{
    update_board();
    if (commands == "MESSAGE PLAYER WIN")
        return;
    std::pair<uint8_t, uint8_t> max_values_pos = current_board.getmaxvaluepos();
    if (current_board.get_pawn(max_values_pos.first, max_values_pos.second) == current_board.PLAYER_PAWN) {
        random_play();
    } else {
        current_board.set_pawn(max_values_pos.first, max_values_pos.second, current_board.AI_PAWN);
        commands = std::to_string(max_values_pos.first) + "," + std::to_string(max_values_pos.second);
    }
    /*
    update_board();
    exected_board = BoardRTree(current_board, DEPTH, true);
    btree.free_leafs();
    */
}

void AI::update_board()
{
    current_board.reset_unplay();
    uint8_t size = current_board.get_board_size();
    for (uint8_t x = 0; x < size; x++) {
        for (uint8_t y = 0; y < size; y++) {
            if (current_board.get_pawn(x, y) == current_board.AI_PAWN
                || current_board.get_pawn(x, y) == current_board.PLAYER_PAWN) {
                check_every_direc(x, y);
            }
        }
    }
}

void AI::check_every_direc(uint8_t posx, uint8_t posy)
{
    std::pair<short, short> coor;
    short num_assembly = 0;
    uint8_t set_pawn = (current_board.get_pawn(posx, posy) == current_board.AI_PAWN ? AI_PLAY_ASS4 : PLAYER_PLAY_ASS4);

    for (uint8_t i = 0; i < vect_pos.size(); i++) {
        coor.first = vect_pos[i].first * -1;
        coor.second = vect_pos[i].second * -1;
        num_assembly = check_assembly(posx, posy, vect_pos[i]);
        if (num_assembly == -1)
            continue;
        if ((num_assembly == 0) && current_board.get_pawn(posx, posy) == current_board.AI_PAWN) {
            current_board.set_pawn_exp((posx + coor.first), (posy + coor.second), AI_PLAY_ASS2);
            coor = add_pair(coor, num_assembly);
            coor.first = coor.first * -1;
            coor.second = coor.second * -1;
            current_board.set_pawn_exp((posx + coor.first), (posy + coor.second), AI_PLAY_ASS2);
        }
        if ((num_assembly == 1) && current_board.get_pawn(posx, posy) == current_board.AI_PAWN) {
            current_board.set_pawn_exp((posx + coor.first), (posy + coor.second), AI_PLAY_ASS3);
            coor = add_pair(coor, num_assembly);
            coor.first = coor.first * -1;
            coor.second = coor.second * -1;
            current_board.set_pawn_exp((posx + coor.first), (posy + coor.second),
                AI_PLAY_ASS3); // 3 + 2*num_assembly
        }
        if (num_assembly == 2) {
            current_board.set_pawn_exp((posx + coor.first), (posy + coor.second), set_pawn);
            coor = add_pair(coor, 2);
            coor.first = coor.first * -1;
            coor.second = coor.second * -1;
            current_board.set_pawn_exp((posx + coor.first), (posy + coor.second), set_pawn);
        }
        if (num_assembly == 3) {
            if (current_board.get_pawn(posx, posy) == current_board.AI_PAWN) {
                current_board.set_pawn_exp((posx + coor.first), (posy + coor.second), AI_PLAY_ASS5);
            } else {
                current_board.set_pawn_exp((posx + coor.first), (posy + coor.second), PLAYER_PLAY_ASS5);
            }
        }
        if (num_assembly == 4)
            commands = "MESSAGE PLAYER WIN";
    }
}

short AI::check_assembly(const uint8_t &posx, const uint8_t &posy, const std::pair<short, short> &vect)
{
    uint8_t current_pawn = current_board.get_pawn(posx, posy);
    uint8_t i = 0;
    std::pair<uint8_t, uint8_t> pos = {posx, posy};
    if (current_pawn == current_board.UNSET_PAWN)
        return -1;
    for (; i <= 4; i++) {
        pos.first += vect.first;
        pos.second += vect.second;
        if (current_board.is_valid_pos(pos.first, pos.second) == false)
            break;
        if (current_board.get_pawn(pos.first, pos.second) == current_board.UNSET_PAWN)
            break;
        if (current_board.get_pawn(pos.first, pos.second) != current_pawn)
            break;
    }
    return i;
}

void AI::force_set_pawn(const uint8_t &posx, const uint8_t &posy, const uint8_t &player)
{
    if (current_board.get_board_size() < posx || current_board.get_board_size() < posy)
        return;
    if (player == 1) {
        current_board.set_force_pawn(posx, posy, current_board.AI_PAWN);
        update_board();
    }
    if (player == 2) {
        current_board.set_force_pawn(posx, posy, current_board.PLAYER_PAWN);
        update_board();
    }
}

std::string AI::commands_get()
{
    return commands;
}

void AI::reset()
{
}

void AI::generate_expected_board(const size_t &depth)
{
    exected_board = BoardRTree(current_board, depth, true);
}

uint8_t AI::get_pawn(uint8_t posx, uint8_t posy)
{
    return current_board.get_pawn(posx, posy);
}

size_t AI::get_board_size()
{
    return current_board.get_board_size();
}

void AI::set_board_size(size_t size)
{
    if (game_started == false) {
        current_board = Board(size);
        game_started = true;
    }
}

bool AI::is_game_started()
{
    return game_started;
}

bool AI::is_Ai_turn()
{
    return Ai_turn;
}

std::pair<short, short> AI::add_pair(std::pair<short, short> _pair, const short &i)
{
    std::pair<short, short> pair_tmp;
    for (uint8_t j = 0; j <= i; j++) {
        pair_tmp.first += _pair.first;
        pair_tmp.second += _pair.second;
    }
    return pair_tmp;
}

void AI::random_play()
{
    current_board.reset_unplay();
    std::pair<uint8_t, uint8_t> safe_pos = {0, 0};
    bool valid_shot = false;
    size_t i = 0;
    size_t seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine generator(seed);
    std::uniform_int_distribution<size_t> distribution(2, current_board.get_board_size() / 2);
    std::vector<uint8_t> pos
        = {static_cast<uint8_t>(distribution(generator)), static_cast<uint8_t>(distribution(generator))};
    while (valid_shot == false) {
        if (current_board.get_pawn(pos[0], pos[1]) == current_board.UNSET_PAWN && i < 400) {
            current_board.set_pawn(pos[0], pos[1], current_board.AI_PAWN);
            commands = std::to_string(pos[0]) + "," + std::to_string(pos[1]);
            valid_shot = true;
            update_board();
        } else {
            pos[0] = static_cast<uint8_t>(distribution(generator));
            pos[1] = static_cast<uint8_t>(distribution(generator));
        }
        i++;
    }
    if (valid_shot == false) {
        safe_pos = current_board.get_first_playble();
        current_board.set_pawn(safe_pos.first, safe_pos.second, current_board.AI_PAWN);
        commands = std::to_string(safe_pos.first) + "," + std::to_string(safe_pos.second);
    }
}

AI::~AI()
{
}
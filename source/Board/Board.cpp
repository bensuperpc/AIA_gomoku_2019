/*
** EPITECH PROJECT, 2019
** IA_Gomoku
** File description:
** Board.hpp
*/

#include "Board/Board.hpp"

Board::Board()
{
}

Board::Board(const size_t &size)
{
    cells = std::vector<std::vector<uint8_t>>(size, std::vector<uint8_t>(size, UNSET_PAWN));
}

void Board::operator<<(Board &board)
{
    this->cells = board.get_cells();
}

void Board::operator>>(Board &board)
{
    board.set_cells(this->cells);
}

void Board::set_size_board(size_t &size)
{
    cells = std::vector<std::vector<uint8_t>>(size, std::vector<uint8_t>(size, UNSET_PAWN));
}

void Board::set_cells(std::vector<std::vector<uint8_t>> _cells)
{
    cells = _cells;
}

uint8_t Board::get_pawn(const uint8_t &posx, const uint8_t &posy)
{
    if (is_valid_pos(posx, posy) == true) {
        return cells[posx][posy];
    }
    return 0;
}

std::vector<std::vector<uint8_t>> Board::get_cells()
{
    return cells;
}

void Board::set_force_pawn(const uint8_t &posx, const uint8_t &posy, const uint8_t &value)
{
    if (is_valid_pos(posx, posy) == true) {
        cells[posx][posy] = value;
    }
}

void Board::set_pawn(const uint8_t &posx, const uint8_t &posy, const uint8_t &value)
{
    if (is_playable_pos(posx, posy) == PLAYABLE) {
        cells[posx][posy] = value;
    }
}

void Board::set_pawn_exp(const uint8_t &posx, const uint8_t &posy, const uint8_t &value)
{
    if (is_playable_pos(posx, posy) == PLAYABLE) {
        if (get_pawn(posx, posy) == UNSET_PAWN || get_pawn(posx, posy) < value) {
            cells[posx][posy] = value;
        }
    }
}

int Board::is_playable_pos(const uint8_t &posx, const uint8_t &posy)
{
    if (is_valid_pos(posx, posy) == true) {
        if (cells[posx][posy] == PLAYER_PAWN || cells[posx][posy] == AI_PAWN) {
            return PLAYED;
        } else {
            return PLAYABLE;
        }
    } else {
        return ERRPOS;
    }
}

bool Board::is_valid_pos(const uint8_t &posx, const uint8_t &posy)
{
    if (posx < cells.size() && posy < cells.size())
        return true;
    else
        return false;
}

size_t Board::get_board_size()
{
    return cells.size();
}

size_t Board::get_cells_count()
{
    return (cells.size() * cells.size());
}

std::pair<uint8_t, uint8_t> Board::getmaxvaluepos()
{
    std::pair<uint8_t, uint8_t> pos = {0, 0};
    uint8_t max = 0;
    for (size_t y = 0; y < cells.size(); y++) {
        for (size_t x = 0; x < cells.size(); x++) {
            if (cells[y][x] > max) {
                max = cells[y][x];
                pos.first = static_cast<uint8_t>(y);
                pos.second = static_cast<uint8_t>(x);
            }
        }
    }
    return pos;
}

std::pair<uint8_t, uint8_t> Board::get_first_playble()
{
    std::pair<uint8_t, uint8_t> pos = {0, 0};
    for (uint8_t y = 0; y < cells.size(); y++) {
        for (uint8_t x = 0; x < cells.size(); x++) {
            if (is_playable_pos(x, y) == PLAYABLE) {
                pos.first = x;
                pos.second = y;
                return pos;
            }
        }
    }
    return pos;
}

void Board::reset_board()
{
    size_t size = cells.size();
    cells.clear();
    cells.shrink_to_fit();
    cells = std::vector<std::vector<uint8_t>>(size, std::vector<uint8_t>(size, UNSET_PAWN));
}

void Board::reset_unplay()
{
    for (uint8_t y = 0; y < cells.size(); y++) {
        for (uint8_t x = 0; x < cells.size(); x++) {
            if (cells[y][x] == AI_PAWN)
                continue;
            if (cells[y][x] == PLAYER_PAWN)
                continue;
            cells[y][x] = UNSET_PAWN;
        }
    }
}

Board::~Board()
{
}
/*
** EPITECH PROJECT, 2019
** IA_Gomoku
** File description:
** Gomoku.c
*/

#include "Gomoku.hpp"

Gomoku::Gomoku()
{
    history_vec.reserve(400);
}
int Gomoku::get_command()
{
    std::string input_str = "";
    int return_value = 0;
    while (1) {
        getline(std::cin, input_str);
        return_value = check_command(input_str);
        if (return_value == 84 || return_value == 1)
            return (return_value);
    }
    return (return_value);
}

int Gomoku::get_command(std::string &str)
{
    return check_command(str);
}

int Gomoku::check_command(std::string &str)
{
    int return_val = 0;
    history_vec.emplace_back(str);
    if (history_vec.size() > 100)
        history_vec.clear();
    for (auto &vector_pair : command_vector) {
        if (str.compare(0, vector_pair.first.length(), vector_pair.first) == 0) {
            str.erase(0, vector_pair.first.length());
            return_val = (this->*vector_pair.second)(str);
        }
    }
    return return_val;
}

int Gomoku::start(std::string &str)
{
    int i = 0;
    if (str.length() == 0 || get_num(str, i) == 84) {
        std::cout << START_ERR << std::endl;
        return (84);
    }
    if (i < 5 || i > 20) {
        std::cout << START_ERR << std::endl;
        return (84);
    }
    if (glados.is_game_started() == false) {
        glados.set_board_size(i);
        std::cout << START_OK << std::endl;
        return (0);
    } else {
        std::cout << START_ERR << std::endl;
        return (84);
    }
}

int Gomoku::begin(std::string &str)
{
    if (glados.is_game_started() == true) {
        glados.force_set_pawn(9, 9, 1);
        glados.update_board();
        std::cout << "9,9" << std::endl;
        return (0);
    } else {
        std::cout << "ERROR GAME NOT STARTED !" << std::endl;
        return (84);
    }
}

int Gomoku::board(std::string &str)
{
    int posx = 0;
    int posy = 0;
    int player = 0;
    std::string input_str = "";
    while (1) {
        getline(std::cin, input_str);
        if (input_str == "DONE") {
            glados.AI_play();
            std::cout << glados.commands_get() << std::endl;
            return 0;
        }
        if (input_str == "")
            continue;
        if (get_num(input_str, posx) == 84) {
            std::cout << BOARD_ERR << std::endl;
            return (84);
        }
        if (get_num(input_str, posy) == 84) {
            std::cout << BOARD_ERR << std::endl;
            return (84);
        }
        if (get_num(input_str, player) == 84) {
            std::cout << BOARD_ERR << std::endl;
            return (84);
        }
        if (player > 3) {
            std::cout << BOARD_ERR << std::endl;
            return 84;
        }
        glados.force_set_pawn(posx, posy, player);
    }
    return (0);
}

int Gomoku::turn(std::string &str)
{
    int posx = 0;
    int posy = 0;
    if (str.length() == 0) {
        std::cout << TURN_ERR << std::endl;
        return (84);
    }
    if (get_num(str, posx) == 84) {
        std::cout << START_ERR << std::endl;
        return (84);
    }
    if (get_num(str, posy) == 84) {
        std::cout << START_ERR << std::endl;
        return (84);
    }
    if (posy > 20 || posx > 20 || posx < 0 || posy < 0) {
        std::cout << TURN_ERR << std::endl;
        return (84);
    }

    if (posx < static_cast<int>(glados.get_board_size()) && posy < static_cast<int>(glados.get_board_size())
        && glados.is_game_started() == true) {
        glados.enemy_set_pawn(posx, posy);
        std::cout << glados.commands_get() << std::endl;
        glados.update_board();
        return (0);
    } else {
        std::cout << TURN_ERR << std::endl;
        return (84);
    }
}

int Gomoku::restart(std::string &str)
{
    glados.reset();
    glados = AI(glados.name);
    std::cout << RESTART_OK << std::endl;
    return (0);
}

int Gomoku::display(std::string &str)
{
    size_t size = glados.get_board_size();
    for (uint8_t y = 0; (size + 2) * 3 > y; y++)
        std::cout << "*" << std::flush;
    std::cout << std::endl;
    for (uint8_t y = 0; size > y; y++) {
        std::cout << " |  " << std::flush;
        for (uint8_t x = 0; size > x; x++) {
            if (glados.get_pawn(x, y) < 10)
                std::cout << std::to_string(glados.get_pawn(x, y)) << "  " << std::flush;
            if (glados.get_pawn(x, y) >= 10)
                std::cout << std::to_string(glados.get_pawn(x, y)) << " " << std::flush;
        }
        std::cout << "|" << std::flush;
        std::cout << std::endl;
    }
    for (uint8_t y = 0; (size + 2) * 3 > y; y++)
        std::cout << "*" << std::flush;
    std::cout << std::endl;
    return (0);
}

int Gomoku::end(std::string &str)
{
    glados.reset();
    glados = AI(glados.name);
    std::cout << "none" << std::endl;
    return (1);
}

int Gomoku::history(std::string &str)
{
    std::cout << "DEBUG ===== HISTORY =====" << std::endl;
    for (auto &each_cmd : history_vec) {
        std::cout << each_cmd << std::endl;
    }
    return (0);
}

int Gomoku::about(std::string &str)
{
    std::cout << ABOUT_MSG;
    return (0);
}

int Gomoku::get_num(std::string &str, int &i)
{
    size_t pos = 0;
    try {
        i = stoi(str);
        pos = str.find(',');
        if (pos != std::string::npos)
            str.erase(0, pos + 1);
    }
    catch (...) {
        return (84);
    }
    return 0;
}

Gomoku::~Gomoku()
{
}

/*
** EPITECH PROJECT, 2019
** epitech, 2019
** File description:
** >my_chrono.h
*/

#ifndef _GOMOKU_MAIN_H_
#define _GOMOKU_MAIN_H_

#include <cstdint>
#include <iostream>
#include <string>
#include <vector>
#include "AI.hpp"

class Gomoku {
  public:
    // Variables
    // Fonctions
    int get_command();
    int get_command(std::string &);
    // Constructeurs
    Gomoku();
    // Destructeurs
    ~Gomoku();

  private:
    // Variables
    AI glados;
    std::vector<std::string> history_vec;
    const std::string START_OK = "OK - everything is good";
    const std::string START_ERR = "ERROR - unsupported size or other error";
    const std::string RESTART_OK = "OK";
    const std::string BOARD_OK = "done";
    const std::string BOARD_ERR = "ERROR - x,y,who or DONE expected after BOARD";
    const std::string TURN_ERR = "ERROR bad coordinates";
    const std::string ABOUT_MSG = "name='LINUX MASTER RACE !', version='0.1', "
                                  "author=':)', 'country='FRANCE'";
    const std::vector<std::pair<const std::string, int (Gomoku::*)(std::string &)>> command_vector {
        {"START", &Gomoku::start},
        {"BEGIN", &Gomoku::begin},
        {"BOARD", &Gomoku::board},
        {"END", &Gomoku::end},
        {"TURN", &Gomoku::turn},
        {"RESTART", &Gomoku::restart},
        {"HISTORY", &Gomoku::history},
        {"DISPLAY", &Gomoku::display},
        {"ABOUT", &Gomoku::about},
    };

    // Fonctions
    int start(std::string &);
    int begin(std::string &);
    int board(std::string &);
    int turn(std::string &);
    int restart(std::string &);
    int history(std::string &);
    int end(std::string &);
    int about(std::string &);
    int check_command(std::string &);
    int display(std::string &);
    int get_num(std::string &str, int &i);

  protected:
};

#endif
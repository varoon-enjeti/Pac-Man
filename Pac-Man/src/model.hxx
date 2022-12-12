#pragma once

#include <ge211.hxx>
#include "character.hxx"

#include <iostream>

class Model
{
public:
    explicit Model();

    Pacman pacman_const() const {
        return pacman_;
    }

    Pacman& pacman() {
        return pacman_;
    }

    std::vector<Ghost>& ghosts() {
        return ghosts_;
    }

    std::vector<Wall>& walls() {
        return walls_;
    }

    std::vector<Food>& foods() {
        return foods_;
    }

    std::vector<Power_Cookie>& power_cookies() {
        return power_cookies_;
    }

    float timer() {
        return timer_.elapsed_time().seconds();
    }

    int score() {
        return score_;
    }

    void inc_score(std::string ate);

    int lives() {
        return lives_;
    }

    void lose_life() {
        lives_ -= 1;
    }

    bool pcookie_mode() {
        return pcookie_mode_;
    }

    void flip_pcookie_mode() {
        pcookie_mode_ = !pcookie_mode_;
    }

    bool live() {
        return live_;
    }

    void flip_live() {
        live_ = !live_;
    }

    void create_ghosts();

    void create_walls();

    void create_food();

    void on_frame(double dt);

    void round_over();

    void game_over();

private:
    Pacman pacman_;
    std::vector<Ghost> ghosts_;
    std::vector<Wall> walls_;
    std::vector<Food> foods_;
    std::vector<Power_Cookie> power_cookies_;
    ge211::Timer timer_;
    int score_ = 0;
    int lives_ = 3;
    bool pcookie_mode_ = false;
    bool live_ = false;
};

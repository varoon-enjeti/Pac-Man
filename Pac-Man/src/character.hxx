#pragma once

#include <ge211.hxx>

#include <iostream>

using Position = ge211::Posn<float>;

using Velocity = ge211::Dims<float>;

using Wall = ge211::Rect<int>;

using Food = ge211::Posn<int>;

using Power_Cookie = ge211::Posn<int>;

/*
 *
 * CHARACTER
 *
*/

class Character {
public:

    Character(Position start_pos,
              Velocity start_velo,
              char start_dir,
              std::string filename);

    virtual ~Character() {};

    int radius() const {
        return radius_;
    }

    Position center() const {
        return {position_.x + radius_, position_.y + radius_};
    }

    Position position() const {
        return position_;
    }

    void set_position(float x, float y) {
        position_ = {x, y};
    }

    Velocity velocity() const {
        return velocity_;
    }

    void set_velocity(float x, float y) {
        velocity_ = {x, y};
    }

    char direction() const {
        return direction_;
    }

    void set_direction(char dir) {
        direction_ = dir;
    }

    std::string filename() {
        return filename_;
    }

    virtual void velo_right() {
        velocity_ = {200,0};
    }

    virtual void velo_left() {
        velocity_ = {-200,0};
    }

    virtual void velo_up() {
        velocity_ = {0, -200};
    }

    virtual void velo_down() {
        velocity_ = {0,200};
    }

    void velo_stop() {
        velocity_ = {0,0};
    }

    void horizontial_edge();

    bool hits_a_wall(Wall const& wall);

    bool hits_any_wall(std::vector<Wall>& walls);


protected:
    int radius_ = 23;

    Position position_;

    Velocity velocity_;

    char direction_;   // r: right, l: left, u: up, d: down, s: stopped

    std::string filename_;
};

/*
 *
 * GHOST
 *
*/

class Ghost : public Character
{
public:
    explicit Ghost(Position start_pos, std::string filename);

    Ghost next(double dt);

    void randomize(bool pcookie_mode);

    void velo_right() {
        velocity_ = {160, 0};
    }

    void velo_left() {
        velocity_ = {-160, 0};
    }

    void velo_up() {
        velocity_ = {0, -160};
    }

    void velo_down() {
        velocity_ = {0, 160};
    }

    void pc_velo_right() {
        velocity_ = {100, 0};
    }

    void pc_velo_left() {
        velocity_ = {-100, 0};
    }

    void pc_velo_up() {
        velocity_ = {0, -100};
    }

    void pc_velo_down() {
        velocity_ = {0, 100};
    }

    std::vector<char> rand_dirs = {'u', 'd', 'l', 'r'};

    std::vector<std::string> filenames = {"red_ghost.png", "blue_ghost.png", "pink_ghost.png", "teal_ghost.png"};
};

/*
 *
 * PACMAN
 *
*/

class Pacman : public Character
{
public:
    explicit Pacman();

    char new_direction() {
        return new_direction_;
    }

    void set_new_direction(char dir) {
        new_direction_ = dir;
    }

    void reset_pacman();

    Pacman next(double dt);

    bool hits_food(Food const& food);

    bool eat_food(std::vector<Food>& foods);

    bool hits_ghost(Ghost const& ghost);

    bool hits_any_ghost(std::vector<Ghost>& ghosts);

    bool eats_ghost(std::vector<Ghost>& ghosts);

    bool hits_power_cookie(Power_Cookie const& pcookie);

    bool eat_power_cookie(std::vector<Power_Cookie>& pcookies);

private:
    char new_direction_ = direction_;
};


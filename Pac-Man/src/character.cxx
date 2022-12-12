#include "character.hxx"

/*
 *
 * CHARACTER
 *
*/

Character::Character(Position start_pos, Velocity start_velo, char start_dir, std::string filename) :
        position_(start_pos),
        velocity_(start_velo),
        direction_(start_dir),
        filename_(filename)
{}

void
Character::horizontial_edge()
{
    if (position_.x > 750) {
        position_.x = 0;
    }
    if (position_.x < 0) {
        position_.x = 750;
    }
}

bool
Character::hits_a_wall(const Wall& wall)
{
    if (center().x + radius_ < (wall.top_left().x)) {
        return false;
    } else if (center().x - radius_ > (wall.top_left().x + wall.width))  {
        return false;
    } else if (center().y + radius_ < wall.top_left().y) {
        return false;
    } else if (center().y - radius_ > wall.top_left().y + wall.height) {
        return false;
    } else {
        return true;
    }
}

bool
Character::hits_any_wall(std::vector<Wall>& walls)
{
    for (Wall w : walls) {
        if (hits_a_wall(w)) {
            return true;
        }
    }
    return false;
}

/*
 *
 * GHOST
 *
*/

Ghost::Ghost(Position start_pos, std::string filename)
        : Character(start_pos,
                    {0,0},
                    's',
                    filename)
{}

Ghost
Ghost::next(double dt)
{
    Ghost result(*this);
    result.position_ += result.velocity_ * dt;
    return result;
}

void
Ghost::randomize(bool pcookie_mode)
{
    direction_ = rand_dirs[rand()%4];

    if (pcookie_mode) {
        if (direction_ == 'r') {
            pc_velo_right();
        } else if (direction_ == 'l') {
            pc_velo_left();
        } else if (direction_ == 'u') {
            pc_velo_up();
        } else if (direction_ == 'd') {
            pc_velo_down();
        }
    } else {
        if (direction_ == 'r') {
            velo_right();
        } else if (direction_ == 'l') {
            velo_left();
        } else if (direction_ == 'u') {
            velo_up();
        } else if (direction_ == 'd') {
            velo_down();
        }
    }
}

/*
 *
 * PACMAN
 *
*/

Pacman::Pacman()
        : Character({353, 577},
                    {200, 0},
                    'r',
                    "pacman.png")
{}

Pacman
Pacman::next(double dt)
{
    Pacman result(*this);
    result.position_ += result.velocity_ * dt;
    return result;
}

void
Pacman::reset_pacman()
{
    position_ = {353, 577};
    velocity_ = {200, 0};
    direction_ = 'r';
    new_direction_ = 'r';
}

bool
Pacman::hits_food(const Food& food)
{
    if (center().x + radius_ < (food.x)) {
        return false;
    } else if (center().x - radius_ > (food.x + 6))  {
        return false;
    } else if (center().y + radius_ < food.y) {
        return false;
    } else if (center().y - radius_ > food.y + 6) {
        return false;
    } else {
        return true;
    }
}

bool
Pacman::eat_food(std::vector<Food>& foods)
{
    for (size_t i=0; i<foods.size(); i++) {
        if (hits_food(foods[i])) {
            foods[i] = foods.back();
            foods.pop_back();
            return true;
        }
    }
    return false;
}

bool
Pacman::hits_ghost(const Ghost& ghost)
{
    if (center().x + radius_ < (ghost.center().x - ghost.radius() + 5)) {
        return false;
    } else if (center().x - radius_ > (ghost.center().x + ghost.radius() - 5))  {
        return false;
    } else if (center().y + radius_ < ghost.center().y - ghost.radius() + 5) {
        return false;
    } else if (center().y - radius_ > ghost.center().y + ghost.radius() - 5) {
        return false;
    } else {
        return true;
    }
}

bool
Pacman::hits_any_ghost(std::vector<Ghost>& ghosts)
{
    for (Ghost g : ghosts) {
        if (hits_ghost(g)) {
            return true;
        }
    }
    return false;
}

bool
Pacman::eats_ghost(std::vector<Ghost>& ghosts)
{
    for (size_t i=0; i<ghosts.size(); i++) {
        if (hits_ghost(ghosts[i])) {
            ghosts[i] = ghosts.back();
            ghosts.pop_back();
            return true;
        }
    }
    return false;
}

bool
Pacman::hits_power_cookie(const Power_Cookie& pcookie)
{
    if (center().x + radius_ < (pcookie.x)) {
        return false;
    } else if (center().x - radius_ > (pcookie.x + 6))  {
        return false;
    } else if (center().y + radius_ < pcookie.y) {
        return false;
    } else if (center().y - radius_ > pcookie.y + 6) {
        return false;
    } else {
        return true;
    }
}

bool
Pacman::eat_power_cookie(std::vector<Power_Cookie>& pcookies)
{
    for (size_t i=0; i<pcookies.size(); i++) {
        if (hits_power_cookie(pcookies[i])) {
            pcookies[i] = pcookies.back();
            pcookies.pop_back();
            return true;
        }
    }
    return false;
}


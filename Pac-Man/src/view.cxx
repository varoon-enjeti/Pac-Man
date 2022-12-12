#include "view.hxx"

#include <iostream>

View::View(Model& model)
        : model_(model)
{
    for (Wall w : model_.walls()) {
        wall_sprites_.push_back(Wall_sprite{{w.width, w.height}, ge211::Color::medium_blue()});
    }

    for (size_t i=0; i<model_.foods().size(); i++) {
        food_sprites_.push_back(Food_sprite{3});
    }

    for (size_t i=0; i<model_.power_cookies().size(); i++) {
        power_cookie_sprites_.push_back(Power_Cookie_sprite{6, ge211::Color::medium_red()});
    }

    for (size_t i=0; i<model_.ghosts().size(); i++) {
        norm_ghost_sprites_.push_back(ge211::Image_sprite{model_.ghosts()[i].filename()});
    }

    for (size_t i=0; i<model_.ghosts().size(); i++) {
        pc_ghost_sprites_.push_back(ge211::Image_sprite{"pc_ghost.png"});
    }
}

View::Dimensions
View::initial_window_dimensions() const
{
    return {750, 790};
}

std::string
View::initial_window_title() const
{
    return "Pac-Man";
}

void
View::draw(ge211::Sprite_set& set)
{
    ge211::Transform tenth_scale = ge211::Transform{}.scale(0.115);
    ge211::Transform tenth_down = ge211::Transform{}.scale(0.115).set_rotation(90);
    ge211::Transform tenth_left = ge211::Transform{}.scale(0.115).set_rotation(180);
    ge211::Transform tenth_up = ge211::Transform{}.scale(0.115).set_rotation(270);

    score_sprite_ = {"SCORE  " + std::to_string(model_.score()), arcade_30};
    lives_sprite_ = {"LIVES  " + std::to_string(model_.lives()), arcade_30};
    set.add_sprite(score_sprite_, {10, 755});
    set.add_sprite(lives_sprite_, {630, 755});

    if (!model_.live()) {
        set.add_sprite(pacman_sprite_, Position(model_.pacman_const().position()), 4, tenth_scale);
        set.add_sprite(start_text1_, {307, 355});
        set.add_sprite(start_text2_, {340, 375});
    } else {
        if (model_.pacman().direction() == 'd') {
            set.add_sprite(pacman_sprite_, Position(model_.pacman_const().position()), 4, tenth_down);
        } else if (model_.pacman().direction() == 'l') {
            set.add_sprite(pacman_sprite_, Position(model_.pacman_const().position()), 4, tenth_left);
        }  else if (model_.pacman().direction() == 'u') {
            set.add_sprite(pacman_sprite_, Position(model_.pacman_const().position()), 4, tenth_up);
        } else {
            set.add_sprite(pacman_sprite_, Position(model_.pacman_const().position()), 4, tenth_scale);
        }
    }

    for (size_t i=0; i<model_.walls().size(); i++) {
        set.add_sprite(wall_sprites_[i], model_.walls()[i].top_left(), 2);
    }

    for (size_t i=0; i<model_.foods().size(); i++) {
        set.add_sprite(food_sprites_[i], model_.foods()[i], 1);
    }

    for (size_t i=0; i<model_.power_cookies().size(); i++) {
        set.add_sprite(power_cookie_sprites_[i], model_.power_cookies()[i], 1);
    }

    if (model_.pcookie_mode()) {
        for (size_t i=0; i<model_.ghosts().size(); i++) {
            set.add_sprite(pc_ghost_sprites_[i], model_.ghosts()[i].position().into<int>(), 3, tenth_scale);
        }
    } else {
        for (size_t i=0; i<model_.ghosts().size(); i++) {
            set.add_sprite(norm_ghost_sprites_[i], model_.ghosts()[i].position().into<int>(), 3, tenth_scale);
        }
    }
}

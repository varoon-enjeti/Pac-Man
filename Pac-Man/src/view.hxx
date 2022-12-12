#pragma once

#include <iostream>

#include "model.hxx"

using Wall = ge211::Rect<int>;

using Food = ge211::Posn<int>;

using Wall_sprite = const ge211::sprites::Rectangle_sprite;

using Food_sprite = const ge211::sprites::Circle_sprite;

using Power_Cookie_sprite = const ge211::sprites::Circle_sprite;

class View
{
public:
    using Position = ge211::Posn<int>;
    using Dimensions = ge211::Dims<int>;

    explicit View(Model&);

    Dimensions initial_window_dimensions() const;
    std::string initial_window_title() const;

    void draw(ge211::Sprite_set& set);

private:
    Model& model_;

    ge211::Font arcade_18{"arcade_font.ttf", 18};
    ge211::Font arcade_30{"arcade_font.ttf", 30};

    ge211::sprites::Text_sprite start_text1_{"Press  Space bar", arcade_18};
    ge211::sprites::Text_sprite start_text2_{"to  Start", arcade_18};

    ge211::sprites::Text_sprite score_sprite_;
    ge211::sprites::Text_sprite lives_sprite_;

    ge211::sprites::Image_sprite pacman_sprite_{model_.pacman().filename()};
    std::vector<Wall_sprite> wall_sprites_;
    std::vector<Food_sprite> food_sprites_;
    std::vector<Power_Cookie_sprite> power_cookie_sprites_;
    std::vector<ge211::Image_sprite> norm_ghost_sprites_;
    std::vector<ge211::Image_sprite> pc_ghost_sprites_;
};

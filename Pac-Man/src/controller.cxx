#include "controller.hxx"

#include <iostream>

Controller::Controller()
        : view_(model_)
{ }

void Controller::on_key(ge211::Key key)
{
    if (!model_.live()) {
        if (key == ge211::Key::code(' ')) {
            model_.flip_live();
        }
    } else {
        if (key == ge211::Key().up()) {
            if (model_.pacman().direction() == 'd') {
                model_.pacman().set_direction('u');
                model_.pacman().set_new_direction('u');
            }
            else {
                model_.pacman().set_new_direction('u');
            }
        }
        else if (key == ge211::Key().down()) {
            if (model_.pacman().direction() == 'u') {
                model_.pacman().set_direction('d');
                model_.pacman().set_new_direction('d');
            }
            else {
                model_.pacman().set_new_direction('d');
            }
        }
        else if (key == ge211::Key().right()) {
            if (model_.pacman().direction() == 'l') {
                model_.pacman().set_direction('r');
                model_.pacman().set_new_direction('r');
            }
            else {
                model_.pacman().set_new_direction('r');
            }
        }
        else if (key == ge211::Key().left()) {
            if (model_.pacman().direction() == 'r') {
                model_.pacman().set_direction('l');
                model_.pacman().set_new_direction('l');
            }
            else {
                model_.pacman().set_new_direction('l');
            }
        }
    }
}

void Controller::on_frame(double dt)
{
    model_.on_frame(dt);
}

void
Controller::draw(ge211::Sprite_set& set)
{
    view_.draw(set);
}

View::Dimensions
Controller::initial_window_dimensions() const
{
    return view_.initial_window_dimensions();
}

std::string
Controller::initial_window_title() const
{
    return view_.initial_window_title();
}



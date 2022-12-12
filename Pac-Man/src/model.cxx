#include "model.hxx"

#include <iostream>

Model::Model()
        : pacman_()
{
    // GHOSTS INITIALIZATION:
    create_ghosts();

    // WALLS INITIALIZATION:
    create_walls();

    // FOODS AND POWER COOKIES INITIALIZATION:
    create_food();
}

void
Model::create_walls()
{
    // side borders
    walls_.push_back(Wall{0,0,25,250});
    walls_.push_back(Wall{0,500,25,250});
    walls_.push_back(Wall{725,0,25,250});
    walls_.push_back(Wall{725,500,25,250});

    // top & bottom borders
    walls_.push_back(Wall{0,0,750,25});
    walls_.push_back(Wall{0,725,750,25});

    // left alley
    walls_.push_back(Wall{0,250,125,25});
    walls_.push_back(Wall{100,250,25,100});
    walls_.push_back(Wall{0,325,125,25});
    walls_.push_back(Wall{0,400,125,25});
    walls_.push_back(Wall{100,400,25,100});
    walls_.push_back(Wall{0,475,125,25});

    // right alley
    walls_.push_back(Wall{625,250,125,25});
    walls_.push_back(Wall{625,250,25,100});
    walls_.push_back(Wall{625,325,125,25});
    walls_.push_back(Wall{625,400,125,25});
    walls_.push_back(Wall{625,400,25,100});
    walls_.push_back(Wall{625,475,125,25});

    // top & bottom middle section
    walls_.push_back(Wall{350,0,50,125});
    walls_.push_back(Wall{350,175,50,100});
    walls_.push_back(Wall{275,250,200,25});
    walls_.push_back(Wall{275,475,200,25});
    walls_.push_back(Wall{350,475,50,100});
    walls_.push_back(Wall{350,625,50,125});

    // centerpiece
    walls_.push_back(Wall{275,325,25,100});
    walls_.push_back(Wall{450,325,25,100});
    walls_.push_back(Wall{275,325,200,25});
    walls_.push_back(Wall{275,400,200,25});

    // top left section
    walls_.push_back(Wall{75,75,50,50});
    walls_.push_back(Wall{75,175,50,25});
    walls_.push_back(Wall{175,75,125,50});
    walls_.push_back(Wall{175,250,50,100});
    walls_.push_back(Wall{175,175,125,25});

    // top right section
    walls_.push_back(Wall{625,75,50,50});
    walls_.push_back(Wall{625,175,50,25});
    walls_.push_back(Wall{450,75,125,50});
    walls_.push_back(Wall{525,250,50,100});
    walls_.push_back(Wall{450,175,125,25});

    // bottom left section
    walls_.push_back(Wall{75,550,50,25});
    walls_.push_back(Wall{75,625,50,50});
    walls_.push_back(Wall{175,625,125,50});
    walls_.push_back(Wall{175,400,50,100});
    walls_.push_back(Wall{175,550,125,25});

    // bottom right section
    walls_.push_back(Wall{625,550,50,25});
    walls_.push_back(Wall{625,625,50,50});
    walls_.push_back(Wall{450,625,125,50});
    walls_.push_back(Wall{525,400,50,100});
    walls_.push_back(Wall{450,550,125,25});
}

void
Model::create_food()
{
    size_t i = 0;

    // Left & Right Columns
    while ((i*35 + 40) < 695){
        foods_.push_back(Food(145, 40 + i*35));
        i++;
    } i=1;
    while ((i*35 + 40) < 695){
        foods_.push_back(Food(595, 40 + i*35));
        i++;
    } i=1;

    // Top & Bottom Row
    while ((i*35 + 40) < 695) {
        if ((i*35 + 40) != 600 && i != 3) {
            foods_.push_back(Food(40 + i*35, 145));
        }
        i++;
    } i=1;
    while ((i*35 + 40) < 695) {
        if ((i*35 + 40) != 600 && i != 3 && i != 9 && i != 10) {
            foods_.push_back(Food(40 + i*35, 600));
        }
        i++;
    } i=0;

    // Top Left
    while ((i*35 + 40) < 350) {
        foods_.push_back(Food((40 + i*35), 40));
        i++;
    } i=1;
    while ((i*35 + 40) < 250) {
        if (i != 3) {
            foods_.push_back(Food(40, (i*35 +40)));
        } else {
            power_cookies_.push_back(Power_Cookie(40, (i*35 + 37)));
        }
        i++;
    } i=1;
    while ((i*35 + 40) < 350) {
        if (i != 3) {
            foods_.push_back(Food(i*35 + 40, 215));
        }
        i++;
    } i=0;
    while ((i*35 + 40) < 250) {
        if (i != 3 && i != 5) {
            foods_.push_back(Food(320, (i*35 + 40)));
        }
        i++;
    } i=0;

    // Top Right
    while ((i*35 + 420) < 725) {
        foods_.push_back(Food((420 + i*35), 40));
        i++;
    } i=1;
    while ((i*35 + 40) < 250) {
        if (i != 3) {
            foods_.push_back(Food(700, (i*35 + 40)));
        } else {
            power_cookies_.push_back(Power_Cookie(700, (i*35 + 37)));
        }
        i++;
    } i=0;
    while ((i*35 + 420) < 725) {
        if (i != 5 && i != 8) {
            foods_.push_back(Food(i*35 + 420, 215));
        }
        i++;
    } i=0;
    while ((i*35 + 40) < 250) {
        if (i != 3 && i != 5) {
            foods_.push_back(Food(420, (i*35 +40)));
        }
        i++;
    } i=0;

    // Bottom Left
    while ((i*35 + 40) < 350) {
        foods_.push_back(Food((40 + i*35), 700));
        i++;
    } i=0;
    while ((i*35 + 530) < 700) {
        if (i != 2) {
            foods_.push_back(Food(40, (i*35 + 530)));
        } else {
            power_cookies_.push_back(Power_Cookie(40, (i*35 + 527)));
        }
        i++;
    } i=1;
    while ((i*35 + 40) < 350) {
        if (i != 3) {
            foods_.push_back(Food(i*35 + 40, 530));
        }
        i++;
    } i=1;
    while ((i*35 + 527) < 700) {
        if (i != 2 && i != 5) {
            foods_.push_back(Food(320, (i*35 + 527)));
        }
        i++;
    } i=0;

    // Bottom Right
    while ((i*35 + 420) < 725) {
        foods_.push_back(Food((420 + i*35), 700));
        i++;
    } i=0;
    while ((i*35 + 530) < 700) {
        if (i != 2) {
            foods_.push_back(Food(700, (i*35 + 530)));
        } else {
            power_cookies_.push_back(Power_Cookie(700, (i*35 + 527)));
        }
        i++;
    } i=0;
    while ((i*35 + 420) < 725) {
        if (i != 5 && i != 8) {
            foods_.push_back(Food(i*35 + 420, 530));
        }
        i++;
    } i=1;
    while ((i*35 + 527) < 700) {
        if (i != 2 && i != 5) {
            foods_.push_back(Food(420, (i*35 + 527)));
        }
        i++;
    } i=0;
}

void
Model::create_ghosts() {
    ghosts_.push_back(Ghost({275,276}, "red_ghost.png"));
    ghosts_.push_back(Ghost({328,276}, "blue_ghost.png"));
    ghosts_.push_back(Ghost({382,276}, "pink_ghost.png"));
    ghosts_.push_back(Ghost({435,276}, "teal_ghost.png"));

    // Randomize Initial Ghost Movements
    for (Ghost &g : ghosts()) {
        g.randomize(pcookie_mode());
    }
}

void
Model::inc_score(std::string ate)
{
    if (ate == "food") score_ += 10;
    if (ate == "pcookie") score_ += 50;
    if (ate == "ghost") score_ += 200;
}

void
Model::round_over()
{
    flip_live();
    pacman_.reset_pacman();
    lose_life();
    for (size_t i=0; i<ghosts().size(); i++) {
        ghosts()[i].set_position(275 + i*53, 276);
        ghosts()[i].randomize(pcookie_mode());
    }
}

void
Model::game_over()
{
    flip_live();
    lives_ = 3;
    pcookie_mode_ = false;
    pacman_.reset_pacman();

    ghosts_.clear();
    create_ghosts();

    foods_.clear();
    power_cookies_.clear();
    create_food();
}

void Model::on_frame(double dt)
{
    if (live()) {

        // Pacman
        Pacman spec = pacman_.next(dt);
        Pacman spec2 = pacman_;

        //Power Cookie Mode
        if (pcookie_mode() && timer() > 10) {
            flip_pcookie_mode();
        }
        if (pcookie_mode() && pacman_.eats_ghost(ghosts())) {
            inc_score("ghost");
        }


        // Collisions
        if (pacman_.hits_any_wall(walls())) {
            pacman_.velo_stop();
            pacman_ = pacman_.next(dt);
        }
        if (pacman_.eat_food(foods())) {
            inc_score("food");
            pacman_ = pacman_.next(dt);
        }
        if (pacman_.eat_power_cookie(power_cookies())) {
            pcookie_mode_ = true;
            inc_score("pcookie");
            timer_.reset();
        }

        // Movement
        if (pacman_.position().x > 750 || pacman_.position().x < 0) {
            pacman_.horizontial_edge();
        }

        // Checks if inputted direction will cause pacman to go into a wall
        if (pacman_.new_direction() != pacman_.direction()) {
            if (pacman_.new_direction() == 'u') {
                spec2.velo_up();
                spec2 = spec2.next(2*dt);
                if (!spec2.hits_any_wall(walls())) {
                    pacman_.set_direction('u');
                    pacman_.velo_up();
                    pacman_ = pacman().next(dt);
                } else {
                    pacman_ = pacman_.next(dt);
                }
            }
            else if (pacman_.new_direction() == 'd') {
                spec2.velo_down();
                spec2 = spec2.next(2*dt);
                if (!spec2.hits_any_wall(walls())) {
                    pacman_.set_direction('d');
                    pacman_.velo_down();
                    pacman_ = pacman().next(dt);
                } else {
                    pacman_ = pacman_.next(dt);
                }
            }
            else if (pacman_.new_direction() == 'r') {
                spec2.velo_right();
                spec2 = spec2.next(2*dt);
                if (!spec2.hits_any_wall(walls())) {
                    pacman_.set_direction('r');
                    pacman_.velo_right();
                    pacman_ = pacman().next(dt);
                } else {
                    pacman_ = pacman_.next(dt);
                }
            }
            else if (pacman_.new_direction() == 'l') {
                spec2.velo_left();
                spec2 = spec2.next(2*dt);
                if (!spec2.hits_any_wall(walls())) {
                    pacman_.set_direction('l');
                    pacman_.velo_left();
                    pacman_ = pacman().next(dt);
                } else {
                    pacman_ = pacman_.next(dt);
                }
            }
        } else {
            if (pacman_.direction() == 'u') {
                spec2.velo_up();
                spec2 = spec2.next(dt);
                if (!spec2.hits_any_wall(walls())) {
                    pacman_.velo_up();
                    pacman_ = pacman().next(dt);
                }
            }
            else if (pacman_.direction() == 'd') {
                spec2.velo_down();
                spec2 = spec2.next(dt);
                if (!spec2.hits_any_wall(walls())) {
                    pacman_.velo_down();
                    pacman_ = pacman().next(dt);
                }
            }
            else if (pacman_.direction() == 'r') {
                spec2.velo_right();
                spec2 = spec2.next(dt);
                if (!spec2.hits_any_wall(walls())) {
                    pacman_.velo_right();
                    pacman_ = pacman().next(dt);
                }
            }
            else if (pacman_.direction() == 'l') {
                spec2.velo_left();
                spec2 = spec2.next(dt);
                if (!spec2.hits_any_wall(walls())) {
                    pacman_.velo_left();
                    pacman_ = pacman().next(dt);
                }
            }
        }

        // Ghosts
        for (Ghost &g : ghosts()) {
            Ghost gspec = g.next(dt);

            if (gspec.position().x > 750 || gspec.position().x < 0) {
                g.horizontial_edge();
            }
            if (gspec.hits_any_wall(walls())) {
                g.randomize(pcookie_mode());
            } else if (!g.hits_any_wall(walls())) {
                g = g.next(dt);
            }

            // Offsets lack of speed change between pcookie_mode turning on and off
            if (pcookie_mode()) {
                if (g.direction() == 'r') g.pc_velo_right();
                if (g.direction() == 'l') g.pc_velo_left();
                if (g.direction() == 'd') g.pc_velo_down();
                if (g.direction() == 'u') g.pc_velo_up();
            } else {
                if (g.direction() == 'r') g.velo_right();
                if (g.direction() == 'l') g.velo_left();
                if (g.direction() == 'd') g.velo_down();
                if (g.direction() == 'u') g.velo_up();
            }
        }

        // Game Over
        if (foods().size() == 0 && power_cookies().size() == 0) {
            game_over();
        }
        // Round Over
        if (!pcookie_mode() && spec.hits_any_ghost(ghosts())) {
            if (lives() == 1) {
                game_over();
            } else {
                round_over();
            }
        }
    }
}
#include "character.hxx"
#include "model.hxx"
#include <catch.hxx>

TEST_CASE("pacman changes direction and velocity")
{
    Model m;

    // Game Begins
    m.flip_live();

    // Check beginning velocity is going right
    CHECK(m.pacman().velocity() == Velocity{200, 0});

    // set position on track to hit right bordering wall with x position of 725
    m.pacman().set_position(600, m.pacman().position().y);

    // advance by 0.5 so pacman advances 100 to the right
    m.on_frame(0.5);

    // call next frame to detect contact between pacman and wall
    m.on_frame(0.1);

    // since pacman hit a wall the velocity should now be zero and pacman comes to a stop
    CHECK(m.pacman().velocity() == Velocity{0,0});
}

TEST_CASE("pacman collides with a ghost")
{
    Model m;

    // Game Begins
    m.flip_live();

    // check to see that game starts with 3 lives
    CHECK(m.lives() == 3);

    // set a ghosts position to 80px right of the pacman
    m.ghosts()[0].set_position(m.pacman().position().x + 80, m.pacman().position().y);

    // initiate collision
    m.on_frame(0.1);

    // allow game to advance to next frame
    m.on_frame(0.1);

    // see that round_over() is called and a life is lost
    CHECK(m.lives() == 2);

    // check that game is no longer live
    CHECK(!m.live());
}

TEST_CASE("pacman collides with a ghost in power cookie mode")
{
    Model m;

    // Game Begins
    m.flip_live();

    // change the game to power cookie mode
    m.flip_pcookie_mode();

    // remove foods so Pacman doesn't eat them and adjust the score
    m.foods().clear();

    // check to see that game starts with 3 lives
    CHECK(m.lives() == 3);

    // check to see that game starts with 4 ghosts
    CHECK(m.ghosts().size() == 4);

    // check to see that the game starts with a score of 0
    CHECK(m.score() == 0);

    // set a ghosts position to 80px right of the pacman
    m.ghosts()[0].set_position(m.pacman().position().x + 80, m.pacman().position().y);

    // initiate collision
    m.on_frame(0.1);

    // allow game to advance to next frame
    m.on_frame(0.1);
    m.on_frame(0.1);

    // check that the game has not lost any lives after the collision
    CHECK(m.lives() == 3);

    // check that the number of ghosts has decreased by 1 after pacman ate a ghost
    CHECK(m.ghosts().size() == 3);

    // check to see that score was updated after eating the ghost
    CHECK(m.score() == 200);

    // check that game is still live
    CHECK(m.live());
}

TEST_CASE("pacman eats a food")
{
    Model m;

    // Game Begins
    m.flip_live();

    // remove all initialized foods
    m.foods().clear();

    // add a food 80px to the right of pacman
    m.foods().push_back(Food(m.pacman().position().x + 80, m.pacman().position().y));

    // add a dummy food 80px to left of pacman (since pacman starts off going right) so game doesn't end once the
    // first food is eaten.
    m.foods().push_back(Food(m.pacman().position().x - 80, m.pacman().position().y));

    // check to see that there are two foods and the game starts with zero points
    CHECK(m.foods().size() == 2);
    CHECK(m.score() == 0);

    // initiate collision and advance game
    m.on_frame(0.1);
    m.on_frame(0.1);
    m.on_frame(0.1);

    // check to see if the food was eaten
    CHECK(m.foods().size() == 1);

    // check to see if score was updated
    CHECK(m.score() == 10);
}

TEST_CASE("pacman eats a power cookie")
{
    Model m;

    // Game Begins
    m.flip_live();

    // remove all initialized foods and power cookies
    m.foods().clear();
    m.power_cookies().clear();

    // add a food 80px to the right of pacman
    m.power_cookies().push_back(Power_Cookie(m.pacman().position().x + 80, m.pacman().position().y));

    // add a dummy food 80px to left of pacman (since pacman starts off going right) so game doesn't end once the
    // first food is eaten.
    m.foods().push_back(Food(m.pacman().position().x - 80, m.pacman().position().y));

    CHECK(m.power_cookies().size() == 1);

    // check that does not start in pcookie mode
    CHECK(m.pcookie_mode() == false);

    // advance game
    m.on_frame(0.1);
    m.on_frame(0.1);
    m.on_frame(0.1);

    // check to see if the power cookie was eaten
    CHECK(m.power_cookies().size() == 0);

    // check that eating the power cookie turns on pcookie mode
    CHECK(m.pcookie_mode() == true);

    // check to see if score was updated
    CHECK(m.score() == 50);
}

TEST_CASE("game ends from running out of lives")
{
    Model m;

    // Game Begins
    m.flip_live();

    // remove 2 lives
    m.lose_life();
    m.lose_life();

    // check to see that game has 1 life
    CHECK(m.lives() == 1);

    // remove foods
    m.foods().clear();
    CHECK(m.foods().size() == 0);

    // remove two ghosts
    m.ghosts().pop_back();
    m.ghosts().pop_back();
    CHECK(m.ghosts().size() == 2);

    // set a ghosts position to 80px right of the pacman
    m.ghosts()[0].set_position(m.pacman().position().x + 80, m.pacman().position().y);

    // initiate collision
    m.on_frame(0.2);

    // allow game to advance to next frame
    m.on_frame(1);

    // see that game_over() is called and lives are reset
    CHECK(m.lives() == 3);

    // check that foods have been reinitialized
    CHECK(m.foods().size() != 0);

    // check that ghosts have been reinitialized
    CHECK(m.ghosts().size() == 4);

    // check that game is no longer live
    CHECK(!m.live());
}

TEST_CASE("game ends from eating all foods")
{
    Model m;

    // Game Begins
    m.flip_live();

    // remove all initialized foods and power cookies
    m.foods().clear();
    m.power_cookies().clear();

    // remove 1 life and all ghosts from game to show game_over() is called later
    m.lose_life();
    CHECK(m.lives() == 2);
    m.ghosts().clear();
    CHECK(m.ghosts().size() == 0);

    // add a food 80px to the right of pacman
    m.foods().push_back(Food(m.pacman().position().x + 80, m.pacman().position().y));

    // check to see that there is 1 food
    CHECK(m.foods().size() == 1);

    // initiate collision and advance game
    m.on_frame(0.1);
    m.on_frame(0.1);
    m.on_frame(0.1);

    // see that game_over() is called and lives are reset
    CHECK(m.lives() == 3);

    // check that foods have been reinitialized
    CHECK(m.foods().size() != 0);

    // check that ghosts have been reinitialized
    CHECK(m.ghosts().size() == 4);

    // check that game is no longer live
    CHECK(!m.live());
}

TEST_CASE("randomized ghost direction after wall collision")
{
    Model m;

    // Game Begins
    m.flip_live();

    // advance game once to initialize random ghost direction and velocity
    m.on_frame(0.1);

    // set the ghost at a position and velocity that is heading towards a wall
    m.ghosts()[0].set_direction('l');
    m.ghosts()[0].velo_left();
    m.ghosts()[0].set_position(185, 577);

    // initiate collision and advance game
    m.on_frame(1);
    m.on_frame(0.1);

    // check to see if the ghost has a new direction and velocity that does match its previous values
    CHECK(m.ghosts()[0].direction() != 'l');
    CHECK(m.ghosts()[0].velocity() != Velocity{-160, 0});
    CHECK(m.ghosts()[0].velocity() != Velocity{0, 0});

    // store these new values
    char rand_dir = m.ghosts()[0].direction();
    Velocity rand_velo = m.ghosts()[0].velocity();

    // initiate another collision and advance the game
    m.on_frame(0.5);
    m.on_frame(0.1);

    // check to see if the new random attributes match the stores values
    CHECK(m.ghosts()[0].direction() != rand_dir);
    CHECK(m.ghosts()[0].velocity() != rand_velo);
    CHECK(m.ghosts()[0].velocity() != Velocity{0, 0});
}



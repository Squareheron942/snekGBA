#include "bn_core.h"
#include "bn_math.h"
#include "bn_fixed.h"
#include "bn_sram.h"
#include "bn_string.h"
#include "bn_random.h"
#include "bn_log.h"
#include "bn_list.h"

#include "bn_keypad.h"

#include "bn_display.h"
#include "bn_sprite_text_generator.h"

#include "common_info.h"
#include "common_variable_8x16_sprite_font.h"

#include "bn_sprites.h"
#include "bn_sprite_actions.h"
#include "bn_sprite_item.h"
#include "bn_sprite_ptr.h"
#include "bn_sprite_palette_ptr.h"
#include "bn_display.h"
#include "bn_sprite_tiles_ptr.h"
#include "bn_sprite_items_snek.h"
#include "bn_sprite_items_apple.h"
#include "bn_sprite_items_bg.h"

#include "bn_bg_palettes.h"
#include "bn_bg_palette_ptr.h"
#include "bn_regular_bg_ptr.h"
#include "bn_sprite_palette_items_fronkpalette.h"
#include "bn_sprite_palette_items_greypalette.h"
#include "bn_regular_bg_items_background.h"

#include "bn_bg_palette_items_bggrass.h"
#include "bn_bg_palette_items_bgdesert.h"
#include "bn_bg_palette_items_bgwood.h"
#include "bn_bg_palette_items_bgnight.h"
#include "bn_bg_palette_items_bgwinter.h"
#include "bn_bg_palette_items_bgvolcano.h"
#include "bn_bg_palette_items_bgocean.h"

using namespace bn;

int score = 0;

namespace
{
    struct save_data 
    {
        int 
        high_score, 
        times_played, 
        palette,
        fruit,
        background,
        difficulty;
        string_view name = {""};
    };
}

void optionsScreen(sprite_text_generator text_generator) {
    int optionSelected = 0, counter0 = 0, counter1 = 2;

    save_data data;

    const string_view options[] = {
        "Snek",
        "Fruit",
        "Background",
        "Difficulty"
    };

    const string_view sneks[] = {
        "  Normal >",
        "< Fronk >",
        "< Gray  "
    };

    const string_view backgrounds[] = {
        "  Grass >",
        "< Snow >",
        "< Desert >",
        "< Forest >",
        "< Volcano >",
        "< Night >",
        "< Ocean  "
    };

    const string_view difficulties[] = {
        "  I >",
        "< II >",
        "< III  "
    };

    sprite_ptr fruit = sprite_items::apple.create_sprite(64, 8);

    while (true) {
        vector<sprite_ptr, 64> text_sprites;
        sram::read(data);

        if (counter0 < 20) counter0++;
        else {
            counter0 = 0;
            counter1++;
        }

        if (keypad::up_pressed()) optionSelected -= optionSelected == 0 ? 0 : 1;
        if (keypad::down_pressed()) optionSelected += optionSelected == 3 ? 0 : 1;

        if (keypad::left_pressed()) {
            if (optionSelected == 0 && data.palette > 0) data.palette--;
            else if (optionSelected == 1 && data.fruit > 0) data.fruit--;
            else if (optionSelected == 2 && data.background > 0) data.background--;
            else if (optionSelected == 3 && data.difficulty > 0) data.difficulty--;
        }

        if (keypad::right_pressed()) {
            if (optionSelected == 0 && data.palette < 2) data.palette++;
            else if (optionSelected == 1 && data.fruit < 5) data.fruit++;
            else if (optionSelected == 2 && data.background < 6) data.background++;
            else if (optionSelected == 3 && data.difficulty < 2) data.difficulty++;
        }
        
        text_generator.generate(fixed_point(-64, -8 - (optionSelected == 0 ? counter1 % 2 : 0) - optionSelected * 16), options[0], text_sprites);
        text_generator.generate(fixed_point(-64, 8 - (optionSelected == 1 ? counter1 % 2 : 0) - optionSelected * 16), options[1], text_sprites);
        text_generator.generate(fixed_point(-64, 24 - (optionSelected == 2 ? counter1 % 2 : 0) - optionSelected * 16), options[2], text_sprites);
        text_generator.generate(fixed_point(-64, 40 - (optionSelected == 3 ? counter1 % 2 : 0) - optionSelected * 16), options[3], text_sprites);

        text_generator.generate(fixed_point(64, -8 - (optionSelected == 0 ? counter1 % 2 : 0) - optionSelected * 16), sneks[data.palette], text_sprites);
        fruit.set_tiles(sprite_items::apple.tiles_item().create_tiles(data.fruit));
        fruit.set_y(8 - (optionSelected == 1 ? counter1 % 2 : 0) - optionSelected * 16);
        text_generator.generate(fixed_point(64, 24 - (optionSelected == 2 ? counter1 % 2 : 0) - optionSelected * 16), backgrounds[data.background], text_sprites);
        text_generator.generate(fixed_point(64, 40 - (optionSelected == 3 ? counter1 % 2 : 0) - optionSelected * 16), difficulties[data.difficulty], text_sprites);


        sram::write(data);

        if (keypad::b_pressed()) return;
        core::update();
    }
}

void titleScreen(sprite_text_generator text_generator) {
    int optionSelected = 0, counter0 = 0, counter1 = 2;
    text_generator.set_center_alignment();
    string_view text[] = {
        "Play",
        "Options"
    };

    const bg_palette_ptr colors[] = {
        bg_palette_items::bggrass.create_palette(),
        bg_palette_items::bgwinter.create_palette(),
        bg_palette_items::bgdesert.create_palette(),
        bg_palette_items::bgwood.create_palette(),
        bg_palette_items::bgvolcano.create_palette(),
        bg_palette_items::bgnight.create_palette(),
    };
    
    save_data data;
    while (true) {
        sram::read(data);
        if (keypad::up_held()) optionSelected -= optionSelected == 0 ? 0 : 1;
        if (keypad::down_held()) optionSelected += optionSelected == 1 ? 0 : 1;

        if (counter0 < 20) counter0++;
        else {
            counter0 = 0;
            counter1++;
        }

        vector<sprite_ptr, 32> text_sprites;
        if (optionSelected == 0) text[0] = "[ Play ]";
        else text[0] = "Play";
        if (optionSelected == 1) text[1] = "[ Options ]";
        else text[1] = "Options";

        text_generator.generate(fixed_point(0, 0 - (optionSelected == 0 ? counter1 % 2 : 0)), text[0], text_sprites);
        text_generator.generate(fixed_point(0, 16 - (optionSelected == 1 ? counter1 % 2 : 0)), text[1], text_sprites);

        if (keypad::a_pressed() && optionSelected == 0) return;
        else if (keypad::a_pressed()) {
            if (optionSelected == 0) return;
            else if (optionSelected == 1) {
                text_sprites = vector<sprite_ptr, 32>();
                optionsScreen(text_generator);
            }
        }

        
        core::update();
    }
}

void unpause(sprite_text_generator text_generator) {
    int time = 4;
    vector<sprite_ptr, 32> text_sprites;
    for (int i = 0; i < 180; i++) {
        text_sprites = vector<sprite_ptr, 32>();
        if (i % 60 == 0) time--;
        text_generator.generate(fixed_point(0, 0), to_string<8>(time), text_sprites);
        core::update();
    }
}

class pos2 {
    public:
        int x;
        int y;
        pos2(int posx, int posy) {
            x = posx;
            y = posy;
        }
        pos2() {
            x = 0;
            y = 0;
        }
        bool operator ==(pos2 other) {
            return x == other.x && y == other.y;
        }
};

class apple {
    public:
        bn::random rand;
        save_data data;
        pos2 position = pos2(0, 0);
        optional<sprite_ptr> sprite = sprite_items::apple.create_sprite(0, 0);
        apple();

        void place();
};

apple::apple() {
    sram::read(data);
    place();
}

void apple::place() {
    sram::read(data);
    position.x = rand.get_int(15) - 7;
    position.y = rand.get_int(9) - 4;

    sprite.value().set_position(position.x * 16, position.y * 16);

    sprite.value().set_tiles(sprite_items::apple.tiles_item().create_tiles(data.fruit));

    log(to_string<16>("apple get"));
}

class bodyPart {
    public:
        pos2 position, oldposition;
        optional<sprite_ptr> sprite = sprite_items::snek.create_sprite(0, 16);
        // vector<sprite_ptr, 1> dirsprite;
        int type, direction;
        bool turning = false;
        sprite_text_generator text_generator = sprite_text_generator(common::variable_8x16_sprite_font);
        bodyPart(pos2 p, sprite_ptr s, int t, int d) {
            position = p;
            oldposition = p;
            sprite = s;
            save_data data;
            sram::read(data);
            // text_generator.generate(fixed_point(p.x, p.y), to_string<16>(d), dirsprite);
            if (data.palette == 1) sprite.value().set_palette(sprite_palette_items::fronkpalette);
            if (data.palette == 2) sprite.value().set_palette(sprite_palette_items::greypalette);
            type = t;
            direction = d;
            sprite.value().set_tiles(sprite_items::snek.tiles_item().create_tiles(type * 4));
        }
        void setDirection(int dir) {
            direction = dir;
            // dirsprite.shrink(0);
            // text_generator.generate(fixed_point(position.x * 16, position.y * 16), to_string<16>(dir), dirsprite);
            sprite.value().set_tiles(sprite_items::snek.tiles_item().create_tiles(type * 4 + dir));
        }
        void setType(int t) {
            type = t;
            sprite.value().set_tiles(bn::sprite_items::snek.tiles_item().create_tiles(t * 4));
        }
};

int getDirectionToForwards(pos2 p0, pos2 p1) {
    int dx = p0.x - p1.x;
    int dy = p0.y - p1.y;

    if (dy < 0) return 0;
    if (dx > 0) return 1;
    if (dy > 0) return 2;
    if (dx < 0) return 3;
    return 0;
}

class snek {
    public:
        int length = 2, previnput = 0;
        apple a;
        bool dead;
        vector<bodyPart, 64> body;
        bn::list<int, 4> inputs;

        // 0 = up, 1 = right, 2 = down, 3 = left
        int direction = 0;

        snek() {
            inputs.push_front(0);
            body.emplace_back(bodyPart(pos2(0, 0), sprite_items::snek.create_sprite(0, 0), 0, 0));
            body.emplace_back(bodyPart(pos2(0, 1), sprite_items::snek.create_sprite(0, 0), 2, 0));


            save_data data;
            sram::read(data);

            for (int i = 0; i < data.times_played; i++) {
                a.rand.update();
            }
            
            data.times_played++;
            sram::write(data);
        }

        void addPart() {
            body.emplace_back(bodyPart(body[length - 1].oldposition, sprite_items::snek.create_sprite(body[length - 1].oldposition.x, body[length - 1].oldposition.y), 2, getDirectionToForwards(body[length - 1].position, body[length - 1].oldposition)));
            length++;
        }

        void move() {
            log(to_string<8>(inputs.front()));
            if ((inputs.front() == 3 && body[0].position.x - 1 == body[1].position.x) || (inputs.front() == 1 && body[0].position.x + 1 == body[1].position.x) || (inputs.front() == 2 && body[0].position.y - 1 == body[1].position.y) || (inputs.front() == 0 && body[0].position.y + 1 == body[1].position.y)) 
            {
                inputs.pop_front();
                inputs.push_front(previnput);
            }

            if (inputs.size() != 1) inputs.pop_front();
            body[0].direction = inputs.front();
            previnput = inputs.front();
            // log(to_string<8>(previnput));

            // body[0].direction = direction;

            body[0].sprite.value().set_bg_priority(2);
            for (int i = 0; i < length; i++) {
                bodyPart part = body[i];
                part.oldposition = part.position;
                int dir = part.direction;
                part.turning = false;

                if (i != 0) {
                    dir = getDirectionToForwards(body[i - 1].oldposition, part.position);
                    if (dir != part.direction) part.turning = true;
                    if (i != length - 1) part.setType(1);
                }
                
                if (dir == 0) part.position.y--;
                else if (dir == 1) part.position.x++;
                else if (dir == 2) part.position.y++;
                else part.position.x--;

                part.sprite.value().set_x(part.position.x * 16);
                part.sprite.value().set_y(part.position.y * 16);
                part.sprite.value().set_bg_priority(3);

                if (i != 0) {
                    dir = getDirectionToForwards(body[i - 1].position, part.position);
                    if (dir != part.direction) part.turning = true;
                }

                part.setDirection(dir);

                body[i] = part;

                if (i == 0 && part.position.x == a.position.x && part.position.y == a.position.y) {
                    score++;
                    int isOverlapping = 1;
                    while(isOverlapping != 0) {
                        isOverlapping = 0;
                    a.place();
                        for (int j = 0; j < body.size(); j++) {
                            if (body[j].position == a.position) {
                                isOverlapping++;
                            }
                        }
                    }
                    addPart();
                }
            }
            for (int i = 0; i < length; i++) {
                bodyPart part = body[i];

                if (i > 0 && i < length - 1 && part.turning) {
                    body[i].sprite.value().set_tiles(sprite_items::snek.tiles_item().create_tiles(12 + getBendDirection(part.direction, i)));
                }
            }

            for (int i = 0; i < length; i++) {
                bodyPart part = body[i];

                if (i != 0 && part.position.x == body[0].position.x && part.position.y == body[0].position.y) die();
                if (i == 0 && (part.position.y > 4 || part.position.y < -4 || part.position.x < -7 || part.position.x > 7)) die();
            }
        }

        void die() {
            save_data data;

            sram::read(data);

            if (data.high_score < score) data.high_score = score;
            data.times_played++;

            sram::write(data);

            bn::sprite_text_generator text_generator(common::variable_8x16_sprite_font);
            text_generator.set_center_alignment();

            string_view text[] = {
                "Game Over",
                "Score: ",
                "[Select] to quit"
            };

            vector<sprite_ptr, 32> text_sprites;
            text_generator.generate(fixed_point(0, -16), text[0], text_sprites);
            text_generator.generate(fixed_point(0, 16), text[1] + to_string<16>(score), text_sprites);
            text_generator.generate(fixed_point(0, 64), text[2], text_sprites);

            while(!keypad::a_pressed() && !keypad::start_pressed() && !keypad::select_pressed()) core::update();
            text_sprites.shrink(0);
            a.sprite.reset();
            

            if (keypad::select_pressed()) titleScreen(text_generator);

            length = 2;
            dead = true;

            score = 0;
        }

        // bool isBent(int i) {
        //     if (i == 0 || i == length - 1) return false;

        //     return !(body[i].direction == body[i + 1].direction);
        // }

        int getBendDirection(int d0, int i) {
            // int d0 = body[i].direction;
            int d1 = body[i + 1].direction;

            // 0 = |- 1 = |_ 2 = -| 3 = _|

            if (d0 == 0) {
                if (d1 == 1) return 2;
                if (d1 == 3) return 3;
            } else if (d0 == 1) {
                if (d1 == 0) return 0; // good
                if (d1 == 2) return 3;
            } else if (d0 == 2) {
                if (d1 == 1) return 1;
                if (d1 == 3) return 0;
            } else {
                if (d1 == 0) return 1;
                if (d1 == 2) return 2;
            }
            return 0;
        }

        // sprite_palette_ptr palettes[] {
        //     sprite_items::snek.palette_item().create_palette(),
        //     sprite_palette_items::fronkpalette.create_palette(),
        //     sprite_palette_items::greypalette.create_palette()
        // };

        void update_palette() {
            save_data data;
            sram::read(data);
            for (int i = 0; i < length; i++) {
                if (data.palette == 0) body[i].sprite.value().set_palette(sprite_items::snek.palette_item().create_palette());
                else if (data.palette == 1) body[i].sprite.value().set_palette(sprite_palette_items::fronkpalette.create_palette());
                else if (data.palette == 2) body[i].sprite.value().set_palette(sprite_palette_items::greypalette.create_palette());
            }
        }
};

int main()
{
    core::init();

    const bg_palette_ptr colors[] = {
        bg_palette_items::bggrass.create_palette(),
        bg_palette_items::bgwinter.create_palette(),
        bg_palette_items::bgdesert.create_palette(),
        bg_palette_items::bgwood.create_palette(),
        bg_palette_items::bgvolcano.create_palette(),
        bg_palette_items::bgnight.create_palette(),
        bg_palette_items::bgocean.create_palette(),
    };

    sprite_text_generator text_generator(common::variable_8x16_sprite_font);

    save_data data;

    sram::read(data);

    if (data.palette < 0) data.palette = 0;
    if (data.fruit < 0) data.fruit = 0;
    if (data.background < 0) data.background = 0;
    if (data.difficulty < 0) data.difficulty = 0;

    sram::write(data);
    regular_bg_ptr bg = regular_bg_items::background.create_bg(8, 8);

    bg.set_palette(colors[data.background]);

    titleScreen(text_generator);

    sram::read(data);

    bg.set_palette(colors[data.background]);

    unpause(text_generator);

    snek snake = snek();

    int counter = 0, period = 20;

    while(true)
    {
        sram::read(data);
        vector<sprite_ptr, 32> text_sprites;

        text_generator.generate(fixed_point(-116, -72), string_view("Score: " + to_string<16>(score)), text_sprites);    

        if (bn::keypad::left_pressed() && snake.inputs.back() != 3)
        {
            if (snake.inputs.size() < 4) snake.inputs.push_back(3);
        }
        else if (bn::keypad::right_pressed() && snake.inputs.back() != 1)
        {
            if (snake.inputs.size() < 4) snake.inputs.push_back(1);
        }

        if (bn::keypad::up_pressed() && snake.inputs.back() != 0)
        {
            if (snake.inputs.size() < 4) snake.inputs.push_back(0);
        }
        else if (bn::keypad::down_pressed() && snake.inputs.back() != 2)
        {
            if (snake.inputs.size() < 4) snake.inputs.push_back(2);
        }

        if (snake.dead) {
            snake = snek();
            bg.set_palette(colors[data.background]);
            unpause(text_generator);
        }

        if (counter < period) counter++;
        else {
            snake.move();
            counter = 0;
        }

        if (score % 2 == 0) period = max(20 - score / 2 - 8 * data.difficulty, 0);

        if (keypad::start_pressed()) {
            core::update();
            text_generator.set_center_alignment();

            while (!keypad::start_pressed()) {
                text_sprites.shrink(0);
                if (keypad::select_pressed()) optionsScreen(text_generator);
                text_generator.generate(fixed_point(0, 0), "Paused", text_sprites);
                text_generator.generate(fixed_point(0, 64), "[Select] for options", text_sprites);
                core::update();
            }

            snake.update_palette();

            sram::read(data);
            bg.set_palette(colors[data.background]);

            text_generator.set_left_alignment();
            text_sprites.shrink(0);
            unpause(text_generator);
        }
        
        core::update();
    }
}
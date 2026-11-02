#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "ex19.h"


int Monster_attack(void *self, int damage)
{
    Monster *monster = self;

    printf("You attack %s!\n", monster->_(description));

    monster->hit_points -= damage;

    if(monster->hit_points > 0) {
        printf("It is still alive.\n");
        return 0;
    } else {
        printf("It is dead!\n");
        return 1;
    }
}

int Monster_init(void *self)
{
    Monster *monster = self;
    monster->hit_points = 10;
    return 1;
}

Object MonsterProto = {
    .init = Monster_init,
    .attack = Monster_attack
};


void *Room_move(void *self, Direction direction)
{
    Room *room = self;
    Room *next = NULL;

    if(direction == NORTH && room->north) {
        printf("You go north, into:\n");
        next = room->north;
    } else if(direction == SOUTH && room->south) {
        printf("You go south, into:\n");
        next = room->south;
    } else if(direction == EAST && room->east) {
        printf("You go east, into:\n");
        next = room->east;
    } else if(direction == WEST && room->west) {
        printf("You go west, into:\n");
        next = room->west;
    } else {
        printf("You can't go that direction.");
        next = NULL;
    }

    if(next) {
        next->_(describe)(next);
    }

    return next;
}


int Room_attack(void *self, int damage)
{
    Room *room = self;
    Monster *monster = room->bad_guy;

    if(monster) {
        monster->_(attack)(monster, damage);
        return 1;
    } else {
        printf("You flail in the air at nothing. Idiot.\n");
        return 0;
    }
}


Object RoomProto = {
    .move = Room_move,
    .attack = Room_attack
};


void *Map_move(void *self, Direction direction)
{
    Map *map = self;
    Room *location = map->location;
    Room *next = NULL;

    next = location->_(move)(location, direction);

    if(next) {
        map->location = next;
    }

    return next;
}

int Map_attack(void *self, int damage)
{
    Map* map = self;
    Room *location = map->location;

    return location->_(attack)(location, damage);
}


int Map_init(void *self)
{
    Map *map = self;

    // make some rooms for a small map
    Room *ysyx_lab = NEW(Room, "The ysyx laboratory!!\nThen DingDing gives you a weapon");
    Room *SunBinhe_workstation = NEW(Room, "孙彬赫出没！他的豪意值高的离谱！快战胜他");
    Room *ShiWenxuan_workstation = NEW(Room, "师文轩出没！他的香水俘获了学妹！快战胜他拯救学妹");
    Room *HuoXuekai_workstation = NEW(Room, "霍雪恺出没！他烫的头锋利无比！注意躲避");

    // put the bad guy in the arena
    ShiWenxuan_workstation->bad_guy = NEW(Monster, "师兄");

    // setup the map rooms
    SunBinhe_workstation->north = ysyx_lab;

    ysyx_lab->west = ShiWenxuan_workstation;
    ysyx_lab->east = HuoXuekai_workstation;
    ysyx_lab->south = SunBinhe_workstation;
    
    ShiWenxuan_workstation->east = ysyx_lab;
    HuoXuekai_workstation->west = ysyx_lab;

    // start the map and the character off in the hall
    map->start = ysyx_lab;
    map->location = ysyx_lab;

    return 1;
}

Object MapProto = {
    .init = Map_init,
    .move = Map_move,
    .attack = Map_attack
};

int process_input(Map *game)
{
    printf("\n> ");

    char ch = getchar();
    getchar(); // eat ENTER

    int damage = rand() % 4;

    switch(ch) {
        case -1:
            printf("Giving up? You suck.\n");
            return 0;
            break;

        case 'n':
            game->_(move)(game, NORTH);
            break;

        case 's':
            game->_(move)(game, SOUTH);
            break;

        case 'e':
            game->_(move)(game, EAST);
            break;

        case 'w':
            game->_(move)(game, WEST);
            break;

        case 'a':

            game->_(attack)(game, damage);
            break;
        case 'l':
            printf("You can go:\n");
            if(game->location->north) printf("NORTH\n");
            if(game->location->south) printf("SOUTH\n");
            if(game->location->east) printf("EAST\n");
            if(game->location->west) printf("WEST\n");
            break;

        default:
            printf("What?: %d\n", ch);
    }

    return 1;
}

int main(int argc, char *argv[])
{
    // simple way to setup the randomness
    srand(time(NULL));

    // make our map to work with
    Map *game = NEW(Map, "The Hall of the Minotaur.");

    printf("You enter the ");
    game->location->_(describe)(game->location);

    while(process_input(game)) {
    }

    return 0;
}

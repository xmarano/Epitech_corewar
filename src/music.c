/*
** EPITECH PROJECT, 2024
** B-CPE-200-MAR-2-1-corewar-leo.gregori
** File description:
** music.c
*/
#include "corewar.h"
#include "my.h"

void init_music(Global_t *s)
{
    if (s->pars.dump == false)
        s->op.nbr_cycles = 1536;
    s->nbr_cycles_count = 1;
    // Initialisation de SDL
    SDL_Init(SDL_INIT_AUDIO);
    // Initialisation de SDL_mixer
    Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);
    s->music = Mix_LoadMUS("src/instructions/Bizon.mp3");
}

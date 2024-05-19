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
    // Initialisation de SDL
    SDL_Init(SDL_INIT_AUDIO);
    // Initialisation de SDL_mixer
    Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);
    s->music = Mix_LoadMUS("src/instructions/Bizon.mp3");
}

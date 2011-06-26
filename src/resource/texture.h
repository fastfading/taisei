/*
 * This software is licensed under the terms of the MIT-License
 * See COPYING for further information. 
 * ---
 * Copyright (C) 2011, Lukas Weber <laochailan@web.de>
 */

#ifndef TEXTURE_H
#define TEXTURE_H

#include <SDL/SDL.h>
#include <GL/glew.h>
#include <math.h>

struct Texture;

typedef struct Texture {
	struct Texture *next;
	struct Texture *prev;
	
	int w, h;
	int truew, trueh;
	
	char *name;	
	GLuint gltex;
} Texture;

Texture *get_tex(char *name);
Texture *prefix_get_tex(char *name, char *prefix);

void load_textures();
void load_resources();

SDL_Surface *load_png(const char *filename);

void delete_texture(void **texs, void *tex);
void delete_textures();

Texture *load_texture(const char *filename);
void load_sdl_surf(SDL_Surface *surface, Texture *texture);
void free_texture(Texture *tex);

void draw_texture(float x, float y, char *name);
void draw_texture_p(float x, float y, Texture *tex);

void fill_screen(float xoff, float yoff, float ratio, char *name);
void fill_screen_p(float xoff, float yoff, float ratio, Texture *tex);
#endif
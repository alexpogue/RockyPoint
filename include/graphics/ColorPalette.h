/*
 * ColorPalette.h
 *
 *  Created on: Apr 5, 2014
 *      Author: Jacob61
 */

#ifndef COLORPALETTE_H_
#define COLORPALETTE_H_

#define FIRST_ENTITY_INDEX 8
#define FIRST_CHARACTER_INDEX 10

#include "graphics/Background.h"

static const unsigned short COLOR_PALETTE[256] = {
		  0x0,    /* transparent */
		  0x03E3, /* zombie skin light */
		  0x09C3, /* zombie skin dark */
		  0x477C, /* hero skin color */
		  0x1084, /* hero gun color */
		  0x0933, /* hero hair dark */
		  0x1176, /* hero hair light */
		  0x3DEF, /* gray */
		  0x0286, /* green */
		  0x0011, /* red */
		  0x03FE, /* yellow */
		  0x7C40, /* blue */
		  0x0001, /* black */
		  0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0
		, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0
		, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0
		, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0
		, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0
		, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0
		, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0
		, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0
		, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0
		, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0
		, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0
		, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0
		, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0
		, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0
		, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0
		, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0
		, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0
		, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0
		, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0
		, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0
		, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0
		, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0
		, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0
		, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0
		, 0x0, 0x0, 0x0, 0x0
};

static const Tile TILE_MAP[] = {
		// transparent
		{
		0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
		0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
		0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
		0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
		0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
		0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
		0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
		0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0
		},

		/* gray */
		{
		0x7, 0x7, 0x7, 0x7, 0x7, 0x7, 0x7, 0x7,
		0x7, 0x7, 0x7, 0x7, 0x7, 0x7, 0x7, 0x7,
		0x7, 0x7, 0x7, 0x7, 0x7, 0x7, 0x7, 0x7,
		0x7, 0x7, 0x7, 0x7, 0x7, 0x7, 0x7, 0x7,
		0x7, 0x7, 0x7, 0x7, 0x7, 0x7, 0x7, 0x7,
		0x7, 0x7, 0x7, 0x7, 0x7, 0x7, 0x7, 0x7,
		0x7, 0x7, 0x7, 0x7, 0x7, 0x7, 0x7, 0x7,
		0x7, 0x7, 0x7, 0x7, 0x7, 0x7, 0x7, 0x7
		},

		/* gray bordered */
		{
		0xB, 0xB, 0xB, 0xB, 0xB, 0xB, 0xB, 0xB,
		0xB, 0x7, 0x7, 0x7, 0x7, 0x7, 0x7, 0xB,
		0xB, 0x7, 0x7, 0x7, 0x7, 0x7, 0x7, 0xB,
		0xB, 0x7, 0x7, 0x7, 0x7, 0x7, 0x7, 0xB,
		0xB, 0x7, 0x7, 0x7, 0x7, 0x7, 0x7, 0xB,
		0xB, 0x7, 0x7, 0x7, 0x7, 0x7, 0x7, 0xB,
		0xB, 0x7, 0x7, 0x7, 0x7, 0x7, 0x7, 0xB,
		0xB, 0xB, 0xB, 0xB, 0xB, 0xB, 0xB, 0xB
		},

		/* green */
		{
		0x8, 0x8, 0x8, 0x8, 0x8, 0x8, 0x8, 0x8,
		0x8, 0x8, 0x8, 0x8, 0x8, 0x8, 0x8, 0x8,
		0x8, 0x8, 0x8, 0x8, 0x8, 0x8, 0x8, 0x8,
		0x8, 0x8, 0x8, 0x8, 0x8, 0x8, 0x8, 0x8,
		0x8, 0x8, 0x8, 0x8, 0x8, 0x8, 0x8, 0x8,
		0x8, 0x8, 0x8, 0x8, 0x8, 0x8, 0x8, 0x8,
		0x8, 0x8, 0x8, 0x8, 0x8, 0x8, 0x8, 0x8,
		0x8, 0x8, 0x8, 0x8, 0x8, 0x8, 0x8, 0x8
		},

		/* green bordered */
		{
		0xB, 0xB, 0xB, 0xB, 0xB, 0xB, 0xB, 0xB,
		0xB, 0x8, 0x8, 0x8, 0x8, 0x8, 0x8, 0xB,
		0xB, 0x8, 0x8, 0x8, 0x8, 0x8, 0x8, 0xB,
		0xB, 0x8, 0x8, 0x8, 0x8, 0x8, 0x8, 0xB,
		0xB, 0x8, 0x8, 0x8, 0x8, 0x8, 0x8, 0xB,
		0xB, 0x8, 0x8, 0x8, 0x8, 0x8, 0x8, 0xB,
		0xB, 0x8, 0x8, 0x8, 0x8, 0x8, 0x8, 0xB,
		0xB, 0xB, 0xB, 0xB, 0xB, 0xB, 0xB, 0xB
		},

		/* yellow */
		{
		0xA, 0xA, 0xA, 0xA, 0xA, 0xA, 0xA, 0xA,
		0xA, 0xA, 0xA, 0xA, 0xA, 0xA, 0xA, 0xA,
		0xA, 0xA, 0xA, 0xA, 0xA, 0xA, 0xA, 0xA,
		0xA, 0xA, 0xA, 0xA, 0xA, 0xA, 0xA, 0xA,
		0xA, 0xA, 0xA, 0xA, 0xA, 0xA, 0xA, 0xA,
		0xA, 0xA, 0xA, 0xA, 0xA, 0xA, 0xA, 0xA,
		0xA, 0xA, 0xA, 0xA, 0xA, 0xA, 0xA, 0xA,
		0xA, 0xA, 0xA, 0xA, 0xA, 0xA, 0xA, 0xA
		},

		/* yellow bordered */
		{
		0xB, 0xB, 0xB, 0xB, 0xB, 0xB, 0xB, 0xB,
		0xB, 0xA, 0xA, 0xA, 0xA, 0xA, 0xA, 0xB,
		0xB, 0xA, 0xA, 0xA, 0xA, 0xA, 0xA, 0xB,
		0xB, 0xA, 0xA, 0xA, 0xA, 0xA, 0xA, 0xB,
		0xB, 0xA, 0xA, 0xA, 0xA, 0xA, 0xA, 0xB,
		0xB, 0xA, 0xA, 0xA, 0xA, 0xA, 0xA, 0xB,
		0xB, 0xA, 0xA, 0xA, 0xA, 0xA, 0xA, 0xB,
		0xB, 0xB, 0xB, 0xB, 0xB, 0xB, 0xB, 0xB
		},

		/* red */
		{
		0x9, 0x9, 0x9, 0x9, 0x9, 0x9, 0x9, 0x9,
		0x9, 0x9, 0x9, 0x9, 0x9, 0x9, 0x9, 0x9,
		0x9, 0x9, 0x9, 0x9, 0x9, 0x9, 0x9, 0x9,
		0x9, 0x9, 0x9, 0x9, 0x9, 0x9, 0x9, 0x9,
		0x9, 0x9, 0x9, 0x9, 0x9, 0x9, 0x9, 0x9,
		0x9, 0x9, 0x9, 0x9, 0x9, 0x9, 0x9, 0x9,
		0x9, 0x9, 0x9, 0x9, 0x9, 0x9, 0x9, 0x9,
		0x9, 0x9, 0x9, 0x9, 0x9, 0x9, 0x9, 0x9
		},

		// hero
		{
			0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
			0x0, 0x3, 0x3, 0x3, 0x3, 0x0, 0x0, 0x0,
			0x5, 0x5, 0x5, 0x5, 0x0, 0x3, 0x0, 0x0,
			0x5, 0x6, 0x6, 0x5, 0x0, 0x4, 0x4, 0x4,
			0x6, 0x6, 0x5, 0x0, 0x0, 0x0, 0x3, 0x0,
			0x5, 0x5, 0x5, 0x5, 0x0, 0x3, 0x0, 0x0,
			0x0, 0x3, 0x3, 0x3, 0x3, 0x0, 0x0, 0x0,
			0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0
		},

		// zombie
		{
		0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
		0x1, 0x1, 0x1, 0x0, 0x0, 0x0, 0x0, 0x0,
		0x0, 0x0, 0x1, 0x1, 0x2, 0x1, 0x1, 0x2,
		0x0, 0x0, 0x0, 0x0, 0x2, 0x1, 0x1, 0x2,
		0x0, 0x0, 0x0, 0x0, 0x1, 0x1, 0x1, 0x1,
		0x0, 0x0, 0x1, 0x1, 0x1, 0x2, 0x2, 0x2,
		0x1, 0x1, 0x1, 0x0, 0x0, 0x0, 0x0, 0x0,
		0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0
		},

		// A
		{
		0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
		0x0, 0x0, 0x0, 0xC, 0xC, 0x0, 0x0, 0x0,
		0x0, 0x0, 0xC, 0x0, 0x0, 0xC, 0x0, 0x0,
		0x0, 0xC, 0x0, 0x0, 0x0, 0x0, 0xC, 0x0,
		0x0, 0xC, 0xC, 0xC, 0xC, 0xC, 0xC, 0x0,
		0x0, 0xC, 0x0, 0x0, 0x0, 0x0, 0xC, 0x0,
		0x0, 0xC, 0x0, 0x0, 0x0, 0x0, 0xC, 0x0,
		0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0
		},

		// B
		{
		0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
		0x0, 0xC, 0xC, 0xC, 0xC, 0xC, 0x0, 0x0,
		0x0, 0xC, 0x0, 0x0, 0x0, 0x0, 0xC, 0x0,
		0x0, 0xC, 0xC, 0xC, 0xC, 0xC, 0x0, 0x0,
		0x0, 0xC, 0x0, 0x0, 0x0, 0x0, 0xC, 0x0,
		0x0, 0xC, 0x0, 0x0, 0x0, 0x0, 0xC, 0x0,
		0x0, 0xC, 0xC, 0xC, 0xC, 0xC, 0x0, 0x0,
		0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0
		},

		// C
		{
		0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
		0x0, 0x0, 0x0, 0xC, 0xC, 0xC, 0xC, 0x0,
		0x0, 0x0, 0xC, 0x0, 0x0, 0x0, 0x0, 0x0,
		0x0, 0xC, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
		0x0, 0xC, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
		0x0, 0x0, 0xC, 0x0, 0x0, 0x0, 0x0, 0x0,
		0x0, 0x0, 0x0, 0xC, 0xC, 0xC, 0xC, 0x0,
		0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0
		},

		// D
		{
		0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
		0x0, 0xC, 0xC, 0xC, 0xC, 0x0, 0x0, 0x0,
		0x0, 0xC, 0x0, 0x0, 0x0, 0xC, 0x0, 0x0,
		0x0, 0xC, 0x0, 0x0, 0x0, 0x0, 0xC, 0x0,
		0x0, 0xC, 0x0, 0x0, 0x0, 0x0, 0xC, 0x0,
		0x0, 0xC, 0x0, 0x0, 0x0, 0xC, 0x0, 0x0,
		0x0, 0xC, 0xC, 0xC, 0xC, 0x0, 0x0, 0x0,
		0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0
		},

		// E
		{
		0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
		0x0, 0xC, 0xC, 0xC, 0xC, 0xC, 0xC, 0x0,
		0x0, 0xC, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
		0x0, 0xC, 0xC, 0xC, 0xC, 0x0, 0x0, 0x0,
		0x0, 0xC, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
		0x0, 0xC, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
		0x0, 0xC, 0xC, 0xC, 0xC, 0xC, 0xC, 0x0,
		0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0
		},

		// F
		{
		0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
		0x0, 0xC, 0xC, 0xC, 0xC, 0xC, 0xC, 0x0,
		0x0, 0xC, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
		0x0, 0xC, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
		0x0, 0xC, 0xC, 0xC, 0xC, 0x0, 0x0, 0x0,
		0x0, 0xC, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
		0x0, 0xC, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
		0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0
		},

		// G
		{
		0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
		0x0, 0x0, 0xC, 0xC, 0xC, 0xC, 0x0, 0x0,
		0x0, 0xC, 0x0, 0x0, 0x0, 0x0, 0xC, 0x0,
		0x0, 0xC, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
		0x0, 0xC, 0x0, 0x0, 0x0, 0xC, 0xC, 0x0,
		0x0, 0xC, 0x0, 0x0, 0x0, 0x0, 0xC, 0x0,
		0x0, 0x0, 0xC, 0xC, 0xC, 0xC, 0xC, 0x0,
		0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0
		},

		// H
		{
		0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
		0x0, 0xC, 0x0, 0x0, 0x0, 0x0, 0xC, 0x0,
		0x0, 0xC, 0x0, 0x0, 0x0, 0x0, 0xC, 0x0,
		0x0, 0xC, 0xC, 0xC, 0xC, 0xC, 0xC, 0x0,
		0x0, 0xC, 0x0, 0x0, 0x0, 0x0, 0xC, 0x0,
		0x0, 0xC, 0x0, 0x0, 0x0, 0x0, 0xC, 0x0,
		0x0, 0xC, 0x0, 0x0, 0x0, 0x0, 0xC, 0x0,
		0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0
		},

		// I
		{
		0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
		0x0, 0xC, 0xC, 0xC, 0xC, 0xC, 0xC, 0x0,
		0x0, 0x0, 0x0, 0xC, 0x0, 0x0, 0x0, 0x0,
		0x0, 0x0, 0x0, 0xC, 0x0, 0x0, 0x0, 0x0,
		0x0, 0x0, 0x0, 0xC, 0x0, 0x0, 0x0, 0x0,
		0x0, 0x0, 0x0, 0xC, 0x0, 0x0, 0x0, 0x0,
		0x0, 0xC, 0xC, 0xC, 0xC, 0xC, 0xC, 0x0,
		0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0
		},

		// J
		{
		0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
		0x0, 0x0, 0xC, 0xC, 0xC, 0xC, 0xC, 0x0,
		0x0, 0x0, 0x0, 0x0, 0xC, 0x0, 0x0, 0x0,
		0x0, 0x0, 0x0, 0x0, 0xC, 0x0, 0x0, 0x0,
		0x0, 0xC, 0x0, 0x0, 0xC, 0x0, 0x0, 0x0,
		0x0, 0xC, 0x0, 0x0, 0xC, 0x0, 0x0, 0x0,
		0x0, 0x0, 0xC, 0xC, 0x0, 0x0, 0x0, 0x0,
		0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0
		},

		// K
		{
		0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
		0x0, 0xC, 0x0, 0x0, 0x0, 0x0, 0xC, 0x0,
		0x0, 0xC, 0x0, 0x0, 0x0, 0xC, 0x0, 0x0,
		0x0, 0xC, 0xC, 0xC, 0xC, 0x0, 0x0, 0x0,
		0x0, 0xC, 0x0, 0x0, 0x0, 0xC, 0x0, 0x0,
		0x0, 0xC, 0x0, 0x0, 0x0, 0x0, 0xC, 0x0,
		0x0, 0xC, 0x0, 0x0, 0x0, 0x0, 0xC, 0x0,
		0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0
		},

		// L
		{
		0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
		0x0, 0xC, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
		0x0, 0xC, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
		0x0, 0xC, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
		0x0, 0xC, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
		0x0, 0xC, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
		0x0, 0xC, 0xC, 0xC, 0xC, 0xC, 0xC, 0x0,
		0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0
		},

		// M
		{
		0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
		0x0, 0xC, 0x0, 0x0, 0x0, 0x0, 0xC, 0x0,
		0x0, 0xC, 0xC, 0x0, 0x0, 0xC, 0xC, 0x0,
		0x0, 0xC, 0x0, 0xC, 0xC, 0x0, 0xC, 0x0,
		0x0, 0xC, 0x0, 0x0, 0x0, 0x0, 0xC, 0x0,
		0x0, 0xC, 0x0, 0x0, 0x0, 0x0, 0xC, 0x0,
		0x0, 0xC, 0x0, 0x0, 0x0, 0x0, 0xC, 0x0,
		0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0
		},

		// N
		{
		0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
		0x0, 0xC, 0x0, 0x0, 0x0, 0x0, 0xC, 0x0,
		0x0, 0xC, 0xC, 0x0, 0x0, 0x0, 0xC, 0x0,
		0x0, 0xC, 0x0, 0xC, 0x0, 0x0, 0xC, 0x0,
		0x0, 0xC, 0x0, 0x0, 0xC, 0x0, 0xC, 0x0,
		0x0, 0xC, 0x0, 0x0, 0x0, 0xC, 0xC, 0x0,
		0x0, 0xC, 0x0, 0x0, 0x0, 0x0, 0xC, 0x0,
		0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0
		},

		// O
		{
		0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
		0x0, 0x0, 0xC, 0xC, 0xC, 0xC, 0x0, 0x0,
		0x0, 0xC, 0x0, 0x0, 0x0, 0x0, 0xC, 0x0,
		0x0, 0xC, 0x0, 0x0, 0x0, 0x0, 0xC, 0x0,
		0x0, 0xC, 0x0, 0x0, 0x0, 0x0, 0xC, 0x0,
		0x0, 0xC, 0x0, 0x0, 0x0, 0x0, 0xC, 0x0,
		0x0, 0x0, 0xC, 0xC, 0xC, 0xC, 0x0, 0x0,
		0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0
		},

		// P
		{
		0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
		0x0, 0xC, 0xC, 0xC, 0xC, 0xC, 0x0, 0x0,
		0x0, 0xC, 0x0, 0x0, 0x0, 0x0, 0xC, 0x0,
		0x0, 0xC, 0x0, 0x0, 0x0, 0x0, 0xC, 0x0,
		0x0, 0xC, 0xC, 0xC, 0xC, 0xC, 0x0, 0x0,
		0x0, 0xC, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
		0x0, 0xC, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
		0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0
		},

		// Q
		{
		0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
		0x0, 0x0, 0xC, 0xC, 0xC, 0x0, 0x0, 0x0,
		0x0, 0xC, 0x0, 0x0, 0x0, 0xC, 0x0, 0x0,
		0x0, 0xC, 0x0, 0x0, 0x0, 0xC, 0x0, 0x0,
		0x0, 0xC, 0x0, 0x0, 0x0, 0xC, 0x0, 0x0,
		0x0, 0xC, 0x0, 0x0, 0x0, 0xC, 0x0, 0x0,
		0x0, 0x0, 0xC, 0xC, 0xC, 0x0, 0xC, 0x0,
		0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0
		},

		// R
		{
		0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
		0x0, 0xC, 0xC, 0xC, 0xC, 0xC, 0x0, 0x0,
		0x0, 0xC, 0x0, 0x0, 0x0, 0x0, 0xC, 0x0,
		0x0, 0xC, 0x0, 0x0, 0x0, 0xC, 0xC, 0x0,
		0x0, 0xC, 0xC, 0xC, 0xC, 0xC, 0x0, 0x0,
		0x0, 0xC, 0x0, 0x0, 0x0, 0x0, 0xC, 0x0,
		0x0, 0xC, 0x0, 0x0, 0x0, 0x0, 0xC, 0x0,
		0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0
		},

		// S
		{
		0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
		0x0, 0x0, 0xC, 0xC, 0xC, 0xC, 0xC, 0x0,
		0x0, 0xC, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
		0x0, 0x0, 0xC, 0xC, 0xC, 0xC, 0x0, 0x0,
		0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xC, 0x0,
		0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xC, 0x0,
		0x0, 0xC, 0xC, 0xC, 0xC, 0xC, 0x0, 0x0,
		0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0
		},

		// T
		{
		0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
		0x0, 0xC, 0xC, 0xC, 0xC, 0xC, 0xC, 0x0,
		0x0, 0x0, 0x0, 0xC, 0x0, 0x0, 0x0, 0x0,
		0x0, 0x0, 0x0, 0xC, 0x0, 0x0, 0x0, 0x0,
		0x0, 0x0, 0x0, 0xC, 0x0, 0x0, 0x0, 0x0,
		0x0, 0x0, 0x0, 0xC, 0x0, 0x0, 0x0, 0x0,
		0x0, 0x0, 0x0, 0xC, 0x0, 0x0, 0x0, 0x0,
		0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0
		},

		// U
		{
		0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
		0x0, 0xC, 0x0, 0x0, 0x0, 0x0, 0xC, 0x0,
		0x0, 0xC, 0x0, 0x0, 0x0, 0x0, 0xC, 0x0,
		0x0, 0xC, 0x0, 0x0, 0x0, 0x0, 0xC, 0x0,
		0x0, 0xC, 0x0, 0x0, 0x0, 0x0, 0xC, 0x0,
		0x0, 0xC, 0x0, 0x0, 0x0, 0x0, 0xC, 0x0,
		0x0, 0x0, 0xC, 0xC, 0xC, 0xC, 0x0, 0x0,
		0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0
		},

		// V
		{
		0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
		0x0, 0xC, 0x0, 0x0, 0x0, 0x0, 0xC, 0x0,
		0x0, 0xC, 0x0, 0x0, 0x0, 0x0, 0xC, 0x0,
		0x0, 0xC, 0x0, 0x0, 0x0, 0x0, 0xC, 0x0,
		0x0, 0x0, 0xC, 0x0, 0x0, 0xC, 0x0, 0x0,
		0x0, 0x0, 0xC, 0x0, 0x0, 0xc, 0x0, 0x0,
		0x0, 0x0, 0x0, 0xC, 0xC, 0x0, 0x0, 0x0,
		0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0
		},

		// W
		{
		0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
		0x0, 0xC, 0x0, 0x0, 0x0, 0x0, 0xC, 0x0,
		0x0, 0xC, 0x0, 0x0, 0x0, 0x0, 0xC, 0x0,
		0x0, 0xC, 0x0, 0x0, 0x0, 0x0, 0xC, 0x0,
		0x0, 0xC, 0x0, 0x0, 0x0, 0x0, 0xC, 0x0,
		0x0, 0xC, 0x0, 0xC, 0xC, 0x0, 0xC, 0x0,
		0x0, 0x0, 0xC, 0x0, 0x0, 0xC, 0x0, 0x0,
		0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0
		},

		// X
		{
		0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
		0x0, 0xC, 0x0, 0x0, 0x0, 0x0, 0xC, 0x0,
		0x0, 0x0, 0xC, 0x0, 0x0, 0xC, 0x0, 0x0,
		0x0, 0x0, 0x0, 0xC, 0xC, 0x0, 0x0, 0x0,
		0x0, 0x0, 0x0, 0xC, 0xC, 0x0, 0x0, 0x0,
		0x0, 0x0, 0xC, 0x0, 0x0, 0xC, 0x0, 0x0,
		0x0, 0xC, 0x0, 0x0, 0x0, 0x0, 0xC, 0x0,
		0x0, 0xC, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0
		},

		// Y
		{
		0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
		0x0, 0xC, 0x0, 0x0, 0x0, 0x0, 0xC, 0x0,
		0x0, 0xC, 0x0, 0x0, 0x0, 0x0, 0xC, 0x0,
		0x0, 0x0, 0xC, 0xC, 0xC, 0xC, 0x0, 0x0,
		0x0, 0x0, 0x0, 0xC, 0x0, 0x0, 0x0, 0x0,
		0x0, 0x0, 0x0, 0xC, 0x0, 0x0, 0x0, 0x0,
		0x0, 0x0, 0x0, 0xC, 0x0, 0x0, 0x0, 0x0,
		0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0
		},

		// Z
		{
		0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
		0x0, 0xC, 0xC, 0xC, 0xC, 0xC, 0xC, 0x0,
		0x0, 0x0, 0xC, 0x0, 0x0, 0x0, 0x0, 0x0,
		0x0, 0x0, 0x0, 0xC, 0x0, 0x0, 0x0, 0x0,
		0x0, 0x0, 0x0, 0x0, 0xC, 0x0, 0x0, 0x0,
		0x0, 0x0, 0x0, 0x0, 0x0, 0xC, 0x0, 0x0,
		0x0, 0xC, 0xC, 0xC, 0xC, 0xC, 0xC, 0x0,
		0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0
		},

		// 0
		{
		0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
		0x0, 0x0, 0xC, 0xC, 0xC, 0xC, 0x0, 0x0,
		0x0, 0xC, 0x0, 0x0, 0x0, 0xC, 0xC, 0x0,
		0x0, 0xC, 0x0, 0x0, 0xC, 0x0, 0xC, 0x0,
		0x0, 0xC, 0x0, 0xC, 0x0, 0x0, 0xC, 0x0,
		0x0, 0xC, 0xC, 0x0, 0x0, 0x0, 0xC, 0x0,
		0x0, 0x0, 0xC, 0xC, 0xC, 0xC, 0x0, 0x0,
		0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0
		},

		// 1
		{
		0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
		0x0, 0x0, 0x0, 0x0, 0xC, 0x0, 0x0, 0x0,
		0x0, 0x0, 0x0, 0xC, 0xC, 0x0, 0x0, 0x0,
		0x0, 0x0, 0xC, 0x0, 0xC, 0x0, 0x0, 0x0,
		0x0, 0x0, 0x0, 0x0, 0xC, 0x0, 0x0, 0x0,
		0x0, 0x0, 0x0, 0x0, 0xC, 0x0, 0x0, 0x0,
		0x0, 0xC, 0xC, 0xC, 0xC, 0xC, 0xC, 0x0,
		0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0
		},

		// 2
		{
		0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
		0x0, 0x0, 0xC, 0xC, 0xC, 0xC, 0x0, 0x0,
		0x0, 0xC, 0x0, 0x0, 0x0, 0x0, 0xC, 0x0,
		0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xC, 0x0,
		0x0, 0x0, 0xC, 0xC, 0xC, 0xC, 0x0, 0x0,
		0x0, 0xC, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
		0x0, 0xC, 0xC, 0xC, 0xC, 0xC, 0xC, 0x0,
		0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0
		},

		// 3
		{
		0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
		0x0, 0xC, 0xC, 0xC, 0xC, 0xC, 0x0, 0x0,
		0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xC, 0x0,
		0x0, 0x0, 0x0, 0xC, 0xC, 0xC, 0x0, 0x0,
		0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xC, 0x0,
		0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xC, 0x0,
		0x0, 0xC, 0xC, 0xC, 0xC, 0xC, 0x0, 0x0,
		0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0
		},

		// 4
		{
		0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
		0x0, 0xC, 0x0, 0x0, 0x0, 0x0, 0xC, 0x0,
		0x0, 0xC, 0x0, 0x0, 0x0, 0x0, 0xC, 0x0,
		0x0, 0xC, 0x0, 0x0, 0x0, 0x0, 0xC, 0x0,
		0x0, 0xC, 0xC, 0xC, 0xC, 0xC, 0xC, 0x0,
		0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xC, 0x0,
		0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xC, 0x0,
		0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xC, 0x0
		},

		// 5
		{
		0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
		0x0, 0xC, 0xC, 0xC, 0xC, 0xC, 0xC, 0x0,
		0x0, 0xC, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
		0x0, 0xC, 0xC, 0xC, 0xC, 0xC, 0x0, 0x0,
		0x0, 0xC, 0x0, 0x0, 0x0, 0x0, 0xC, 0x0,
		0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xC, 0x0,
		0x0, 0xC, 0xC, 0xC, 0xC, 0xC, 0x0, 0x0,
		0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0
		},

		// 6
		{
		0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
		0x0, 0x0, 0xC, 0xC, 0xC, 0xC, 0x0, 0x0,
		0x0, 0xC, 0x0, 0x0, 0x0, 0x0, 0xC, 0x0,
		0x0, 0xC, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
		0x0, 0xC, 0xC, 0xC, 0xC, 0xC, 0x0, 0x0,
		0x0, 0xC, 0x0, 0x0, 0x0, 0x0, 0xC, 0x0,
		0x0, 0x0, 0xC, 0xC, 0xC, 0xC, 0x0, 0x0,
		0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0
		},

		// 7
		{
		0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
		0x0, 0xC, 0xC, 0xC, 0xC, 0xC, 0xC, 0x0,
		0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xC, 0x0,
		0x0, 0x0, 0x0, 0x0, 0x0, 0xC, 0x0, 0x0,
		0x0, 0x0, 0x0, 0x0, 0xC, 0x0, 0x0, 0x0,
		0x0, 0x0, 0x0, 0xC, 0x0, 0x0, 0x0, 0x0,
		0x0, 0x0, 0xC, 0x0, 0x0, 0x0, 0x0, 0x0,
		0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0
		},

		// 8
		{
		0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
		0x0, 0x0, 0xC, 0xC, 0xC, 0xC, 0x0, 0x0,
		0x0, 0xC, 0x0, 0x0, 0x0, 0x0, 0xC, 0x0,
		0x0, 0x0, 0xC, 0xC, 0xC, 0xC, 0x0, 0x0,
		0x0, 0xC, 0x0, 0x0, 0x0, 0x0, 0xC, 0x0,
		0x0, 0xC, 0x0, 0x0, 0x0, 0x0, 0xC, 0x0,
		0x0, 0x0, 0xC, 0xC, 0xC, 0xC, 0x0, 0x0,
		0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0
		},

		// 9
		{
		0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
		0x0, 0x0, 0xC, 0xC, 0xC, 0xC, 0x0, 0x0,
		0x0, 0xC, 0x0, 0x0, 0x0, 0x0, 0xC, 0x0,
		0x0, 0x0, 0xC, 0xC, 0xC, 0xC, 0xC, 0x0,
		0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xC, 0x0,
		0x0, 0xC, 0x0, 0x0, 0x0, 0x0, 0xC, 0x0,
		0x0, 0xC, 0xC, 0xC, 0xC, 0xC, 0x0, 0x0,
		0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0
		},

		// -
		{
		0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
		0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
		0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
		0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
		0x0, 0x0, 0xC, 0xC, 0xC, 0xC, 0x0, 0x0,
		0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
		0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
		0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0
		},

};

#endif /* COLORPALETTE_H_ */

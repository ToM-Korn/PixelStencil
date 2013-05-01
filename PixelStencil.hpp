/*
 * PixelStencil
 * Copyright (C) 2013 Amir Hassan <amir@viel-zu.org>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */


#ifndef PIXELSTENCIL_HPP_
#define PIXELSTENCIL_HPP_

#include "CImg.h"
#include <stdint.h>
#include <string>
#include <map>
#include <vector>
#include <iostream>
#include <fstream>
#include <boost/format.hpp>

namespace kallaballa
{
using namespace cimg_library;
using std::string;
using std::map;
using std::vector;
using std::ostream;

typedef unsigned char sample_t;
typedef std::pair<int32_t,int32_t> Pixel;
typedef std::vector<Pixel> PixelList;
typedef std::map<long, std::vector<Pixel> > PixelMap;

float PIXEL_TO_MM = 3.52112676056;

class PixelPlanes {
	CImg<sample_t> img;
	size_t width;
	size_t height;
	PixelMap planes;
public:
	typedef PixelMap::iterator iterator;

	PixelPlanes(char* filename);
	virtual ~PixelPlanes();

	iterator begin() {
		return planes.begin();
	}

	iterator end() {
		return planes.end();
	}

	size_t getWidth() {
		return width;
	}

	size_t getHeight() {
		return height;
	}
};

class SVGStencil {
	std::ofstream ofs;
	size_t rectWidthMM = 20;
	size_t rectMarginMM = 20;
	size_t boardMarginMM = 20;
	size_t rectID = 0;

	void writeHeader(size_t widthMM, size_t heightMM);
	void writeFooter();
public:
	SVGStencil(const char* filename, size_t width, size_t height, size_t rectWidth, size_t rectMargin, size_t boardMargin) ;
	virtual ~SVGStencil();

	void writePixel(size_t x, size_t y);
};
}

/* namespace kallaballa */
#endif /* PIXELSTENCIL_HPP_ */

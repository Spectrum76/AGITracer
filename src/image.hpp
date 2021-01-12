#pragma once

/****************************************************************************/

/****************************************************************************/
/*                                                                          */
/*                                                                          */
/*                            IMAGE CLASS                                   */
/*                                                                          */
/*                                                                          */
/****************************************************************************/

/****************************************************************************/

#include <vector>
#include "vec.hpp"

/****************************************************************************/

template <typename T>
class Image
{
public:
	Image() : width(0), height(0) {}

	Image(int width, int height) 
		: width(width), height(height), e(width*height) {}

	int w() const { return width; }
	int h() const { return height; }
	int n() const { return (int)e.size(); }

	const T& operator[](int i) const {return e[i];}
	T& operator[](int i) {return e[i];}
	const T& operator()(int x, int y) const {return e[x+y*width];}
	T& operator()(int x, int y) {return e[x+y*width];}

	void resize(int width, int height)
	{
		this->width = width;
		this->height = height;
		e.resize(width*height);
	}

private:
	int width;
	int height;

	std::vector<T> e;
};

/****************************************************************************/
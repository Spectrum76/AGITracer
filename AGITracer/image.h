#pragma once

#include <vector>
#include "vec3.h"

template <class T>
class image
{
public:
	image(int width, int height);
	vec3<T> operator()(int x, int y);
	std::vector<vec3<T>>& operator[](int x);

private:
	const int image_width;
	const int image_height;

	std::vector<unsigned char> data;
	std::vector<std::vector<vec3<T>>> texture;
};

template<class T>
inline image<T>::image(int width, int height) : image_width(width), image_height(height)
{
	texture.resize(height);

	for (size_t i = 0; i < texture.size(); i++)
	{
		texture[i].resize(width);
	}
}

template<class T>
inline vec3<T> image<T>::operator()(int x, int y)
{
	return texture[x][y];
}

template<class T>
inline std::vector<vec3<T>>& image<T>::operator[](int x)
{
	return texture[x];
}

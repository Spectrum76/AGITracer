#include "vec3.h"
#include "image.h"

int main()
{
	vec3<float> vect;
	image<float> text(800, 600);

	text[0][0] = vec3<float>(2, 3, 4);
	vect = text(0, 0);

	vect += vec3<float>(4, 3, 2);

	text[0][0] = vect;

	return EXIT_SUCCESS;
}
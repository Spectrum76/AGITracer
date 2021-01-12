/****************************************************************************/

/****************************************************************************/
/*                                                                          */
/*                                                                          */
/*                               MAIN PROGRAM                               */
/*                                                                          */
/*                                                                          */
/****************************************************************************/

/****************************************************************************/

#include <chrono>
#include <omp.h>
#include "vec.hpp"
#include "image.hpp"
#include "tigr.h"

/****************************************************************************/

struct Shaders
{						        
	vec3	     iResolution;           /* image/buffer         The viewport resolution (z is pixel aspect ratio, usually 1.0)*/
	float	     iTime;	                /* image/sound/buffer   Current time in seconds */
	float	     iTimeDelta;            /* image/buffer	        Time it takes to render a frame, in seconds */
	int	         iFrame;                /* image/buffer	        Current frame */
	float	     iFrameRate;	        /* image/buffer	        Number of frames rendered per second */
	float	     iChannelTime[4]; 	    /* image/buffer	        Time for channel (if video or sound), in seconds */
	vec3	     iChannelResolution[4]; /* image/buffer/sound   Input texture resolution for each channel */
	vec4	     iMouse;	            /* image/buffer	        xy = current pixel coords (if LMB is down). zw = click pixel */
	Image<vec4>* iChannel[4];	        /* image/buffer/sound	Sampler for input textures */
	vec4	     iDate;	                /* image/buffer/sound   Year, month, day, time in seconds in .xyzw */
	float	     iSampleRate;	        /* image/buffer/sound	The sound sample rate (typically 44100) */

	void image_shader(vec4& fragColor, const vec2& fragCoord) const;
};

/****************************************************************************/

void Shaders::image_shader(vec4& fragColor, const vec2& fragCoord) const
{
    // Normalized pixel coordinates (from 0 to 1)
    vec2 uv = fragCoord/iResolution.xy;

    // Time varying pixel color
    vec3 col = vec3(0.5) + 0.5*cos(vec3(iTime)+vec3(uv, uv.x)+vec3(0,2,4));

    // Output to screen
    fragColor = vec4(col,1.0);
}

/****************************************************************************/

struct ShadertoyState
{
	int width;
	int height;

	Image<vec4>  bufferA[2];
	Image<vec4>* bufferA_prev;
	Image<vec4>* bufferA_curr;
	Image<vec4>* bufferA_attached;

	Image<vec4>  bufferB[2];
	Image<vec4>* bufferB_prev;
	Image<vec4>* bufferB_curr;
	Image<vec4>* bufferB_attached;

	Image<vec4>  bufferC[2];
	Image<vec4>* bufferC_prev;
	Image<vec4>* bufferC_curr;
	Image<vec4>* bufferC_attached;

	Image<vec4>  bufferD[2];
	Image<vec4>* bufferD_prev;
	Image<vec4>* bufferD_curr;
	Image<vec4>* bufferD_attached;

	Image<vec4>  image;

	std::chrono::high_resolution_clock clock;
	std::chrono::high_resolution_clock::time_point time_point;
	Shaders shaders;

	void init(int w, int h)
	{
		width = w;
		height = h;

		image.resize(w,h);

		bufferA[0].resize(w,h);
		bufferA[1].resize(w,h);
		bufferA_prev = &(bufferA[0]);
		bufferA_curr = &(bufferA[1]);

		bufferB[0].resize(w,h);
		bufferB[1].resize(w,h);
		bufferB_prev = &(bufferB[0]);
		bufferB_curr = &(bufferB[1]);

		bufferC[0].resize(w,h);
		bufferC[1].resize(w,h);
		bufferC_prev = &(bufferC[0]);
		bufferC_curr = &(bufferC[1]);

		bufferD[0].resize(w,h);
		bufferD[1].resize(w,h);
		bufferD_prev = &(bufferD[0]);
		bufferD_curr = &(bufferD[1]);

		time_point = clock.now();
	}

	void run()
	{
		#pragma omp parallel for
		for (int y=0; y<height; ++y)
			for (int x=0; x<width; ++x)
				shaders.image_shader(image(x,y), vec2(x,y));
	}

	void upate_shaders()
	{
		shaders.iTime = std::chrono::duration<float>(clock.now() - time_point).count();
		shaders.iResolution = vec3(width, height, 1);
	}
};

/****************************************************************************/

vec4 gamma_compress(vec4 v)
{
	return vec4(powf(v[0], 1.0/2.2f), 
				powf(v[1], 1.0/2.2f), 
				powf(v[2], 1.0/2.2f), 
				powf(v[3], 1.0/2.2f));
}

/****************************************************************************/

template<typename T>
T clamp(const T& x, const T& a, const T& b)
{
	return x < a ? a : x > b ? b : x;
}

/****************************************************************************/

using u8 = unsigned char;

void to_tigr(const Image<vec4>& src, Tigr* buff)
{
	for (int y=0; y<src.h(); ++y)
	{
		for (int x=0; x<src.w(); ++x)
		{
			vec4 v = gamma_compress(src(x,y));
			buff->pix[x+y*src.w()].r = (u8)clamp((int)(256.0*v[0]), 0, 255);
			buff->pix[x+y*src.w()].g = (u8)clamp((int)(256.0*v[1]), 0, 255);
			buff->pix[x+y*src.w()].b = (u8)clamp((int)(256.0*v[2]), 0, 255);
			buff->pix[x+y*src.w()].a = (u8)clamp((int)(256.0*v[3]), 0, 255);
		}
	}
}

/****************************************************************************/

int main(int argc, char *argv[])
{
	const int w = 640;
	const int h = 480;

	ShadertoyState state;
	state.init(w,h);



	Tigr* back_buffer = tigrBitmap(w, h);


    Tigr *screen = tigrWindow(w, h, "Hello", 0);
    while (!tigrClosed(screen))
    {
		state.upate_shaders();
		state.run();
		to_tigr(state.image, back_buffer);
        tigrClear(screen, tigrRGB(0x80, 0x90, 0xa0));
		tigrBlit (screen, back_buffer, 0, 0, 0, 0, w, h);
        tigrPrint(screen, tfont, 120, 110, tigrRGB(0xff, 0xff, 0xff), "Hello, world.");
        tigrUpdate(screen);
    }
    tigrFree(screen);
    return 0;
}

/****************************************************************************/
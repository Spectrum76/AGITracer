#pragma once

/****************************************************************************/

/****************************************************************************/
/*                                                                          */
/*                                                                          */
/*                           GLSL-LIKE VECTOR CLASS                         */
/*                                                                          */
/*                                                                          */
/****************************************************************************/

/****************************************************************************/

#include <cmath>
#include <cstdint>

/****************************************************************************/

template <typename T>
class tvec2
{

public:
	union 
	{
		T e[2];
		struct
		{
			T x, y;
		};
	};

public:
	tvec2() : e{0,0} {}
	tvec2(const T& s) : e{s, s} {}
	tvec2(const T& e0, const T& e1) : e{e0, e1} {}


	/* unary operators */
	tvec2& operator+() {return *this; }
	const tvec2& operator+() const {return *this; }
	tvec2 operator-() const { return tvec3(-e[0], -e[1], -e[2]); }
	const T& operator[](int i) const { return e[i]; }
	T& operator[](int i) { return e[i]; }

	/* binary operators */
	tvec2& operator=(const tvec2& v)
	{
		e[0] = v.e[0];
		e[1] = v.e[1];

		return *this;
	}

	tvec2& operator+=(const tvec2& v)
	{
		e[0] += v.e[0];
		e[1] += v.e[1];

		return *this;
	}

	tvec2& operator-=(const tvec2& v)
	{
		e[0] -= v.e[0];
		e[1] -= v.e[1];

		return *this;
	}

	tvec2& operator*=(const tvec2& v)
	{
		e[0] *= v.e[0];
		e[1] *= v.e[1];

		return *this;
	}

	tvec2& operator/=(const tvec2& v)
	{
		e[0] /= v.e[0];
		e[1] /= v.e[1];

		return *this;
	}

	tvec2& operator*=(const T& s)
	{
		e[0] *= s;
		e[1] *= s;

		return *this;
	}

	tvec2& operator/=(const T& s)
	{
		e[0] /= s;
		e[1] /= s;

		return *this;
	}

};

/****************************************************************************/

template <typename T>
class tvec3
{

public:
	union 
	{
		T e[3];
		struct
		{
			T x, y, z;
		};
		struct
		{
			tvec2<T> xy;
			T z;
		};
		struct
		{
			T x;
			tvec2<T> yz;
		};
	};

public:
	tvec3() : e{0,0,0} {}
	tvec3(const T& s) : e{s, s, s} {}
	tvec3(const T& e0, const T& e1, const T& e2) : e{e0, e1, e2} {}
	tvec3(const T& e0, tvec2<T>& e12) : e{e0, e12[0], e12[1]} {}
	tvec3(const tvec2<T>& e01, T& e2) : e{e01[0], e01[1], e2} {}

	/* unary operators */
	tvec3& operator+() {return *this; }
	const tvec3& operator+() const {return *this; }
	tvec3 operator-() const { return tvec3(-e[0], -e[1], -e[2]); }
	const T& operator[](int i) const { return e[i]; }
	T& operator[](int i) { return e[i]; }

	/* binary operators */
	tvec3& operator=(const tvec3& v)
	{
		e[0] = v.e[0];
		e[1] = v.e[1];
		e[2] = v.e[2];

		return *this;
	}

	tvec3& operator+=(const tvec3& v)
	{
		e[0] += v.e[0];
		e[1] += v.e[1];
		e[2] += v.e[2];

		return *this;
	}

	tvec3& operator-=(const tvec3& v)
	{
		e[0] -= v.e[0];
		e[1] -= v.e[1];
		e[2] -= v.e[2];

		return *this;
	}

	tvec3& operator*=(const tvec3& v)
	{
		e[0] *= v.e[0];
		e[1] *= v.e[1];
		e[2] *= v.e[2];

		return *this;
	}

	tvec3& operator/=(const tvec3& v)
	{
		e[0] /= v.e[0];
		e[1] /= v.e[1];
		e[2] /= v.e[2];

		return *this;
	}

	tvec3& operator*=(const T& s)
	{
		e[0] *= s;
		e[1] *= s;
		e[2] *= s;

		return *this;
	}

	tvec3& operator/=(const T& s)
	{
		e[0] /= s;
		e[1] /= s;
		e[2] /= s;

		return *this;
	}

};

/****************************************************************************/

template <typename T>
class tvec4
{

public:
	union 
	{
		T e[4];
		struct
		{
			T x, y, z, w;
		};
		struct
		{
			tvec3<T> xyz;
			T w;
		};
		struct
		{
			tvec2<T> xy;
			tvec2<T> zw;
		};
		struct
		{
			T x;
			tvec3<T> yzw;
		};
		struct
		{
			T x;
			tvec2<T> yz;
			T w;
		};
	};

public:
	tvec4() : e{0,0,0,0} {}
	tvec4(const T& s) : e{s, s, s, s} {}
	tvec4(const T& e0, const T& e1, const T& e2, const T& e3) : e{e0, e1, e2, e3} {}
	tvec4(const tvec3<T>& e012, const T& e3) : e{e012[0], e012[1], e012[2], e3} {}
	tvec4(const tvec2<T>& e01, const T& e2, const T& e3) : e{e01[0], e01[1], e2, e3} {}
	tvec4(const tvec2<T>& e01, const tvec2<T>& e23) : e{e01[0], e01[1], e23[0], e23[1]} {}
	tvec4(const T& e0, const T& e1, const tvec2<T>& e23) : e{e0, e1, e23[0], e23[1]} {}
	tvec4(const T& e0, const tvec3<T>& e123) : e{e0, e123[0], e123[1], e123[2]} {}

	/* unary operators */
	tvec4& operator+() {return *this; }
	const tvec4& operator+() const {return *this; }
	tvec4 operator-() const { return tvec4(-e[0], -e[1], -e[2]); }
	const T& operator[](int i) const { return e[i]; }
	T& operator[](int i) { return e[i]; }

	/* binary operators */
	tvec4& operator=(const tvec4& v)
	{
		e[0] = v.e[0];
		e[1] = v.e[1];
		e[2] = v.e[2];
		e[3] = v.e[3];

		return *this;
	}

	tvec4& operator+=(const tvec4& v)
	{
		e[0] += v.e[0];
		e[1] += v.e[1];
		e[2] += v.e[2];
		e[3] += v.e[3];

		return *this;
	}

	tvec4& operator-=(const tvec4& v)
	{
		e[0] -= v.e[0];
		e[1] -= v.e[1];
		e[2] -= v.e[2];
		e[3] -= v.e[3];

		return *this;
	}

	tvec4& operator*=(const tvec4& v)
	{
		e[0] *= v.e[0];
		e[1] *= v.e[1];
		e[2] *= v.e[2];
		e[3] *= v.e[3];

		return *this;
	}

	tvec4& operator/=(const tvec4& v)
	{
		e[0] /= v.e[0];
		e[1] /= v.e[1];
		e[2] /= v.e[2];
		e[3] /= v.e[3];

		return *this;
	}

	tvec4& operator*=(const T& s)
	{
		e[0] *= s;
		e[1] *= s;
		e[2] *= s;
		e[3] *= s;

		return *this;
	}

	tvec4& operator/=(const T& s)
	{
		e[0] /= s;
		e[1] /= s;
		e[2] /= s;
		e[3] /= s;

		return *this;
	}

};

/****************************************************************************/

using vec2 = tvec2<float>;
using vec3 = tvec3<float>;
using vec4 = tvec4<float>;

using ivec2 = tvec2<int>;
using ivec3 = tvec3<int>;
using ivec4 = tvec4<int>;

using uint = uint32_t;
using uvec2 = tvec2<uint>;
using uvec3 = tvec3<uint>;
using uvec4 = tvec4<uint>;

/****************************************************************************/

template<typename T>
tvec2<T> operator+(const tvec2<T>& lhs, const tvec2<T>& rhs)
{
	return tvec2<T>(lhs[0]+rhs[0], lhs[1]+rhs[1]);
}

/****************************************************************************/

template<typename T>
tvec3<T> operator+(const tvec3<T>& lhs, const tvec3<T>& rhs)
{
	return tvec3<T>(lhs[0]+rhs[0], lhs[1]+rhs[1], lhs[2]+rhs[2]);
}

/****************************************************************************/

template<typename T>
tvec4<T> operator+(const tvec4<T>& lhs, const tvec4<T>& rhs)
{
	return tvec4<T>(lhs[0]+rhs[0], lhs[1]+rhs[1], lhs[2]+rhs[2], lhs[3]+rhs[3]);
}

/****************************************************************************/

template<typename T>
tvec2<T> operator-(const tvec2<T>& lhs, const tvec2<T>& rhs)
{
	return tvec2<T>(lhs[0]-rhs[0], lhs[1]-rhs[1]);
}

/****************************************************************************/

template<typename T>
tvec3<T> operator-(const tvec3<T>& lhs, const tvec3<T>& rhs)
{
	return tvec3<T>(lhs[0]-rhs[0], lhs[1]-rhs[1], lhs[2]-rhs[2]);
}

/****************************************************************************/

template<typename T>
tvec4<T> operator-(const tvec4<T>& lhs, const tvec4<T>& rhs)
{
	return tvec4<T>(lhs[0]-rhs[0], lhs[1]-rhs[1], lhs[2]-rhs[2], lhs[3]-rhs[3]);
}

/****************************************************************************/

template<typename T>
tvec2<T> operator*(const tvec2<T>& lhs, const tvec2<T>& rhs)
{
	return tvec2<T>(lhs[0]*rhs[0], lhs[1]*rhs[1]);
}

/****************************************************************************/

template<typename T>
tvec3<T> operator*(const tvec3<T>& lhs, const tvec3<T>& rhs)
{
	return tvec3<T>(lhs[0]*rhs[0], lhs[1]*rhs[1], lhs[2]*rhs[2]);
}

/****************************************************************************/

template<typename T>
tvec4<T> operator*(const tvec4<T>& lhs, const tvec4<T>& rhs)
{
	return tvec4<T>(lhs[0]*rhs[0], lhs[1]*rhs[1], lhs[2]*rhs[2], lhs[3]*rhs[3]);
}

/****************************************************************************/

template<typename T>
tvec2<T> operator/(const tvec2<T>& lhs, const tvec2<T>& rhs)
{
	return tvec2<T>(lhs[0]/rhs[0], lhs[1]/rhs[1]);
}

/****************************************************************************/

template<typename T>
tvec3<T> operator/(const tvec3<T>& lhs, const tvec3<T>& rhs)
{
	return tvec3<T>(lhs[0]/rhs[0], lhs[1]/rhs[1], lhs[2]/rhs[2]);
}

/****************************************************************************/

template<typename T>
tvec4<T> operator/(const tvec4<T>& lhs, const tvec4<T>& rhs)
{
	return tvec4<T>(lhs[0]/rhs[0], lhs[1]/rhs[1], lhs[2]/rhs[2], lhs[3]/rhs[3]);
}

/****************************************************************************/

template<typename T, typename U>
tvec2<T> operator*(const tvec2<T>& lhs, const U& rhs)
{
	return tvec2<T>(lhs[0]*rhs, lhs[1]*rhs);
}

/****************************************************************************/

template<typename T, typename U>
tvec3<T> operator*(const tvec3<T>& lhs, const U& rhs)
{
	return tvec3<T>(lhs[0]*rhs, lhs[1]*rhs, lhs[2]*rhs);
}

/****************************************************************************/

template<typename T, typename U>
tvec4<T> operator*(const tvec4<T>& lhs, const U& rhs)
{
	return tvec4<T>(lhs[0]*rhs, lhs[1]*rhs, lhs[2]*rhs, lhs[3]*rhs);
}

/****************************************************************************/

template<typename T, typename U>
tvec2<T> operator*(const U& lhs, const tvec2<T>& rhs)
{
	return tvec2<T>(lhs*rhs[0], lhs*rhs[1]);
}

/****************************************************************************/

template<typename T, typename U>
tvec3<T> operator*(const U& lhs, const tvec3<T>& rhs)
{
	return tvec3<T>(lhs*rhs[0], lhs*rhs[1], lhs*rhs[2]);
}

/****************************************************************************/

template<typename T, typename U>
tvec4<T> operator*(const U& lhs, const tvec4<T>& rhs)
{
	return tvec4<T>(lhs*rhs[0], lhs*rhs[1], lhs*rhs[2], lhs*rhs[3]);
}

/****************************************************************************/

template<typename T>
tvec2<T> operator/(const tvec2<T>& lhs, const T& rhs)
{
	return tvec2<T>(lhs[0]/rhs, lhs[1]/rhs);
}

/****************************************************************************/

template<typename T>
tvec3<T> operator/(const tvec3<T>& lhs, const T& rhs)
{
	return tvec3<T>(lhs[0]/rhs, lhs[1]/rhs, lhs[2]/rhs);
}

/****************************************************************************/

template<typename T>
tvec4<T> operator/(const tvec4<T>& lhs, const T& rhs)
{
	return tvec4<T>(lhs[0]/rhs, lhs[1]/rhs, lhs[2]/rhs, lhs[3]/rhs);
}

/****************************************************************************/


template<typename T>
tvec2<T> operator/(const T& lhs, const tvec2<T>& rhs)
{
	return tvec2<T>(lhs/rhs[0], lhs/rhs[1]);
}

/****************************************************************************/

template<typename T>
tvec3<T> operator/(const T& lhs, const tvec3<T>& rhs)
{
	return tvec3<T>(lhs/rhs[0], lhs/rhs[1], lhs/rhs[2]);
}

/****************************************************************************/

template<typename T>
tvec4<T> operator/(const T& lhs, const tvec4<T>& rhs)
{
	return tvec4<T>(lhs/rhs[0], lhs/rhs[1], lhs/rhs[2], lhs/rhs[3]);
}

/****************************************************************************/

template<typename T>
T dot (const tvec2<T>& lhs, const tvec2<T>& rhs)
{
	return lhs[0]*rhs[0] + lhs[1]*rhs[1];
}

/****************************************************************************/

template<typename T>
T dot (const tvec3<T>& lhs, const tvec3<T>& rhs)
{
	return lhs[0]*rhs[0] + lhs[1]*rhs[1] + lhs[2]*rhs[2];
}

/****************************************************************************/

template<typename T>
T dot (const tvec4<T>& lhs, const tvec4<T>& rhs)
{
	return lhs[0]*rhs[0] + lhs[1]*rhs[1] + lhs[2]*rhs[2] + lhs[3]*rhs[3];
}

/****************************************************************************/

template<typename T>
tvec3<T> cross(const tvec3<T>& lhs, const tvec3<T>& rhs)
{
	return tvec3<T>(lhs[1]*rhs[2]-lhs[2]*rhs[1], 
					lhs[2]*rhs[0]-lhs[0]*rhs[2], 
					lhs[0]*rhs[1]-lhs[1]*rhs[0]);
}

/****************************************************************************/

template<typename T>
T length_squared (const tvec2<T>& v)
{
	return dot(v,v);
}

/****************************************************************************/

template<typename T>
T length_squared (const tvec3<T>& v)
{
	return dot(v,v);
}

/****************************************************************************/

template<typename T>
T length_squared (const tvec4<T>& v)
{
	return dot(v,v);
}

/****************************************************************************/

template<typename T>
T length (const tvec2<T>& v)
{
	return sqrt(dot(v,v));
}

/****************************************************************************/

template<typename T>
T length (const tvec3<T>& v)
{
	return sqrt(dot(v,v));
}

/****************************************************************************/

template<typename T>
T length (const tvec4<T>& v)
{
	return sqrt(dot(v,v));
}

/****************************************************************************/

template<typename T>
tvec2<T> normalize(const tvec2<T>& v)
{
	return v/length(v);
}

/****************************************************************************/

template<typename T>
tvec3<T> normalize(const tvec3<T>& v)
{
	return v/length(v);
}

/****************************************************************************/

template<typename T>
tvec4<T> normalize(const tvec4<T>& v)
{
	return v/length(v);
}

/****************************************************************************/

template<typename T>
tvec2<T> cos (const tvec2<T>& v)
{
	return tvec2<T>(std::cos(v[0]), 
					std::cos(v[1]));
}

/****************************************************************************/

template<typename T>
tvec3<T> cos (const tvec3<T>& v)
{
	return tvec3<T>(std::cos(v[0]), 
					std::cos(v[1]), 
					std::cos(v[2]));
}

/****************************************************************************/

template<typename T>
tvec4<T> cos (const tvec4<T>& v)
{
	return tvec4<T>(std::cos(v[0]), 
					std::cos(v[1]), 
					std::cos(v[2]), 
					std::cos(v[3]));
}

/****************************************************************************/
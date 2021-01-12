#pragma once

#include <cmath>

template <class T>
class vec3
{
public:
	vec3();
	vec3(T e0, T e1, T e2);

	T x() const;
	T y() const;
	T z() const;

	vec3 operator-() const;
	T operator[](int i) const;
	T& operator[](int i);

	vec3& operator+=(const vec3& v);

	vec3& operator*=(const T t);

	vec3& operator/=(const T t);

	T length() const;

	T length_squared() const;

	T dot(const vec3& u, const vec3& v);

	vec3 cross(const vec3& u, const vec3& v);

	vec3 unit_vector(vec3 v);

private:
	T e[3];
};

template<class T>
inline vec3<T>::vec3() : e{ 0, 0, 0 }
{
}

template<class T>
inline vec3<T>::vec3(T e0, T e1, T e2) : e{ e0,e1,e2 }
{
}

template<class T>
inline T vec3<T>::x() const
{
	return e[0];
}

template<class T>
inline T vec3<T>::y() const
{
	return e[1];
}

template<class T>
inline T vec3<T>::z() const
{
	return e[2];
}

template<class T>
inline vec3<T> vec3<T>::operator-() const
{
	return vec3(-e[0], -e[1], -e[2]);
}

template<class T>
inline T vec3<T>::operator[](int i) const
{
	return e[i];
}

template<class T>
inline T& vec3<T>::operator[](int i)
{
	return e[i];
}

template<class T>
inline vec3<T>& vec3<T>::operator+=(const vec3& v)
{
	e[0] += v.e[0];
	e[1] += v.e[1];
	e[2] += v.e[2];
	return *this;
}

template<class T>
inline vec3<T>& vec3<T>::operator*=(const T t)
{
	e[0] *= t;
	e[1] *= t;
	e[2] *= t;
	return *this;
}

template<class T>
inline vec3<T>& vec3<T>::operator/=(const T t)
{
	return *this *= 1 / t;
}

template<class T>
inline T vec3<T>::length() const
{
	return sqrt(length_squared());
}

template<class T>
inline T vec3<T>::length_squared() const
{
	return e[0] * e[0] + e[1] * e[1] + e[2] * e[2];
}

template<class T>
inline T vec3<T>::dot(const vec3& u, const vec3& v)
{
	return u.e[0] * v.e[0] + u.e[1] * v.e[1] + u.e[2] * v.e[2];
}

template<class T>
inline vec3<T> vec3<T>::cross(const vec3& u, const vec3& v)
{
	return vec3(u.e[1] * v.e[2] - u.e[2] * v.e[1],
		u.e[2] * v.e[0] - u.e[0] * v.e[2],
		u.e[0] * v.e[1] - u.e[1] * v.e[0]);
}

template<class T>
inline vec3<T> vec3<T>::unit_vector(vec3 v)
{
	return v / v.length();
}

template<class T>
inline vec3<T> operator+(const vec3<T>& u, const vec3<T>& v)
{
	return vec3<T>(u.e[0] + v.e[0], u.e[1] + v.e[1], u.e[2] + v.e[2]);
}

template<class T>
inline vec3<T> operator-(const vec3<T>& u, const vec3<T>& v)
{

}

template<class T>
inline vec3<T> operator*(const vec3<T>& u, const vec3<T>& v)
{

}

template<class T>
inline vec3<T> operator*(T t, const vec3<T>& v)
{
	return vec3<T>(t * v.e[0], t * v.e[1], t * v.e[2]);
}

template<class T>
inline vec3<T> operator*(const vec3<T>& v, T t)
{
	return t * v;
}

template<class T>
inline vec3<T> operator/(vec3<T> v, T t)
{
	return (1 / t) * v;
}
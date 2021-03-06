#include "Vector2.h"
#include <math.h>


namespace GameDev2D
{
    //Initialize the static ZeroVector and UnitVector variables
    const Vector2 Vector2::Zero = Vector2(0.0f, 0.0f);
    const Vector2 Vector2::Unit = Vector2(1.0f, 1.0f);

	const Vector2 Vector2::Left = Vector2(-1.0f, 0.0f);
	const Vector2 Vector2::Right = Vector2(1.0f, 0.0f);
	const Vector2 Vector2::Up = Vector2(0.0f, 1.0f);
	const Vector2 Vector2::Down = Vector2(0.0f, -1.0f);

    Vector2::Vector2(float x, float y) :
        x(x),
        y(y)
    {}

    Vector2::Vector2(const Vector2& vector2) :
        x(vector2.x),
        y(vector2.y)
    {}

    Vector2::Vector2() :
        x(0.0f),
        y(0.0f)
    {}

    Vector2 Vector2::Min(const Vector2& a, const Vector2& b)
    {
        return Vector2(fminf(a.x, b.x), fminf(a.y, b.y));
    }

    Vector2 Vector2::Max(const Vector2& a, const Vector2& b)
    {
        return Vector2(fmaxf(a.x, b.x), fmaxf(a.y, b.y));
    }

    void Vector2::Set(float x, float y)
    {
        this->x = x;
        this->y = y;
    }

    float Vector2::Angle()
    {
		float radians = fmodf((atan2f(y, x) + static_cast<float>(M_PI) * 4.0f), static_cast<float>(M_PI) * 2.0f);
        return radians;
    }

    float Vector2::Length()
    {
        return sqrtf(LengthSquared());
    }

    float Vector2::LengthSquared()
    {
        return x * x + y * y;
    }

    void Vector2::Normalize()
    {
        float length = LengthSquared();
        if (length != 0)
        {
            length = sqrtf(length);
            x /= length;
            y /= length;
        }
    }

    Vector2 Vector2::Normalized()
    {
        Vector2 vector2(x, y);
        vector2.Normalize();
        return vector2;
    }

    float Vector2::Distance(const Vector2& aVector) const
    {
        return sqrtf(DistanceSquared(aVector));
    }

    float Vector2::DistanceSquared(const Vector2& aVector) const
    {
        return (x - aVector.x) * (x - aVector.x) + (y - aVector.y) * (y - aVector.y);
    }

    float Vector2::DotProduct(const Vector2& vector2)
    {
        return x * vector2.x + y * vector2.y;
    }

	Vector2 Vector2::PerpendicularClockwise()
	{
		return Vector2(y, -x);
	}

	Vector2 Vector2::PerpendicularCounterClockwise()
	{
		return Vector2(-y, x);
	}

    Vector2 Vector2::operator+(const Vector2& vector2) const
    {
        return Vector2(x + vector2.x, y + vector2.y);
    }

    void Vector2::operator+=(const Vector2& vector2)
    {
        x += vector2.x;
        y += vector2.y;
    }

    Vector2 Vector2::operator-(const Vector2& vector2) const
    {
        return Vector2(x - vector2.x, y - vector2.y);
    }

    void Vector2::operator-=(const Vector2& vector2)
    {
        x -= vector2.x;
        y -= vector2.y;
    }

    Vector2 Vector2::operator*(const Vector2& vector2) const
    {
        return Vector2(x * vector2.x, y * vector2.y);
    }

    Vector2 Vector2::operator*(const float& scale) const
    {
        return Vector2(x * scale, y * scale);
    }

    void Vector2::operator*=(const Vector2& vector2)
    {
        x *= vector2.x;
        y *= vector2.y;
    }

    void Vector2::operator*=(const float& scale)
    {
        x *= scale;
        y *= scale;
    }

    Vector2 Vector2::operator/(const Vector2& vector2) const
    {
        return Vector2(x / vector2.x, y / vector2.y);
    }

    Vector2 Vector2::operator/(const float& scale) const
    {
        return Vector2(x / scale, y / scale);
    }

    void Vector2::operator/=(const Vector2& vector2)
    {
        x /= vector2.x;
        y /= vector2.y;
    }

    void Vector2::operator/=(const float& scale)
    {
        x /= scale;
        y /= scale;
    }

    Vector2 Vector2::operator-() const
    {
        return Vector2(-x, -y);
    }

    bool Vector2::operator==(const Vector2& vector2) const
    {
        return x == vector2.x && y == vector2.y;
    }

    bool Vector2::operator != (const Vector2& vector2) const
    {
        return x != vector2.x || y != vector2.y;
    }

    bool Vector2::operator<(const Vector2& aVector2) const
    {
        return (x == aVector2.x) ? (y < aVector2.y) : (x < aVector2.x);
    }

    bool Vector2::operator<=(const Vector2& aVector2) const
    {
        return (x == aVector2.x) ? (y <= aVector2.y) : (x <= aVector2.x);
    }

    bool Vector2::operator>(const Vector2& aVector2) const
    {
        return (x == aVector2.x) ? (y > aVector2.y) : (x > aVector2.x);
    }

    bool Vector2::operator>=(const Vector2& aVector2) const
    {
        return (x == aVector2.x) ? (y >= aVector2.y) : (x >= aVector2.x);
    }

	Vector2 operator* (float scale, const Vector2& vector2)
	{
		return Vector2(vector2.x * scale, vector2.y * scale);
	}
}
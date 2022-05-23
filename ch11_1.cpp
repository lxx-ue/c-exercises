#include <cmath>
#include "ch11_1.h"
using std::sqrt;
using std::sin;
using std::cos;
using std::atan;
using std::atan2;
using std::cout;

namespace VECTOR
{
	const double rad_to_deg = 45.0 / atan(1.0);

	void Vector::Vector::set_mag()
	{
		mag = sqrt(x * x + y * y);
	}

	void Vector::Vector::set_ang()
	{
		if (x == 0.0 && y == 0.0)
			ang = 0;
		else
			ang = atan2(y, x);
	}

	void Vector::Vector::set_x()
	{
		x = mag * cos(ang);
	}

	void Vector::Vector::set_y()
	{
		y = mag * sin(ang);
	}

	Vector::Vector()
	{
		x = y = mag = ang = 0.0;
		mode = Mode::RECT;
	}

	Vector::Vector(double n1, double n2, Mode form)
	{
		mode = form;
		if (form == Mode::RECT)
		{
			x = n1;
			y = n2;
			set_mag();
			set_ang();
		}
		else if (form == Mode::POL)
		{
			mag = n1;
			ang = n2;
			set_x();
			set_y();
		}
		else
		{
			cout << "Incorrect 3rd argument to Vector() -- vector set to 0\n";
			x = y = mag = ang = 0.0;
			mode = Mode::RECT;
		}
	}

	void Vector::reset(double n1, double n2, Mode form)
	{
		mode = form;
		if (form == Mode::RECT)
		{
			x = n1;
			y = n2;
			set_mag();
			set_ang();
		}
		else if (form == Mode::POL)
		{
			mag = n1;
			ang = n2;
			set_x();
			set_y();
		}
		else
		{
			cout << "Incorrect 3rd argument to Vector() -- vector set to 0\n";
			x = y = mag = ang = 0.0;
			mode = Mode::RECT;
		}
	}

	Vector::~Vector() {}

	void Vector::polar_mode()
	{
		mode = Mode::POL;
	}

	void Vector::rect_mode()
	{
		mode = Mode::RECT;
	}

	Vector Vector::operator+(const Vector& b) const
	{
		return Vector(x + b.x, y + b.y);
	}

	Vector Vector::operator-(const Vector& b) const
	{
		return Vector(x - b.x, y - b.y);
	}

	Vector Vector::operator-() const
	{
		return Vector(-x, -y);
	}

	Vector Vector::operator*(double n) const
	{
		return Vector(x * n, y * n);
	}

	Vector operator*(double n, const Vector & a)
	{
		return a * n;
	}

	std::ostream& operator <<(std::ostream& os, const Vector& v)
	{
		if (v.mode == Vector::Mode::RECT)
		{
			os << "(x, y) = (" << v.x << ", " << v.y << ")";
		}
		else if (v.mode == Vector::Mode::POL)
		{
			os << "(m, a) = (" << v.mag << ", " << v.ang * rad_to_deg << ")";
		}
		else
		{
			os << "Vector object mode is invalid";
		}
		return os;
	}
}


#include "euler.hpp"
#include "quaternion.hpp"
#include "matrix4.hpp"
#include <cmath>
#include <algorithm>

Euler::Euler() :
    Euler(0, 0, 0)
{}

Euler::Euler(float x, float y, float z, Order order) :
    x(x), y(y), z(z), order(order)
{}

Euler::Euler(const Quaternion& q, Order order) : Euler(Matrix4(q), order) {}

Euler::Euler(const Matrix4& m, Order order) : order(order) {
    // assumes the upper 3x3 of m is a pure rotation matrix (i.e, unscaled)

    const float* const me = m.getElements();
    const float &m11 = me[0], &m12 = me[4], &m13 = me[8];
	const float &m21 = me[1], &m22 = me[5], &m23 = me[9];
	const float &m31 = me[2], &m32 = me[6], &m33 = me[10];

    switch(order) {
        case xyz:
            y = asinf(std::clamp(m13, -1.0f, 1.0f));

			if(std::abs(m13) < 0.9999999f) {
				x = atan2f(-m23, m33);
				z = atan2f(-m12, m11);
			} else {
				x = atan2f(m32, m22);
				z = 0;
			}

            break;
        case xzy:
            z = asinf(-std::clamp(m12, -1.0f, 1.0f));

            if (std::abs(m12) < 0.9999999f) {
                x = atan2f(m32, m22);
                y = atan2f(m13, m11);
            } else {
                x = atan2f(-m23, m33);
                y = 0;
            }

            break;
        case yxz:
            x = asinf(-std::clamp(m23, -1.0f, 1.0f));

			if (std::abs(m23) < 0.9999999f) {
				y = atan2f(m13, m33);
				z = atan2f(m21, m22);
			} else {
				y = atan2f(-m31, m11);
				z = 0;
			}

            break;
        case yzx:
            z = asinf(std::clamp(m21, -1.0f, 1.0f));

			if (std::abs(m21) < 0.9999999f ) {
				x = atan2f( -m23, m22);
				y = atan2f( -m31, m11);
			} else {
				x = 0;
				y = atan2f(m13, m33);
			}

            break;
        case zxy:
            x = asinf(std::clamp(m32, -1.0f, 1.0f));

			if (std::abs(m32) < 0.9999999f) {
				y = atan2f(-m31, m33);
				z = atan2f(-m12, m22);

			} else {
				y = 0;
				z = atan2f(m21, m11);
			}

            break;
        case zyx:
            y = asinf(-std::clamp(m31, -1.0f, 1.0f));

			if (std::abs(m31) < 0.9999999f) {
				x = atan2f(m32, m33);
				z = atan2f(m21, m11);
			} else {
				x = 0;
				z = atan2f(-m12, m22);
			}

            break;
    }
}
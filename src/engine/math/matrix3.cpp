#include "matrix3.hpp"
#include "matrix4.hpp"

Matrix3::Matrix3() {
    identity();
}

Matrix3::Matrix3(const Matrix3& m) {
    for (int i = 0; i < 9; i++) {
		elements[i] = m.elements[i];
	}
}

Matrix3::Matrix3(const Matrix4& m) {
    const float* me = m.getElements();

    set(*(me + 0), *(me + 4), *(me + 8),
        *(me + 1), *(me + 5), *(me + 9),
        *(me + 2), *(me + 6), *(me + 10));
}

Matrix3& Matrix3::identity() {
    set(1, 0, 0,
		0, 1, 0,
		0, 0, 1);

	return *this;
}

void Matrix3::set(float n11, float n12, float n13,
				  float n21, float n22, float n23,
				  float n31, float n32, float n33) {

    float (&te)[9] = elements;

	te[0] = n11; te[3] = n12; te[6] = n13;
	te[1] = n21; te[4] = n22; te[7] = n23;
	te[2] = n31; te[5] = n32; te[8] = n33;
}

const float* Matrix3::getElements() const {
	return elements;
}
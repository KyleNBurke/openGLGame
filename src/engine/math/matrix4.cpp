#include "Matrix4.hpp"
#include <cmath>

Matrix4::Matrix4() {
	identity();
}

Matrix4::Matrix4(const Matrix4& m) {
	for (int i = 0; i < 16; i++) {
		elements[i] = m.elements[i];
	}
}

Matrix4::Matrix4(const Quaternion& q) {
	compose(Vector3(0.0f), q, Vector3(1.0f));
}

Matrix4& Matrix4::identity() {
	set(1, 0, 0, 0,
		0, 1, 0, 0,
		0, 0, 1, 0,
		0, 0, 0, 1);

	return *this;
}

Matrix4& Matrix4::compose(const Vector3& position, const Quaternion& quaternion, const Vector3& scale) {
	float (&te)[16] = elements;

	float x = quaternion.x, y = quaternion.y, z = quaternion.z, w = quaternion.w;
	float x2 = x + x, y2 = y + y, z2 = z + z;
	float xx = x * x2, xy = x * y2, xz = x * z2;
	float yy = y * y2, yz = y * z2, zz = z * z2;
	float wx = w * x2, wy = w * y2, wz = w * z2;

	float sx = scale.x, sy = scale.y, sz = scale.z;

	te[0] = (1 - (yy + zz)) * sx;
	te[1] = (xy + wz) * sx;
	te[2] = (xz - wy) * sx;
	te[3] = 0;

	te[4] = (xy - wz) * sy;
	te[5] = (1 - (xx + zz)) * sy;
	te[6] = (yz + wx) * sy;
	te[7] = 0;

	te[8] = (xz + wy) * sz;
	te[9] = (yz - wx) * sz;
	te[10] = (1 - (xx + yy)) * sz;
	te[11] = 0;

	te[12] = position.x;
	te[13] = position.y;
	te[14] = position.z;
	te[15] = 1;

	return *this;
}

Matrix4& Matrix4::transpose() {
	float (&te)[16] = elements;
	float temp;

	temp = te[1]; te[1] = te[4]; te[4] = temp;
	temp = te[2]; te[2] = te[8]; te[8] = temp;
	temp = te[6]; te[6] = te[9]; te[9] = temp;

	temp = te[3]; te[3] = te[12]; te[12] = temp;
	temp = te[7]; te[7] = te[13]; te[13] = temp;
	temp = te[11]; te[11] = te[14]; te[14] = temp;

	return *this;
}

Matrix4& Matrix4::invert() {
	float (&me)[16] = elements;

	float n11 = me[0], n21 = me[1], n31 = me[2], n41 = me[3];
	float n12 = me[4], n22 = me[5], n32 = me[6], n42 = me[7];
	float n13 = me[8], n23 = me[9], n33 = me[10], n43 = me[11];
	float n14 = me[12], n24 = me[13], n34 = me[14], n44 = me[15];

	float t11 = n23 * n34 * n42 - n24 * n33 * n42 + n24 * n32 * n43 - n22 * n34 * n43 - n23 * n32 * n44 + n22 * n33 * n44;
	float t12 = n14 * n33 * n42 - n13 * n34 * n42 - n14 * n32 * n43 + n12 * n34 * n43 + n13 * n32 * n44 - n12 * n33 * n44;
	float t13 = n13 * n24 * n42 - n14 * n23 * n42 + n14 * n22 * n43 - n12 * n24 * n43 - n13 * n22 * n44 + n12 * n23 * n44;
	float t14 = n14 * n23 * n32 - n13 * n24 * n32 - n14 * n22 * n33 + n12 * n24 * n33 + n13 * n22 * n34 - n12 * n23 * n34;

	float det = n11 * t11 + n21 * t12 + n31 * t13 + n41 * t14;

	if (det == 0) {
		return identity();
	}

	float detInv = 1 / det;

	me[0] = t11 * detInv;
	me[1] = (n24 * n33 * n41 - n23 * n34 * n41 - n24 * n31 * n43 + n21 * n34 * n43 + n23 * n31 * n44 - n21 * n33 * n44) * detInv;
	me[2] = (n22 * n34 * n41 - n24 * n32 * n41 + n24 * n31 * n42 - n21 * n34 * n42 - n22 * n31 * n44 + n21 * n32 * n44) * detInv;
	me[3] = (n23 * n32 * n41 - n22 * n33 * n41 - n23 * n31 * n42 + n21 * n33 * n42 + n22 * n31 * n43 - n21 * n32 * n43) * detInv;

	me[4 ] = t12 * detInv;
	me[5] = (n13 * n34 * n41 - n14 * n33 * n41 + n14 * n31 * n43 - n11 * n34 * n43 - n13 * n31 * n44 + n11 * n33 * n44) * detInv;
	me[6] = (n14 * n32 * n41 - n12 * n34 * n41 - n14 * n31 * n42 + n11 * n34 * n42 + n12 * n31 * n44 - n11 * n32 * n44) * detInv;
	me[7] = (n12 * n33 * n41 - n13 * n32 * n41 + n13 * n31 * n42 - n11 * n33 * n42 - n12 * n31 * n43 + n11 * n32 * n43 ) * detInv;

	me[8] = t13 * detInv;
	me[9] = (n14 * n23 * n41 - n13 * n24 * n41 - n14 * n21 * n43 + n11 * n24 * n43 + n13 * n21 * n44 - n11 * n23 * n44) * detInv;
	me[10] = (n12 * n24 * n41 - n14 * n22 * n41 + n14 * n21 * n42 - n11 * n24 * n42 - n12 * n21 * n44 + n11 * n22 * n44) * detInv;
	me[11] = (n13 * n22 * n41 - n12 * n23 * n41 - n13 * n21 * n42 + n11 * n23 * n42 + n12 * n21 * n43 - n11 * n22 * n43) * detInv;

	me[12] = t14 * detInv;
	me[13] = (n13 * n24 * n31 - n14 * n23 * n31 + n14 * n21 * n33 - n11 * n24 * n33 - n13 * n21 * n34 + n11 * n23 * n34) * detInv;
	me[14] = (n14 * n22 * n31 - n12 * n24 * n31 - n14 * n21 * n32 + n11 * n24 * n32 + n12 * n21 * n34 - n11 * n22 * n34) * detInv;
	me[15] = (n12 * n23 * n31 - n13 * n22 * n31 + n13 * n21 * n32 - n11 * n23 * n32 - n12 * n21 * n33 + n11 * n22 * n33) * detInv;
	
	return *this;
}

Matrix4& Matrix4::makePerspective(float left, float right, float top, float bottom, float near, float far) {
	float (&te)[16] = elements;

	float a = 2.0f * near / (right - left);
	float b = (right + left) / (right - left);
	float c = 2.0f * near / (top - bottom);
	float d = (top + bottom) / (top - bottom);
	float e = -(far + near) / (far - near);
	float f = -2.0f * far * near / (far - near);

	te[0] = a; te[4] = 0; te[8] = b; te[12] = 0;
	te[1] = 0; te[5] = c; te[9] = d; te[13] = 0;
	te[2] = 0; te[6] = 0; te[10] = e; te[14] = f;
	te[3] = 0; te[7] = 0; te[11] = -1.0f; te[15] = 0;

	return *this;
}

Matrix4 Matrix4::operator*(const Matrix4& b) const {
	Matrix4 r;
	const float (&ae)[16] = elements;
	const float (&be)[16] = b.elements;
	float (&re)[16] = r.elements;

	float a11 = ae[0], a12 = ae[4], a13 = ae[8], a14 = ae[12];
	float a21 = ae[1], a22 = ae[5], a23 = ae[9], a24 = ae[13];
	float a31 = ae[2], a32 = ae[6], a33 = ae[10], a34 = ae[14];
	float a41 = ae[3], a42 = ae[7], a43 = ae[11], a44 = ae[15];

	float b11 = be[0], b12 = be[4], b13 = be[8], b14 = be[12];
	float b21 = be[1], b22 = be[5], b23 = be[9], b24 = be[13];
	float b31 = be[2], b32 = be[6], b33 = be[10], b34 = be[14];
	float b41 = be[3], b42 = be[7], b43 = be[11], b44 = be[15];

	float &r11 = re[0], &r12 = re[4], &r13 = re[8], &r14 = re[12];
	float &r21 = re[1], &r22 = re[5], &r23 = re[9], &r24 = re[13];
	float &r31 = re[2], &r32 = re[6], &r33 = re[10], &r34 = re[14];
	float &r41 = re[3], &r42 = re[7], &r43 = re[11], &r44 = re[15];

	r11 = a11 * b11 + a12 * b21 + a13 * b31 + a14 * b41;
	r12 = a11 * b12 + a12 * b22 + a13 * b32 + a14 * b42;
	r13 = a11 * b13 + a12 * b23 + a13 * b33 + a14 * b43;
	r14 = a11 * b14 + a12 * b24 + a13 * b34 + a14 * b44;

	r21 = a21 * b11 + a22 * b21 + a23 * b31 + a24 * b41;
	r22 = a21 * b12 + a22 * b22 + a23 * b32 + a24 * b42;
	r23 = a21 * b13 + a22 * b23 + a23 * b33 + a24 * b43;
	r24 = a21 * b14 + a22 * b24 + a23 * b34 + a24 * b44;

	r31 = a31 * b11 + a32 * b21 + a33 * b31 + a34 * b41;
	r32 = a31 * b12 + a32 * b22 + a33 * b32 + a34 * b42;
	r33 = a31 * b13 + a32 * b23 + a33 * b33 + a34 * b43;
	r34 = a31 * b14 + a32 * b24 + a33 * b34 + a34 * b44;

	r41 = a41 * b11 + a42 * b21 + a43 * b31 + a44 * b41;
	r42 = a41 * b12 + a42 * b22 + a43 * b32 + a44 * b42;
	r43 = a41 * b13 + a42 * b23 + a43 * b33 + a44 * b43;
	r44 = a41 * b14 + a42 * b24 + a43 * b34 + a44 * b44;

	return r;
}

Matrix4& Matrix4::operator*=(float s) {
	for (float& f : elements) {
		f *= s;
	}

	return *this;
}

void Matrix4::set(float n11, float n12, float n13, float n14,
				  float n21, float n22, float n23, float n24,
				  float n31, float n32, float n33, float n34,
				  float n41, float n42, float n43, float n44) {

	float (&te)[16] = elements;

	te[0] = n11; te[4] = n12; te[8] = n13; te[12] = n14;
	te[1] = n21; te[5] = n22; te[9] = n23; te[13] = n24;
	te[2] = n31; te[6] = n32; te[10] = n33; te[14] = n34;
	te[3] = n41; te[7] = n42; te[11] = n43; te[15] = n44;
}

const float* Matrix4::getElements() const {
	return elements;
}
#include "Matrix4.hpp"

Matrix4::Matrix4() {
	identity();
}

Matrix4::Matrix4(const Matrix4& m) {
	for (int i = 0; i < 16; i++) {
		elements[i] = m.elements[i];
	}
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

	float px = position.x, py = position.y, pz = position.z;
	float qx = quaternion.x, qy = quaternion.y, qz = quaternion.z, qw = quaternion.w;
	float sx = scale.x, sy = scale.y, sz = scale.z;

	float& t11 = te[0], t12 = te[4], t13 = te[8], t14 = te[12];
	float& t21 = te[1], t22 = te[5], t23 = te[9], t24 = te[13];
	float& t31 = te[2], t32 = te[6], t33 = te[10], t34 = te[14];
	float& t41 = te[3], t42 = te[7], t43 = te[11], t44 = te[15];

	t11 = (1 - 2 * (qy * qy + qz * qz)) * sx;
	t21 = 2 * (qx * qy + qw * qz) * sx;
	t31 = -2 * (qw * qy - qx * qz) * sx;
	t41 = 0;

	t12 = 2 * (qx * qy - qw  * qz) * sy;
	t22 = (1 - 2 * (qx * qx + qz * qz)) * sy;
	t32 = 2 * (qy * qz + qw  * qx) * sy;
	t42 = 0;

	t13 = 2 * (qx * qz + qw * qy) * sz;
	t23 = 2 * (qy * qz - qw * qx) * sz;
	t33 = (1 - 2 * (qx * qx + qy * qy)) * sz;
	t43 = 0;

	t14 = px;
	t24 = py;
	t34 = pz;
	t44 = 1;

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

	float& r11 = re[0], r12 = re[4], r13 = re[8], r14 = re[12];
	float& r21 = re[1], r22 = re[5], r23 = re[9], r24 = re[13];
	float& r31 = re[2], r32 = re[6], r33 = re[10], r34 = re[14];
	float& r41 = re[3], r42 = re[7], r43 = re[11], r44 = re[15];

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
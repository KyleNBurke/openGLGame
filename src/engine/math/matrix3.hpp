#pragma once

class Matrix4;

class Matrix3 {
    public:
        Matrix3();
        Matrix3(const Matrix3& m);
        Matrix3(const Matrix4& m);

        Matrix3& identity();

        void set(float n11, float n12, float n13,
				 float n21, float n22, float n23,
				 float n31, float n32, float n33);

        const float* getElements() const;

    private:
        float elements[9];
};
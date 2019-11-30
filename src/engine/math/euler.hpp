#pragma once

class Quaternion;
class Matrix4;

class Euler {
    public:
        enum Order { xyz, xzy, yxz, yzx, zxy, zyx };

        Euler();
        Euler(float x, float y, float z, Order order = xyz);
        Euler(const Quaternion& q, Order order = xyz);
        Euler(const Matrix4& m, Order order = xyz);

        float x;
        float y;
        float z;
        Order order;
};
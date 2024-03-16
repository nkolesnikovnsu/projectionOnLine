#pragma once

namespace Projection {
    struct Plane {
        double a, b, c, d;
        
        Plane(double a = 0, double b = 0, double c = 0, double d = 0) : a(a), b(b), c(c), d(d) {}
    };

    struct Vector {
        double x, y, z;

        Vector(double x = 0, double y = 0, double z = 0) : x(x), y(y), z(z) {}

        Vector operator-(const Vector& v) const {
            return Vector(x - v.x, y - v.y, z - v.z);
        }

        Vector operator+(const Vector& v) const {
            return Vector(x + v.x, y + v.y, z + v.z);
        }

        Vector operator*(double scalar) const {
            return Vector(x * scalar, y * scalar, z * scalar);
        }

        double dot(const Vector& v) const {
            return x * v.x + y * v.y + z * v.z;
        }

        double dot(const Vector& v1, const Vector& v2) const {
            return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
        }
    };

    class Projection {
        public:
            Vector normal;
            Vector intersectionPoint;
            Vector projection;
            
            void calculateDirectingVector(const Vector& A, const Vector& B);
            void findIntersectionPoint(const Vector& P, const Plane& plane);
            void projectPointOnLine(const Vector& point, const Vector& linePoint);
    };

    Plane calculatePlaneEquation(const Vector& normal, const Vector& point);
}

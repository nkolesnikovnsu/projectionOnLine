#include "projection.h"

namespace Projection {

    void Projection::calculateDirectingVector(const Vector& A, const Vector& B) {
        normal = {B.x - A.x, B.y - A.y, B.z - A.z};
        return;
    }

    void Projection::findIntersectionPoint(const Vector& P, const Plane& plane) {
        Vector normal = {plane.a, plane.b, plane.c};
        double t = -(plane.a * P.x + plane.b * P.y + plane.c * P.z + plane.d) / normal.dot(P);
        intersectionPoint = P + (normal * t);
        return;
    }

    void Projection::projectPointOnLine(const Vector& point, const Vector& linePoint) {
        Vector lineToPoint = point - linePoint;
        double t = (lineToPoint.x * normal.x + lineToPoint.y * normal.y + lineToPoint.z * normal.z) /
                (normal.x * normal.x + normal.y * normal.y + normal.z * normal.z);
        projection = linePoint + normal * t;
        return;
    }

    Plane calculatePlaneEquation(const Vector& normal, const Vector& point) {
        Plane plane;
        plane.a = normal.x;
        plane.b = normal.y;
        plane.c = normal.z;
        plane.d = -(plane.a * point.x + plane.b * point.y + plane.c * point.z);
        return plane;
    }
}

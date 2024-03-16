#include <iostream>
#include <cmath>
#include "projection.h"


int main() {
    Projection::Vector A(-2, 6, -1);
    Projection::Vector B(1, 2, 0);
    Projection::Vector P(0, 1, -1);

    Projection::Projection result;
    
    result.calculateDirectingVector(A, B);
   
    auto resultPlane = Projection::Plane();
    resultPlane = Projection::calculatePlaneEquation(result.normal, P);
    result.findIntersectionPoint(P, resultPlane);
    result.projectPointOnLine(P, A);

    std::cout << "Projection: " << "("<< result.projection.x << ", " << result.projection.y << ", " << result.projection.z << ")" << std::endl;
    return 0;
}
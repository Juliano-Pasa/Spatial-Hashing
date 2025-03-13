#ifndef __CURVA_HPP__
#define __CURVA_HPP__

#include <vector>
#include "glslprogram.hpp"

namespace spatialhash
{
    class Curva
    {
    public:
        float steps;
        std::vector<vec3> controlPoints;
        std::vector<vec3> curvePoints;
    
        Curva(float steps);
        void addControlPoint(vec3 p);
    };
}

#endif
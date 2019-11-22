#define GLM_FORCE_SWIZZLE 
#include <glm/glm.hpp>
#include <omp.h>
#include "../config.h"
#include "../output.cpp"

#define time frameTime

using glm::vec2;
using glm::vec3;
using glm::vec4;
using glm::mat2;
using glm::mat3;
using glm::clamp;
using glm::min;
using glm::max;
using glm::length;
using glm::round;
using glm::sin;
using glm::cos;
using glm::atan;
using glm::sign;
using glm::mod;
using glm::mix;
using glm::fract;
using glm::normalize;

vec3 worldPos = vec3(0.0f,0.0f,0.0f);
vec3 cameraPosition = vec3(0.0f, 0.0f, -1.0f);


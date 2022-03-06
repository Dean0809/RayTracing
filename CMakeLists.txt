#---------------------------------------------------------------------------------------------------
# CMake Build Configuration for the Ray Tracing Weekend Series
#
# See README.md for guidance.
#---------------------------------------------------------------------------------------------------
cmake_minimum_required (VERSION 3.8)

project(RatTracing
	VERSION 1.0.0
)

# set to c++11
set(CMAKE_CXX_STANDARD 11)

set(COMMON_ALL
	"src/common/rtweekend.h"
	"src/common/vec3.h"
	"src/common/ray.h"
	"src/common/camera.h"
)

set(SOURCE_ONE_WEEKEND
	${COMMON_ALL}
	"src/InOneWeekend/sphere.h"
	"src/InOneWeekend/hittable_list.h"
	"src/InOneWeekend/hittable.h"
	"src/InOneWeekend/main.cpp"
)


# executables
add_executable (inOneWeekend ${SOURCE_ONE_WEEKEND})
include_directories(
	"src/common" 
	)

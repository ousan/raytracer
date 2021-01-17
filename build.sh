g++ -std=c++17 \
main.cpp \
libRaytracer/src/camera/*.cpp \
libRaytracer/src/canvas/*.cpp \
libRaytracer/src/interface/*.cpp \
libRaytracer/src/object/*.cpp \
libRaytracer/src/operation/*.cpp \
libRaytracer/src/scene/*.cpp \
libRaytracer/src/utils/*.cpp \
-o raytracer \
-IlibRaytracer/inc/camera \
-IlibRaytracer/inc/canvas \
-IlibRaytracer/inc/interface \
-IlibRaytracer/inc/object \
-IlibRaytracer/inc/operation \
-IlibRaytracer/inc/scene \
-IlibRaytracer/inc/utils 
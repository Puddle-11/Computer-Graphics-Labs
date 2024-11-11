#pragma once


//Independant classes ONLY


#include <iostream>
#include "ScreenBounds.h"
#include "Vector4.h"
#include "ImageDef.h"
#include "VertexScreen.h"
#include "Mesh.h"
#define ImageWidth 500
#define ImageHeight 500
#define imagePixelCount ImageHeight * ImageWidth
#define FOV 70
#define NearPlane 0.5
#define FarPlane 10
#define AspectRatio ImageHeight / ImageWidth
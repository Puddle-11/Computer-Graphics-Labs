#pragma once


//Independant classes ONLY


#include <iostream>
#include "ScreenBounds.h"
#include "Vector4.h"
#include "Vector2.h"
#include "Vector3.h"
#include "ImageDef.h"
#include "VertexScreen.h"
#include "Mesh.h"
#include "3DMath.h"
#include "Particle.h"
#define ImageWidth 800
#define ImageHeight 500
#define imagePixelCount ImageHeight * ImageWidth
#define FOV 90
#define NearPlane 0.5
#define FarPlane 100
#define AspectRatio ImageHeight / (float)ImageWidth
#pragma once
#include "Vector2Int.h"
#include "Color.h"
#include "BLITVars.h"
#include "ScreenBounds.h"

//Variables
unsigned int* image_pixels = nullptr;
const unsigned int layerCount = 2;
unsigned int layers[layerCount][imagePixelCount];

Vector2Int pixelPos;
ScreenBounds mainBounds;
ScreenBounds srcBounds;
ScreenBounds fireAnimBounds;



//Decleration
void Plot(int x, int y, unsigned int _color, int _layerIndex);
void Plot(int x, int y, Color _color, int _layerIndex);
void Plot(Vector2Int _pos, Color _color, int _layerIndex);
void Plot(Vector2Int _pos, unsigned int _color, int _layerIndex);
void Plot(int _index, Color _color, int _layerIndex);
void Plot(int _index, unsigned int _color, int _layerIndex);

void ResetPixel(int _index, int _layerIndex);

Color Access(int x, int y, ScreenBounds _bounds, const unsigned int* _array);
Color Access(Vector2Int _pos, ScreenBounds _bounds, const unsigned int* _array);
Color Access(int _index, const unsigned int* _array);

Color AccessARGB(int _index, const unsigned int* _array);
Color AccessARGB(int x, int y, ScreenBounds _bounds, const unsigned int* _array);
Color AccessARGB(Vector2Int _pos, ScreenBounds _bounds, const unsigned int* _array);

void ClearBuffer();
void ClearLayers(int _index);
void ClearLayers();

void RasterizeLayers();
void RasterizeRange(Vector2Int _min, Vector2Int _max);

void Copy(Vector2Int _scrMin, Vector2Int _scrMax, Vector2Int _cpyPos, bool _center = false, const unsigned int* _src = tiles_12_pixels, ScreenBounds _srcBounds = srcBounds, int _layerIndex = 0);
void Copy(Vector2Int _scrMin, Vector2Int _scrMax, Vector2Int _cpyPos, Vector2Int _offset, bool _center = false, const unsigned int* _src = tiles_12_pixels, ScreenBounds _srcBounds = srcBounds, int _layerIndex = 0);


void DrawRect(Vector2Int _min, Vector2Int _max, Color _color, bool _fill = false, int _layerIndex = 0);
void DrawLine(VertexScreen _p1, VertexScreen _p2);
void DrawLineSet(const VertexScreen* _points, int _pointCount);
void DrawPolygon(const VertexScreen* _points, int _pointCount);
void DrawRegularPolygon(int _size, int _vertCount, Color c, Color c2, bool _wire = true, Vector2Int _position = Vector2Int::Zero());

void Copy(Vector2Int _srcMin, Vector2Int _srcMax, Vector2Int _cpyPos, Vector2Int _offset, bool _center, const unsigned int* _src, ScreenBounds _srcBounds, int _layerIndex)
{
	Color pixelColor;
	Vector2Int filteredPos;
	for (int x = _srcMin.x; x < _srcMax.x; x++)
	{
		for (int y = _srcMin.y; y < _srcMax.y; y++)
		{

			pixelColor = Access(x, y, _srcBounds, _src);
			filteredPos = _cpyPos + Vector2Int(x, y) - _srcMin;
			if (_center)
			{
				filteredPos = filteredPos - Vector2Int((_srcMax.x - _srcMin.x) / 2, (_srcMax.y - _srcMin.y) / 2);
			}

			filteredPos = filteredPos + _offset;
			Plot(filteredPos, pixelColor, _layerIndex);
		}
	}
}
void Copy(Vector2Int _scrMin, Vector2Int _scrMax, Vector2Int _cpyPos, bool _center, const unsigned int* _src, ScreenBounds _srcBounds, int _layerIndex)
{
	Copy(_scrMin, _scrMax, _cpyPos, Vector2Int(0, 0), _center, _src, _srcBounds, _layerIndex);
}


void RasterizeRange(Vector2Int _min, Vector2Int _max)
{
	Color l1;
	Color l2;
	int index = 0;
	Vector2Int currPos;

	for (int x = _min.x; x < _max.x; x++)
	{
		for (int y = _min.y; y < _max.y; y++)
		{
			currPos = Vector2Int(x, y);
			index = ToIndex(currPos);



			l2 = AccessARGB(index, layers[0]);
			l1 = l2;


			for (int j = 1; j < layerCount; j++)
			{
				l2 = AccessARGB(index, layers[j]);
				if (l2.GetAlpha() == 255) l1 = l2;
				else l1 = Color::CLerp(l2, l1, l2.GetAlpha());
			}
			Plot(index, l1.GetARGB(), 0);
		}
	}
}

void RasterizeLayers()
{
	Color l1;
	Color l2;
	for (int i = 0; i < imagePixelCount; i++)
	{


		l2 = AccessARGB(i, layers[0]);
		l1 = l2;


		for (int j = 1; j < layerCount; j++)
		{
			l2 = AccessARGB(i, layers[j]);
			if (l2.GetAlpha() == 255) l1 = l2;
			else l1 = Color::CLerp(l2, l1, l2.GetAlpha());
		}
		Plot(i, l1.GetARGB(), 0);
	}
}



void Plot(int x, int y, unsigned int _color, int _layerIndex) { Plot(Vector2Int(x, y), _color, _layerIndex); }
void Plot(int x, int y, Color _color, int _layerIndex) { Plot(Vector2Int(x, y), _color.GetARGB(), _layerIndex); }


void Plot(Vector2Int _pos, Color _color, int _layerIndex) { Plot(_pos, _color.GetARGB(), _layerIndex); }
void Plot(Vector2Int _pos, unsigned int _color, int _layerIndex)
{
	if (InScreenBounds(_pos))
	{

		Plot(ToIndex(_pos), _color, _layerIndex);
	}
}
void Plot(int _index, Color _color, int _layerIndex) { Plot(_index, _color.GetARGB(), _layerIndex); }
//color has to be in ARGB format
void Plot(int _index, unsigned int _color, int _layerIndex)
{
	if (_index > imagePixelCount) return;

	if (_layerIndex > layerCount) return;
	if ((_color & 0xFF000000) >> 24 == 0) return;

	if (_layerIndex == 0) image_pixels[_index] = _color;
	else layers[_layerIndex - 1][_index] = _color;

}




Color Access(int x, int y, ScreenBounds _bounds, const unsigned int* _array)
{
	return Access(Vector2Int(x, y), _bounds, _array);
}
Color Access(int _index, const unsigned int* _array)
{
	Color res;
	res.SetBGRA(_array[_index]);
	return res;
}
Color AccessARGB(int _index, const unsigned int* _array)
{
	Color res;
	res.SetARGB(_array[_index]);
	return res;
}
Color AccessARGB(int x, int y, ScreenBounds _bounds, const unsigned int* _array)
{
	return AccessARGB(Vector2Int(x, y), _bounds, _array);

}
Color AccessARGB(Vector2Int _pos, ScreenBounds _bounds, const unsigned int* _array)
{
	if (_pos.x >= (int)_bounds.Width || _pos.x < 0 || _pos.y >= (int)_bounds.Height || _pos.y < 0) return Color::Zero();
	Color res;
	res.SetARGB(_array[ToIndex(_pos, _bounds.Width)]);
	return res;
}
Color Access(Vector2Int _pos, ScreenBounds _bounds, const unsigned int* _array)
{
	if (_pos.x >= (int)_bounds.Width || _pos.x < 0 || _pos.y >= (int)_bounds.Height || _pos.y < 0) return Color::Zero();
	Color res;
	res.SetBGRA(_array[ToIndex(_pos, _bounds.Width)]);
	return res;
}

void ResetPixel(int _index, int _layerIndex)
{

	if (_layerIndex == 0)
	{
		image_pixels[_index] = Color::Transparent().GetARGB();
	}
	else
	{
		layers[_layerIndex - 1][_index] = Color::Transparent().GetARGB();
	}
}

void ClearBuffer()
{
	ClearLayers(0);
}
void ClearLayers(int _index)
{
	for (int x = 0; x < imagePixelCount; x++)
	{
		ResetPixel(x, _index);

	}
}
void ClearLayers()
{
	for (int x = 0; x < imagePixelCount; x++)
	{
		for (int i = 1; i < layerCount + 1; i++)
		{
			ResetPixel(x, i);
		}
	}
}

void DrawRect(Vector2Int _min, Vector2Int _max, Color _color, bool _fill, int _layerIndex)
{
	for (int x = _min.x; x <= _max.x; x++)
	{
		for (int y = _min.y; y <= _max.y; y++)
		{
			if (_fill)
			{
				Plot(x, y, _color, _layerIndex);
			}
			else
			{
				if (x == _min.x || x == _max.x || y == _min.y || y == _max.y)
				{
					Plot(x, y, _color, _layerIndex);
				}
			}
		}
	}
}

void DrawLineSet(const VertexScreen* _points, int _pointCount)
{

	if (_pointCount <= 1)return;
	for (int i = 1; i < _pointCount; i++)
	{
		DrawLine(_points[i - 1], _points[i]);
	}
}
void DrawPolygon(const VertexScreen* _points, int _pointCount)
{
	//Use triangle fill to fill in polygons
	VertexScreen* newPoints = new VertexScreen[_pointCount + 1];
	for (size_t i = 0; i < _pointCount; i++)
	{
		newPoints[i] = _points[i];
	}
	newPoints[_pointCount] = _points[0];
	DrawLineSet(newPoints, _pointCount + 1);
	delete[] newPoints;
}

void DrawLine(VertexScreen _p1, VertexScreen _p2)
{
	float r = 0;
	int yChange = abs(_p2.point.y - _p1.point.y);
	int xChange = abs(_p2.point.x - _p1.point.x);

	int maxChange = xChange > yChange ? xChange : yChange;
	Vector2Int currPos = _p1.point;
	for (int i = 0; i <= maxChange; i++)
	{
		r = (float)i / (float)abs(maxChange);
		currPos = Vector2Int((int)floor(lerp((float)_p1.point.x, (float)_p2.point.x, r) + 0.5), (int)floor(lerp((float)_p1.point.y, (float)_p2.point.y, r) + 0.5));
		Color c = Color::CLerp(_p2.vertColor, _p1.vertColor, (int)(r * 255));
		Plot(currPos, c, 1);
	}
}


void DrawCircle(float _radius, Color c1, Color c2, Vector2Int _pos)
{





}
void DrawRegularPolygon(int _size, int _vertCount, Color c, Color c2, bool _wire, Vector2Int _position)
{
	VertexScreen* temp = new VertexScreen[_vertCount];
	for (int i = 0; i < _vertCount; i++)
	{
		float x = _size * (float)cos((2 * M_PI * i / _vertCount) + M_PI / 8);
		float y = _size * (float)sin((2 * M_PI * i / _vertCount) + M_PI / 8);
		x = (float)floor(x + 0.5) + _position.x;
		y = (float)floor(y + 0.5) + _position.y;
		temp[i].point = Vector2Int((int)x, (int)y);
		if(i > _vertCount / 2)
		{
			temp[i].vertColor = Color::CLerp(c, c2, (int)(((_vertCount - i) / (float)_vertCount * 2) * 255));
		}
		else
		{
			temp[i].vertColor = Color::CLerp(c, c2, (int)((i / (float)_vertCount * 2) * 255));
		}
	}
	if (_wire)
	{
		for (int i = 0; i < _vertCount; i++)
		{
			int oposingIndex = (i + _vertCount / 2) % _vertCount;
			DrawLine(temp[i], VertexScreen(Vector2Int(_position.x, _position.y), Color::CLerp( temp[i].vertColor, temp[oposingIndex].vertColor, 0.5*255)));
		}

	}
	DrawPolygon(temp, _vertCount);
	delete[] temp;
}

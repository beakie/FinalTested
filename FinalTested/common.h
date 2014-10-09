#ifndef COMMON_H
#define COMMON_H

#include "core.h"
#include "common-array.h"
#include "common-image.h"
#include "common-imageconv.h"
#include "common-imatrixadapter.h"
#include "common-matrix2.h"
#include "common-matrix3.h"
#include "common-matrix4.h"
#include "common-matrixadapter.h"
#include "common-matrixn.h"
#include "common-static.h"

namespace Common
{
	/// <summary>
	/// 4 byte unit interval (0 - 1)
	/// </summary>
	typedef Float32 UnitInterval32;
	/// <summary>
	/// 8 byte unit interval (0 - 1)
	/// </summary>
	typedef Float64 UnitInterval64;
	/// <summary>
	/// matrix of size 2 with 1 bit values
	/// </summary>
	typedef Matrix2<UInt1> Matrix2U1;
	/// <summary>
	/// matrix of size 3 with 1 bit values
	/// </summary>
	typedef Matrix3<UInt1> Matrix3U1;
	/// <summary>
	/// matrix of size 4 with 1 bit values
	/// </summary>
	typedef Matrix4<UInt1> Matrix4U1;
	/// <summary>
	/// matrix of size 2 with 1 byte unsigned integer values
	/// </summary>
	typedef Matrix2<UInt8> Matrix2U8;
	/// <summary>
	/// matrix of size 3 with 1 byte unsigned integer values
	/// </summary>
	typedef Matrix3<UInt8> Matrix3U8;
	/// <summary>
	/// matrix of size 4 with 1 byte unsigned integer values
	/// </summary>
	typedef Matrix4<UInt8> Matrix4U8;
	/// <summary>
	/// matrix of size 2 with 2 byte unsigned integer values
	/// </summary>
	typedef Matrix2<UInt16> Matrix2U16;
	/// <summary>
	/// matrix of size 3 with 2 byte unsigned integer values
	/// </summary>
	typedef Matrix3<UInt16> Matrix3U16;
	/// <summary>
	/// matrix of size 4 with 2 byte unsigned integer values
	/// </summary>
	typedef Matrix4<UInt16> Matrix4U16;
	/// <summary>
	/// matrix of size 2 with 4 byte unsigned integer values
	/// </summary>
	typedef Matrix2<UInt32> Matrix2U32;
	/// <summary>
	/// matrix of size 3 with 4 byte unsigned integer values
	/// </summary>
	typedef Matrix3<UInt32> Matrix3U32;
	/// <summary>
	/// matrix of size 4 with 4 byte unsigned integer values
	/// </summary>
	typedef Matrix4<UInt32> Matrix4U32;
	/// <summary>
	/// matrix of size 2 with 1 byte signed integer values
	/// </summary>
	typedef Matrix2<Int8> Matrix2I8;
	/// <summary>
	/// matrix of size 3 with 1 byte signed integer values
	/// </summary>
	typedef Matrix3<Int8> Matrix3I8;
	/// <summary>
	/// matrix of size 4 with 1 byte signed integer values
	/// </summary>
	typedef Matrix4<Int8> Matrix4I8;
	/// <summary>
	/// matrix of size 2 with 2 byte signed integer values
	/// </summary>
	typedef Matrix2<Int16> Matrix2I16;
	/// <summary>
	/// matrix of size 3 with 2 byte signed integer values
	/// </summary>
	typedef Matrix3<Int16> Matrix3I16;
	/// <summary>
	/// matrix of size 4 with 2 byte signed integer values
	/// </summary>
	typedef Matrix4<Int16> Matrix4I16;
	/// <summary>
	/// matrix of size 2 with 4 byte signed integer values
	/// </summary>
	typedef Matrix2<Int32> Matrix2I32;
	/// <summary>
	/// matrix of size 3 with 4 byte signed integer values
	/// </summary>
	typedef Matrix3<Int32> Matrix3I32;
	/// <summary>
	/// matrix of size 4 with 4 byte signed integer values
	/// </summary>
	typedef Matrix4<Int32> Matrix4I32;
	/// <summary>
	/// matrix of size 2 with floating point values
	/// </summary>
	typedef Matrix2<Float32> Matrix2F;
	/// <summary>
	/// matrix of size 3 with floating point values
	/// </summary>
	typedef Matrix3<Float32> Matrix3F;
	/// <summary>
	/// matrix of size 4 with floating point values
	/// </summary>
	typedef Matrix4<Float32> Matrix4F;
	/// <summary>
	/// Adapter for matrix of size 2 with 1 bit values
	/// </summary>
	typedef MatrixAdapter<Matrix2U1, UInt1> Matrix2AdapterU1;
	/// <summary>
	/// Adapter for matrix of size 3 with 1 bit values
	/// </summary>
	typedef MatrixAdapter<Matrix3U1, UInt1> Matrix3AdapterU1;
	/// <summary>
	/// Adapter for matrix of size 4 with 1 bit values
	/// </summary>
	typedef MatrixAdapter<Matrix4U1, UInt1> Matrix4AdapterU1;
	/// <summary>
	/// Adapter for matrix of size 2 with 1 byte unsigned integer values
	/// </summary>
	typedef MatrixAdapter<Matrix2U8, UInt8> Matrix2AdapterU8;
	/// <summary>
	/// Adapter for matrix of size 3 with 1 byte unsigned integer values
	/// </summary>
	typedef MatrixAdapter<Matrix3U8, UInt8> Matrix3AdapterU8;
	/// <summary>
	/// Adapter for matrix of size 4 with 1 byte unsigned integer values
	/// </summary>
	typedef MatrixAdapter<Matrix4U8, UInt8> Matrix4AdapterU8;
	/// <summary>
	/// Adapter for matrix of size 2 with 2 byte unsigned integer values
	/// </summary>
	typedef MatrixAdapter<Matrix2U16, UInt16> Matrix2Adapter16;
	/// <summary>
	/// Adapter for matrix of size 3 with 2 byte unsigned integer values
	/// </summary>
	typedef MatrixAdapter<Matrix3U16, UInt16> Matrix3Adapter16;
	/// <summary>
	/// Adapter for matrix of size 4 with 2 byte unsigned integer values
	/// </summary>
	typedef MatrixAdapter<Matrix4U16, UInt16> Matrix4Adapter16;
	/// <summary>
	/// Adapter for matrix of size 2 with 4 byte unsigned integer values
	/// </summary>
	typedef MatrixAdapter<Matrix2U32, UInt32> Matrix2Adapter32;
	/// <summary>
	/// Adapter for matrix of size 3 with 4 byte unsigned integer values
	/// </summary>
	typedef MatrixAdapter<Matrix3U32, UInt32> Matrix3Adapter32;
	/// <summary>
	/// Adapter for matrix of size 4 with 4 byte unsigned integer values
	/// </summary>
	typedef MatrixAdapter<Matrix4U32, UInt32> Matrix4Adapter32;
	/// <summary>
	/// Adapter for matrix of size 2 with 1 byte signed integer values
	/// </summary>
	typedef MatrixAdapter<Matrix2U8, Int8> Matrix2AdapterI8;
	/// <summary>
	/// Adapter for matrix of size 3 with 1 byte signed integer values
	/// </summary>
	typedef MatrixAdapter<Matrix3U8, Int8> Matrix3AdapterI8;
	/// <summary>
	/// Adapter for matrix of size 4 with 1 byte signed integer values
	/// </summary>
	typedef MatrixAdapter<Matrix4U8, Int8> Matrix4AdapterI8;
	/// <summary>
	/// Adapter for matrix of size 2 with 2 byte signed integer values
	/// </summary>
	typedef MatrixAdapter<Matrix2U16, Int16> Matrix2AdapterI16;
	/// <summary>
	/// Adapter for matrix of size 3 with 2 byte signed integer values
	/// </summary>
	typedef MatrixAdapter<Matrix3U16, Int16> Matrix3AdapterI16;
	/// <summary>
	/// Adapter for matrix of size 4 with 2 byte signed integer values
	/// </summary>
	typedef MatrixAdapter<Matrix4U16, Int16> Matrix4AdapterI16;
	/// <summary>
	/// Adapter for matrix of size 2 with 4 byte signed integer values
	/// </summary>
	typedef MatrixAdapter<Matrix2U32, Int32> Matrix2AdapterI32;
	/// <summary>
	/// Adapter for matrix of size 3 with 4 byte signed integer values
	/// </summary>
	typedef MatrixAdapter<Matrix3U32, Int32> Matrix3AdapterI32;
	/// <summary>
	/// Adapter for matrix of size 4 with 4 byte signed integer values
	/// </summary>
	typedef MatrixAdapter<Matrix4U32, Int32> Matrix4AdapterI32;
	/// <summary>
	/// Adapter for matrix of size 2 with floating point values
	/// </summary>
	typedef MatrixAdapter<Matrix2F, Float32> Matrix2AdapterF;
	/// <summary>
	/// Adapter for matrix of size 3 with floating point values
	/// </summary>
	typedef MatrixAdapter<Matrix3F, Float32> Matrix3AdapterF;
	/// <summary>
	/// Adapter for matrix of size 4 with floating point values
	/// </summary>
	typedef MatrixAdapter<Matrix4F, Float32> Matrix4AdapterF;
	/// <summary>
	/// Image with 1 byte dimensions and 1 bit pixels
	/// </summary>
	typedef Image<UInt1, UInt8> Image8U1;
	/// <summary>
	/// Image with 1 byte dimensions and 1 byte pixels
	/// </summary>
	typedef Image<UInt8, UInt8> Image8U8;
	/// <summary>
	/// Image with 1 byte dimensions and 2 byte pixels
	/// </summary>
	typedef Image<UInt16, UInt8> Image8U16;
	/// <summary>
	/// Image with 1 byte dimensions and 4 byte pixels
	/// </summary>
	typedef Image<UInt32, UInt8> Image8U32;
	/// <summary>
	/// Image with 1 byte dimensions and floating point pixels
	/// </summary>
	typedef Image<Float32, UInt8> Image8F;
	/// <summary>
	/// Image with 2 byte dimensions and 1 bit pixels
	/// </summary>
	typedef Image<UInt1, UInt16> Image16U1;
	/// <summary>
	/// Image with 2 byte dimensions and 1 byte pixels
	/// </summary>
	typedef Image<UInt8, UInt16> Image16U8;
	/// <summary>
	/// Image with 2 byte dimensions and 2 byte pixels
	/// </summary>
	typedef Image<UInt16, UInt16> Image16U16;
	/// <summary>
	/// Image with 2 byte dimensions and 4 byte pixels
	/// </summary>
	typedef Image<UInt32, UInt16> Image16U32;
	/// <summary>
	/// Image with 2 byte dimensions and floating point pixels
	/// </summary>
	typedef Image<Float32, UInt16> Image16F;

}

#endif // COMMON_H

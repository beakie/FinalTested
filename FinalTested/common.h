#ifndef COMMON_H
#define COMMON_H

#include "core.h"
#include "common-array.h"
#include "common-bounds_.h"
#include "common-castpixelconv.h"
#include "common-chainpixelconv.h"
#include "common-image.h"
#include "common-imatrixadapter.h"
#include "common-ipixelconverter.h"
#include "common-matrix2.h"
#include "common-matrix3.h"
#include "common-matrix4.h"
#include "common-matrixn.h"
#include "common-scalecastpixelconv.h"
#include "common-tuple.h"
#include "common-unitinterval.h"
#include "common-vector2.h"
#include "common-vector3.h"
#include "common-vector4.h"

namespace Common
{
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
	/// matrix of size 2 with max byte unsigned integer values
	/// </summary>
	typedef Matrix2<UIntMax> Matrix2U;
	/// <summary>
	/// matrix of size 3 with max byte unsigned integer values
	/// </summary>
	typedef Matrix3<UIntMax> Matrix3U;
	/// <summary>
	/// matrix of size 4 with max byte unsigned integer values
	/// </summary>
	typedef Matrix4<UIntMax> Matrix4U;
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
	/// matrix of size 2 with max byte signed integer values
	/// </summary>
	typedef Matrix2<IntMax> Matrix2I;
	/// <summary>
	/// matrix of size 3 with max byte signed integer values
	/// </summary>
	typedef Matrix3<IntMax> Matrix3I;
	/// <summary>
	/// matrix of size 4 with max byte signed integer values
	/// </summary>
	typedef Matrix4<IntMax> Matrix4I;
	/// <summary>
	/// matrix of size 2 with 32 bit floating point values
	/// </summary>
	typedef Matrix2<Float32> Matrix2F32;
	/// <summary>
	/// matrix of size 3 with 32 bit floating point values
	/// </summary>
	typedef Matrix3<Float32> Matrix3F32;
	/// <summary>
	/// matrix of size 4 with 32 bit floating point values
	/// </summary>
	typedef Matrix4<Float32> Matrix4F32;
	/// <summary>
	/// matrix of size 2 with 64 bit floating point values
	/// </summary>
	typedef Matrix2<Float64> Matrix2F64;
	/// <summary>
	/// matrix of size 3 with 64 bit floating point values
	/// </summary>
	typedef Matrix3<Float64> Matrix3F64;
	/// <summary>
	/// matrix of size 4 with 64 bit floating point values
	/// </summary>
	typedef Matrix4<Float64> Matrix4F64;
	/// <summary>
	/// matrix of size 2 with max bit floating point values
	/// </summary>
	typedef Matrix2<FloatMax> Matrix2F;
	/// <summary>
	/// matrix of size 3 with max bit floating point values
	/// </summary>
	typedef Matrix3<FloatMax> Matrix3F;
	/// <summary>
	/// matrix of size 4 with max bit floating point values
	/// </summary>
	typedef Matrix4<FloatMax> Matrix4F;
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
	/// Image with 1 byte dimensions and max byte pixels
	/// </summary>
	typedef Image<UIntMax, UInt8> Image8U;
	/// <summary>
	/// Image with 1 byte dimensions and 32 bit floating point pixels
	/// </summary>
	typedef Image<Float32, UInt8> Image8F32;
	/// <summary>
	/// Image with 1 byte dimensions and 64 bit floating point pixels
	/// </summary>
	typedef Image<Float64, UInt8> Image8F64;
	/// <summary>
	/// Image with 1 byte dimensions and max bit floating point pixels
	/// </summary>
	typedef Image<FloatMax, UInt8> Image8F;
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
	/// Image with 2 byte dimensions and max byte pixels
	/// </summary>
	typedef Image<UIntMax, UInt16> Image16U;
	/// <summary>
	/// Image with 2 byte dimensions and 32 bit floating point pixels
	/// </summary>
	typedef Image<Float32, UInt16> Image16F32;
	/// <summary>
	/// Image with 2 byte dimensions and 64 bit floating point pixels
	/// </summary>
	typedef Image<Float64, UInt16> Image16F64;
	/// <summary>
	/// Image with 2 byte dimensions and max bit floating point pixels
	/// </summary>
	typedef Image<FloatMax, UInt16> Image16F;

}

#endif // COMMON_H

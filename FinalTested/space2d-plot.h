#ifndef SPACE2DPLOT_H
#define SPACE2DPLOT_H

#include "common.h"

namespace Space2d
{

	/// <summary>
	/// 1 byte precision signed plot
	/// </summary>
	typedef Common::Vector2<Int8> PlotI8;

	/// <summary>
	/// 2 byte precision signed plot
	/// </summary>
	typedef Common::Vector2<Int16> PlotI16;

	/// <summary>
	/// 4 byte precision signed plot
	/// </summary>
	typedef Common::Vector2<Int32> PlotI32;

	/// <summary>
	/// max byte precision signed plot
	/// </summary>
	typedef Common::Vector2<IntMax> PlotI;

	/// <summary>
	/// 1 byte precision unsigned plot
	/// </summary>
	typedef Common::Vector2<UInt8> PlotU8;

	/// <summary>
	/// 2 byte precision unsigned plot
	/// </summary>
	typedef Common::Vector2<UInt16> PlotU16;

	/// <summary>
	/// 4 byte precision unsigned plot
	/// </summary>
	typedef Common::Vector2<UInt32> PlotU32;

	/// <summary>
	/// max byte precision unsigned plot
	/// </summary>
	typedef Common::Vector2<UIntMax> PlotU;

	/// <summary>
	/// 4 byte precision floating number plot
	/// </summary>
	typedef Common::Vector2<Float32> PlotF32;

	/// <summary>
	/// 8 byte precision floating number plot
	/// </summary>
	typedef Common::Vector2<Float64> PlotF64;

	/// <summary>
	/// max byte precision floating number plot
	/// </summary>
	typedef Common::Vector2<FloatMax> PlotF;

}

#endif // SPACE2DPLOT_H

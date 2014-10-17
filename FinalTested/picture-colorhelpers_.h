#ifndef PICTURECOLORHELPERS_H
#define PICTURECOLORHELPERS_H

#include "common.h"

namespace Picture
{
	template <typename TUNITINTERVAL = Common::UnitIntervalMax>
	static Common::Vector3<TUNITINTERVAL> getWhiteRgb()
	{
		return Common::Vector3<TUNITINTERVAL>(1, 1, 1);
	}

	template <typename TUNITINTERVAL = Common::UnitIntervalMax>
	static Common::Vector3<TUNITINTERVAL> getSilverRgb()
	{
		return Common::Vector3<TUNITINTERVAL>(0.75, 0.75, 0.75);
	}

	template <typename TUNITINTERVAL = Common::UnitIntervalMax>
	static Common::Vector3<TUNITINTERVAL> getGreyRgb()
	{
		return Common::Vector3<TUNITINTERVAL>(0.5, 0.5, 0.5);
	}

	template <typename TUNITINTERVAL = Common::UnitIntervalMax>
	static Common::Vector3<TUNITINTERVAL> getBlackRgb()
	{
		return Common::Vector3<TUNITINTERVAL>(0, 0, 0);
	}

	template <typename TUNITINTERVAL = Common::UnitIntervalMax>
	static Common::Vector3<TUNITINTERVAL> getRedRgb()
	{
		return Common::Vector3<TUNITINTERVAL>(1, 0, 0);
	}

	template <typename TUNITINTERVAL = Common::UnitIntervalMax>
	static Common::Vector3<TUNITINTERVAL> getMaroonRgb()
	{
		return Common::Vector3<TUNITINTERVAL>(0.5, 0, 0);
	}

	template <typename TUNITINTERVAL = Common::UnitIntervalMax>
	static Common::Vector3<TUNITINTERVAL> getYellowRgb()
	{
		return Common::Vector3<TUNITINTERVAL>(1, 1, 0);
	}

	template <typename TUNITINTERVAL = Common::UnitIntervalMax>
	static Common::Vector3<TUNITINTERVAL> getOliveRgb()
	{
		return Common::Vector3<TUNITINTERVAL>(0.5, 0.5, 0);
	}

	template <typename TUNITINTERVAL = Common::UnitIntervalMax>
	static Common::Vector3<TUNITINTERVAL> getLimeRgb()
	{
		return Common::Vector3<TUNITINTERVAL>(0, 1, 0);
	}

	template <typename TUNITINTERVAL = Common::UnitIntervalMax>
	static Common::Vector3<TUNITINTERVAL> getGreenRgb()
	{
		return Common::Vector3<TUNITINTERVAL>(0, 0.5, 0);
	}

	template <typename TUNITINTERVAL = Common::UnitIntervalMax>
	static Common::Vector3<TUNITINTERVAL> getAquaRgb()
	{
		return Common::Vector3<TUNITINTERVAL>(0, 1, 1);
	}

	template <typename TUNITINTERVAL = Common::UnitIntervalMax>
	static Common::Vector3<TUNITINTERVAL> getTealRgb()
	{
		return Common::Vector3<TUNITINTERVAL>(0, 0.5, 0.5);
	}

	template <typename TUNITINTERVAL = Common::UnitIntervalMax>
	static Common::Vector3<TUNITINTERVAL> getBlueRgb()
	{
		return Common::Vector3<TUNITINTERVAL>(0, 0, 1);
	}

	template <typename TUNITINTERVAL = Common::UnitIntervalMax>
	static Common::Vector3<TUNITINTERVAL> getNavyRgb()
	{
		return Common::Vector3<TUNITINTERVAL>(0, 0, 0.5);
	}

	template <typename TUNITINTERVAL = Common::UnitIntervalMax>
	static Common::Vector3<TUNITINTERVAL> getFuchsiaRgb()
	{
		return Common::Vector3<TUNITINTERVAL>(1, 0, 1);
	}

	template <typename TUNITINTERVAL = Common::UnitIntervalMax>
	static Common::Vector3<TUNITINTERVAL> getPurpleRgb()
	{
		return Common::Vector3<TUNITINTERVAL>(0.5, 0, 0.5);
	}
}

#endif // PICTURECOLORHELPERS_H

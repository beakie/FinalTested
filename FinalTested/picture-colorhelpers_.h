#ifndef PICTURECOLORHELPERS_H
#define PICTURECOLORHELPERS_H

#include "common.h"

namespace Picture
{
	template <typename TUINTINTERVAL>
	static Common::Vector3<TUINTINTERVAL> getWhiteRgb()
	{
		return Common::Vector3<TUINTINTERVAL>(1, 1, 1);
	}

	template <typename TUINTINTERVAL>
	static Common::Vector3<TUINTINTERVAL> getSilverRgb()
	{
		return Common::Vector3<TUINTINTERVAL>(0.75, 0.75, 0.75);
	}

	template <typename TUINTINTERVAL>
	static Common::Vector3<TUINTINTERVAL> getGreyRgb()
	{
		return Common::Vector3<TUINTINTERVAL>(0.5, 0.5, 0.5);
	}

	template <typename TUINTINTERVAL>
	static Common::Vector3<TUINTINTERVAL> getBlackRgb()
	{
		return Common::Vector3<TUINTINTERVAL>(0, 0, 0);
	}

	template <typename TUINTINTERVAL>
	static Common::Vector3<TUINTINTERVAL> getRedRgb()
	{
		return Common::Vector3<TUINTINTERVAL>(1, 0, 0);
	}

	template <typename TUINTINTERVAL>
	static Common::Vector3<TUINTINTERVAL> getMaroonRgb()
	{
		return Common::Vector3<TUINTINTERVAL>(0.5, 0, 0);
	}

	template <typename TUINTINTERVAL>
	static Common::Vector3<TUINTINTERVAL> getYellowRgb()
	{
		return Common::Vector3<TUINTINTERVAL>(1, 1, 0);
	}

	template <typename TUINTINTERVAL>
	static Common::Vector3<TUINTINTERVAL> getOliveRgb()
	{
		return Common::Vector3<TUINTINTERVAL>(0.5, 0.5, 0);
	}

	template <typename TUINTINTERVAL>
	static Common::Vector3<TUINTINTERVAL> getLimeRgb()
	{
		return Common::Vector3<TUINTINTERVAL>(0, 1, 0);
	}

	template <typename TUINTINTERVAL>
	static Common::Vector3<TUINTINTERVAL> getGreenRgb()
	{
		return Common::Vector3<TUINTINTERVAL>(0, 0.5, 0);
	}

	template <typename TUINTINTERVAL>
	static Common::Vector3<TUINTINTERVAL> getAquaRgb()
	{
		return Common::Vector3<TUINTINTERVAL>(0, 1, 1);
	}

	template <typename TUINTINTERVAL>
	static Common::Vector3<TUINTINTERVAL> getTealRgb()
	{
		return Common::Vector3<TUINTINTERVAL>(0, 0.5, 0.5);
	}

	template <typename TUINTINTERVAL>
	static Common::Vector3<TUINTINTERVAL> getBlueRgb()
	{
		return Common::Vector3<TUINTINTERVAL>(0, 0, 1);
	}

	template <typename TUINTINTERVAL>
	static Common::Vector3<TUINTINTERVAL> getNavyRgb()
	{
		return Common::Vector3<TUINTINTERVAL>(0, 0, 0.5);
	}

	template <typename TUINTINTERVAL>
	static Common::Vector3<TUINTINTERVAL> getFuchsiaRgb()
	{
		return Common::Vector3<TUINTINTERVAL>(1, 0, 1);
	}

	template <typename TUINTINTERVAL>
	static Common::Vector3<TUINTINTERVAL> getPurpleRgb()
	{
		return Common::Vector3<TUINTINTERVAL>(0.5, 0, 0.5);
	}
}

#endif // PICTURECOLORHELPERS_H

/// <summary>
/// ...
/// </summary>
template <typename TVALUE, typename TINDEX>
static TripleChannelPixel<TVALUE> mapImageTo3ChannelFalse(const TVALUE& value)
{
	TripleChannelPixel<TVALUE>

		for (TINDEX x = 0; x < image.Width; x++)
			for (TINDEX y = 0; y < image.Height; y++)
			{
		i.Values[x][y] = TripleChannelPixel<TVALUE>(1, 1, 1);
			}

	return i;
}

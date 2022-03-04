#include <iostream>

const
int main()
{
	// Image
	const int image_width  = 256;
	const int image_height = 256;

	// Render

	std::cout << "P3\n" << image_width << ' ' << image_height << "\n255\n";

	for (int col = image_height - 1; col >= 0; --col)
	{
		for (int row = 0; row < image_height; ++row)
		{
			auto r = double(row) / (image_width - 1);
			auto g = double(col) / (image_height - 1);
			auto b = 0.25;

			int rowR = static_cast<int>(255.999 * r);
			int rowG = static_cast<int>(255.999 * g);
			int rowB = static_cast<int>(255.999 * b);

			std::cout << rowR << ' ' << rowG << ' ' << rowB << '\n';
		}
	}
}
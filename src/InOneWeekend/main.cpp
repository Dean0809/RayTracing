#include "colour.h"
#include "vec3.h"
#include "ray.h"
#include <iostream>

colour ray_colour(const ray& r)
{
	vec3 unitDir = r.direction().normalize();
	auto t = 0.5f * (unitDir[1] + 1.0f);
	return (1.0f - t) * colour(1.0f, 1.0f, 1.0f) + t * colour(0.5f, 0.7f, 1.0f);
}


int main()
{
	// Image
	const auto aspectRatio = 16.0f / 9.0f;
	const int image_width  = 400;
	const int image_height = static_cast<int>(image_width / aspectRatio);

	// Camera
	auto viewportHeight = 2.0f;
	auto viewportWidth = aspectRatio * viewportHeight;
	auto focal_length = 1.0f;

	auto orgin = point3(0.f, 0.f, 0.f);
	auto horizontal = vec3(viewportWidth, 0.f, 0.f);
	auto vertical = vec3(0.f, viewportHeight, 0.f);
	auto lowerLeftCorner = orgin - horizontal / 2 - vertical / 2 - vec3(0, 0, focal_length);


	// Render

	std::cout << "P3\n" << image_width << ' ' << image_height << "\n255\n";

	for (int col = image_height - 1; col >= 0; --col)
	{
		std::cerr << "\rScanlines remaining:" << col << ' ' << std::flush;
		for (int row = 0; row < image_width; ++row)
		{
			auto u = float(row) / (image_width - 1);
			auto v = float(col) / (image_height - 1);
			ray r(orgin, lowerLeftCorner + u * horizontal + v * vertical - orgin);
			colour pixel_colour = ray_colour(r);
			write_colour(std::cout, pixel_colour);
		}
	}
	std::cerr << "\nDone\n";
}
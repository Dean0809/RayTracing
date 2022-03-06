#include "rtweekend.h"
#include "camera.h"
#include "colour.h"
#include "hittable_list.h"
#include "sphere.h"

#include <iostream>
colour ray_colour(const ray& r, const hittable& world);


int main()
{
	// Image
	const auto aspectRatio = 16.0f / 9.0f;
	const int image_width  = 400;
	const int image_height = static_cast<int>(image_width / aspectRatio);
	const int samples_per_pixel = 100;

	// World
	hittable_list world;
	world.add(make_shared<sphere> (point3(0.0f, 0.0f, -1.0f), 0.5f));
	world.add(make_shared<sphere> (point3(0.0f, -100.5f, -1.0f), 100.0f));

	camera cam;


	// Render

	std::cout << "P3\n" << image_width << ' ' << image_height << "\n255\n";

	for (int col = image_height - 1; col >= 0; --col)
	{
		std::cerr << "\rScanlines remaining:" << col << ' ' << std::flush;
		for (int row = 0; row < image_width; ++row)
		{
			colour pixel_colour(0.0f, 0.0f, 0.0f);
			for (int i = 0; i < samples_per_pixel; ++i)
			{
				auto u = float(row) / (image_width - 1);
				auto v = float(col) / (image_height - 1);
				ray r = cam.get_ray(u, v);
				pixel_colour += ray_colour(r, world);
				write_colour(std::cout, pixel_colour, samples_per_pixel);
			}
		}
	}
	std::cerr << "\nDone\n";
}


colour ray_colour(const ray& r, const hittable& world)
{	
	hit_record rec;
	if(world.hit(r, 0, infinity, rec))
		return 0.5 * (rec.normal + colour(1.0f, 1.0f, 1.0f));

	vec3 unitDir = r.direction().normalize();
	auto t = 0.5f * (unitDir[1] + 1.0f);
	return (1.0f - t) * colour(1.0f, 1.0f, 1.0f) + t * colour(0.5f, 0.7f, 1.0f);
}
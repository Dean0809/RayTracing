#ifndef SPHERE_H
#define SPHERE_H
#include "rtweekend.h"
#include "hittable.h"


class sphere : public hittable
{
public:
    point3 center;
    float radius;
public:
    sphere() {}
    sphere(point3 newCenter, float r) : center(newCenter), radius(r) {}
    virtual bool hit(const ray& r, float t_min, float t_max, hit_record& rec) const override;
};

bool sphere::hit(const ray& r, float t_min, float t_max, hit_record& rec) const
{
    vec3 oc = r.origin() - center;
	vec3 dir = r.direction();
	// t^2 * b * b + 2tb * (A-C) + (A-C) * (A-C) - r^2 = 0
	auto a = dir.length() * dir.length();
	auto half_b = dir.dot(oc);
	auto c = oc.length() * oc.length() - radius * radius;
	auto discriminant = half_b * half_b - a * c;

	if(discriminant < 0) return false;
	auto sqrtd = sqrt(discriminant);

    auto root = (-half_b - sqrtd) / a;
    if(root < t_min || t_max < root)
    {
        root = (-half_b + sqrtd) / a;
        if(root < t_min || t_max < root)
            return false;
    }

    rec.t = root;
    rec.p = r.at(rec.t);
    vec3 outward_normal = (rec.p - center) / radius;
    rec.set_face_normal(r, outward_normal);

    return true;
}
#endif
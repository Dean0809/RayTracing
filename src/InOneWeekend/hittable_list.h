#ifndef HITTABLE_LIST_H
#define HITTABLE_LIST_H
#include "rtweekend.h"
#include "hittable.h"

#include <memory>
#include <vector>

class hittable_list : public hittable
{
public:
    std::vector<shared_ptr<hittable>> objects;
public:
    hittable_list() {}
    hittable_list(shared_ptr<hittable> object) {add(object);}

    void clear();
    void add(shared_ptr<hittable> object);
    virtual bool hit(const ray& r, float t_min, float t_max, hit_record& rec) const override;
};

void hittable_list::clear()
{
    objects.clear();
}

void hittable_list::add(shared_ptr<hittable> object)
{
    objects.push_back(object);
}

bool hittable_list::hit(const ray& r, float t_min, float t_max, hit_record& rec) const
{
    hit_record temp_rec;
    bool hit_anything = false;
    auto closest_so_far = t_max;

    for(const auto& object : objects)
    {
        if(object->hit(r, t_min, closest_so_far, temp_rec))
        {
            hit_anything = true;
            closest_so_far = temp_rec.t;
            rec = temp_rec;
        }
    }

    return hit_anything;
}

#endif
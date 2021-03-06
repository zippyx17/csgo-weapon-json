#ifndef WEAPON_ATTRIBUTES_H
#define WEAPON_ATTRIBUTES_H

#include <string>
#include <boost/ptr_container/ptr_map.hpp>

class KeyValues;

struct WeaponAttributes
{
public:
    WeaponAttributes(KeyValues* item_class, KeyValues* weapon_attrs, const std::string& item_type);
    WeaponAttributes(KeyValues* item_class, const std::string& item_type);

    std::string item_type;
    int max_player_speed, max_player_speed_alt;
    std::string flinch_velocity_mod_small, flinch_velocity_mod_large;
    int penetration, damage;
    std::string range, range_modifier;
    int bullets;
    std::string cycle_time, cycle_time_alt;
    std::string spread;
    std::string inaccuracy_crouch, inaccuracy_stand, inaccuracy_jump, inaccuracy_land,
        inaccuracy_ladder, inaccuracy_fire, inaccuracy_move;
    std::string spread_alt;
    std::string inaccuracy_crouch_alt, inaccuracy_stand_alt, inaccuracy_jump_alt, inaccuracy_land_alt,
        inaccuracy_ladder_alt, inaccuracy_fire_alt, inaccuracy_move_alt;
    std::string recoil_angle, recoil_angle_variance, recoil_magnitude, recoil_magnitude_variance;
    std::string recoil_angle_alt, recoil_angle_variance_alt, recoil_magnitude_alt, recoil_magnitude_variance_alt;
    int recoil_seed;
    std::string inaccuracy_reload, inaccuracy_alt_switch;
    std::string recovery_time_crouch, recovery_time_stand;
    std::string armor_ratio;
    int full_auto, clip_size;
    int price;
    std::string model_world, model_player;

private:
    void load_item_class(KeyValues* item_class);
    void load_weapon_attrs(KeyValues* weapon_attrs);
};

class WeaponAttributesDatabase
{
public:

    WeaponAttributesDatabase(const char* manifest_filename, const char* items_script_filename, const char* resource_filename);

    const WeaponAttributes* get(const char* weapon_name) const;
    void write_json(const char* filename, const char* version) const;

private:
    typedef boost::ptr_map<std::string, WeaponAttributes> weapon_attrs_t;
    weapon_attrs_t weapon_attrs_;
};

#endif

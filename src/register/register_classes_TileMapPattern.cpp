#include "register/register_classes.h"
#include "register/utils.h"
#include <godot_cpp/classes/tile_map_pattern.hpp>

using namespace godot;

void register_classes_TileMapPattern() {
    qjs::Context::Module &_module = _General;
    _module.class_<TileMapPattern>("TileMapPattern")
           .constructor<>()
		    .fun<static_cast<void(TileMapPattern::*)(const Vector2i &,int32_t,const Vector2i &,int32_t)>(&TileMapPattern::set_cell)>("set_cell")
		    .fun<static_cast<bool(TileMapPattern::*)(const Vector2i &)const>(&TileMapPattern::has_cell)>("has_cell")
		    .fun<static_cast<void(TileMapPattern::*)(const Vector2i &,bool)>(&TileMapPattern::remove_cell)>("remove_cell")
		    .fun<static_cast<int32_t(TileMapPattern::*)(const Vector2i &)const>(&TileMapPattern::get_cell_source_id)>("get_cell_source_id")
		    .fun<static_cast<Vector2i(TileMapPattern::*)(const Vector2i &)const>(&TileMapPattern::get_cell_atlas_coords)>("get_cell_atlas_coords")
		    .fun<static_cast<int32_t(TileMapPattern::*)(const Vector2i &)const>(&TileMapPattern::get_cell_alternative_tile)>("get_cell_alternative_tile")
		    .fun<static_cast<TypedArray<Vector2i>(TileMapPattern::*)()const>(&TileMapPattern::get_used_cells)>("get_used_cells")
		    .fun<static_cast<Vector2i(TileMapPattern::*)()const>(&TileMapPattern::get_size)>("get_size")
		    .fun<static_cast<void(TileMapPattern::*)(const Vector2i &)>(&TileMapPattern::set_size)>("set_size")
		    .fun<static_cast<bool(TileMapPattern::*)()const>(&TileMapPattern::is_empty)>("is_empty")
;}
/* This file is part of the Spring engine (GPL v2 or later), see LICENSE.html */

#ifndef LUA_ATLAS_TEXTURES_H
#define LUA_ATLAS_TEXTURES_H

#include <string>

#include "Rendering/GL/myGL.h"
#include "System/UnorderedMap.hpp"
#include "System/SafeUtil.h"

class CTextureAtlas;
struct AtlasedTexture;

class LuaAtlasTextures {
public:
	static const char prefix = '*';

	~LuaAtlasTextures() { Clear(); }
	LuaAtlasTextures() {
		textureAtlasMap.reserve(32);
	}

	void Clear();

	std::string Create(const std::string& name, const int xsize, const int ysize, const int allocatorType = 0);
	bool Delete(const std::string& idStr);
	CTextureAtlas* GetAtlasById(const std::string& idStr) const;
	CTextureAtlas* GetAtlasByIndex(const size_t index) const;
	size_t GetAtlasIndexById(const std::string& idStr) const;
	size_t GetNextId() { return lastIndex; }
private:
	using TextureAtlasMap = spring::unsynced_map<size_t, CTextureAtlas*>;
private:
	bool GetIterator(const std::string& idStr, TextureAtlasMap::iterator& iter);
	bool GetIterator(const std::string& idStr, TextureAtlasMap::const_iterator& iter) const;
	// maps names to textureVec indices
	TextureAtlasMap textureAtlasMap;
	size_t lastIndex = 1;
};

#endif /* LUA_ATLAS_TEXTURES_H */

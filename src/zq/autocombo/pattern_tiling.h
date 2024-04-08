#pragma once

#include <functional>
#include "base/autocombo.h"
#include "zq/autocombo/autopattern_base.h"

namespace AutoPattern
{
	class tiling : public container
	{
	public:
		explicit tiling(int32_t ntype, int32_t nlayer, int32_t nbasescreen, int32_t nbasepos, combo_auto* nsource) :
			container(ntype, nlayer, nbasescreen, nbasepos, nsource),
			size(std::make_pair((nsource->getArg() & 0xF) + 1, ((nsource->getArg() >> 4) & 0xF) + 1)), offsets(nsource->getOffsets()) {}
		virtual bool execute(int32_t exscreen, int32_t expos) override;
		virtual bool erase(int32_t exscreen, int32_t expos) override;
		virtual int32_t get_floating_cid(int32_t s, int32_t p) override;
		virtual uint32_t slot_to_flags(int32_t slot) override;
		virtual int32_t flags_to_slot(uint32_t flags) override;
	private:
		std::pair<byte, byte> size;
		std::pair<byte, byte> offsets;
	};
}

/* -*- Mode: C++; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*- */
/*
 * Copyright (C) Flamewing 2017 <flamewing.sonic@gmail.com>
 * Loosely based on code by snkenjoi
 *
 * This program is free software: you can redistribute it and/or modify it
 * under the terms of the GNU Lesser General Public License as published
 * by the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#include <iosfwd>
#include <mdcomp/basic_decoder.hh>
#include <mdcomp/moduled_adaptor.hh>

class snkrle;
using basic_snkrle = BasicDecoder<snkrle, PadMode::PadEven>;
using moduled_snkrle = ModuledAdaptor<snkrle, 4096u, 1u>;

class snkrle : public basic_snkrle, public moduled_snkrle {
	friend basic_snkrle;
	friend moduled_snkrle;
	static bool encode(std::ostream &Dst, uint8_t const *data, size_t const Size);
public:
	using basic_snkrle::encode;
	static bool decode(std::istream &Src, std::ostream &Dst);
};

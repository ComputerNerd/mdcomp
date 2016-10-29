/* -*- Mode: C++; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*- */
/*
 * Copyright (C) Flamewing 2015-2016 <flamewing.sonic@gmail.com>
 *
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

#ifndef __LIB_MKOSINSKI_H
#define __LIB_MKOSINSKI_H

#include <iosfwd>

class mkosinski {
public:
	static bool decode(std::istream &Src, std::iostream &Dst,
	                   size_t Location = 0, bool Moduled = false);
	static bool encode(std::istream &Src, std::ostream &Dst,
	                   bool Moduled = false, size_t ModuleSize = 0x1000);
};

#endif // __LIB_MKOSINSKI_H

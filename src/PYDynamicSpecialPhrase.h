/* vim:set et ts=4 sts=4:
 *
 * ibus-libpinyin - Intelligent Pinyin engine based on libpinyin for IBus
 *
 * Copyright (c) 2008-2010 Peng Huang <shawn.p.huang@gmail.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2, or (at your option)
 * any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 */
#ifndef __PY_DYNAMIC_SPECIAL_PHRASE_H_
#define __PY_DYNAMIC_SPECIAL_PHRASE_H_

#include <ctime>
#include <string>
#include <glib.h>
#include "PYSpecialPhrase.h"

namespace PY {

class DynamicSpecialPhrase : public SpecialPhrase {
public:
    DynamicSpecialPhrase (const std::string &text, guint pos) :
        SpecialPhrase (pos), m_text (text) { }
    ~DynamicSpecialPhrase (void);

    std::string text (void);
    const std::string dec (gint d, const gchar *fmt = "%d");
    const std::string year_cn (gboolean yy = FALSE);
    const std::string month_cn (void);
    const std::string weekday_cn (void);
    const std::string hour_cn (guint i);
    const std::string fullhour_cn (void);
    const std::string halfhour_cn (void);
    const std::string day_cn (void);
    const std::string minsec_cn (guint i);
    const std::string variable (const std::string &name);

    /* declaration function about Chinese Number. */
    const std::string simplest_cn_number(gint64 num);
    const std::string simplified_number(gint64 num);
    const std::string traditional_number(gint64 num);

private:
    std::string m_text;
    std::tm m_time;
};

};
#endif

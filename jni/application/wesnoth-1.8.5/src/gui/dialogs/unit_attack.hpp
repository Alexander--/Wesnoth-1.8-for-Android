/* $Id$ */
/*
   Copyright (C) 2010 - 2011 by Chris Hopman <cjhopman@gmail.com>
   Part of the Battle for Wesnoth Project http://www.wesnoth.org/

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2 of the License, or
   (at your option) any later version.
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY.

   See the COPYING file for more details.
*/

#ifndef GUI_DIALOGS_UNIT_ATTACK_HPP_INCLUDED
#define GUI_DIALOGS_UNIT_ATTACK_HPP_INCLUDED

#include "gui/dialogs/dialog.hpp"

#include "actions.hpp"
#include "unit_map.hpp"

#include "attack_prediction_display.hpp"

namespace gui2 {

class tunit_attack
	: public tdialog
{
public:
	tunit_attack(
			  const unit_map::iterator& attacker_itor
			, const unit_map::iterator& defender_itor
			, const std::vector<battle_context>& weapons
			, const int best_weapon);

	/***** ***** ***** setters / getters for members ***** ****** *****/

	int get_selected_weapon() const { return selected_weapon_; }

private:

	/** Inherited from tdialog. */
	twindow* build_window(CVideo& video);

	/** Inherited from tdialog. */
	void pre_show(CVideo& video, twindow& window);

	/** Inherited from tdialog. */
	void post_show(twindow& window);

	void show_damage_calculations(twindow& window);
	void set_selected_weapon(twindow& window);

	/** The index of the selected weapon. */
	int selected_weapon_;

	/** Iterator pointing to the attacker. */
	unit_map::iterator attacker_itor_;

	/** Iterator pointing to the defender. */
	unit_map::iterator defender_itor_;

	/** List of all battle contexts used for getting the weapons. */
	std::vector<battle_context> weapons_;

	/** The best weapon, aka the one high-lighted. */
	int best_weapon_;
	attack_prediction_displayer ap_displayer_;

};

} // namespace gui2

#endif


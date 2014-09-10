#include "DataTypes.h"

bool AbilBonus::operator==(const AbilBonus& oth) const {
	return (abil == oth.abil && bonus == oth.bonus);
}

bool AbilBonus::operator!=(const AbilBonus& oth) const {
	return !(abil == oth.abil && bonus == oth.bonus);
}

bool Abilities::operator==(const Abilities& oth) const {
	return (str == oth.str && dex == oth.dex && con == oth.con
			&& intl == oth.intl && wis == oth.wis && cha == oth.cha);
}

bool Abilities::operator!=(const Abilities& oth) const {
	return (str != oth.str && dex != oth.dex && con != oth.con
			&& intl != oth.intl && wis != oth.wis && cha != oth.cha);
}
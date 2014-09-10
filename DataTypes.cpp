#include "DataTypes.h"

bool AbilBonus::operator==(const AbilBonus& oth) const {
	return (abil == oth.abil && bonus == oth.bonus);
}

bool AbilBonus::operator!=(const AbilBonus& oth) const {
	return !(abil == oth.abil && bonus == oth.bonus);
}
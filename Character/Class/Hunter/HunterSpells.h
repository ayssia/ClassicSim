#ifndef HUNTERSPELLS_H
#define HUNTERSPELLS_H

#include "CharacterSpells.h"

class Hunter;
class MultiShot;

class HunterSpells: public CharacterSpells {
public:
    HunterSpells(Hunter *hunter);

    void add_next_ranged_attack() override;

    AutoShoot* get_auto_shoot() const override;
    MultiShot* get_multi_shot() const;

private:
    Hunter* hunter;
    AutoShoot* auto_shoot;
    MultiShot* multi_shot;
};

#endif // HUNTERSPELLS_H

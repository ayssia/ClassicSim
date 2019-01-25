#include "Marksmanship.h"

#include "GenericTalent.h"
#include "Talent.h"

Marksmanship::Marksmanship(Character *pchar) :
    TalentTree("Marksmanship", "Assets/hunter/hunter_marksmanship.jpg")
{
    QMap<QString, Talent*> tier1 {{"1ML", new GenericTalent(pchar, this, "Improved Concussive Shot", "1ML", "Assets/spell/Spell_frost_stun.png", 5, "Gives your Concussive Shot a %1% chance to stun the target for 3 sec.", QVector<QPair<int, int>>{{4, 4}})},
                                  {"1MR", new GenericTalent(pchar, this, "Efficiency", "1MR", "Assets/spell/Spell_frost_wizardmark.png", 5, "Reduces the Mana cost of your Shots and Stings by %1%", QVector<QPair<int, int>>{{2, 2}})}};
    add_talents(tier1);

    QMap<QString, Talent*> tier2 {{"2ML", new GenericTalent(pchar, this, "Improved Hunter's Mark", "2ML", "Assets/ability/Ability_hunter_snipershot.png", 5, "Increases the Ranged Attack Power bonus of your Hunter's Mark spell by %1%.", QVector<QPair<int, int>>{{3, 3}})},
                                  {"2MR", new GenericTalent(pchar, this, "Lethal Shots", "2MR", "Assets/ability/Ability_searingarrow.png", 5, "Increases your critical strike chance with ranged weapons by %1%.", QVector<QPair<int, int>>{{1, 1}})}};
    add_talents(tier2);

    QMap<QString, Talent*> tier3 {{"3LL", new GenericTalent(pchar, this, "Aimed Shot", "3LL", "Assets/items/Inv_spear_07.png", 1, "An aimed shot that increases ranged damage by 70.", QVector<QPair<int, int>>())},
                                  {"3ML", new GenericTalent(pchar, this, "Improved Arcane Shot", "3ML", "Assets/ability/Ability_impalingbolt.png", 5, "Reduces the cooldown of your Arcane Shot by %1 sec.", QVector<QPair<double, double>>{{0.2, 0.2}})},
                                  {"3RR", new GenericTalent(pchar, this, "Hawk Eye", "3RR", "Assets/ability/Ability_townwatch.png", 3, "Increases the range of your ranged weapons by %1 yards.", QVector<QPair<int, int>>{{2, 2}})}};
    add_talents(tier3);

    QMap<QString, Talent*> tier4 {{"4ML", new GenericTalent(pchar, this, "Improved Serpent Sting", "4ML", "Assets/ability/Ability_hunter_quickshot.png", 5, "Increases the damage done by your Serpent Sting by %1%.", QVector<QPair<int, int>>{{2, 2}})},
                                  {"4MR", new GenericTalent(pchar, this, "Mortal Shots", "4MR", "Assets/ability/Ability_piercedamage.png", 5, "Increases your ranged weapon critical strike damage bonus by %1%.", QVector<QPair<int, int>>{{6, 6}})}};
    add_talents(tier4);

    QMap<QString, Talent*> tier5 {{"5LL", new GenericTalent(pchar, this, "Scatter Shot", "5LL", "Assets/ability/Ability_golemstormbolt.png", 1, "A short-range shot that deals 50% weapon damage and disorients the target for 4 sec. Any damage caused will remove the effect. Turns off your attack when used.", QVector<QPair<int, int>>())},
                                  {"5ML", new GenericTalent(pchar, this, "Barrage", "5ML", "Assets/ability/Ability_upgrademoonglaive.png", 3, "Increases the damage done by your Multi-Shot and Volley spells by %1%.", QVector<QPair<int, int>>{{5, 5}})},
                                  {"5MR", new GenericTalent(pchar, this, "Improved Scorpid Sting", "5MR", "Assets/ability/Ability_hunter_criticalshot.png", 3, "Reduces the Stamina of targets affected by your Scorpid Sting by %1% of the amount of Strength reduced.", QVector<QPair<int, int>>{{10, 10}})}};
    add_talents(tier5);

    QMap<QString, Talent*> tier6 {{"6MR", new GenericTalent(pchar, this, "Ranged Weapon Specialization", "6MR", "Assets/items/Inv_weapon_rifle_06.png", 5, "Increases the damage you deal with ranged weapons by %1%.", QVector<QPair<int, int>>{{1, 1}})}};
    add_talents(tier6);

    QMap<QString, Talent*> tier7 {{"7ML", new GenericTalent(pchar, this, "Trueshot Aura", "7ML", "Assets/ability/Ability_trueshot.png", 1, "Increases the attack power of party members within 45 yards by 50. Lasts 30 min.", QVector<QPair<int, int>>())}};
    add_talents(tier7);

    talents["2MR"]->talent->set_bottom_child(talents["4MR"]->talent);
    talents["4MR"]->talent->set_parent(talents["2MR"]->talent);

    talents["5ML"]->talent->set_bottom_child(talents["7ML"]->talent);
    talents["7ML"]->talent->set_parent(talents["5ML"]->talent);
}

Marksmanship::~Marksmanship() = default;
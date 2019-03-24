#include "ExternalBuff.h"

#include <utility>

#include "Character.h"
#include "CharacterStats.h"
#include "Target.h"

ExternalBuff::ExternalBuff(Character* pchar,
                           const QString& name,
                           const int dur,
                           const int base_charges,
                           ExternalBuffName buff_name,
                           AvailableFactions::Name faction,
                           QString icon,
                           QString description,
                           QVersionNumber min_patch):
    Buff(pchar, name, icon, dur, base_charges),
    buff_name(buff_name),
    faction(faction),
    description(std::move(description)),
    min_patch(std::move(min_patch))
{
    this->enabled = true;
    this->hidden = true;
}

ExternalBuff::~ExternalBuff() {
    if (this->is_active())
        cancel_buff();
}

QString ExternalBuff::get_description() const {
    return this->description;
}

bool ExternalBuff::valid_for_patch(const QString& patch) const {
    QVersionNumber new_version = QVersionNumber::fromString(patch);

    return min_patch <= new_version;
}

bool ExternalBuff::valid_for_faction(AvailableFactions::Name faction) const {
    if (this->faction == AvailableFactions::Neutral)
        return true;

    return this->faction == faction;
}

ExternalBuffName ExternalBuff::get_enum_value() const {
    return this->buff_name;
}

void ExternalBuff::buff_effect_when_applied() {
    switch (buff_name) {
    case ExternalBuffName::BattleShout:
        pchar->get_stats()->increase_melee_ap(232);
        break;
    case ExternalBuffName::RallyingCryOfTheDragonslayer:
        pchar->get_stats()->increase_spell_crit(1000);
        pchar->get_stats()->increase_melee_crit(500);
        pchar->get_stats()->increase_melee_ap(140);
        break;
    case ExternalBuffName::SpiritOfZandalar:
        pchar->get_stats()->add_total_stat_mod(15);
        break;
    case ExternalBuffName::SongflowerSerenade:
        pchar->get_stats()->increase_melee_crit(500);
        pchar->get_stats()->increase_agility(15);
        pchar->get_stats()->increase_strength(15);
        pchar->get_stats()->increase_stamina(15);
        pchar->get_stats()->increase_intellect(15);
        pchar->get_stats()->increase_spirit(15);
        break;
    case ExternalBuffName::ElixirOfTheMongoose:
        pchar->get_stats()->increase_agility(25);
        pchar->get_stats()->increase_melee_crit(200);
        break;
    case ExternalBuffName::ElixirOfBruteForce:
        pchar->get_stats()->increase_strength(18);
        pchar->get_stats()->increase_stamina(18);
        break;
    case ExternalBuffName::ElixirOfGiants:
        pchar->get_stats()->increase_strength(25);
        break;
    case ExternalBuffName::WinterfallFirewater:
        pchar->get_stats()->increase_melee_ap(35);
        break;
    case ExternalBuffName::JujuPower:
        pchar->get_stats()->increase_strength(30);
        break;
    case ExternalBuffName::MarkOfTheWild:
        pchar->get_stats()->increase_agility(16);
        pchar->get_stats()->increase_strength(16);
        pchar->get_stats()->increase_stamina(16);
        pchar->get_stats()->increase_intellect(16);
        pchar->get_stats()->increase_spirit(16);
        break;
    case ExternalBuffName::ScrollOfStrengthIV:
        pchar->get_stats()->increase_strength(17);
        break;
    case ExternalBuffName::SmokedDesertDumplings:
        pchar->get_stats()->increase_strength(20);
        break;
    case ExternalBuffName::ROIDS:
        pchar->get_stats()->increase_strength(25);
        break;
    case ExternalBuffName::BlessingOfKings:
        pchar->get_stats()->add_total_stat_mod(10);
        break;
    case ExternalBuffName::BlessingOfMight:
        pchar->get_stats()->increase_melee_ap(185);
        break;
    case ExternalBuffName::StrengthOfEarthTotem:
        pchar->get_stats()->increase_strength(77);
        break;
    case ExternalBuffName::Annihilator:
        pchar->get_target()->decrease_armor(600);
        break;
    case ExternalBuffName::CurseOfRecklessness:
        pchar->get_target()->decrease_armor(640);
        break;
    case ExternalBuffName::FaerieFire:
        pchar->get_target()->decrease_armor(505);
        break;
    case ExternalBuffName::SunderArmor:
        pchar->get_target()->decrease_armor(2250);
        break;
    }
}

void ExternalBuff::buff_effect_when_removed() {
    switch (buff_name) {
    case ExternalBuffName::BattleShout:
        pchar->get_stats()->decrease_melee_ap(232);
        break;
    case ExternalBuffName::RallyingCryOfTheDragonslayer:
        pchar->get_stats()->decrease_spell_crit(1000);
        pchar->get_stats()->decrease_melee_crit(500);
        pchar->get_stats()->decrease_melee_ap(140);
        break;
    case ExternalBuffName::SpiritOfZandalar:
        pchar->get_stats()->remove_total_stat_mod(15);
        break;
    case ExternalBuffName::SongflowerSerenade:
        pchar->get_stats()->decrease_melee_crit(500);
        pchar->get_stats()->decrease_agility(15);
        pchar->get_stats()->decrease_strength(15);
        pchar->get_stats()->decrease_stamina(15);
        pchar->get_stats()->decrease_intellect(15);
        pchar->get_stats()->decrease_spirit(15);
        break;
    case ExternalBuffName::ElixirOfTheMongoose:
        pchar->get_stats()->decrease_agility(25);
        pchar->get_stats()->decrease_melee_crit(200);
        break;
    case ExternalBuffName::ElixirOfBruteForce:
        pchar->get_stats()->decrease_strength(18);
        pchar->get_stats()->decrease_stamina(18);
        break;
    case ExternalBuffName::ElixirOfGiants:
        pchar->get_stats()->decrease_strength(25);
        break;
    case ExternalBuffName::WinterfallFirewater:
        pchar->get_stats()->decrease_melee_ap(35);
        break;
    case ExternalBuffName::JujuPower:
        pchar->get_stats()->decrease_strength(30);
        break;
    case ExternalBuffName::MarkOfTheWild:
        pchar->get_stats()->decrease_agility(16);
        pchar->get_stats()->decrease_strength(16);
        pchar->get_stats()->decrease_stamina(16);
        pchar->get_stats()->decrease_intellect(16);
        pchar->get_stats()->decrease_spirit(16);
        break;
    case ExternalBuffName::ScrollOfStrengthIV:
        pchar->get_stats()->decrease_strength(17);
        break;
    case ExternalBuffName::SmokedDesertDumplings:
        pchar->get_stats()->decrease_strength(20);
        break;
    case ExternalBuffName::ROIDS:
        pchar->get_stats()->decrease_strength(25);
        break;
    case ExternalBuffName::BlessingOfKings:
        pchar->get_stats()->remove_total_stat_mod(10);
        break;
    case ExternalBuffName::BlessingOfMight:
        pchar->get_stats()->decrease_melee_ap(185);
        break;
    case ExternalBuffName::StrengthOfEarthTotem:
        pchar->get_stats()->decrease_strength(77);
        break;
    case ExternalBuffName::Annihilator:
        pchar->get_target()->increase_armor(600);
        break;
    case ExternalBuffName::CurseOfRecklessness:
        pchar->get_target()->increase_armor(640);
        break;
    case ExternalBuffName::FaerieFire:
        pchar->get_target()->increase_armor(505);
        break;
    case ExternalBuffName::SunderArmor:
        pchar->get_target()->increase_armor(2250);
        break;
    }
}

ExternalBuff* get_external_buff_by_name(const ExternalBuffName name, Character* pchar) {
    switch (name) {
    case ExternalBuffName::BattleShout:
        return new ExternalBuff(pchar, "Improved Battle Shout", BuffDuration::PERMANENT, 0,
                                name, AvailableFactions::Neutral, "Assets/ability/Ability_warrior_battleshout.png",
                                "+232 attack power",
                                QVersionNumber::fromString("1.0.0"));
    case ExternalBuffName::RallyingCryOfTheDragonslayer:
        return new ExternalBuff(pchar, "Rallying Cry of the Dragonslayer", BuffDuration::PERMANENT, 0,
                                name, AvailableFactions::Neutral, "Assets/buffs/Inv_misc_head_dragon_01.png",
                                "+10% Spell crit, +5% melee/ranged crit, +140 attack power",
                                QVersionNumber::fromString("1.0.0"));
    case ExternalBuffName::SpiritOfZandalar:
        return new ExternalBuff(pchar, "Spirit of Zandalar", BuffDuration::PERMANENT, 0,
                                name, AvailableFactions::Neutral, "Assets/buffs/Ability_creature_poison_05.png",
                                "Increases movement speed by 10% and all stats by 15%",
                                QVersionNumber::fromString("1.0.0"));
    case ExternalBuffName::SongflowerSerenade:
        return new ExternalBuff(pchar, "Songflower Serenade", BuffDuration::PERMANENT, 0,
                                name, AvailableFactions::Neutral, "Assets/buffs/Spell_holy_mindvision.png",
                                "+5% Crit, +15 all attributes",
                                QVersionNumber::fromString("1.0.0"));
    case ExternalBuffName::ElixirOfTheMongoose:
        return new ExternalBuff(pchar, "Elixir of the Mongoose", BuffDuration::PERMANENT, 0,
                                name, AvailableFactions::Neutral, "Assets/buffs/Inv_potion_32.png",
                                "+25 Agility, +%2 Critical Strike",
                                QVersionNumber::fromString("1.0.0"));
    case ExternalBuffName::ElixirOfBruteForce:
        return new ExternalBuff(pchar, "Elixir of Brute Force", BuffDuration::PERMANENT, 0,
                                name, AvailableFactions::Neutral, "Assets/buffs/Inv_potion_40.png",
                                "+18 Strength and Stamina",
                                QVersionNumber::fromString("1.0.0"));
    case ExternalBuffName::ElixirOfGiants:
        return new ExternalBuff(pchar, "Elixir of Giants", BuffDuration::PERMANENT, 0,
                                name, AvailableFactions::Neutral, "Assets/buffs/Inv_potion_61.png",
                                "+25 Strength",
                                QVersionNumber::fromString("1.0.0"));
    case ExternalBuffName::WinterfallFirewater:
        return new ExternalBuff(pchar, "Winterfall Firewater", BuffDuration::PERMANENT, 0,
                                name, AvailableFactions::Neutral, "Assets/buffs/Inv_potion_92.png",
                                "+35 Melee attack power",
                                QVersionNumber::fromString("1.0.0"));
    case ExternalBuffName::JujuPower:
        return new ExternalBuff(pchar, "Juju Power", BuffDuration::PERMANENT, 0,
                                name, AvailableFactions::Neutral, "Assets/buffs/Inv_misc_monsterscales_11.png",
                                "+30 Strength",
                                QVersionNumber::fromString("1.0.0"));
    case ExternalBuffName::MarkOfTheWild:
        return new ExternalBuff(pchar, "Mark of the Wild", BuffDuration::PERMANENT, 0,
                                name, AvailableFactions::Neutral, "Assets/buffs/Spell_nature_regeneration.png",
                                "+16 all attributes, +384 armor, +27 all resistances",
                                QVersionNumber::fromString("1.0.0"));
    case ExternalBuffName::ScrollOfStrengthIV:
        return new ExternalBuff(pchar, "Scroll of Strength IV", BuffDuration::PERMANENT, 0,
                                name, AvailableFactions::Neutral, "Assets/buffs/Inv_scroll_02.png",
                                "+17 Strength",
                                QVersionNumber::fromString("1.0.0"));
    case ExternalBuffName::SmokedDesertDumplings:
        return new ExternalBuff(pchar, "Smoked Desert Dumplings", BuffDuration::PERMANENT, 0,
                                name, AvailableFactions::Neutral, "Assets/buffs/Inv_misc_food_64.png",
                                "+20 Strength",
                                QVersionNumber::fromString("1.0.0"));
    case ExternalBuffName::ROIDS:
        return new ExternalBuff(pchar, "R.O.I.D.S", BuffDuration::PERMANENT, 0,
                                name, AvailableFactions::Neutral, "Assets/buffs/Inv_stone_15.png",
                                "+25 Strength",
                                QVersionNumber::fromString("1.0.0"));
    case ExternalBuffName::BlessingOfKings:
        return new ExternalBuff(pchar, "Greater Blessing of Kings", BuffDuration::PERMANENT, 0,
                                name, AvailableFactions::Alliance, "Assets/buffs/Spell_magic_greaterblessingofkings.png",
                                "Increases total stats by 10%",
                                QVersionNumber::fromString("1.0.0"));
    case ExternalBuffName::BlessingOfMight:
        return new ExternalBuff(pchar, "Greater Blessing of Might", BuffDuration::PERMANENT, 0,
                                name, AvailableFactions::Alliance, "Assets/buffs/Spell_holy_greaterblessingofkings.png",
                                "Increases melee attack power by 185",
                                QVersionNumber::fromString("1.0.0"));
    case ExternalBuffName::StrengthOfEarthTotem:
        return new ExternalBuff(pchar, "Strength of Earth Totem", BuffDuration::PERMANENT, 0,
                                name, AvailableFactions::Horde, "Assets/buffs/Spell_nature_earthbindtotem.png",
                                "+77 Strength",
                                QVersionNumber::fromString("1.0.0"));
    case ExternalBuffName::Annihilator:
        return new ExternalBuff(pchar, "Annihilator Proc", BuffDuration::PERMANENT, 0,
                                name, AvailableFactions::Neutral, "Assets/items/Inv_axe_12.png",
                                "Reduces target armor by 600.",
                                QVersionNumber::fromString("1.0.0"));
    case ExternalBuffName::CurseOfRecklessness:
        return new ExternalBuff(pchar, "Curse of Recklessness", BuffDuration::PERMANENT, 0,
                                name, AvailableFactions::Neutral, "Assets/buffs/Spell_shadow_unholystrength.png",
                                "Reduces target armor by 640.",
                                QVersionNumber::fromString("1.0.0"));
    case ExternalBuffName::FaerieFire:
        return new ExternalBuff(pchar, "Faerie Fire", BuffDuration::PERMANENT, 0,
                                name, AvailableFactions::Neutral, "Assets/buffs/Spell_nature_faeriefire.png",
                                "Reduces target armor by 505.",
                                QVersionNumber::fromString("1.0.0"));
    case ExternalBuffName::SunderArmor:
        return new ExternalBuff(pchar, "Sunder Armor", BuffDuration::PERMANENT, 0,
                                name, AvailableFactions::Neutral, "Assets/ability/Ability_warrior_sunder.png",
                                "Reduces target armor by 2250.",
                                QVersionNumber::fromString("1.0.0"));
    }

    return nullptr;
}

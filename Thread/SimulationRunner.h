#ifndef SIMULATIONRUNNER_H
#define SIMULATIONRUNNER_H

#include <QObject>
#include <QMap>

class Character;
class CharacterDecoder;
class CombatRoll;
class Engine;
class Equipment;
class Faction;
class Race;
class Target;

class SimulationRunner: public QObject {
    Q_OBJECT
public:
    SimulationRunner(QString seed, QObject* parent = 0);
    ~SimulationRunner();

public slots:
    void run_sim(QString setup_string);

signals:
    void finished();
    void result(QString seed, float result);
    void error(QString seed, QString err);

protected:
private:
    Character* pchar;
    CombatRoll* combat;
    Engine* engine;
    Equipment* equipment;
    Faction* faction;
    Race* race;
    Target* target;

    QString setup_string;
    QString seed;

    QMap<QString, Character*> chars;
    QMap<QString, Race*> races;

    void setup_race(CharacterDecoder& decoder);
    void setup_pchar(CharacterDecoder& decoder);
    void equip_gear(CharacterDecoder& decoder);
    void invest_talent_points(CharacterDecoder& decoder);
    void add_points_to_talent_tree(CharacterDecoder &decoder, const QString& tree_position);
    void apply_external_buffs(CharacterDecoder& decoder);
    void setup_target(CharacterDecoder& decoder);
    void exit_thread(QString err);
    void delete_objects();
};

#endif // SIMULATIONRUNNER_H
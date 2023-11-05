#ifndef MONSTERDATA_H
#define MONSTERDATA_H

#include "src/engines/io/d2o/game/AbstractGameData.h"

class MonsterData : public AbstractGameData
{
public:
  int getId() const;
  uint getNameId() const;
  uint getGfxId() const;
  int getRace() const;
  QString getLook() const;
  bool getUseSummonSlot() const;
  bool getUseBombSlot() const;
  bool getCanPlay() const;
  bool getCanTackle() const;
  bool getIsBoss() const;
  QList<uint> getSubareas() const;
  QList<uint> getSpells() const;
  QList<QString> getSpellGrades() const;
  int getFavoriteSubareaId() const;
  bool getIsMiniBoss() const;
  bool getIsQuestMonster() const;
  uint getCorrespondingMiniBossId() const;
  double getSpeedAdjust() const;
  int getCreatureBoneId() const;
  bool getCanBePushed() const;
  bool getCanBeCarried() const;
  bool getCanUsePortal() const;
  bool getCanSwitchPos() const;
  bool getCanSwitchPosOnTarget() const;
  bool getFastAnimsFun() const;
  QList<uint> getIncompatibleIdols() const;
  bool getAllIdolsDisabled() const;
  QList<uint> getIncompatibleChallenges() const;
  bool getUseRaceValues() const;
  int getAggressiveZoneSize() const;
  int getAggressiveLevelDiff() const;
  QString getAggressiveImmunityCriterion() const;
  int getAggressiveAttackDelay() const;
  int getScaleGradeRef() const;
  QList<QList<double>> getCharacRatios() const;
  QString getName() const;
  virtual void loadData(const QList<D2OField*> &fields, I18nFile *I18n);

  int m_id;
  uint m_nameId;
  uint m_gfxId;
  int m_race;
  QString m_look;
  bool m_useSummonSlot;
  bool m_useBombSlot;
  bool m_canPlay;
  bool m_canTackle;
  bool m_isBoss;
  QList<uint> m_subareas;
  QList<uint> m_spells;
  QList<QString> m_spellGrades;
  int m_favoriteSubareaId;
  bool m_isMiniBoss;
  bool m_isQuestMonster;
  uint m_correspondingMiniBossId;
  double m_speedAdjust;
  int m_creatureBoneId;
  bool m_canBePushed;
  bool m_canBeCarried;
  bool m_canUsePortal;
  bool m_canSwitchPos;
  bool m_canSwitchPosOnTarget;
  bool m_fastAnimsFun;
  QList<uint> m_incompatibleIdols;
  bool m_allIdolsDisabled;
  QList<uint> m_incompatibleChallenges;
  bool m_useRaceValues;
  int m_aggressiveZoneSize;
  int m_aggressiveLevelDiff;
  QString m_aggressiveImmunityCriterion;
  int m_aggressiveAttackDelay;
  int m_scaleGradeRef;
  QList<QList<double>> m_characRatios;
};

#endif // MONSTERDATA_H
#ifndef GUILDRECRUITMENTINFORMATION_H
#define GUILDRECRUITMENTINFORMATION_H

#include "src/protocol/types/AbstractClass.h"
#include "src/engines/io/network/utils/BooleanByteWrapper.h"
#include "src/engines/io/network/utils/FuncTree.h"

class GuildRecruitmentInformation : public AbstractClass
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_GuildRecruitmentInformation(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_GuildRecruitmentInformation(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_GuildRecruitmentInformation(FuncTree tree);
  GuildRecruitmentInformation();
  bool operator==(const GuildRecruitmentInformation &compared);

  uint guildId;
  uint recruitmentType;
  QString recruitmentTitle;
  QString recruitmentText;
  QList<uint> selectedLanguages;
  QList<uint> selectedCriterion;
  uint minLevel;
  bool minLevelFacultative;
  uint minSuccess;
  bool minSuccessFacultative;
  bool invalidatedByModeration;
  QString lastEditPlayerName;
  double lastEditDate;
  bool recruitmentAutoLocked;

private:
  void deserializeByteBoxes(Reader *input);
  void _guildIdFunc(Reader *input);
  void _recruitmentTypeFunc(Reader *input);
  void _recruitmentTitleFunc(Reader *input);
  void _recruitmentTextFunc(Reader *input);
  void _selectedLanguagestreeFunc(Reader *input);
  void _selectedLanguagesFunc(Reader *input);
  void _selectedCriteriontreeFunc(Reader *input);
  void _selectedCriterionFunc(Reader *input);
  void _minLevelFunc(Reader *input);
  void _minSuccessFunc(Reader *input);
  void _lastEditPlayerNameFunc(Reader *input);
  void _lastEditDateFunc(Reader *input);

  FuncTree _selectedLanguagestree;
  FuncTree _selectedCriteriontree;
};

#endif // GUILDRECRUITMENTINFORMATION_H
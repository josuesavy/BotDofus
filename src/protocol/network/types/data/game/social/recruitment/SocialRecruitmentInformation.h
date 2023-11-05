#ifndef SOCIALRECRUITMENTINFORMATION_H
#define SOCIALRECRUITMENTINFORMATION_H

#include "src/protocol/types/AbstractClass.h"
#include "src/engines/io/network/utils/BooleanByteWrapper.h"
#include "src/engines/io/network/utils/FuncTree.h"

class SocialRecruitmentInformation : public AbstractClass
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_SocialRecruitmentInformation(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_SocialRecruitmentInformation(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_SocialRecruitmentInformation(FuncTree tree);
  SocialRecruitmentInformation();
  bool operator==(const SocialRecruitmentInformation &compared);

  uint socialId;
  uint recruitmentType;
  QString recruitmentTitle;
  QString recruitmentText;
  QList<uint> selectedLanguages;
  QList<uint> selectedCriterion;
  uint minLevel;
  bool minLevelFacultative;
  bool invalidatedByModeration;
  QString lastEditPlayerName;
  double lastEditDate;
  bool recruitmentAutoLocked;

private:
  void deserializeByteBoxes(Reader *input);
  void _socialIdFunc(Reader *input);
  void _recruitmentTypeFunc(Reader *input);
  void _recruitmentTitleFunc(Reader *input);
  void _recruitmentTextFunc(Reader *input);
  void _selectedLanguagestreeFunc(Reader *input);
  void _selectedLanguagesFunc(Reader *input);
  void _selectedCriteriontreeFunc(Reader *input);
  void _selectedCriterionFunc(Reader *input);
  void _minLevelFunc(Reader *input);
  void _lastEditPlayerNameFunc(Reader *input);
  void _lastEditDateFunc(Reader *input);

  FuncTree _selectedLanguagestree;
  FuncTree _selectedCriteriontree;
};

#endif // SOCIALRECRUITMENTINFORMATION_H
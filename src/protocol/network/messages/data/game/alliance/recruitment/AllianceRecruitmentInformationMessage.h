#ifndef ALLIANCERECRUITMENTINFORMATIONMESSAGE_H
#define ALLIANCERECRUITMENTINFORMATIONMESSAGE_H

#include "src/protocol/types/data/game/alliance/recruitment/AllianceRecruitmentInformation.h"
#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class AllianceRecruitmentInformationMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_AllianceRecruitmentInformationMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_AllianceRecruitmentInformationMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_AllianceRecruitmentInformationMessage(FuncTree tree);
  AllianceRecruitmentInformationMessage();

  AllianceRecruitmentInformation recruitmentData;

private:
  void _recruitmentDatatreeFunc(Reader *input);

  FuncTree _recruitmentDatatree;
};

#endif // ALLIANCERECRUITMENTINFORMATIONMESSAGE_H
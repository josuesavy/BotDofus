#ifndef ALLIANCEUPDATERECRUITMENTINFORMATIONMESSAGE_H
#define ALLIANCEUPDATERECRUITMENTINFORMATIONMESSAGE_H

#include "src/protocol/types/data/game/alliance/recruitment/AllianceRecruitmentInformation.h"
#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class AllianceUpdateRecruitmentInformationMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_AllianceUpdateRecruitmentInformationMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_AllianceUpdateRecruitmentInformationMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_AllianceUpdateRecruitmentInformationMessage(FuncTree tree);
  AllianceUpdateRecruitmentInformationMessage();

  AllianceRecruitmentInformation recruitmentData;

private:
  void _recruitmentDatatreeFunc(Reader *input);

  FuncTree _recruitmentDatatree;
};

#endif // ALLIANCEUPDATERECRUITMENTINFORMATIONMESSAGE_H
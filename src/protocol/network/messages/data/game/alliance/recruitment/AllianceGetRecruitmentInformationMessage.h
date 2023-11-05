#ifndef ALLIANCEGETRECRUITMENTINFORMATIONMESSAGE_H
#define ALLIANCEGETRECRUITMENTINFORMATIONMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class AllianceGetRecruitmentInformationMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_AllianceGetRecruitmentInformationMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_AllianceGetRecruitmentInformationMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_AllianceGetRecruitmentInformationMessage(FuncTree tree);
  AllianceGetRecruitmentInformationMessage();
};

#endif // ALLIANCEGETRECRUITMENTINFORMATIONMESSAGE_H
#ifndef ALLIANCERECRUITMENTINVALIDATEMESSAGE_H
#define ALLIANCERECRUITMENTINVALIDATEMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class AllianceRecruitmentInvalidateMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_AllianceRecruitmentInvalidateMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_AllianceRecruitmentInvalidateMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_AllianceRecruitmentInvalidateMessage(FuncTree tree);
  AllianceRecruitmentInvalidateMessage();
};

#endif // ALLIANCERECRUITMENTINVALIDATEMESSAGE_H
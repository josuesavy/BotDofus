#ifndef UPDATERECRUITMENTINFORMATIONMESSAGE_H
#define UPDATERECRUITMENTINFORMATIONMESSAGE_H

#include "src/protocol/types/data/game/guild/recruitment/GuildRecruitmentInformation.h"
#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class UpdateRecruitmentInformationMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_UpdateRecruitmentInformationMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_UpdateRecruitmentInformationMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_UpdateRecruitmentInformationMessage(FuncTree tree);
  UpdateRecruitmentInformationMessage();

  GuildRecruitmentInformation recruitmentData;

private:
  void _recruitmentDatatreeFunc(Reader *input);

  FuncTree _recruitmentDatatree;
};

#endif // UPDATERECRUITMENTINFORMATIONMESSAGE_H
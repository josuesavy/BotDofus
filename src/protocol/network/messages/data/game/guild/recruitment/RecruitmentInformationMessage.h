#ifndef RECRUITMENTINFORMATIONMESSAGE_H
#define RECRUITMENTINFORMATIONMESSAGE_H

#include "src/protocol/types/data/game/guild/recruitment/GuildRecruitmentInformation.h"
#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class RecruitmentInformationMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_RecruitmentInformationMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_RecruitmentInformationMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_RecruitmentInformationMessage(FuncTree tree);
  RecruitmentInformationMessage();

  GuildRecruitmentInformation recruitmentData;

private:
  void _recruitmentDatatreeFunc(Reader *input);

  FuncTree _recruitmentDatatree;
};

#endif // RECRUITMENTINFORMATIONMESSAGE_H
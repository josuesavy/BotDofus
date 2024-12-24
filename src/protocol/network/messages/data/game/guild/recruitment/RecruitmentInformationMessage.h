#ifndef RECRUITMENTINFORMATIONMESSAGE_H
#define RECRUITMENTINFORMATIONMESSAGE_H

#include "src/protocol/network/types/data/game/guild/recruitment/GuildRecruitmentInformation.h"
#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

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
#ifndef GUILDRECRUITMENTINFORMATION_H
#define GUILDRECRUITMENTINFORMATION_H

#include "src/protocol/types/AbstractClass.h"
#include "src/protocol/types/data/game/social/recruitment/SocialRecruitmentInformation.h"
#include "src/engines/io/network/utils/FuncTree.h"

class GuildRecruitmentInformation : public SocialRecruitmentInformation
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_GuildRecruitmentInformation(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_GuildRecruitmentInformation(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_GuildRecruitmentInformation(FuncTree tree);
  GuildRecruitmentInformation();
  bool operator==(const GuildRecruitmentInformation &compared);

  uint minSuccess;
  bool minSuccessFacultative;

private:
  void _minSuccessFunc(Reader *input);
  void _minSuccessFacultativeFunc(Reader *input);
};

#endif // GUILDRECRUITMENTINFORMATION_H
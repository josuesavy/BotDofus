#ifndef BASICGUILDINFORMATIONS_H
#define BASICGUILDINFORMATIONS_H

#include "src/Protocol/Types/AbstractClass.h"
#include "src/Protocol/Types/Data/game/social/AbstractSocialGroupInfos.h"
#include "src/Engines/IO/Network/Utils/FuncTree.h"

class BasicGuildInformations : public AbstractSocialGroupInfos
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_BasicGuildInformations(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_BasicGuildInformations(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_BasicGuildInformations(FuncTree tree);
  BasicGuildInformations();
  bool operator==(const BasicGuildInformations &compared);

  uint guildId;
  QString guildName;
  uint guildLevel;

private:
  void _guildIdFunc(Reader *input);
  void _guildNameFunc(Reader *input);
  void _guildLevelFunc(Reader *input);
};

#endif // BASICGUILDINFORMATIONS_H
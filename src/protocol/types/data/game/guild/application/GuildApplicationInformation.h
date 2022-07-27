#ifndef GUILDAPPLICATIONINFORMATION_H
#define GUILDAPPLICATIONINFORMATION_H

#include "src/protocol/types/AbstractClass.h"
#include "src/protocol/types/data/game/guild/application/ApplicationPlayerInformation.h"
#include "src/engines/io/network/utils/FuncTree.h"

class GuildApplicationInformation : public AbstractClass
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_GuildApplicationInformation(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_GuildApplicationInformation(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_GuildApplicationInformation(FuncTree tree);
  GuildApplicationInformation();
  bool operator==(const GuildApplicationInformation &compared);

  QSharedPointer<ApplicationPlayerInformation> playerInfo;
  QString applyText;
  double creationDate;

private:
  void _playerInfotreeFunc(Reader *input);
  void _applyTextFunc(Reader *input);
  void _creationDateFunc(Reader *input);

  FuncTree _playerInfotree;
};

#endif // GUILDAPPLICATIONINFORMATION_H
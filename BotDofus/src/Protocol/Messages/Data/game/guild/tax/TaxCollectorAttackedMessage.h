#ifndef TAXCOLLECTORATTACKEDMESSAGE_H
#define TAXCOLLECTORATTACKEDMESSAGE_H

#include "src/Protocol/Types/Data/game/context/roleplay/BasicGuildInformations.h"
#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

class TaxCollectorAttackedMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_TaxCollectorAttackedMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_TaxCollectorAttackedMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_TaxCollectorAttackedMessage(FuncTree tree);
  TaxCollectorAttackedMessage();

  uint firstNameId;
  uint lastNameId;
  int worldX;
  int worldY;
  double mapId;
  uint subAreaId;
  QSharedPointer<BasicGuildInformations> guild;

private:
  void _firstNameIdFunc(Reader *input);
  void _lastNameIdFunc(Reader *input);
  void _worldXFunc(Reader *input);
  void _worldYFunc(Reader *input);
  void _mapIdFunc(Reader *input);
  void _subAreaIdFunc(Reader *input);
  void _guildtreeFunc(Reader *input);

  FuncTree _guildtree;
};

#endif // TAXCOLLECTORATTACKEDMESSAGE_H
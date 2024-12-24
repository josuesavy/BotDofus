#ifndef TAXCOLLECTORATTACKEDMESSAGE_H
#define TAXCOLLECTORATTACKEDMESSAGE_H

#include "src/protocol/network/types/data/game/context/roleplay/BasicAllianceInformations.h"
#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

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
  QSharedPointer<BasicAllianceInformations> alliance;

private:
  void _firstNameIdFunc(Reader *input);
  void _lastNameIdFunc(Reader *input);
  void _worldXFunc(Reader *input);
  void _worldYFunc(Reader *input);
  void _mapIdFunc(Reader *input);
  void _subAreaIdFunc(Reader *input);
  void _alliancetreeFunc(Reader *input);

  FuncTree _alliancetree;
};

#endif // TAXCOLLECTORATTACKEDMESSAGE_H
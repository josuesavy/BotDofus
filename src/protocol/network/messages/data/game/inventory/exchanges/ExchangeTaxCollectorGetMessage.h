#ifndef EXCHANGETAXCOLLECTORGETMESSAGE_H
#define EXCHANGETAXCOLLECTORGETMESSAGE_H

#include "src/protocol/network/types/data/game/data/items/ObjectItemGenericQuantity.h"
#include "src/protocol/network/types/data/game/look/EntityLook.h"
#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class ExchangeTaxCollectorGetMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_ExchangeTaxCollectorGetMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_ExchangeTaxCollectorGetMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_ExchangeTaxCollectorGetMessage(FuncTree tree);
  ExchangeTaxCollectorGetMessage();

  QString collectorName;
  int worldX;
  int worldY;
  double mapId;
  uint subAreaId;
  QString userName;
  double callerId;
  QString callerName;
  uint pods;
  QList<ObjectItemGenericQuantity> objectsInfos;
  QSharedPointer<EntityLook> look;

private:
  void _collectorNameFunc(Reader *input);
  void _worldXFunc(Reader *input);
  void _worldYFunc(Reader *input);
  void _mapIdFunc(Reader *input);
  void _subAreaIdFunc(Reader *input);
  void _userNameFunc(Reader *input);
  void _callerIdFunc(Reader *input);
  void _callerNameFunc(Reader *input);
  void _podsFunc(Reader *input);
  void _objectsInfostreeFunc(Reader *input);
  void _objectsInfosFunc(Reader *input);
  void _looktreeFunc(Reader *input);

  FuncTree _objectsInfostree;
  FuncTree _looktree;
};

#endif // EXCHANGETAXCOLLECTORGETMESSAGE_H
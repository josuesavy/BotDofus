#ifndef EXCHANGEGUILDTAXCOLLECTORGETMESSAGE_H
#define EXCHANGEGUILDTAXCOLLECTORGETMESSAGE_H

#include "src/protocol/types/data/game/data/items/ObjectItemGenericQuantity.h"
#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class ExchangeGuildTaxCollectorGetMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_ExchangeGuildTaxCollectorGetMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_ExchangeGuildTaxCollectorGetMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_ExchangeGuildTaxCollectorGetMessage(FuncTree tree);
  ExchangeGuildTaxCollectorGetMessage();

  QString collectorName;
  int worldX;
  int worldY;
  double mapId;
  uint subAreaId;
  QString userName;
  double callerId;
  QString callerName;
  double experience;
  uint pods;
  QList<ObjectItemGenericQuantity> objectsInfos;

private:
  void _collectorNameFunc(Reader *input);
  void _worldXFunc(Reader *input);
  void _worldYFunc(Reader *input);
  void _mapIdFunc(Reader *input);
  void _subAreaIdFunc(Reader *input);
  void _userNameFunc(Reader *input);
  void _callerIdFunc(Reader *input);
  void _callerNameFunc(Reader *input);
  void _experienceFunc(Reader *input);
  void _podsFunc(Reader *input);
  void _objectsInfostreeFunc(Reader *input);
  void _objectsInfosFunc(Reader *input);

  FuncTree _objectsInfostree;
};

#endif // EXCHANGEGUILDTAXCOLLECTORGETMESSAGE_H